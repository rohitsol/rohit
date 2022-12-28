#include <iostream>
#define SZ 20
using namespace std;
class Edge
  {
    int v1,v2,d;
    friend class Graph;
  }E[SZ],T;
class Graph
  {
      char v[SZ][20];
      int n,ecnt;
  public :
      void create();
      void prims();
      void kruskal();
  };
void Graph::create()
  {
     int i,j,d;
     cout<<"\n Enter no of landmarks:";
     cin>>n; cin.get();
     for(i=1;i<=n;i++)
       {
	     cout<<"\nEnter landmark"<<i<<" : ";
	     cin.getline(v[i],20);
	   }
	 ecnt=1;  
     while(1)
	   {
	     for(i=1;i<=n;i++)
		   cout<<"\n"<<i<<"."<<v[i];
		 cout<<"\nEnter Two Landmark Nos having edge :"
		     <<"\n(Enter any landmark no -1 to stop):";
		 cin>>i>>j;
		 if(i==-1 || j==-1)
		   break;
		 else
		  {
		    if(i<1||j<1||i>n||j>n)
			 cout<<"\n Wrong Edge";
			else
			 {
			   cout<<"\n Enter Edge Distance :";
			   cin>>d;
			   E[ecnt].v1=i;
			   E[ecnt].v2=j;
			   E[ecnt].d=d;
			   ecnt++;
			 }
		  }
	   }
	 //Sorting Of Edge array According To Distance   
	 for(i=1;i<ecnt;i++)
       {
         for(j=i+1;j<ecnt;j++)
	       {
	         if(E[i].d > E[j].d)
		       {
		         T=E[i];
		         E[i]=E[j];
		         E[j]=T;
		       }
	      }
       }
  }
void Graph :: prims()
  {
    int i,j,k,es=0,visit[20];
    for(i=1;i<=n;i++)
      visit[i]=0;
    cout<<"\nPrims Algo";
	T=E[1];
    cout<<"\nEdges Selected\n"<<T.v1<<" <---> "
        <<T.v2<< " = "<<T.d;
    visit[T.v1]=visit[T.v2]=1;
    es=1;
	
    while(es<n-1)
      {
        for(i=2;i<=ecnt;i++)
	      {
	        T=E[i];
		    if(visit[T.v1]!=visit[T.v2])
		      {
			    cout<<"\n"<<T.v1<<" <---> "<<T.v2<< " = "<<T.d;
    	        if(visit[T.v1]=0)
		          visit[T.v1]=1;
		        else
                  visit[T.v2]=1;
		        es++;
		        break;	  	     
		      }
	      }
      }
  }	       
void Graph ::kruskal()
  {
    Edge T;
    int c[SZ][SZ],i,j,k,es=0,pv1,pv2;
    for(i=1;i<=n;i++)
      {
        for(j=1;j<=n;j++)
	      {
	        if(j==1)
		      c[i][j]=i;
		    else
		      c[i][j]=0;
	      } 
      }
   k=1;
   while(es<n-1)
    {
	  T=E[k];k++;
	  for(i=1;i<=n;i++)
	   {
	     for(j=1;j<=n;j++)
		  {
		    if(c[i][j]==T.v1)
			  pv1=i;
			if(c[i][j]==T.v2)
			  pv2=i;
			  
		  } 
	   }
	  if(pv1!=pv2)
	    {
	      cout<<"\n"<<T.v1<<"<--->"<<T.v2
		      << "  =  "<<T.d;
		  es++;
		  for(j=1;c[pv1][j]!=0;j++);
		  for(i=1;c[pv2][i]!=0;j++,i++)
		    {
		      c[pv1][j]=c[pv2][i];
	          c[pv1][i]=0;
	        }
	    }
	}
  }
int main()
  {
    Graph G;
	G.create();
//	  G.kruskal();
	G.prims();
	return(0);
  }
