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
cout<<"Asymmetric friendhips :\n ";
for(int i=0;i<rows;i++)
{
    for(int j=1;j<columns;j++)
    {
        string friendname=students[i][j];
        if(friendname!="0")
        {
            bool issymmetric=false;
            
        
        for(int k=0;k<rows;k++)
        {
            if(students[k][0]==friendname)
            {
                for(int l=0;l<columns;l++)
                {
                    if(students[k][l]==students[i][0])
                    {
                        issymmetric=true;
                        break;
                    }
                }
            }
            if(issymmetric)
            break;
        }
        if(!issymmetric)
    {
        cout<<"("<<students[i][0]<<","<<friendname<<")"<<endl;
    }

    }
 }
}
return 0;
}