class treenode{
private:
treenode* left;
treenode* right;
int value;

public:
treenode(int=0);
void set_left(treenode* );
void set_right(treenode* );
treenode* get_left(){return left;};
treenode* get_right(){return right;};
int get_value(){return value;};
void print();
~treenode();
};
treenode::treenode(int x)
{
    left=NULL;
    right=NULL;
    this->value=x;
}
void treenode::set_left(treenode* t)
{
    this->left=t;
}
void treenode::set_right(treenode* t)
{
    this->right=t;
}
void treenode::print()
{
    cout<<value<<setw(3)<<endl;
}
treenode::~treenode()
{
    cout<<"deleting "<<value<<endl;
}