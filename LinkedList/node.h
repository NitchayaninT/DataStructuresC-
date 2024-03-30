#ifndef node_h
#define node_h
#include "student.h"
class Node{
private:
ID StudentID;
Node* Next;

public:
Node(ID);
void set_next(Node* t){this->Next=t;};
Node* get_next(){return Next;};
int get_value(){return StudentID.get_id();};
void display();
~Node();
};
Node::Node(ID student1)
{
    this->StudentID=student1;
    this->Next=NULL;
}
void Node::display()
{
    cout<<StudentID.get_id()<<setw(8)<<StudentID.get_name()<<setw(5)<<StudentID.get_score()<<endl;
}
Node::~Node()
{
    cout<<StudentID.get_id()<<" Deleted"<<endl;
}
#endif