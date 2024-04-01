#ifndef LL_h
#define LL_h
#include "node.h"
typedef Node* Nodeptr;

class DoublyLL{
private:
Nodeptr head;
Nodeptr tail;
int size;
public:
DoublyLL();
void InsertNode(int);
void DeleteNode(int);
void Display();
~DoublyLL();
};
DoublyLL::DoublyLL()
{
    head=NULL;
    tail=NULL;
    size=0;
}
void DoublyLL::InsertNode(int x)
{
    Nodeptr NewNode=new Node(x);
    Nodeptr Previous=NULL;
    Nodeptr temp=head;
    if(head==NULL)//if theres no node
    {
      head=NewNode;
      tail=NewNode;
      size++;
    }
    else
    {
        while(temp->get_next()!=NULL&&x>temp->get_value())
        {
            Previous=temp;
            temp=temp->get_next();
        }

        if(temp==head)//insert in front of first node
        {
            NewNode->set_next(head);
            head=NewNode;
            if(size==1) tail=temp;
            size++;
            cout<<x<<" Inserted in front"<<endl;
        }
        else if(temp->get_next()==NULL)//if last node
        {
            if(x<temp->get_value())
            {
                temp=temp->get_prev();
                temp->set_next(NewNode);
                NewNode->set_next(tail);
            }
            else
            {
                temp->set_next(NewNode);
                tail=NewNode;
            }
             cout<<x<<" Inserted at tail"<<endl;
            size++;
        }
        else//in between
        {
            Previous->set_next(NewNode);
            NewNode->set_next(temp);
            size++;
            cout<<x<<" Inserted between"<<endl;
        }
    }
}
void DoublyLL::DeleteNode(int x)
{
    Nodeptr temp;
    Nodeptr Previous;
    if(x==head->get_value())//if first node
    {
        temp=head;
        head=head->get_next();
        delete temp;
        size--;
    }
    else if(x==tail->get_value())//if last node
    {
       temp=tail;
       tail=tail->get_prev();
       delete temp;
       size--;
    }
    else//if in between
    {
       temp=head;
       while(temp->get_next()!=NULL&&x!=temp->get_value())
       {
        Previous=temp;
        temp=temp->get_next();
       }
       Previous->set_next(temp->get_next());
       delete temp;
       size--;
    }
}
void DoublyLL::Display()
{
    Nodeptr temp=head;
    if(size==0)
    {
        cout<<"Linked list is empty"<<endl;
    }
    else
    {
        cout<<"Doubly Linked List"<<endl;
        while(temp!=NULL)
        {
            temp->display();
            temp=temp->get_next();
        }

    }
}
DoublyLL::~DoublyLL()
{
    cout<<"Deleting all nodes"<<endl;
    Nodeptr temp=head;
    Nodeptr Previous=NULL;
    while(temp!=NULL)
    {
        if(temp->get_next()==NULL)
        {
            delete tail;
            break;
        }
        Previous=temp;
        temp=temp->get_next();
        delete Previous;  
    }
}
#endif
