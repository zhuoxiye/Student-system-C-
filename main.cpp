//C++ student system demo
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <map>
#include<stdio.h>
using namespace std;
class Courses{
private:
    vector<string> lectures;
public:
    Courses(){
        ;
    }
    Courses(string s){
        lectures.push_back(s);
    }
    void add(string c){
        lectures.push_back(c);
    }
    void remove(string c){
        //vector::iterator it;
    }
    void show_courses(){
        for(vector<string>::iterator it = lectures.begin(); it!= lectures.end(); it++){
            cout<< *it <<endl;
        }
    }

};
class Student{
private:
    int student_id;
    string student_name;
    Courses course;
public:
    static int num_student;
    Student(){
    student_id = 0;
    student_name = "";

    }
    Student(int id, string name){
        student_id = id;
        student_name = name;
        num_student++;
    }
    void set_name(string name){
        student_name = name;
    }
    void set_id(int id){
        student_id = id;
    }
    int get_id(){
        return student_id;
    }
    string get_name(){
        return student_name;
    }
    void add_course(const string &c){
        course.add(c);
    }
    void Student_printf(){
        cout<< student_id << ":" << student_name <<endl;
    }
    void update_number(){
        num_student++;
    }
    Courses get_Courses(){
        return course;
    }
};
ostream& operator<<(ostream &out, Student &s){
    out << s.get_name();
    return out;
}
int Student::num_student = 0;
void menu(){
    system("cls");
    system("title MIT Student Database");
    system("color 37");
    cout<< "Welcome to T Student Database System"<<endl;
    cout<< "1.search student"<<endl;
    cout<< "2.add student"<<endl;
    cout<< "3.remove student" <<endl;
    cout<< "4. quit" << endl;
}

void logic(map<int,Student> &stu){
    int s;
    int id;
    string temp_name;
    int temp_id;
    map<int,Student>::iterator it;
    map<int,Student>::iterator map_it;
    while(1){
    cout<< "choose your service:";
        cin >> s;
        switch(s){
        case 1:
            cout<< "input the student's id:";
            cin >> id;
            for(map_it = stu.begin(); map_it != stu.end(); map_it++)
                if(id == map_it->first){
                    map_it->second.Student_printf();
                    map_it->second.get_Courses().show_courses();
                    break;
                }
            if(map_it == stu.end())
                cout<< "can't find student's id:"<< id <<endl;
            break;
        case 2:
            cout<< "input the student's name:";
            cin >> temp_name;
            temp_id = Student::num_student + 1;
            stu[temp_id] =Student(Student::num_student + 1,temp_name);
            break;
        case 3:
            cout<< "input your student's id:";
            cin >> temp_id;
            it = stu.find(temp_id);
            if(it != stu.end()){
                stu.erase(it);
            }
            break;
        case 4:
            system("cls");
            cout<< "Thanks for using ZXY System" << endl;
            system("pause");
            exit(0);
            break;
        default:
            cout<< "wrong command" <<endl;
            break;
        }
    }
}
int main()
{
    map<int,Student> stu;
    stu[1] = Student(1,"Zhuoxi");
    stu[2] = Student(2,"abc");
    stu[1].add_course("PE");

    menu();
    logic(stu);
    return 0;
}
