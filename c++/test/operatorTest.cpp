/*
 * @Author: your name
 * @Date: 2021-12-06 15:18:52
 * @LastEditTime: 2021-12-06 15:45:01
 * @LastEditors: Please set LastEditors
 * @Description: 重载单目运算符
 * @FilePath: \c++g:\王子辰\c++\test\operatorTest.cpp
 */
#include<iostream>
using namespace std;
class Time{
    public:
        Time(){minute=0;sec=0;}
        Time(int m,int s):minute(m),sec(s){}
        Time operator++();
        Time operator++(int);
        void display(){
            cout<<minute<<":"<<sec<<endl;
        }
    private:
        int minute;
        int sec;
};
Time Time::operator++(){
    if(++sec>=60){
        sec-=60;
        ++minute;
    }
    return *this;       //返回自加后的当前对象
}
Time Time::operator++(int){//int只是为了和前置自增运算符重置函数有所区别,在定义函数时也不必使用此参数,因此可以省写参数名,只需在括号中写int即可
    Time temp(* this);
    sec++;
    if(sec>=60){
        sec-=60;
        ++minute;
    }
    return temp;        //返回自加前的对象
}
int main(){
    Time time1(34,59),time2;
    // for(int i=0;i<61;i++){
    //     ++time1;
    //     time1.display();
    // }
    cout<<"time1:";time1.display();
    ++time1;
    cout<<"++time1:";time1.display();
    time2=time1++;
    cout<<"time1++";time1.display();
    cout<<"time2:";time2.display();
    
    return 0;
}