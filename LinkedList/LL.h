#ifndef LL_h
#define LL_h
#include "node.h"
typedef Node* Nodeptr;

class LL{
private:
Nodeptr head;
Nodeptr tail;
int size;
public:
LL();
void InsertNode(ID,int);
void DeleteNode(int);
void Display();
~LL();
};
LL::LL()
{
    head=NULL;
    tail=NULL;
    size=0;
}
void LL::InsertNode(ID student,int position)//insert after which node?
{
    Nodeptr NewNode=new Node(student);
    if(head==NULL)//if theres no node
    {
        if(position==1)
        {
            head=NewNode;
            tail=NewNode;
            size++;
        }
        else
        {
            cout<<"Cannot insert at other positions at this point!"<<endl;
        }
    }
    else if(position>size+1)
    {
        cout<<"Cannot insert at other positions at this point!"<<endl;
    }
    else if(position==size+1)//insert at the end
    {
        tail->set_next(NewNode);
        NewNode->set_next(NULL);
        tail=NewNode;
        size++;
    }
    else//insert in between
    {
        Nodeptr temp=head;
        int count=1;
        while(temp->get_next()!=NULL&&count!=position-1)
        {
            temp=temp->get_next();
            count++;
        }
        NewNode->set_next(temp->get_next());
        temp->set_next(NewNode);
        size++;
    }
}
void LL::DeleteNode(int x)
{
    Nodeptr temp;
    Nodeptr PreviousNode=NULL;
    if(x==head->get_value())
    {
        temp=head;
        head=head->get_next();
        delete temp;
        size--;
    }
    else if(x==tail->get_value())
    {
        temp=head;
        while(temp->get_next()!=NULL)
        {
            PreviousNode=temp;
            temp=temp->get_next();
        }
        tail=PreviousNode;
        delete temp;
        size--;
    }
    else//delete in between
    {
        temp=head;
        while(temp->get_next()!=NULL&&temp->get_value()!=x)
        {
            PreviousNode=temp;
            temp=temp->get_next();
        }
        PreviousNode->set_next(temp->get_next());
        delete temp;
        size--;
    }
}
void LL::Display()
{
    Nodeptr temp=head;
    if(size==0)
    {
        cout<<"Linked list is empty"<<endl;
    }
    else
    {
        cout<<"Simple Linked List"<<endl;
        while(temp!=NULL)
        {
            temp->display();
            temp=temp->get_next();
        }

    }
}
LL::~LL()
{
    cout<<"Deleting all nodes"<<endl;
    Nodeptr temp=head;
    while(temp!=NULL)
    {
        if(temp->get_next()==NULL)
        {
            delete tail;
            break;
        }
        delete temp;
        temp=temp->get_next();
    }
}
#endif