#include <iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;
};

class BT{
    public:
    node *root;
    void create();
    void insert(node *, node *);

    void inorder(node *);
    void preorder(node *);
    void postorder(node *);

    BT(){
        root=NULL;
    }
};

void BT::create(){
    char ch;
    do
    {
        node *temp=new node;
        cout<<"Enter Data:";
        cin>> temp->data;
        temp->left=NULL;
        temp->right=NULL;
        if(root==NULL){
            root=temp;
        }
        else{
            insert(root, temp);
        }
        cout<<"Do you want to insert new node: "<<" ";
        cin>>ch;
    } while (ch=='y');
}

void BT::insert(node *root, node *temp){
    char ch;
    if(temp->data < root->data){
        if(root->left==NULL){
            root->left=temp;
        }
        else{
            insert(root->left, temp);
        }
    }
    if(temp->data >= root->data){
        if(root->right==NULL){
            root->right=temp;
        }
        else{
            insert(root->right, temp);
        }
    }
}


void BT::inorder(node *root){ 
        if(root!=NULL){
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }

void BT::preorder(node *root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void BT::postorder(node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}


int main(){
    BT b;
    b.create();

    b.inorder(b.root)<<endl;
    b.preorder(b.root)<<endl;
    b.postorder(b.root);

    return 0;
}