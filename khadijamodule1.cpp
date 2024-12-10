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

for(int i=0;i<rows;i++)
{
cout<<students[i][0]<<" "<<students[i][1]<<"\t"<<students[i][2]<<"\t "<<students[i][3]<<" \t"<<students[i][4]<<"\t "<<students[i][5]<<endl;
}
int column2=2;
string array2[rows][column2];
for(int i=0;i<rows;i++)
{
    array2[i][1]="0";
}
 for(int i=0;i<rows;i++)
 {
    array2[i][0]=students[i][0];
 }

 for(int i=0;i<rows;i++)
 {
    for(int j=1;j<columns;j++)
    {
        string friendname=students[i][j];
        if(friendname!="0")
        {
            for(int k=0;k<rows;k++)
        {
            if(array2[k][0]==friendname)
            {
            int currentcount=stoi(array2[k][1]);
            currentcount++;
            array2[k][1]=to_string(currentcount);
            break;
            }
        }
        }
        
    }
 }
 for(int i=0;i<rows;i++)
 {
    cout<<array2[i][0]<<": "<<" friend count = "<<array2[i][1]<<endl;
 }
 string maxperson=" ";
 int maxcount=-1;
 for(int i=0;i<rows;i++)
 {
    int currentcount=stoi(array2[i][1]);
    if(currentcount>maxcount)
    {
        maxcount=currentcount;
        maxperson=array2[i][0];

    }
 }
 cout<<"The most popular person of class is "<<maxperson<<" who is the friend of "<<maxcount<<" people"<<endl;
 
 }
 




