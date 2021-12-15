/*
 * @Author: your name
 * @Date: 2021-11-14 20:52:49
 * @LastEditTime: 2021-11-14 21:11:33
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \c++\cTest\constructor.cpp
 */
#include<iostream>
using namespace std;
class Time{
    public:
        // Time(){//构造函数
        //     hour = 0;
        //     minute = 0;
        //     sec = 0;
        // }
        Time();
        void set_time();//一般成员函数
        void show_time();
    private:
        int hour;
        int minute;
        int sec;
};
Time::Time(){
    hour = 0;
    minute = 0;
    sec = 0;
}
void Time::set_time(){
    cin>>hour;
    cin>>minute;
    cin>>sec;
}
void Time::show_time(){
    cout<<hour<<":"<<minute<<":"<<sec<<endl;
}
int main(){
    Time t1;
    t1.set_time();
    t1.show_time();
    Time t2;
    t2.show_time();
    return 0;

}
