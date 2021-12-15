/*
 * @Author: your name
 * @Date: 2021-10-21 16:28:36
 * @LastEditTime: 2021-10-21 17:08:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \c++\stack\sqQueue.cpp
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
    q->front=q->rear=-1;
}

void DestroyQueue(SqQueue * &q){
    free(q);
}
bool QueueEmpty(SqQueue *q){
    return(q->front==q->rear);
}
//进队列
bool enQueue(SqQueue * &q,ElemType e){
    if(q->rear==MaxSize-1){
        return false;
    }
    q->rear++;
    q->data[q->rear]=e;
    return true;
}
//出队列
bool deQueue(SqQueue * &q,ElemType &e){
    if(q->front==q->rear)
        return false;
    q->front++;
    e=q->data[q->front];
    return true;
}
