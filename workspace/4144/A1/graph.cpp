/*
 * graph.cpp
 *
 *  Created on: Jun 16, 2015
 *      Author: pict
 */

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
const int THRESHOLD=5;
fstream file;
file.open("xyz.txt");
int nodes,edges;
file >>nodes>>edges;
int mat[nodes][nodes];
int s1,d1,v1;
for(int i=0;i<nodes;i++)
for (int j=0;j<nodes;j++)
{

	mat[i][j]=0;

}
for (int k=0;k<edges;k++)
{
	file >>s1>>d1>>v1;
	mat[s1][d1]=v1;

}
for(int i=0;i<nodes;i++)
for (int j=0;j<nodes;j++)
{

	cout << mat[i][j]<<endl;

}


return 0;
}

