/*
 * @Author: your name
 * @Date: 2021-10-21 18:45:15
 * @LastEditTime: 2021-10-21 20:07:55
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \c++\stack\LinkQueue.cpp
 */
#include<iostream>
using namespace std;
#define MaxSize 5
typedef int ElemType;
typedef struct QNode{
    ElemType data;
    struct QNode *next;
}DataNode;

typedef struct {
    DataNode *front;
    DataNode *rear;
}LinkQuNode;
 
void InitQueue(LinkQuNode * &q){

    q=(LinkQuNode *)malloc(sizeof(LinkQuNode));
    q->front=q->rear=NULL;
}
void DestroyQueue(LinkQuNode * &q){
    DataNode *pre = q->front, *p;
    if(pre!=NULL){
        p=pre->next;
        while (p!=NULL)
        {
            free(pre);
            pre=p;
            p=p->next;
        }
        free(pre);
    }
    free(q);
}

bool QueueEmpty(LinkQuNode *q){
    return(q->rear==NULL);
}
void enQueue(LinkQuNode * &q,ElemType e){
    DataNode *p;
    p=(DataNode *)malloc(sizeof(DataNode));
    p->data=e;
    p->next=NULL;
    if(q->rear==NULL) 
        q->front=q->rear=p;
    else{
        q->rear->next=p;
        q->rear=p;
    }
} 
bool deQueue(LinkQuNode * &q,ElemType &e){
    DataNode *t;
    if(q->rear==NULL)
        return false;
    t=q->front;
    if(q->front==q->rear)
        q->front=q->rear=NULL;                                                                 
    else   
        q->front=q->front->next;
    e=t->data;
    free(t);
    return true;
}