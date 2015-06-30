//============================================================================
// Name        : a.cpp
// Author      : AISHWARYA
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
int adj[10][10],i,j,k,n,qu[10],front,rear,v,visit[10],visited[10],stk[10],top;
FILE *fp;
class node
{
public :

    int node_num, dist;
    node *next;
    node(int n, int d) {
        this->node_num = n;
        this->dist = d;
        next = NULL;
    }
};

//adjacency List
void insert_node(node *graph_list[], int num, node * p) {

    if (graph_list[num] == NULL) {
        graph_list[num] = p;
        return;
    }
    node *temp = graph_list[num];

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = p;

}


node *graph_list[10];
void list(int num_nodes, int num_links) {
    //init to null;
    for (int i = 0; i < num_nodes; i++) {
        graph_list[i] = NULL;
    }

    for (int i = 0; i < num_links; i++) {
    	   int src,dest,cost;
    	   char c=0;
    		fscanf(fp, "%d,%d,%d%c", &src, &dest, &cost,&c);

        node *p = new node(dest, cost);
        node *q = new node(src, cost);
        --src;
        --dest;
        insert_node(graph_list, src, p);
        insert_node(graph_list, dest, q);

    }

    cout << "Adjacency List:" << endl;
    for (int i = 0; i < num_nodes; i++) {
        cout << i + 1;
        node * temp = graph_list[i];
        while (temp != NULL) {
            cout << " " << temp->node_num;
            temp = temp->next;
        }
        cout << endl;
    }

}
//adjacency list bfs
void BFS(int num_nodes, bool a) {
    cout << "BFS ";
    bool visit[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        visit[i] = 0;
    }
    visit[0] = 1;
    queue<int> q;
    q.push(1);
    int num;
    node * temp;

    while (!q.empty()) {
        num = q.front();
        cout << num << " --> ";
        temp = graph_list[num - 1];
        q.pop();

        while (temp) {
            if (!visit[temp->node_num - 1]) {
                visit[temp->node_num - 1] = 1;
                q.push(temp->node_num);
            }
            temp = temp->next;

        }

    }

    cout << endl;

}
//adjacency list dfs
void DFS(int num_nodes, bool a) {
    cout << "DFS  ";

    stack<int> s;
    bool visit[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        visit[i] = 0;
    }
    visit[0] = 1;
    s.push(1);

    node* temp;
    int itemp;
    while (!s.empty()) {

        b: itemp = s.top();
        temp = graph_list[itemp - 1];
        cout << itemp << " --> ";
        s.pop();

        while (temp) {
            if (!visit[temp->node_num - 1]) {
                itemp = temp->node_num;
                visit[itemp - 1] = 1;
                s.push(itemp);
                goto b;
            }
            temp = temp->next;

        }

    }
    cout << endl;

}

//ADJACENCY MATRIX
void create_adjmat(int n)
{
	fp = fopen ("/home/pict/file2.txt", "r");
	while (!feof(fp)) {
	    int src,dest,cost;
	    char c=0;
	    fscanf(fp, "%d,%d,%d%c", &src, &dest, &cost,&c);
	    adj[src][dest]=cost;
	    adj[dest][src]=cost;
	    }

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<" "<<adj[i][j];
		}
	cout<<"\n";
	}
}
//adjacency matrix bfs
void BFS()
{

	cout <<"Enter initial vertex : ";
	cin >>v;
	cout <<"Visited vertices (BFS TRAVERSAL): \n";
	cout << v<<" ";
	visited[v]=1;
	k=1;
	while(k<n)
	{
	for(j=1;j<=n;j++)
	{
		if(adj[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
		{
			visit[j]=1;
			qu[rear++]=j;
		}
	}
	v=qu[front++];
	cout<<v<< " ";
	k++;
	visit[v]=0; visited[v]=1;

	}
}
//adjacency matrix dfs
void DFS()
{
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
	}

	cout <<"\nEnter initial vertex : ";
	cin >>v;
	cout <<"Visited vertices (DFS TRAVERSAL): \n";
	cout << v <<" ";
	visited[v]=1;
	k=1;
	while(k<n)
	{
	for(j=n;j>0;j--)
	if(adj[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
	{
	visit[j]=1;
	stk[top]=j;
	top++;
	}
	v=stk[--top];
	cout<<v<< " ";
	k++;
	visit[v]=0; visited[v]=1;
	}

}

int main() {
int ch=0,num_links=0,threshold=0;

cout<<"Enter number of nodes : ";
cin>>n;

for(i=0;i<n;i++)		//initialize matrix
{
	for(j=0;j<n;j++)
	{
		adj[i][j]=0;
	}
}

fp = fopen ("/home/pict/file2.txt", "r");	//open input file

while(!feof(fp))
{
    ch = fgetc(fp);
    if (ch == '\n')
    	num_links++;
}

//CALCULATING THRESHOLD
int m=n-1;
threshold=num_links*200/(m*n);
cout<<"threshold : "<<threshold<<endl;
rewind(fp);

if(threshold>=50)
{
create_adjmat(n);
BFS();
DFS();
}
else
{
	list(n, num_links);
	BFS(n, true);
	DFS(n, true);
}
}

