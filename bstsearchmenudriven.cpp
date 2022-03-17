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

    void search(node *, int);


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

void BT::search(node *root, int val){
    
    if (val==root->data){
    cout<<root->data<<endl;
    }
    else if (val<root->data){
        search(root->left, val);
    }
    else{ 
        search(root->right, val);
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
    int val;
    int a;
    char yn;
    
    do{
        cout<<"What do you want to do "<<endl;
        cout<<"1. Inorder Traversal "<<endl;
        cout<<"2. Preorder Traversal "<<endl;
        cout<<"3. Postorder Traversal "<<endl;
        cout<<"4. Search"<<endl;
        cin>>a;
        if (a==1){
            b.inorder(b.root);
        }
        else if (a==2){
            b.preorder(b.root);
        }
        else if (a==3){
            b.postorder(b.root);
        }
        else{
            int val;
            cout<<"Enter the value to be searched: "<<endl;
            cin>>val;
            b.search(b.root, val);
        }
        
        cout<<"Do you want the menu again?"<<endl;
        cin>>yn;
    }while(yn=='y');
    return 0;
}
