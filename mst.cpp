#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class tree
{    int m[10][10],n,i,j,visited[20]; char ch;  string v[20];
     public:
     void getgraph();
     void displaym();
     void mst();
};

void tree::getgraph()
{
   cout<<"\n enter no. of cities(max. 20): ";
   cin>>n;
   cout<<"\n enter name of cities: ";
   for(i=0;i<n;i++)
   {
      visited[i]=0;
     cin>>v[i];
   }         
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
         {  m[i][j]=999;  }
         else
         { cout<<"\n unknown entry";  }
      }
   }       
}

void tree::displaym()
{    cout<<"\n";
     for(j=0;j<n;j++)
     {  cout<<"\t"<<v[j];  }

     for(i=0;i<n;i++)
     {  cout<<"\n "<<v[i];
        for(j=0;j<n;j++)
        {  
             cout<<"\t"<<m[i][j];
        }
            cout<<"\n";
     }
}   

void tree::mst()
{
	int p=0,q=0,total=0,min;
	visited[0]=1;
	for(int count=0;count<(n-1);count++)
	{
		min=999;
		for(i=0;i<n;i++)
		{
			if(visited[i]==1)
			{
				for(j=0;j<n;j++)
				{
					if(visited[j]!=1)
					{
						if(min > m[i][j])
						{
							min=m[i][j];
							p=i;
							q=j;
						}
					}
				}
			}
		}
		visited[p]=1;
		visited[q]=1;
		total=total + min;
		cout<<"Minimum cost connection is "<<v[p]<<" -> "<<v[q]<<"  with charge : "<<min<< endl;
	}
	cout<<"The minimum total cost of connections of all branches is: "<<total<<endl;
}

int main()
{  int t;   
   tree a;

   while(1)
   {
   cout<<"\n\n Enter the choice";
   cout<<"\n 1.Enter graph";
   cout<<"\n 2.Display adjacency matrix for cities";
   cout<<"\n 3.Display mst";
   cout<<"\n 4.Exit"<<endl;
   cin>>t;
  
        switch(t)
      { 
         case 1: a.getgraph();
                  break;
         case 2: a.displaym();
                  break;
         case 3:a.mst();
                  break;
         case 4: exit(0);
         default:  cout<<"\n unknown choice";
      }
    }
    return 0;
} 
