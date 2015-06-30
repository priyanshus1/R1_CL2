
#include <iostream>
#include "fstream"
using namespace std;


class node
{
	int level;
	int visited;
	char name;
	node *next;
	node()
	{
		level=0;
		visited=0;
		name = NULL;
		next=NULL;
	}
	friend class queue;
	friend class graph;
};
class queue
{
	node *head;
	node *tail;
public :
	queue()
	{
		head=NULL;
		tail=NULL;
	}
	void push(node *);
	node* pop();
	friend class graph;
};
class graph
{

	int num_nodes;
	node *n;
public:
	graph();
	int get_num_nodes();
	void init_node_array();
	void get_graph();
	node* search(char);
	void manav();
	void traversal();
	void visited(node *);
};
graph::graph()
{
	num_nodes=0;
	n=NULL;
}
void graph::manav()
{
	int na = get_num_nodes();
	init_node_array();
	get_graph();
	for(int i=0;i<na;i++)
	{
		node *temp = &n[i];
		while(temp)
		{
			cout<<temp->name<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
	traversal();
}
int graph::get_num_nodes()
{
	int num=0;
	cout<<"Enter The Number Of Nodes : "<<endl;
	cin>>num;
	return num;
}
void graph::init_node_array()
{
	num_nodes = get_num_nodes();
	n = new node[num_nodes];
	for(int i=0;i<num_nodes;i++)
	{
		cout<<"Enter Node "<< (i+1) <<" : ";
		cin>>n[i].name;
		n[i].next=NULL;
	}
}
void graph::get_graph()
{
	char src,dest;

	ifstream inu;
	//cout<<"Enter The name Of input file : ";
	//cin>>filename;
	//cout<<filename<<endl;
	inu.open("manav.txt");
	node *source=NULL,*destination,*temp;
	while(inu>>src>>dest)
	{

		source = search(src);
		if(source)
		{

			while(source->next)
			{
				source = source->next;
			}
			temp = new node;
			source->next=temp;
			temp->next=NULL;
			temp->name = dest;
		}
		else
		{
			cout<<"Source not Found invalid input"<<endl;
			break;
		}

		destination = search(dest);
		if(destination)
		{

			while(destination->next)
			{
				destination = destination->next;
			}
			temp = new node;
			destination->next=temp;
			temp->next=NULL;
			temp->name = src;
		}
		else
		{
			cout<<"Source not Found invalid input"<<endl;
			break;
		}
	}
	inu.close();
}
node* graph::search(char sea)
{
	node *temp;
	temp =NULL;
	for(int i=0;i<num_nodes;i++)
	{
		if(n[i].name==sea)
		{
			temp=&n[i];
			break;
		}
	}
	return temp;
}
void graph::traversal()
{
	int prev=0;
	queue q;
	char home;
	cout<<"Enter Start point"<<endl;
	cin>>home;
	node *temp = search(home);
	if(temp)
	{
		temp->level=0;
		while(temp)
		{
			temp=search(temp->name);
			if(temp->visited==0)
			{
				if(prev==temp->level)
				{
					cout<<temp->name<<" ";
				}
				else
				{
					cout<<endl;
					cout<<temp->name<<" ";
				}
				visited(temp);
				prev=temp->level;
				node *temp2=temp;
				while(temp2)
				{
					if(temp2->visited==0)
					{
						q.push(temp2);
						node *set=search(temp2->name);
						set->level=temp->level+1;
					}
					temp2=temp2->next;
				}
			}
			temp=q.pop();
		}
	}
	else
	{
		cout<<"Enter Valid Node"<<endl;
	}
}
void graph::visited(node *visit)
{
	for(int i=0;i<num_nodes;i++)
	{
		node *temp = &n[i];
		while(temp)
		{
			if(temp->name==visit->name)
			{
				temp->visited=1;
			}
			temp=temp->next;
		}
	}
}
void queue::push(node *point)
{
	node *temp1;
	if(head==NULL)
	{
		temp1 = new node;
		temp1->next=NULL;
		head=temp1;
	}
	else
	{
		temp1 = new node;
		temp1->next=head;
		head=temp1;
	}
	temp1->name=point->name;
}
node* queue::pop()
{
	node *temp,*temp1;
	temp=head;
	if(temp!=NULL)
	{
		if(temp->next!=NULL)
		{
			while(temp->next)
			{
				temp1=temp;
				temp=temp->next;
			}
			temp1->next=NULL;
		}
		else
		{
			temp=head;
			head=NULL;
		}
	}
	else
	{
		cout<<endl;
		cout<<"Queue Is Empty nothing To pop"<<endl;
		temp=NULL;
	}
	return temp;
}

int main()
{
	graph g;
	g.manav();
	return 0;
}
