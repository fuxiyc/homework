#include<iostream>


using namespace std;
//双链表


class DLinkList{    
private:
    typedef int ElemType;

    typedef struct DNode{
        ElemType data;
        struct DNode *prior;
        struct DNode *next;
    }DLinkNode;
public:
void CreateListF(DLinkNode * &L,ElemType a[],int n){
    DLinkNode *s;
    L=(DLinkNode *)malloc(sizeof(DLinkNode));
    L->prior=L->next=NULL;
    for (int i = 0; i < n; i++)
    {
        s=(DLinkNode *)malloc(sizeof(DLinkNode));
        s->data=a[i];
        s->next=L->next;
        if(L->next!=NULL)
            L->next->prior=s;
        L->next=s;
        s->prior=L;
    }
    
}
void CreateListR(DLinkNode * &L,ElemType a[],int n){
    DLinkNode *s,*r;
    L=(DLinkNode *)malloc(sizeof(DLinkNode));
    r=L;
    for (int i = 0; i < n; i++)
    {
        s=(DLinkNode *)malloc(sizeof(DLinkNode));
        s->data=a[i];
        r->next=s;s->prior=r;
        r=s;
    }
    r->next=NULL;
}
void DispList(DLinkNode *L){
    DLinkNode *p=L->next;
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    
}
bool ListInsert(DLinkNode * &L,int i,ElemType e){
    int j=0;
    DLinkNode *p=L,*s;
    if(i<=0) return false;
    while (j<i-1 && p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else{
        s=(DLinkNode *)malloc(sizeof(DLinkNode));
        s->data=e;
        s->next=p->next;
        if(p->next!=NULL)
            p->next->prior=s;
        s->prior=p;
        p->next=s;
        return true;

    }
}
bool ListDelete(DLinkNode * &L,int i,ElemType &e){
    int j=0;
    DLinkNode *p=L,*q;
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
        if(q->next!=NULL)
            q->next->prior=p;
        free(q);
        return true;

    }
}
void DestroyList(DLinkNode * &L){
    DLinkNode *p=L->next;
    while (p!=NULL)
    {
        free(p->prior);
        p=p->next;
    }
    free(p);
    
}
void reverse(DLinkNode * &L){
    DLinkNode *p=L->next,*q;
    L->next=NULL;
    while (p!=NULL)
    {
        q=p->next;
        p->next=L->next;
        if(L->next!=NULL)
            L->next->prior=p;
        L->next=p;
        p->prior=L;
        p=q;
    }
    
}
void sort(DLinkNode * &L){
    DLinkNode *p,*pre,*q;
    p=L->next->next;
    L->next->next=NULL;
    while (p!=NULL)
    {
        q=p->next;
        pre=L;
        while (pre->next!=NULL&&pre->next->data<p->data)
            pre=pre->next;
        p->next=pre->next;
        if(pre->next!=NULL)
            pre->next->prior=p;
        pre->next=p;
        p->prior=pre;
        p=q;
        
    }
    
}
void sortR(DLinkNode * &L){
    DLinkNode *p,*pre,*q;
    p=L->next->next;
    L->next->next=NULL;
    while (p!=NULL)
    {
        q=p->next;
        pre=L;
        while (pre->next!=NULL&&pre->next->data>p->data)
            pre=pre->next;
        p->next=pre->next;
        if(pre->next!=NULL)
            pre->next->prior=p;
        pre->next=p;
        p->prior=pre;
        p=q;
        
    }
    
}


};

