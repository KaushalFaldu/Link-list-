//priority queue

#include<iostream>
using namespace std;

class Node
{
	public:
		int no;
		int prior;
		Node *next;
		
		Node(int i, int j)
		{
			this->no=i;
			this->prior=j;
			this->next=NULL;
		}
};
Node *Front=NULL, *Rear=NULL;
void enqueue(Node *);
void dequeue();
void printqueue();

int main()
{
	Node *t1=new Node(10,1);
	Node *t2=new Node(30,2);
	Node *t3=new Node(20,1);
	Node *t4=new Node(40,2);
	enqueue(t1);
	enqueue(t2);
	enqueue(t3);
	enqueue(t4);
	printqueue();
	
	return 0;
}

void enqueue(Node *t)
{
	if(Front==NULL && Rear==NULL)
	{
		Front=t;
		Rear=t;
		//Rear->next=NULL;
	}
	else
	{
		if(Front==Rear)
		{
			if(t->prior>=Front->prior)
			{
				Front->next=t;
				Rear=t;
			}
			else
			{
				t->next=Front;
				Front=t;
			}
		}
		else
		{
			Node *first=Front;
			while(t->prior>=first->prior && first!=Rear)
			{
				first=first->next;
			}
			if(t->prior>=first->prior)
			{
				if(t->prior==first->prior)
				{
					Rear->next=t;
					Rear=t;
				}
				else
				{
					t=Rear;
					first->next=t;
				}
				
			}
			else
			{
				Node *prev=Front;
				while(prev->next!=first)
				{
					prev=prev->next;
				}
				prev->next=t;
				t->next=first;
			}
		}
	}
	cout<<endl<<t->no<<" is enqueued";
}

void dequeue()
{
	Node *temp;
	if(Front==NULL)
	{
		cout<<endl<<"Queue is empty";
	}
	else if(Front==Rear)
	{
		temp=Front;
		Front=Rear=NULL;
		delete temp;
	}
	else
	{
		temp=Front;
		Front=Front->next;
		delete temp;
	}
}

void printqueue()
{
	Node *first=Front;
	cout<<endl;
	if(Front==NULL)
	{
		cout<<endl<<"Queue is empty";
	}
	else
	{
		while(first!=Rear)
		{
			cout<<first->no<<" -> ";
			first=first->next;
		}
		cout<<Rear->no;
	}
}
