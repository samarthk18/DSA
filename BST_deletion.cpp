#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node*left;
    Node*right;
    
    Node(int n)
    {
        data=n;
    }
};
class BST
{
    public:
    Node*root;
    
    Node*create_root(int n)
    {
        root=new Node(n);
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
            cout<<"\nNo duplicate entries allowed!!!";
        }
    }
    
    Node* delete_ele(Node*root,int key)
    {
        if (root == NULL)
        return root;

        if (key < root->data)
        root->left = delete_ele(root->left, key);
 
   
        else if (key > root->data)
        root->right = delete_ele(root->right, key);
 
    
        else {
        //node with no child
        if (root->left==NULL and root->right==NULL)
            return NULL;
       
        // node with only one child 
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
    }
    return root;
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
  
};

int main()
{
    BST obj;
    int len,flag=0,num,del_ele;
    Node* root;
    cout<<"\nEnter number of nodes to be created: ";
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
    
    cout<<"\nInorder before deletion ";
    obj.inorder(root);
    
    cout<<"\nEnter number to be deleted: ";
    cin>>del_ele;
    obj.delete_ele(root,del_ele);
    
    cout<<"\nInorder after deletion ";
    obj.inorder(root);
    
    return 0;
}
