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
ifstream inputfile("C:\\Users\\hp\\Downloads\\Friends Dataset.csv");
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
string onehop[rows],twohop[rows],threehop[rows];
int onehopcount=0,twohopcount=0,threehopcount=0;
string studentname;
cout<<"enter the name of student"<<endl;
cin>>studentname;

for(int i=0;i<rows;i++)
{
    if(students[i][0]==studentname)
    {
        for(int j=1;j<columns;j++)
        {
            if(students[i][j]!="0")
            {
                onehop[onehopcount++]=students[i][j];
            }
        }
        break;
    }
}
for(int i=0;i<onehopcount;i++)
{
    for(int j=0;j<rows;j++)
    {
        if(students[j][0]==onehop[i])
        {
            for(int k=1;k<columns;k++)
            {
                if(students[j][k]!="0"&&students[j][k]!=studentname)
                {
                    bool already2hop=false;
                    for(int l=0;l<onehopcount;l++)
                    {
                        if(onehop[l]==students[j][k])
                        {
                            already2hop=true;
                            break;
                        }
                    }
                    if(!already2hop)
                    {
                        twohop[twohopcount++]=students[j][k];
                        
                    }
                    
                }
            }
            break;
        }
    }
}
for(int i=0;i<twohopcount;i++)
{
    for(int j=0;j<rows;j++)
    {
        if(students[j][0]==twohop[i])
        {
            for(int k=1;k<columns;k++)
            {
                if(students[j][k]!="0"&&students[j][k]!=studentname)
                {
                    bool already3hop=false;
                
                    for(int l=0;l<onehopcount;l++)
                    {
                        if(onehop[l]==students[j][k])
                        {
                            already3hop=true;
                            break;
                        }
                        
//test
                    }   
                    for(int l=0;l<twohopcount;l++)
                    {
                    if(twohop[l]==students[j][k])
                    {
                        already3hop=true;
                        break;
                    }
                 
                    }
                    
                if(!already3hop)
                {
                    threehop[threehopcount++]=students[j][k];    
                }

            }             
                
            }
            break;
        }
    }
}

cout<<"one hop friends are "<<endl;
for(int i=0;i<onehopcount;i++)
{
    cout<<onehop[i]<<"     ";
}
cout<<endl<<endl;
cout<<"two hop friends are "<<endl;
for(int i=0;i<twohopcount;i++)
{
    cout<<twohop[i]<<"     ";
}
cout<<endl<<endl;
if(threehopcount==0)
{
    cout<<"none"<<endl;
}
else
cout<<"three hop friends are "<<endl;
for(int i=0;i<threehopcount;i++)
{
    cout<<threehop[i]<<"    ";
}


}