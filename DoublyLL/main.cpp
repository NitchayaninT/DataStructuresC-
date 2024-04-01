//sorted LL
#include <iostream>
#include <iomanip>
using namespace std;
#include "LL.h"
void menu();
int main()
{
    int choice,value;
    DoublyLL List1;
    while(choice!=3)
    {
        menu();
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Value you want to insert : ";
            cin>>value;
            List1.InsertNode(value);
            List1.Display();
            break;

            case 2:
            cout<<"Value you want to delete : ";
            cin>>value;
            List1.DeleteNode(value);
            List1.Display();
            break;

            case 3:
            cout<<"Bye"<<endl;
            break;

            default:
            cout<<"insert again"<<endl;
            break;
        }
    }
}
void menu()
{
    cout<<"What would you like to do?"<<endl;
    cout<<"1.Insert Node"<<endl;
    cout<<"2.Delete Node"<<endl;
    cout<<"3.Exit Program"<<endl;
}