/* Ass 4 (recursively) part1*/

#include<iostream>
#include<conio.h>
using namespace std;

class Node
{
	char d;
	Node *lp, *rp;
	friend class ET;
};

class ET
{
	Node *root;
	public:
		Node *getNode()
		{
			Node *n;
			n=new Node;
			n->lp=n->rp=NULL;
			return(n);
		}
		void createPost();
		void createPre();
		void inOrder(Node*);
		void preOrder(Node*);
		void postOrder(Node*);
		ET()
		{
			root=NULL;
		}
		Node *getRoot()
		{
			return(root);
		}
};
int isOp(char ch)
 {
 	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'||ch=='$')
	  return(1);
	else
	  return(0); 
 }
void ET::createPost()
{
	char exp[50],ch;
	Node *st[20], *n;
	int top=-1,i;
	cout<<"\n Enter Postfix Expression";
	cin.getline(exp,50);
	for(i=0;exp[i]!='\0';i++)
	{
		n=getNode();
		n->d=exp[i];
		if(isOp(exp[i])==0)
		{
			top++;
			st[top]=n;
		}
		else
		{
			n->rp=st[top];top--;
			n->lp=st[top];
			st[top]=n;
		}
	}
	root=st[top];
}
void ET::preOrder(Node *r)
{
	if(r!=NULL)
	{
		cout<<r->d;
		preOrder(r->lp);
		preOrder(r->rp);
	}
}
void ET::inOrder(Node *r)
{
	if(r!=NULL)
	{
		inOrder(r->lp);
		cout<<r->d;
		inOrder(r->rp);
	}
}
void ET::postOrder(Node *r)
{
	if(r!=NULL)
	{
		postOrder(r->lp);
		postOrder(r->rp);
		cout<<r->d;
	}
}
int main()
{
	ET T;
	T.createPost();
	cout<<"\nPost Order  : ";
	T.postOrder(T.getRoot());
	cout<<"\nPre Order  : ";
	T.preOrder(T.getRoot());
    cout<<"\nIn Order : ";
	T.inOrder(T.getRoot());
	return(0);
}

