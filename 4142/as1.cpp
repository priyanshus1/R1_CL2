//============================================================================
// Name        : ass1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdio.h>
using namespace std;
#define m 10
int c;
int rows=0;
int no_of_nodes=0;
FILE *fp;
int main()
{int max[10][10];

	cout<<"enter the no of nodes : "<<endl;
	cin>>no_of_nodes;

	for (int i=0;i<no_of_nodes;i++)
	{
		for(int j=0;j<no_of_nodes;j++)
		{
			max[i][j]=0;
		}
	}
	fp= fopen("/home/pict/4142/ass1/src/abc.txt", "r");
	while ((c = getc(fp)) != EOF)
	    {
	        if (c == '\n')
	        	rows++;
	       // cout << c<<endl;
	    }
    cout<<"no of links : "<<rows<<endl;
    rewind(fp);
    while (!feof(fp)) {
        int src;
        int dest;
        int cost;
        char c=0;
        fscanf(fp, "%d,%d,%d%c", &src, &dest, &cost,&c);
        max[src-1][dest-1]=cost;
        max[dest-1][src-1]=cost;
        }

    for(int i=0;i<no_of_nodes;i++)
    {
    	for(int j=0;j<no_of_nodes;j++)
    	{
    		cout<<" "<<max[i][j];
    	}
    cout<<"\n";
    }



    return 0;

}

