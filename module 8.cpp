#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    const int ROWS=41;
    const int COLUMN=6;
    int alpha; 
    string data[ROWS][COLUMN]={};
    int adj[ROWS][ROWS]={};
    int connectivity[ROWS]={};
    int rowcount=0;
    int max=0;
    cout<<"enter threshold "<<endl;
    cin>>alpha;
    for (int i=0;i<ROWS;i++)
    {
        if(connectivity[i]>max)
        {
            max=connectivity[i];
        }
    }
    cout<<"Broadcast Points "<<endl;
    for(int i=0;i<ROWS;i++)
    {
        if(connectivity[i]==max)
        {
            cout<<data[i][0]<<"with"<<connectivity[i]<<" connectivity"<<endl;
        }
    }
    return 0;
}
