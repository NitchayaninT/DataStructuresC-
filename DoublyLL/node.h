#ifndef node_h
#define node_h
class Node{
private:
int value;
Node* next;
Node* prev;

public:
Node(int);
void set_next(Node* t);
Node* get_next(){return next;};
Node* get_prev(){return prev;};
int get_value(){return value;};
void display();
~Node();
};
Node::Node(int x)
{
    this->value=x;
    this->next=NULL;
    this->prev=NULL;
}
void Node::display()
{
    cout<<value<<endl;
}
void Node::set_next(Node* t)
{
    this->next=t;
    if(t) t->prev=this;
}
Node::~Node()
{
    cout<<value<<" Deleted"<<endl;
}
#endif