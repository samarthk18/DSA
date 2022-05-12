#include <iostream>
#include<string.h>

using namespace std;
struct Node
{
    int data;
    Node*next;
};
Node*HashTable[10];

class Hashing
{
    public:
    Hashing()
    {
        for(int i=0;i<10;i++)
        {
            HashTable[i]=NULL;
        }
    }
    int HashFunction(int data)
    {
        return (data%10);
    }
    Node*Create_Node(int X)
    {
        Node*temp=new Node;
        temp->next=NULL;
        temp->data=X;
        return temp;
    }
    void Display()
    {
        for(int i=0;i<10;i++)
        {
            Node*temp=new Node;
            temp=HashTable[i];
            cout<<"["<<i<<"]";
            while(temp!=NULL)
            {
                cout<<"->"<<temp->data;
                temp=temp->next;
            }
            cout<<endl;

        }
    }
    void Insert_Node(int data)
    {
        int Hash_value=HashFunction(data);
        Node*temp=new Node;
        Node*Head=new Node;
        Head=Create_Node(data);
        temp=HashTable[Hash_value];

        if(temp==NULL)
        {
            HashTable[Hash_value]=Head;

        }
        else{
            while (temp->next!=NULL)
            {
                temp->next=temp;
            }
            temp->next=Head;
         
            
        }
    }
};

int main(){
    Hashing h;
    int a;
    cout<<"enter number to be inseted"<<endl;
    for(int i=0;i<5;i++)
    {
    cin>>a;
    h.Insert_Node(a);

    }
    h.Display();

    
    return 0;
}
