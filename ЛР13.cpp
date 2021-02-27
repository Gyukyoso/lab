#include <locale.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
void output(int const *arr,  int amount);
void outputF(int const *arr, int amount);
void inputD(int *arr, int &amount);
void inputF(int *arr, int &amount);
void inputK(int *arr, int &amount);
void subtraction(int *arr, int amount);
void shift(int *arr,  int amount);
void insert(int *arr, int &amount);
void findCountOf(int *arr, int amount);
void InputSelection(int *arr, int &amount);
void OutputSelection(int *arr, int &amount);
int main()
{
	setlocale(LC_ALL, "Russian");
	int arr[100];
	int amount=0;
	char command;
	InputSelection(arr, amount);
	do    //Что сделать с массивом
	{
		cout<<endl;
		cout<<"****************************************";
		cout<<endl;
		cout<<"Выберите что необходимо сделать:\n\t(1)Определить количество элементов;\n\t(2)Вычесть из всех четных элементов массива сумму всех элементов массива\n\t(3)Циклически сдвинуть массив влево на одигн элемент\n\t(4)Добавить в конец все элементы, которые встречаются меньше двух раз\n\t(5)Ввести массив заново\n\t(6)Вывести массив\n\t(0)Выйти "<<endl;
		cout<<"****************************************";
		cout<<endl;
		cin>>command;
      switch(command)
      { 
      	case'1': findCountOf(arr, amount);	break;
      	case'2': subtraction(arr, amount);break;
      	case'3': shift(arr, amount);    break;
      	case'4': insert(arr, amount);	break;
      	case'5': InputSelection(arr, amount);	break;
      	case'6': OutputSelection(arr, amount);	break;
      	case'0':	break;
      	default :   cout<<"Вы ввели неправильную команду"<<endl;  break;
	  }
	}while(command!='0');
	return 0;
}
void inputD(int *arr, int &amount) // заполняет  массив рандомными числами от А до В
{	
	int A, B;
	srand(time(NULL));
	do			    //Проверка на А<В
	{
		cout<<"Введите кол-во элементов: "<<endl; cin>>amount;
		cout<<"Введите диапазон значений [А, В];"<<endl;
		cin>>A;
		cin>>B;
		if (A>B) cout<<"Введённый диапазон некорректен"<<endl;
		if (amount<0) cout<<"Количество элементов не можешт быть меньше нуля "<<endl;
	}while (A>B || amount<0);
	for (int i=0; i< amount; i++)
	{
		arr[i]= rand()%(B-A+1)+A;
	}
}
void inputF(int *arr, int &amount) // ввод из файла
{
	ifstream f("Ввод массива.txt");
	amount=0;
	if(!f.is_open() || f.peek() == EOF)
	{
		cout<<"Файла не существует или в нём отсутствуют элементы "<<endl;
		InputSelection(arr, amount);
	}
	else
	{
		while(!f.eof())
		{
			f>>arr[amount];
			amount++;
		}
	}
	f.close();	
}
void inputK(int *arr, int &amount) // Ввод с клавиатуры
{
	cout<<"Введите кол-во элементов в массиве: "; 
	do
	{
		cin>>amount; 
		if (amount<0 || amount>100) cout<<"Кол-во элементов не может первышать 100 или быть меньше 0 :( "<<endl;
	}while(amount<0 || amount>100);
	cout<<"Ввод массива: "<<endl;
	for( int i=0; i<amount; i++)
	{
		cin>>arr[i];
	}
}
void subtraction(int *arr, int amount) // Вычитание из чётных элементов суммы элементов 
{
	int sum=0;
	for (int i=0; i<amount; i++)
	{
		sum+=arr[i];
	}
	for (int j=0; j<amount; j++)
	{
		if ((arr[j]%2)==0) arr[j]-=sum;
	}
}
void shift(int *arr, int amount)	   //Циклический сдвиг массива влево на один элемент
{
	int save= arr[0];
	for(int i=1;i<amount; i++)
	{
		arr[i-1]=arr[i];
	}
	arr[amount-1]=save;
}
void findCountOf(int *arr, int amount)  // Поиск количества из диапазона
{
	int A,B, count;
	cout<<"Введите диапазон от А до В: "<<endl; 
	do{
		cin>>A>>B;
		if (A>B) cout<<"Левая границы должна быть меньше правой "<<endl;
	}while(A>B);
	for (int i=0; i<amount; i++)
	{
		if ((arr[i]>A || arr[i]==A) && (arr[i]<B || arr[i]==B)) count++;
	}
	cout<<"Кол-во элементов, принадлежащих указанному диапазону: "<<count<<endl;
}
void insert(int *arr, int &amount)    //Добавление в конец массива элементов, которые встречаются меньше двух раз
{
	for(int i=0; i<amount; i++)		  
	{
		int count=0;
		for(int j=0; j<amount; j++)	 		// Проверяем сколько раз элемент arr[i] встречался в массиве
		{
			if (arr[i]==arr[j]) count++;	// Когда элемент встречается мы увеличиваем переменную на один
			if (count==2)	break;			// Если элемент встречается >2 раз, то мы выходим из цикла
		}
		if (count<2) 						// Если элемент встретился <2 раз, то мы добавляем его в конце
		{
			arr[amount]=arr[i];
			amount++;	
		}
	}
}
void output(int const *arr,  int amount) //выводит массив на экран
{		
	cout<<"Массив: "<<endl;
	for (int i=0; i< amount; i++)
	{
		cout<<arr[i]<<" ";
	}
}
void outputF(int const *arr,  int amount) //вывод массива в файл
{
	ofstream f ("Вывод массива.txt");
	for (int i=0; i<amount ; i++ )	f<<arr[i]<<"\t";
	f.close();
}
void InputSelection(int *arr, int &amount) //Для выбора ввода
{
	char command;
		do
	{
	  cout<<endl;	
      cout<<"Введите вариант ввода массива: \n(1)с клавиатуры; (2)из диапазона; (3)из файла; ";
      cin>>command;
      cout<<endl;
      switch(command)
      {
      	case '1':	inputK(arr, amount);	break;
      	case '2': {	inputD(arr, amount);	output(arr, amount); } break;
      	case '3': { inputF(arr, amount); 	output(arr, amount); } break;
      	default :   cout<<"Вы ввели неправильную команду"<<endl;  break;
	  }
	} while(command<'1' || command>'3' );
}
void OutputSelection(int *arr, int &amount)//Для выбора вывода
{
	char command;
	do	
	{
	  cout<<endl;	
      cout<<"Введите вариант вывода массива: \n(1)на экран; (2)в файл;";
	  cin>>command;
      cout<<endl;		
	  switch(command)
      {
      	case '1':  output(arr, amount);	 break;
      	case '2':  outputF(arr, amount); break;
      	default :  cout<<"Вы ввели неправильную команду"<<endl;  break;
	  }	
	} while(command<'1' || command>'2' );
}
