/*
 * @Author: your name
 * @Date: 2021-11-14 21:17:26
 * @LastEditTime: 2021-11-14 21:25:04
 * @LastEditors: Please set LastEditors
 * @Description: 带参数的构造函数
 * @FilePath: \c++\cTest\constructor1.cpp
 */
#include<iostream>
using namespace std;
class Box{
    public:
        Box(int,int,int);
        int volume();//一般成员函数
        
    private:
        int height;
        int width;
        int length;
};
Box::Box(int h,int w,int len){
    height = h;
    width = w;
    length = len;
}
int Box::volume(){
    return(height*width*length);
}

int main(){
    Box b1(12,25,30);
    cout<<"The Volume of b1 is"<<b1.volume()<<endl;
    Box b2(15,35,40);
    cout<<"The Volume of b2 is"<<b2.volume()<<endl;

    
    return 0;

}
