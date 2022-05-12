#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class adjmatlist
{    int m[10][10],n,i,j; char ch;  string v[20];
     public:
     void getgraph();
     void displaym();
};

void adjmatlist::getgraph()
{
   cout<<"\n enter no. of cities(max. 20): ";
   cin>>n;
   cout<<"\n enter name of cities: ";
   for(i=0;i<n;i++)
     cin>>v[i];         
   for(i=0;i<n;i++)
   { 
      for(j=0;j<n;j++)
      {  cout<<"\n if path is present between city "<<v[i]<<" and "<<v[j]<<" then press enter y otherwise n: "; 
         cin>>ch;
         if(ch=='y')
         { 
           cout<<"\n enter time required to reach city "<<v[j]<<" from "<<v[i]<<" in minutes:" ;
           cin>>m[i][j];
         }
         else if(ch=='n')
         {  m[i][j]=0;  }
         else
         { cout<<"\n unknown entry";  }
      }
   }       
}

void adjmatlist::displaym()
{    cout<<"\n";
     for(j=0;j<n;j++)
     {  cout<<"\t"<<v[j];  }

     for(i=0;i<n;i++)
     {  cout<<"\n "<<v[i];
        for(j=0;j<n;j++)
        {   cout<<"\t"<<m[i][j];
        }
            cout<<"\n";
     }
}   

int main()
{  int m;   
   adjmatlist a;

   while(1)
   {
   cout<<"\n\n Enter the choice";
   cout<<"\n 1.Enter graph";
   cout<<"\n 2.Display adjacency matrix for cities";
   cout<<"\n 3.Exit"<<endl;
   cin>>m;
  
        switch(m)
      { 
         case 1: a.getgraph();
                  break;
         case 2: a.displaym();
                  break;
         case 3: exit(0);
         default:  cout<<"\n unknown choice";
      }
    }
    return 0;
} 
