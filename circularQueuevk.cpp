// ASS 3 Circular Queue

#include<iostream>
#define SZ 5
using namespace std;

class Queue
{
	int q[SZ],f,r,k;   // k is counter
	public:
		Queue()
		{
			f=0; r=-1; k=0;   //To Make Q Empty
		}
		int qFull()
		{
			if(k==SZ)
			return(1);
			else
			return(0);
		}
		int qEmpty()
		{
			if(k==0)
			return(1);
			else
			return(0);
		}
		void add();
		void del();
		void disp();
};
void Queue::add()
{
	int cont;
	do
	{
		if(qFull()==1)
		{
			cout<<"\nQ Full";
			break;
		}
		else
		{
			disp();
			r=(r+1)%SZ; k++;
			cout<<"\n Enter the elements : ";
			cin>>q[r];
			disp();
		}
		cout<<"\n Continue(1:yes): ";
		cin>>cont;
	}while(cont==1);
}
void Queue::del()
{
	int cont;
	do
	{
		if(qEmpty()==1)
		{
			cout<<"\n QEmpty";
			break;
		}
		else
		{
			disp();
			cout<<"\n"<<q[f]<<" Is Deleted";
			f=(f+1)%SZ; k--;
			disp();
		}
		cout<<"\n Cntinue(1:yes): ";
		cin>>cont;
	}while(cont==1);
}
void Queue::disp()
{
	int i;
	if(qEmpty()==1)
	{
		cout<<"\nQ Empty";
	}
	else
	{
		cout<<"\nFront-> ";
		for(i=f;i!=r;i=(i+1)%SZ)
		  cout<<q[i]<<" ";
		cout<<q[i]<<" <-Rear";
	}
}
int main()
{
	int ch;
	Queue Q;
	do
	{
		
		cout<<"\n\n\t\t Menu\n\n\t1.Add\n\t2.Del\n\t3.Disp\n\t4.Exit\n\n\t\t Enter ch: ";
		cin>>ch;
		switch(ch)
		{
			case 1: Q.add();break;
			case 2: Q.del();break;
			case 3: Q.disp();break;
			case 4: cout<<"\n coming out!!!";break;
			default:
				cout<<"\n wrong ch!!!";
		}
		
	}while(ch!=4);
	return(0);
}
