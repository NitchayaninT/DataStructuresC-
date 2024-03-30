//basic linked list, not sorted
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "LL.h"

void menu();
int main()
{
    LL List1;
    int choice;
    int id;
    string name;
    int score,position;
    ID Student;
    while(choice!=4)
    {
        menu();
        cout<<"Choose : ";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
            cout<<"Insert Student ID : ";
            cin>>id;
            cout<<"Insert Student Name : ";
            cin>>name;
            cout<<"Insert Student Score : ";
            cin>>score;
            Student.set_student(id,name,score);
            cout<<"Position you want to insert : ";
            cin>>position;
            List1.InsertNode(Student,position);
            break;

            case 2:
            cout<<"ID you want to delete : ";
            cin>>id;
            List1.DeleteNode(id);
            break;

            case 3:
            List1.Display();
            break;

            case 4:
            cout<<"Bye"<<endl;
            break;

            default:
            cout<<"Please choose one of the three!"<<endl;
            break;
        }
    }

    return 0;
}
void menu()
{
    cout<<"What would you like to do?"<<endl;
    cout<<"1.Insert Node"<<endl;
    cout<<"2.Delete Node"<<endl;
    cout<<"3.Display all Nodes"<<endl;
    cout<<"4.Exit Program"<<endl;
}