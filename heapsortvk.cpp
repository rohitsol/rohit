// ASS 9 Heap Sort

#include<iostream>
#define sz 50

using namespace std;
class Heap
{
	    int a[sz],n;
	public:
		void accArr();
		void dispArr();
		void arrange(int);
		void sort();
};

void Heap::accArr()
{
	int i;
	cout<<"\nEnter no. of elements : ";
	cin>>n;
	cout<<"\nEnter "<<n<<" elements \n";
	for(i=0;i<n;i++)
	  cin>>a[i];
}

void Heap::dispArr()
{
	int i;
	cout<<"\n";
	for(i=0;i<n;i++)
	  cout<<a[i]<<" ";
}

void Heap::arrange(int i)
{
	int p,t;
	while(i>0)
	{
		if(i%2==1)  //if i is odd, parent is at i/2 else at i/2-1
		  p=i/2;
		else
		  p=i/2-1;
		
		if(a[p]<a[i])
		  {  
			t=a[p];
			a[p]=a[i];
			a[i]=t;
			i=p;   // shift i to parent
		  }  
		else
		  break;
	}
}

void Heap::sort()
{
	int i,t,j;
	for(i=1;i<n;i++)  // for step 1 i.e to arrange all ele in heap form
	  arrange(i);
	cout<<"\n\nData in Heap form";
	dispArr();
	for(i=n-1;i>0;i--)  // for step2 i.e actual sorting by interchanging first and last ele and rearranging remaining ele
	  {
		t=a[i];
		a[i]=a[0];
		a[0]=t;
		for(j=0;j<i;j++)
	      arrange(j);
      }
    cout<<"\n\nSorted Array";
    dispArr();
}

int main()
{
	Heap H;
	H.accArr();
	H.dispArr();
	H.sort();
	return(0);
}
