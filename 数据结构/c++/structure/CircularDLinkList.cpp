#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
using namespace std;
typedef int ElemType;
typedef struct CDLNode{
    ElemType data;
    struct CDLNode *next;
    struct CDLNode *prior;
}DLinkNode;



bool delelem(DLinkNode *&L,ElemType x){
    DLinkNode *p=L->next;
    if(p!=L){
        p->next->prior=p->prior;
        p->prior->next=p->next;
        free(p);
        return true;
    }
    else
        return false;
}

bool Symm(DLinkNode *L){
    bool same = true;
    DLinkNode *p=L->next;
    DLinkNode *q=L->prior;
    while (same)
    {
        if(p->data!=q->data)
            same=false;
        else{
            if(p==q || p==q->prior) break;
            q=q->prior;
            p=p->next;
        }
    }
    return same;
}