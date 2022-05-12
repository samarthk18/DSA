#include<iostream>
#include<string.h>

using namespace std;

struct node              //Declaration of Node Structure 
{
    char title[20];      // Character array used to store name
    int child_count;     // count variable to count the number of childs
    node *child[50];     // Pointer array to store addrresses of the child nodes
} * root;                // creating a object pointer to the node structure

class Book           //Declaration of the class Book
{
public:
    void insert_node();   // function for the inserting of nodes into the tree
    void display_tree();  // function to display nodes of the tree
    Book()
    {
        root == NULL;
    }
};
void Book::insert_node()
{
    root = new node(); // root node of the tree is been created

    cout << "Enter name of the book:" << endl;
    cin >> root->title;
    cout << "Enter the number of chapters in book:" << endl;
    cin >> root->child_count;
    for (int i = 0; i < root->child_count; i++)
    {
        root->child[i] = new node(); // chapters of the book are created
        cout << "Enter the name of chapters:" << endl;
        cin >> root->child[i]->title;
        cout << "Enter the number of sections:" << endl;
        cin >> root->child[i]->child_count;
        for (int j = 0; j < root->child[i]->child_count; j++)
        {
            root->child[i]->child[j] = new node(); // sections of the book are created
            cout << "Enter the name of section:" << endl;
            cin >> root->child[i]->child[j]->title;
            cout << "Enter the number of sub sections:" << endl;
            cin >> root->child[i]->child[j]->child_count;
            for (int k = 0; k < root->child[i]->child[j]->child_count; k++)
            {
                root->child[i]->child[j]->child[k] = new node(); // subsections of the book are created
                cout << "Enter the name of sub section:" << endl;
                cin >> root->child[i]->child[j]->child[k]->title;
            }
        }
    }
}
void Book::display_tree()
{
    if (root != NULL)
    {
        cout << "______TREE______" << endl;
        cout << "Name of the book is :- " << root->title << endl;
        for (int i = 0; i < root->child_count; i++)                                 // Giving the names of chapters
        {
            cout << "Chapter "<<i+1<<" name is :- "<<root->child[i]->title << endl;
            for (int j = 0; j < root->child[i]->child_count; j++)                   // Giving the names of sections
            {
                cout << "Section "<<j+1<<" name is :- "<< root->child[i]->child[j]->title << endl;
                for (int k = 0; k < root->child[i]->child[j]->child_count; k++)     // Giving the names of subsections
                {
                    cout << "Sub-section "<<k+1<<" name is :- "<< root->child[i]->child[j]->child[k]->title << endl;
                }
            }
        }
    }
}
int main()
{
    Book book1;
    int choice;
    do
    {
        cout << "__Select The Operation That you Want To Perform__" << endl;
        cout << "1. Insert a Node." << endl;
        cout << "2. Display The TREE Data." << endl;
        cout << "3. Exit "<<endl;
        cout << "Enter Your choice :- " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            book1.insert_node();
            break;
        case 2:
            if(root==NULL){
                cout<<endl<<"Error :- Insert data in tree"<<endl<<endl;
            }
            else{
            book1.display_tree();
            }
            break;
        }
    } while (choice < 3);

    cout<<"________Successfully Ended The Program________"<<endl;

    return 0;
}
