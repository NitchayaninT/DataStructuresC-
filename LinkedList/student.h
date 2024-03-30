#ifndef student_h
#define student_h

class ID{
private:
int id;
string name;
int score;
public:
ID(int=0,string="unknown",int=0);
void set_student(int,string,int);
int get_id(){return id;};
string get_name(){return name;};
int get_score(){return score;};
~ID();
};
ID::ID(int id,string name,int score)
{
    this->id=id;
    this->name=name;
    this->score=score;
}
void ID::set_student(int id,string name,int score)//not constructor
{
    this->id=id;
    this->name=name;
    this->score=score;   
}
ID::~ID()
{
    //cout<<"deleting student "<<id<<endl;
}
#endif