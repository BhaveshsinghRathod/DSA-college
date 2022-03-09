#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left,*right;
};
class BT
{
    node *root;
    public:
    void create();
    void insert(node *, node *);



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


int main() {
  BT b;
  b.create();
  

}