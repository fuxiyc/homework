/*
 * @Author: your name
 * @Date: 2021-10-21 17:11:04
 * @LastEditTime: 2021-10-21 18:44:54
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \c++\stack\CircularSqQueue.cpp
 */
#include<iostream>
using namespace std;
#define MaxSize 5
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;

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

