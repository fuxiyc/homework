/*
 * @Author: 王子辰
 * @Date: 2021-10-06 11:38:09
 * @LastEditTime: 2021-11-09 16:55:19
 * @theme: 单链表
 */
// #include<iostream>
// #include<iomanip>
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
// using namespace std;
//单链表
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LinkNode;

void CreateListF(LinkNode * &L,ElemType a[],int n){
    LinkNode *s;
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
    for (int i = 0; i < n; i++)
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=a[i];
        s->next=L->next;
        L->next=s;
    }
    
}
/**
 * @brief 尾插法,正序
 * 
 * @param L 
 * @param a 
 * @param n 
 */
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
    r->next=NULL;
}

void InitList(LinkNode * &L){
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next=NULL;
}

void DestroyList(LinkNode * &L){
    LinkNode *pre = L, *p = L->next;
    while (p!=NULL)
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
    while (p->next!=NULL)
    {
        n++;
        p=p->next;
    }
    return(n);
}

void DispList(LinkNode *L){
    LinkNode *p=L->next;
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

bool GetElem(LinkNode *L,int i,ElemType &e){
    int j=0;
    LinkNode *p=L;
    if (i<=0) return false;
    while (j<i&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else{
        e=p->data;
        return true;
    }
    
}

int LocateElem(LinkNode *L,ElemType e){
    int i=1;
    LinkNode *p=L->next;
    while (p!=NULL&&p->data!=e)
    {
        p=p->next;
        i++;
    }
    if(p==NULL)
        return(0);
    else
        return(i);
}

bool ListInsert(LinkNode * &L,int i,ElemType e){
    int j=0;
    LinkNode *p = L,*s;
    if(i<=0) return false;
    while (j<i-1 && p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
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
    while (j<i-1 && p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else{
        q=p->next;
        if(q==NULL)
            return false;
        e=q->data;
        p->next=q->next;
        free(q);
        return true;
    }
}

void split(LinkNode * &L,LinkNode * &L1,LinkNode * &L2){
    LinkNode *p = L->next,*q,*r1;
    L1=L;
    r1=L1;//定义尾节点
    L2=(LinkNode *)malloc(sizeof(LinkNode));
    L2->next=NULL;
    while (p!=NULL)
    {   //尾插法
        r1->next=p;
        r1=p;
        p=p->next;//p移动到下一个节点(data值bi)
        q=p->next;//p的next域会被修改,用q保存p的后继节点(data值ai+1)
        //头插法
        p->next=L2->next;
        L2->next=p;
        p=q;

    }
    r1->next=NULL;
    
}

void delmaxnode(LinkNode * &L){
    LinkNode *p=L->next,*pre=L,*maxp=p,*maxpre=pre;
    while (p!=NULL)
    {
        if(maxp->data<p->data){
            maxp=p;
            maxpre=pre;
        }
        pre=p;
        p=p->next;
    }
    maxpre->next=maxp->next;
    free(maxp);
    
}

void sort(LinkNode * &L){
    LinkNode *p,*pre,*q;
    p=L->next->next;
    L->next->next=NULL;
    while (p!=NULL)
    {
        q=p->next;
        pre=L;
        while(pre->next!=NULL&&pre->next->data<p->data)
            pre=pre->next;
        p->next=pre->next;
        pre->next=p;
        p=q;
    }
    
}
void sortR(LinkNode * &L){
    LinkNode *p,*pre,*q;
    p=L->next->next;
    L->next->next=NULL;
    while (p!=NULL)
    {
        q=p->next;
        pre=L;
        while(pre->next!=NULL&&pre->next->data>p->data)
            pre=pre->next;
        p->next=pre->next;
        pre->next=p;
        p=q;
    }
    
}
//12.
void Trs(LinkNode * &L){
    LinkNode *p=L->next,*q;
    L->next=NULL;
    while (p!=NULL)
    {
        q=p->next;
        p->next=L->next;
        L->next=p;
        p=q;
    }
}
//14.
void MaxInsert(LinkNode * &L,ElemType x){
    LinkNode *p=L->next,*pre=L,*maxp=p,*maxpre=pre,*s;
    while (p!=NULL)
    {
        if(maxp->data<p->data){
            maxp=p;
            maxpre=pre;
        }
        pre=p;
        p=p->next;
    }
    s=(LinkNode *)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=maxpre->next;
    maxpre->next=s;
}
/**
 * @brief 删除重复结点
 * 
 * @param L 
 */
void DeleteRepeat(LinkNode * &L){   
    LinkNode *p=L->next,*pre=L,*q;
    while (p!=NULL)
    {
        if(pre->data==p->data){
            q=p->next;
            pre->next=p->next;
            free(p);
            p=q;
        }else{
            pre=p;
            p=p->next;
        }   
    }
}

//------递归---------
//7.无头结点的单链表L
void traverse(LinkNode *L){
    if(L==NULL) 
        return;
    else{
        printf("%d ",L->data);
        traverse(L->next);
    }
}
void traverseR(LinkNode *L){
    if(L==NULL) 
        return;
    else{
        traverseR(L->next);
        printf("%d ",L->data);
    }
}
//8无头结点的单链表L
//删除第一个x
void del(LinkNode * &L,ElemType x){
    LinkNode *t,*pre=L;
    if(L==NULL)
        return;
    if (L->data==x){
        t=L;
        L=L->next;
        free(t);
        return;
    }
    del(L->next,x);
    
}
//删除全部x
void delall(LinkNode * &L,ElemType x){
    LinkNode *t;
    if(L==NULL)
        return;
    if (L->data==x){
        t=L;
        L=L->next;
        free(t);
    }
    delall(L->next,x);
}

int main(){
    LinkNode *L;
    ElemType a[]={1,2,3,4,5,6,5,8,5,10};
    CreateListR(L,a,10);
    printf("正向输出单链表的值\n");
    traverse(L->next);
    printf("\n反向输出单链表的值\n");
    traverseR(L->next);//设为无头结点
    printf("\n");
    //删除第一个5
    del(L->next,5);
    printf("删除L中第一个值为5的结点值\n");
    DispList(L);
    //删除全部5
    delall(L->next,5);
    printf("删除L中第所有值为5的结点值\n");
    DispList(L);

    DestroyList(L);
}

// int main(){
//     LinkNode *L1;
//     ElemType a[]={1,2,2,4,4,6,7,7,10,10};
//     CreateListR(L1,a,10);
//     printf("修改前\n");
//     DispList(L1);
//     DeleteRepeat(L1);
//     printf("修改后\n");
//     DispList(L1);
//     DestroyList(L1);

// }
// int main(){
//     LinkNode *L1,*L2;
//     ElemType a[]={1,2,3,4,5,6,7,8,9,10};
//     ElemType b[]={3,6,5,10,4,3,10,6,4,5};
//     CreateListR(L1,a,10);
//     CreateListR(L2,b,10);
//     printf("-----12题修改前-----\n");
//     DispList(L1);
//     Trs(L1); 
//     printf("-----12题修改后-----\n");
//     DispList(L1);
//     printf("-----14题修改前-----\n");
//     DispList(L2);
//     MaxInsert(L2,666);
//     printf("-----14题修改后-----\n");
//     DispList(L2);

//     DestroyList(L1);
//     DestroyList(L2);

// }
// int main()
// {
//     LinkNode *ln,*ln1,*ln2;
//     ElemType a[]={1,2,1,2,1,2,1,2,1,2};
//     CreateListR(ln,a,10);
//     DispList(ln);
//     split(ln,ln1,ln2);

//     // DispList(ln);
//     DispList(ln1);
//     DispList(ln2);

//     DestroyList(ln);
//     DestroyList(ln2);

//     return 0;
// }

//删除最大的一个结点-主函数
// int main(){
//     LinkNode *L;
//     ElemType a[]={5,6,4,3,7,8,9,2,1};
//     CreateListR(L,a,9);
//     DispList(L);
//     delmaxnode(L);
//     DispList(L);

//     DestroyList(L);

// }
/**
 * 排序的main
*/
// int main(){
//     LinkNode *L;
//     ElemType a[]={5,3,6,7,2,1};
//     CreateListR(L,a,6);
//     DispList(L);
//     sortR(L);
//     DispList(L);
//     DestroyList(L);
// }