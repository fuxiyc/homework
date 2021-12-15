/*
 * @Author: 王子辰
 * @Date: 2021-10-19 18:44:54
 * @LastEditTime: 2021-11-03 23:30:25
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \c++\stack\sqStack.cpp
 */
#include<iostream>
using namespace std;
#define MaxSize 50

typedef int ElemType;

typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;
//共享栈
typedef struct{
    ElemType data[MaxSize];
    int top1,top2;
}DStack;

void InitStack(SqStack * &s){
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
}
void DestroyStack(SqStack * &s){
    free(s);
}
bool StackEmpty(SqStack *s){
    return(s->top==-1);
}
/**
 * @brief 进栈
 * 
 * @param s 
 * @param e 
 * @return true 
 * @return false 
 */
bool Push(SqStack * &s,ElemType e){
    if(s->top == MaxSize-1)
        return false;
    s->top++;
    s->data[s->top]=e;
    return true;
}
/**
 * @brief 出栈
 * 
 * @param s 
 * @param e 
 * @return true 
 * @return false 
 */
bool Pop(SqStack * &s,ElemType &e){
    if(s->top == -1)
        return false;
    e=s->data[s->top];
    s->top--;
    return true;
}
bool GetTop(SqStack *s,ElemType &e){
    if(s->top == -1)
        return false;
    e=s->data[s->top];
    return true;
}

void trans(char * exp,char postexp[]){
    char e;
    SqStack *Optr;
}