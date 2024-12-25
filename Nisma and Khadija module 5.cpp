#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
	const int ROWS=41;
	const int COLUMN=6;
	string data[ROWS][COLUMN]={};
	int adj[ROWS][ROWS]={};
	int rowcount=0;
	ifstream inputfile("C:\\Users\\hp\\Downloads\\Friends Dataset.csv");
	string line;
	while(getline(inputfile,line) && rowcount<ROWS)
	{
		stringstream ss(line);
		string word;
		int colcount=0;
		 while (getline(ss, word, ',') && colcount < COLUMN)
		{
            data[rowcount][colcount++] = word;
        }
		rowcount++;
	}
	inputfile.close();
	for(int i=0;i<ROWS;i++)
	{
		for(int j=i+1;j<ROWS;j++)
		{
			int common=0;
			for(int k=1;k<COLUMN;k++)
			{
				for(int l=1;l<COLUMN;l++)
				{
					if(data[i][k]==data[j][l] && !data[i][k].empty())
					{
						common++;
					}
				}
			}
			adj[i][j]=common;
			adj[j][i]=common;
		}
	}
	cout<<"common friends will be "<<endl;
	for(int i=0;i<rowcount;i++)
	{
		for(int j=0;j<rowcount;j++)
		{
				cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<rowcount;i++)
	{
		for(int j=i+1;j<rowcount;j++)
		{
				cout<<data[i][0]<<" and "<<data[j][0]<<":"<<adj[i][j]<<endl;
		}
	}
	return 0;
}

