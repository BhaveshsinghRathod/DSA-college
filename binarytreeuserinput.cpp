#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left,*right;
};


class BT
{
    public:
    node *root;
    void create();
    void insert(node *, node *);
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    

    BT()
    {
        root=NULL;
    }
};


void BT::create()
{
    char ch;
    do
    {
         
        node *temp=new node;
        cout<<"Enter data";
        cin>> temp->data;
        temp->left=NULL;
        temp->right=NULL;
        if(root==NULL){
            root=temp;
        }
        else{
            insert(root, temp);
        }
        cout<<"do you want to add node?"<<endl;
        cin>>ch;
    }while(ch=='y');
}


void BT::insert(node *root, node* temp){
    char ch;
    cout<<"current root node"<<endl;
    cout<<root->data;
    cout<<"enter direction left/right"<<endl;
    cin>>ch;

    if(ch=='l'){
        if(root->left==NULL){
            root->left=temp;
        }
        else {
            insert(root->left, temp);
        }
    }

    if(ch=='r'){
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
    b.inorder(b.root);
    b.preorder(b.root);
    b.postorder(b.root);


    
    return 0;
}
