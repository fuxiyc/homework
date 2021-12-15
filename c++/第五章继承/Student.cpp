/*
 * @Author: your name
 * @Date: 2021-12-13 16:08:48
 * @LastEditTime: 2021-12-13 17:14:38
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \c++g:\王子辰\c++\第五章继承\Student.cpp
 */
#include<iostream>
#include<string>
using namespace std;
class Student{
    public:
        Student(int n,string nam,char s){
            num=n;
            name=nam;
            sex=s;
        }
        ~Student(){}
        void get_value(){
            cin>>num>>name>>sex;
        }
        void display(){
            cout<<"num:"<<num<<endl;
            cout<<"name:"<<name<<endl;
            cout<<"sex:"<<sex<<endl;
        }
        // private:
        //     int num;
        //     string name;
        //     char sex;
        protected:
            int num;
            string name;
            char sex;
};
class Student1:public Student{  //private protected
    public:
        int xi,yi; 
        // Student1(int n,string nam,char s,int a,string ad):Student(n,nam,s){
        //     age=a;addr=ad;
        // } 
        Student1(int n,string nam,char s,int a,string ad):Student(n,nam,s),age(a),addr(ad){}
        void get_value_1(){
            cin>>age>>addr;
        }
        void in(){
            x=4;y=5;
        }
        void display_1(){
            display();
            cout<<"age:"<<age<<endl;
            cout<<"addr:"<<addr<<endl;
        }
        void display_2(){
            cout<<"xi:"<<xi<<endl;
            cout<<"yi:"<<yi<<endl;
            cout<<"x:"<<x<<endl;
            cout<<"y:"<<y<<endl;
        }
        ~Student1(){ }
    private:
        int age;
        string addr;
    protected:
        int x;
        int y;
};

int main(){
    Student1 stud(10010,"wang",'f',19,"shanghdi");
    // stud.get_value();
    // stud.get_value_1();
    // stud.display();
    // stud.display_1();
    stud.xi=4;
    stud.yi=5;
    stud.in();
    stud.display_2();
    return 0;
}