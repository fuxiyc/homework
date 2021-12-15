/*
 * @Author: your name
 * @Date: 2021-12-13 17:15:23
 * @LastEditTime: 2021-12-13 17:30:32
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \c++g:\王子辰\c++\第五章继承\StudentObject.cpp
 */
#include<iostream>
#include<string>
using namespace std;
class Student{
    public:
        Student(int n,string nam)
        {
            num=n;
            name=nam;
        }
        void display(){
            cout<<"num:"<<num<<endl<<"name;"<<name<<endl;
        }
    protected:
        int num;
        string name;
};
class Student1:public Student{
    public:
        Student1(int n,string nam,int n1,string nam1,int a,string ad ):Student(n,nam),monitor(n1,nam1){
            age=a;addr=ad;
        }
        void show(){
            cout<<"this student is:"<<endl;
            display();
            cout<<"age:"<<age<<endl;
            cout<<"address:"<<addr<<endl<<endl;
        }
        void show_monitor(){
            cout<<endl<<"Class monitor is:"<<endl;
            monitor.display();
        }
    private:
        Student monitor;
        int age;
        string addr;
};
int main(){
    Student1 stud1(10010,"wang_li",10001,"li_ming",19,"114 beijing");
    stud1.show();
    stud1.show_monitor();
    return 0;
}