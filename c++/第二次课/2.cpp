/*
 * @Author: your name
 * @Date: 2021-12-06 13:56:55
 * @LastEditTime: 2021-12-06 15:02:32
 * @LastEditors: Please set LastEditors
 * @Description: 运算符重载
 * @FilePath: \c++g:\王子辰\c++\第二次课\2.cpp
 */
#include<iostream>
using namespace std;

class Complex{
    public:
        Complex(){real=0;imag=0;}
        Complex(double r,double i){real=r;imag=i;}
        friend Complex operator+(Complex &c1,Complex &c2);
        friend Complex operator+(int &i,Complex &c2);
        // complex operator + (complex &c2);
        void display();
    private:
        double real;//实部
        double imag;//虚部

};
Complex operator+(Complex &c1,Complex &c2){ //定义友元运算符重载函数
    return Complex(c1.real+c2.real,c1.imag+c2.imag);
}
/**
 * @brief 定义友元运算符重载函数 有int ,如果想把int放在后面就必须重写一个友元函数
 * 
 * @param i 
 * @param c2 
 * @return Complex 
 */
Complex operator+(int &i,Complex &c2){ 
    return Complex(i+c2.real,c2.imag);
}

// complex complex::operator+(complex &c2){ //定义成员运算符重载函数
//     return complex(real+c2.real,imag+c2.imag);
// }
void Complex::display(){
    cout<<"("<<real<<","<<imag<<"i)"<<endl;
}
int main(){
    // Complex c1=Complex(2.5,3.7);
    // Complex c2=Complex(4.2,6.5);
    // Complex c3;
    Complex c1(2.5,3.7), c2(4.2,6.5),c3;
    int a=5;
    c3=a+c2;
    c3=c1+c2;
    cout<<"c1=";
    c1.display();
    cout<<"c2=";
    c2.display();
    cout<<"c3=";
    c3.display();
    
}



// complex complex::operator+(complex &c2){
//     return complex(real+c2.real,imag+c2.imag);
//     // complex c;
//     // c.real=real+c2.real;
//     // c.imag=imag+c2.imag;
//     // return c;
// }