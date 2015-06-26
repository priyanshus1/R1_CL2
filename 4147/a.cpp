//============================================================================
// Name        : a.cpp
// Author      : AISHWARYA
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
using namespace std;
int adj[10][10],i,j,k,n,qu[10],front,rear,v,visit[10],visited[10],stk[10],top;
FILE *fp;

class traverse
{

public :

	void create_adjmat(int n);
	void bfs_adjm();
	void dfs_adjm();

};
void traverse::create_adjmat(int n)
{
	fp = fopen ("/home/pict/file.txt", "r");
	while (!feof(fp)) {
	    int src;
	    int dest;
	    int cost;
	    char c=0;
	    fscanf(fp, "%d,%d,%d%c", &src, &dest, &cost,&c);
	    adj[src-1][dest-1]=cost;
	    adj[dest-1][src-1]=cost;
	    }

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<" "<<adj[i][j];
		}
	cout<<"\n";
	}
}
void traverse::bfs_adjm()
{

	cout <<"Enter initial vertex : ";
	cin >>v;
	cout <<"Visited vertices (BFS TRAVERSAL): \n";
	cout << v<<" ";
	visited[v]=1;
	k=1;
	while(k<n)
	{
	for(j=0;j<n;j++)
	{
		if(adj[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
		{
			visit[j]=1;
			qu[rear++]=j;
		}
	}
	v=qu[front++];
	cout<<v << " ";
	k++;
	visit[v]=0; visited[v]=1;

	}
}
void traverse::dfs_adjm()
{
	for(i=0;i<=n;i++)
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
	for(j=n-1;j>=0;j--)
	if(adj[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
	{
	visit[j]=1;
	stk[top]=j;
	top++;
	}
	v=stk[--top];
	cout<<v << " ";
	k++;
	visit[v]=0; visited[v]=1;
	}

}

int main() {
int ch=0;
int lines=0;
int threshold=0;

traverse t;
cout<<"Enter number of nodes : ";
cin>>n;

for(i=0;i<n;i++)		//initialize matrix
{
	for(j=0;j<n;j++)
	{
		adj[i][j]=0;
	}

}

fp = fopen ("/home/pict/file.txt", "r");	//open input file

while(!feof(fp))
{
    ch = fgetc(fp);
    if (ch == '\n')
    lines++;
}
int m=n-1;
threshold=lines*200/(m*n);		//calculate threshold
cout<<"threshold : "<<threshold<<endl;
rewind(fp);

if(threshold>=50)
{
	cout<<"threshold : ";
t.create_adjmat(n);
t.bfs_adjm();
t.dfs_adjm();
}
}
