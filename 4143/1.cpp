#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream f;
	char data[50];
	f.open("/home/pict/4143/1.txt",ios::in);
	while (!f.eof())
	{
	f.getline(data,17);
	for(int i=0;i<17;i++)
		{	
				if (i==0)
					cout<<"Source Node is :"<<data[i]<<endl;
				else if (i==8)
					cout<<"Destination Node is :"<<data[i]<<endl;
				else if (i==16)
					cout<<"Distance between them is :"<<data[i]<<endl;
		}
	return 0;
}
}
