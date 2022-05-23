#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int n)
    {
        data=n;
    }
};

class BST
{
    public:
    Node* root;
       
    Node* create_root(int n)
    {
        root= new Node(n);
        root->data=n;
        root->left=NULL;
        root->right=NULL;

        return root;
    }
    void insert(Node* root,int key)
    {
        if(root->data>key)
        {
            if(root->left==NULL)
            {
                root->left=new Node(key);
            }
            else
            {
                insert(root->left,key);
            }
        }
        else if(root->data<key)
        {
            if(root->right==NULL)
            {
                root->right=new Node(key);
            }
            else
            {
                insert(root->right,key);
            }
        }
        else
        {
            cout<<"No Duplicate Entries allowed !!!"<<endl;
        }
    }
    
    void search(Node* root, int key)
    {
        if(key==root->data)
        {
            cout<<"\nNumber is present";
        }
        else if(key<root->data)
        {
            if(root->left!=NULL)
            {
                search(root->left,key);
            }
            else
            {
                cout<<"\nNot Found";
            }
        }
        else if(key>root->data)
        {
            if(root->right!=NULL)
            {
                search(root->right,key);
            }
            else
            {
                cout<<"\nNot Found";
            }
        }
        else
        {
            cout<<"\nNot Found";
        }
    }
    
    void inorder(Node* root)
    {
        if(root!=NULL)
        {
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }
    
    void preorder(Node *root)
    {
        
        if (root != NULL)
        {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
            
        }
        
    }
    
    void postorder(Node *root)
    {
        if (root != NULL)
        {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
            
        }
    }
    
};

int main()
{
    BST obj;
    int len,flag=0,num,k,x;
    Node* root;
    cout<<"\nEnter number of nodes you want to enter: ";
    cin>>len;
    for(int i=0;i<len;i++)
    {
        cout<<"\nEnter number to insert: ";
        cin>>num;
        if(flag==0)
        {
            root=obj.create_root(num);
            flag=1;
        }
        else
        {
            obj.insert(root,num);
        }
    }

    cout<<"/nInorder: ";
    obj.inorder(root);
    cout<<"/nPreorder";
    obj.preorder(root);
    cout<<"/nPostorder";
    obj.postorder(root);
    
    cout<<"\nElement to be searched";
    cin>>k;
    obj.search(root,k);
    
    cout<<"\nElement to be deleted";
    cin>>x;
    obj.delete_node(root,x);
    obj.inorder(root);
    return 0;
}
