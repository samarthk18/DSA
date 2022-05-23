#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node*right;
    Node*left;

    bool Is_thread;
};
Node*Create_Thread(Node*root)
{
    // root is null then return from here
    if(root==NULL)
    {
        return NULL;
    }
    // condtion for leaf node if root is a leaf node then return itself
    if(root->left==NULL&&root->right==NULL)
    {
        return root;
    }
    /*now we will find a predessor of the root if root is not null then condtion gets 
    and enter in the if statemnet*/
    if(root->left!=NULL)
    {
        // recusirvise we will got in the left tree till we not get the predessor of the root 
        Node*ptr=Create_Thread(root->left);
        // if predessor get then we will create a thread between predessor and root
        ptr->right=root;
        ptr->Is_thread=true;
    }
    // now it is need to check that do we have right sub tree

    if(root->right==NULL)
    {
        return root;
    }
    // if sub treee exsit call the function _recursive for right sub tree
    else{

    return Create_Thread(root->right);
    } 

}
// finding the left most child for inorder display
Node*Left_most(Node*root)
{
    while(root!=NULL && root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
void In_order(Node*root)
{
    if(root==NULL)
    {
        return ;
    }
    // here current will be having the left sub chld of the left sub tree
    Node*current=Left_most(root);
    while (current != NULL)
    {
        cout << current->data << " ";
 
        // If this Node is a thread Node, then go to
        // inorder successor
        if (current->Is_thread)
        {

          current = current->right;
        }
 
        else // Else go to the leftmost child in right subtree
    {

            current = Left_most(current->right);
    }
    }
}

Node*Create_node(int data)
{
    Node*n= new Node;
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

int main(){
    
    /*       5
            / \
           2   8
          / \ / \
         1  3 6  9   */
    Node *root = Create_node(5);

    root->left = Create_node(2);

    root->right = Create_node(8);

    root->left->left = Create_node(1);

    root->left->right = Create_node(3);

    root->right->left = Create_node(6);

    root->right->right = Create_node(9);
 

    Create_Thread(root);
 

    cout << "Inorder traversal of created "

            "threaded tree is\n";

    In_order(root);
  

    
    return 0;
}
