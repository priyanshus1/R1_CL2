//============================================================================
// Name        : a.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
using namespace std;

int main() {
	int n=0;
cout<<"Enter number of nodes : ";
cin>>n;

int adj[n][n];

   int ch = 0;
   int lines = 0;
for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
	{
		adj[i][j]=0;

	}

}

FILE *fp;
fp = fopen ("/home/pict/file.txt", "r");

while(!feof(fp))
{
    ch = fgetc(fp);
    if (ch == '\n')
    lines++;
}

rewind(fp);
while (!feof(fp)) {
    int src;
    int dest;
    int cost;
    char c=0;
    fscanf(fp, "%d,%d,%d%c", &src, &dest, &cost,&c);
    adj[src-1][dest-1]=cost;
    adj[dest-1][src-1]=cost;
    }

for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
	{
		cout<<" "<<adj[i][j];
	}
cout<<"\n";
}

}
