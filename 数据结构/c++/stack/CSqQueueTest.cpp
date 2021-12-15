/*
 * @Author: your name
 * @Date: 2021-11-03 19:36:13
 * @LastEditTime: 2021-11-03 20:11:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \c++\stack\CSqQueueTest.cpp
 */
#include<iostream>
using namespace std;
#define MaxSize 50

typedef int ElemType;

typedef struct{
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;

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
void InitQueue(SqQueue * &q){
    q=(SqQueue *)malloc(sizeof(SqQueue));
    q->front=q->rear=0;
}

void DestroyQueue(SqQueue * &q){
    free(q);
}

bool QueueEmpty(SqQueue *q){
    return(q->front==q->rear);
}

bool enQueue(SqQueue * &q,ElemType e){
    if((q->rear+1)%MaxSize==q->front) //队满上溢出
        return false;
    q->rear=(q->rear+1)%MaxSize;
    q->data[q->rear]=e;
    return true;
}
bool deQueue(SqQueue * &q,ElemType &e){
    if(q->front==q->rear)
        return false;
    q->front =(q->front+1)%MaxSize;
    e=q->data[q->front];
    return true;
}

void Reverse(SqQueue *&qu){
    ElemType e;
    SqStack *st;
    InitStack(st);
    while (!QueueEmpty(qu))
    {
        deQueue(qu,e);
        Push(st,e);
    }
    InitQueue(qu);
    while (!StackEmpty(st))
    {
        Pop(st,e);
        enQueue(qu,e);
    }
    DestroyStack(st);
}

