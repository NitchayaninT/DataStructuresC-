#include "treenode.h"
class BST{
private:
treenode* root;

public:
BST();
void Insert(int);
void kill(treenode*);
void InOrder(treenode*);//pass temp ptr
void PreOrder(treenode*);
void PostOrder(treenode*);
~BST();
};
BST::BST()
{
    root==NULL;
}
void BST::Insert(int x)
{
    treenode* new_node=new treenode(x);
    treenode* temp=root;
    bool found=false;

    while(found==false)
    {
        if(x<temp->get_value())
        {
            if(temp->get_left()==NULL) 
            {
                temp->set_left(new_node);
                found=true;
            }
            else
            {   
                temp=temp->get_left();
            }
        }
        else
        {
            if(temp->get_right()==NULL) 
            {
                temp->set_right(new_node);
                found=true;
            }
            else
            {
                temp=temp->get_right();
            }
        }
    }
}
void BST::InOrder(treenode* t)//L n R
{
    InOrder(t->get_left());
    cout<<t->get_value();
    InOrder(t->get_right());
}
void BST::PreOrder(treenode* t)//n L R
{
    cout<<t->get_value();
    PreOrder(t->get_left());
    PreOrder(t->get_right());
}
void BST::PostOrder(treenode* t)//L R n
{
    PostOrder(t->get_left());
    PostOrder(t->get_right());
    cout<<t->get_value();
}
void BST::kill(treenode* t)
{
    if(t!=NULL)
    {
        kill(t->get_left());
        kill(t->get_right());
        delete t;
    }
    
}
BST::~BST()//destructor
{
    cout<<"Kill Bst"<<endl;
    kill(root);
}