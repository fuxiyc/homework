/*
 * @Author: your name
 * @Date: 2021-11-05 20:39:54
 * @LastEditTime: 2021-12-09 16:24:38
 * @LastEditors: Please set LastEditors
 * @Description: 链串基本运算的算法
 * @FilePath: \c++\string\LinkString.cpp
 */
#include<iostream>
using namespace std;
#define MaxSize 10

typedef struct snode{
    char data;
    struct snode * next;
}LinkStrNode;

void StrAssign(LinkStrNode * &s,char cstr[]){
    int i;
    LinkStrNode *r, *p;
    s=(LinkStrNode *)malloc(sizeof(LinkStrNode));
    r=s;
    for(i=0;cstr[i] != '\0';i++){
        p=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        p->data=cstr[i];
        r->next=p;
        r=p;
    }
    r->next = NULL;
}

void DestroyStr(LinkStrNode * &s){
    LinkStrNode *pre = s,*p=s->next;
    while (p!=NULL)
    {
        free(pre);
        pre=p;
        p=pre->next;
    }
    free(pre);
    
}

void StrCopy(LinkStrNode * &s,LinkStrNode *t){
    LinkStrNode *p = t->next,*q,*r;
    s=(LinkStrNode *)malloc(sizeof(LinkStrNode));
    r=s;
    while (p!=NULL)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    r->next=NULL;
    
}
bool StrEqual(LinkStrNode *s,LinkStrNode *t){
    LinkStrNode *p = s->next,*q=t->next;
    while (p!=NULL&&q!=NULL&&p->data==q->data)
    {
        p=p->next;
        q=q->next;
    }
    if(q==NULL && p==NULL)
        return true;
    else
        return false;
}

int StrLength(LinkStrNode *s){
    int i=0;
    LinkStrNode *p = s->next;
    while (p!=NULL)
    {
        i++;
        p=p->next;
    }
    return i;
}

LinkStrNode *Concat(LinkStrNode *s,LinkStrNode *t){
    LinkStrNode * str, *p=s->next, *q,*r;
    str=(LinkStrNode *)malloc(sizeof(LinkStrNode));
    r=str;
    while (p!=NULL)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    p=t->next;
    while (p!=NULL)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    r->next = NULL;
    return str;
}

LinkStrNode *SubStr(LinkStrNode *s,int i,int j){
    int k;
    LinkStrNode *str,*p=s->next,*q,*r;
    str=(LinkStrNode *)malloc(sizeof(LinkStrNode));
    str->next=NULL;
    r=str;
    if(i<=0 || i>StrLength(s) || j<0 || i+j-1 > StrLength(s))
        return str;
    for(k=1;k<i;k++)  //指向第i个结点  运行i-1次即可正确指向  也可用k=0;k<i-1
        p=p->next;
    for ( k = 1; k <= j; k++)//链表可以用1开始,没影响 也可用 k=0;k<j
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next =q;
        r=q;
        p=p->next;
    }
    r->next = NULL;
    return str;
}

LinkStrNode *InsStr(LinkStrNode *s,int i,LinkStrNode *t){
    int k;
    LinkStrNode *str, *p=s->next, *p1=t->next, *q, *r;
    str=(LinkStrNode *)malloc(sizeof(LinkStrNode));
    str->next==NULL;
    r=str;
    if(i<=0 || i>StrLength(s)+1)
        return str;
    for ( k = 1; k < i; k++)//将s的 前i个 结点复制到str
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next = q;
        r=q;
        p=p->next;
    }
    while (p1!=NULL)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p1->data;
        r->next=q;
        r=q;
        p1=p1->next;
    }
    while (p!=NULL)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    r->next = NULL;
    return str;
    
}
LinkStrNode *DelStr(LinkStrNode *s,int i,int j){
    int k;
    LinkStrNode *str, *p=s->next,*q,*r;
    str=(LinkStrNode *)malloc(sizeof(LinkStrNode));
    str->next=NULL;
    r=str;
    if(i<=0 || i>StrLength(s) || j<0 || i+j-1>StrLength(s))
        return str;
    for(k=1;k<i;k++){
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        r->next = q;
        r=q;
        p=p->next;
    }
    for(k=0;k<j;k++) //让p沿next 跳j个结点
        p=p->next;
    while (p!=NULL)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r=q;
        p=p->next;
    }
    r->next = NULL;
    return str;
    
}

LinkStrNode * RepStr(LinkStrNode *s,int i,int j ,LinkStrNode *t){
    int k;
    LinkStrNode *str , *p=s->next, *p1=t->next,*q,*r;
    str=(LinkStrNode *)malloc(sizeof(LinkStrNode));
    str->next=NULL;
    r=str;
    if(i<=0 || i>StrLength(s) || j<0 || i+j-1>StrLength(s));
        return str;
    for ( k = 0; k < i-1; k++){//将s的前i-1个数据结点复制到str
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        q->next=NULL;//??
        r->next = q;
        r=q;
        p=p->next;
    }
    for(k=0;k<j;k++)
        p=p->next;
    while (p1!=NULL)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p1->data;
        q->next=NULL;//??
        r->next = q;
        r = q;
        p1=p1->next;
    }
    while (p!=NULL)
    {
        q=(LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data=p->data;
        q->next=NULL;//??有没有都无影响,不过有了可以更规范
        r->next = q;
        r=q;
        p=p->next;
    }
    r->next = NULL;
    return str;
}

void DispStr(LinkStrNode *s){
    LinkStrNode *p=s->next;
    while (p!=NULL)
    {
        printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
    
}