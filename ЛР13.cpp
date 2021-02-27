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
	do    //��� ������� � ��������
	{
		cout<<endl;
		cout<<"****************************************";
		cout<<endl;
		cout<<"�������� ��� ���������� �������:\n\t(1)���������� ���������� ���������;\n\t(2)������� �� ���� ������ ��������� ������� ����� ���� ��������� �������\n\t(3)���������� �������� ������ ����� �� ����� �������\n\t(4)�������� � ����� ��� ��������, ������� ����������� ������ ���� ���\n\t(5)������ ������ ������\n\t(6)������� ������\n\t(0)����� "<<endl;
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
      	default :   cout<<"�� ����� ������������ �������"<<endl;  break;
	  }
	}while(command!='0');
	return 0;
}
void inputD(int *arr, int &amount) // ���������  ������ ���������� ������� �� � �� �
{	
	int A, B;
	srand(time(NULL));
	do			    //�������� �� �<�
	{
		cout<<"������� ���-�� ���������: "<<endl; cin>>amount;
		cout<<"������� �������� �������� [�, �];"<<endl;
		cin>>A;
		cin>>B;
		if (A>B) cout<<"�������� �������� �����������"<<endl;
		if (amount<0) cout<<"���������� ��������� �� ������ ���� ������ ���� "<<endl;
	}while (A>B || amount<0);
	for (int i=0; i< amount; i++)
	{
		arr[i]= rand()%(B-A+1)+A;
	}
}
void inputF(int *arr, int &amount) // ���� �� �����
{
	ifstream f("���� �������.txt");
	amount=0;
	if(!f.is_open() || f.peek() == EOF)
	{
		cout<<"����� �� ���������� ��� � �� ����������� �������� "<<endl;
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
void inputK(int *arr, int &amount) // ���� � ����������
{
	cout<<"������� ���-�� ��������� � �������: "; 
	do
	{
		cin>>amount; 
		if (amount<0 || amount>100) cout<<"���-�� ��������� �� ����� ��������� 100 ��� ���� ������ 0 :( "<<endl;
	}while(amount<0 || amount>100);
	cout<<"���� �������: "<<endl;
	for( int i=0; i<amount; i++)
	{
		cin>>arr[i];
	}
}
void subtraction(int *arr, int amount) // ��������� �� ������ ��������� ����� ��������� 
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
void shift(int *arr, int amount)	   //����������� ����� ������� ����� �� ���� �������
{
	int save= arr[0];
	for(int i=1;i<amount; i++)
	{
		arr[i-1]=arr[i];
	}
	arr[amount-1]=save;
}
void findCountOf(int *arr, int amount)  // ����� ���������� �� ���������
{
	int A,B, count;
	cout<<"������� �������� �� � �� �: "<<endl; 
	do{
		cin>>A>>B;
		if (A>B) cout<<"����� ������� ������ ���� ������ ������ "<<endl;
	}while(A>B);
	for (int i=0; i<amount; i++)
	{
		if ((arr[i]>A || arr[i]==A) && (arr[i]<B || arr[i]==B)) count++;
	}
	cout<<"���-�� ���������, ������������� ���������� ���������: "<<count<<endl;
}
void insert(int *arr, int &amount)    //���������� � ����� ������� ���������, ������� ����������� ������ ���� ���
{
	for(int i=0; i<amount; i++)		  
	{
		int count=0;
		for(int j=0; j<amount; j++)	 		// ��������� ������� ��� ������� arr[i] ���������� � �������
		{
			if (arr[i]==arr[j]) count++;	// ����� ������� ����������� �� ����������� ���������� �� ����
			if (count==2)	break;			// ���� ������� ����������� >2 ���, �� �� ������� �� �����
		}
		if (count<2) 						// ���� ������� ���������� <2 ���, �� �� ��������� ��� � �����
		{
			arr[amount]=arr[i];
			amount++;	
		}
	}
}
void output(int const *arr,  int amount) //������� ������ �� �����
{		
	cout<<"������: "<<endl;
	for (int i=0; i< amount; i++)
	{
		cout<<arr[i]<<" ";
	}
}
void outputF(int const *arr,  int amount) //����� ������� � ����
{
	ofstream f ("����� �������.txt");
	for (int i=0; i<amount ; i++ )	f<<arr[i]<<"\t";
	f.close();
}
void InputSelection(int *arr, int &amount) //��� ������ �����
{
	char command;
		do
	{
	  cout<<endl;	
      cout<<"������� ������� ����� �������: \n(1)� ����������; (2)�� ���������; (3)�� �����; ";
      cin>>command;
      cout<<endl;
      switch(command)
      {
      	case '1':	inputK(arr, amount);	break;
      	case '2': {	inputD(arr, amount);	output(arr, amount); } break;
      	case '3': { inputF(arr, amount); 	output(arr, amount); } break;
      	default :   cout<<"�� ����� ������������ �������"<<endl;  break;
	  }
	} while(command<'1' || command>'3' );
}
void OutputSelection(int *arr, int &amount)//��� ������ ������
{
	char command;
	do	
	{
	  cout<<endl;	
      cout<<"������� ������� ������ �������: \n(1)�� �����; (2)� ����;";
	  cin>>command;
      cout<<endl;		
	  switch(command)
      {
      	case '1':  output(arr, amount);	 break;
      	case '2':  outputF(arr, amount); break;
      	default :  cout<<"�� ����� ������������ �������"<<endl;  break;
	  }	
	} while(command<'1' || command>'2' );
}
