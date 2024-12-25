#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
int main()
{    
int rows=41;
int columns=6;
string students[rows][columns];
int adj[41][41]={0};
for(int i=0;i<rows;i++)
{
    for(int j=0;j<columns;j++)
    {
        students[i][j]="0";
    }  
}
ifstream inputfile("C:/Users/Dell/Downloads/Friends Dataset.csv");
string line,person;
int index=0;
while(getline(inputfile,line)&&index<rows)
{
    stringstream ss(line);
    for(int i=0;i<columns;i++)
    {
        if(getline(ss,person,','))
        {
            students[index][i]=person;
        }      
    }
    index++;
}
inputfile.close();
 for (int i=0;i<rows;i++)
    {
        for(int j=i+1;j<rows;j++)
        {
            int common=0;
            for(int k=1;k<columns;k++)
            {
                for(int l=1;l<columns;l++)
                {
                    if(students[i][k]==students[j][l]&&students[i][k]!="0")
                    {
                        common++;
                    }
                }
            }
            adj[i][j]=common;
            adj[j][i]=common;
        }
    }
    int alpha=3;
    cout<<"Potential Friendships (common friends >= "<<alpha<<"):\n"<<endl;
    for (int i=0;i<rows;i++)
    {
        for(int j=i+1;j<rows;j++)
        {
            if(adj[i][j]>=alpha)
            {
                cout<<students[i][0]<<" and "<< students[j][0] <<" could be potential friends with "<<adj[i][j]<<" common friends."<<endl;
            }
        }
    }
    return 0;
}
