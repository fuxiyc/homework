/*
 * @Author: your name
 * @Date: 2021-10-19 19:19:56
 * @LastEditTime: 2021-10-19 19:22:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \c++\stack\DDStack.cpp
 */
#include<iostream>
using namespace std;
#define MaxSize 50

typedef int ElemType;

//共享栈
typedef struct{
    ElemType data[MaxSize];
    int top1,top2;
}DStack;

void InitStack(DStack * &s){
    s=(DStack *)malloc(sizeof(DStack));
    s->top1=-1;
    s->top2=MaxSize;
}
void DestroyStack(DStack * &s){
    free(s);
}
bool StackEmpty(DStack *s){
    return(s->top1==-1)&&(s->top2==MaxSize);
}
/**
 * @brief 进栈
 * 
 * @param s 
 * @param e 
 * @return true 
 * @return false 
 */
// bool Push(DStack * &s,ElemType e){
//     if(s->top == MaxSize-1)
//         return false;
//     s->top++;
//     s->data[s->top]=e;
//     return true;
// }
// /**
//  * @brief 出栈
//  * 
//  * @param s 
//  * @param e 
//  * @return true 
//  * @return false 
//  */
// bool Pop(DStack * &s,ElemType &e){
//     if(s->top == -1)
//         return false;
//     e=s->data[s->top];
//     s->top--;
//     return true;
// }
// bool GetTop(DStack *s,ElemType &e){
//     if(s->top == -1)
//         return false;
//     e=s->data[s->top];
//     return true;
// }
