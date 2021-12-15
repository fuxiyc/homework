#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
using namespace std;
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LinkNode;
/**
 * @brief Create a List F object
 * 头插法
 * @param L 
 * @param a 
 */
void CreateListF(LinkNode * &L,ElemType a[],int n){
    LinkNode *s;
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next=L;
    for (int i = 0; i < n; i++)
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=a[i];
        s->next=L->next;
        L->next=s;
    }
}
void CreateListR(LinkNode * &L,ElemType a[],int n){
    LinkNode *s,*r;
    L=(LinkNode *)malloc(sizeof(LinkNode));
    r=L;
    for (int i = 0; i < n; i++)
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=L;
}
void InitList(LinkNode * &L){
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next=L;
}

void DestroyList(LinkNode * &L){
    LinkNode *pre = L,*p=L->next;
    while (p!=L)
    {
        free(pre);
        pre=p;
        p=pre->next;
    }
    free(pre);
    
}
bool ListEmpty(LinkNode *L){
    return(L->next==NULL);
}
int ListLength(LinkNode *L){
    int n=0;
    LinkNode *p=L;
    while (p->next!=L)
    {
        n++;
        p=p->next;
    }
    return(n);
}
void DispList(LinkNode *L){
    LinkNode *p=L->next;
    while (p!=L)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
    
}
bool GetElem(LinkNode *L,int i,ElemType &e){
    int j=0;
    LinkNode *p=L;
    if(i<0) return false;
    while (j<i && p != L)
    {
        j++;
        p=p->next;
    }
    if(p==L)
        return false;
    else{
        e=p->data;
        return true;
    }
}
int LocateElem(LinkNode *L,ElemType e){
    int i=1;
    LinkNode *p=L->next;
    while (p!=L && p->data!=e)
    {
        p=p->next;
        i++;
    }
    if(p==NULL)
        return(0);//为什么加括号
    else
        return (i);
}

bool ListInsert(LinkNode * &L,int i,ElemType e){
    int j=0;
    LinkNode *p = L, *s;
    if(i<=0) return false;
    while (j<i-1 && p!=L)
    {
        j++;
        p=p->next;
    }
    if(p==L)
        return false;
    else{
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return true;
    }
}

bool ListDelete(LinkNode * &L,int i,ElemType &e){
    int j=0;
    LinkNode *p=L,*q;
    if(i<=0) return false;
    while (j<i-1 && p!=L)
    {
        j++;
        p=p->next;
    }
    if(p==L){
        return false;
    }else{
        q=p->next;
        if(q=L)
            return false;
        e=q->data;
        p->next=q->next;
        free(q);
        return true;
    }
}

int count(LinkNode *L,ElemType x){
    int i=0;
    LinkNode *p=L->next;
    while (p!=L)
    {
        if(p->data==x)
            i++;
        p=p->next;

    }
    return i;
}
/**
 * @brief 练习2第17题 合并两个循环单链表
 * 
 * @param hc 带头结点的循环单链表
 * @param ha 带头结点的循环单链表
 * @param hb 带头结点的循环单链表
 */
void marge(LinkNode * &hc,LinkNode * &ha,LinkNode * &hb){
    LinkNode *p=ha->next;
    hc=ha;
    while (p->next!=ha)
    {
        p=p->next;
    }
    p->next=hb->next;
    while(p->next!=hb){
        p=p->next;
    }
    p->next=hc;
    free(hb);
}
int main(){
    LinkNode *ha,*hb,*hc;
    ElemType a[]={1,1,1,1,1};
    ElemType b[]={2,2,2,2,2};
    CreateListF(ha,a,5);
    CreateListF(hb,b,5);
    marge(hc,ha,hb);
    printf("合并后\n");
    DispList(hc);
    
    DestroyList(ha);
    DestroyList(hc);
    DestroyList(hb);

}