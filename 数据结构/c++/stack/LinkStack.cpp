/*
 * @Author: your name
 * @Date: 2021-10-19 19:23:22
 * @LastEditTime: 2021-10-19 19:50:40
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \c++\stack\LinkStack.cpp
 */
#include<iostream>
using namespace std;
typedef char ElemType;
typedef struct linknode{
    ElemType data;
    struct linknode *next;

}LinkStNode;
void InitStack(LinkStNode * &s){
    s=(LinkStNode *)malloc(sizeof(LinkStNode));
    s->next=NULL;
}
void DestroyStack(LinkStNode * &s){
    LinkStNode *pre=s, *p=s->next;
    while (p!=NULL)
    {
        free(pre);
        pre=p;
        p=p->next;
    }
    
}
bool StackEmpty(LinkStNode *s){
    return(s->next==NULL);
}
void Push(LinkStNode * &s,ElemType e){
    LinkStNode *p;
    p=(LinkStNode *)malloc(sizeof(LinkStNode));
    p->data=e;
    p->next = s->next;
    s->next=p;
}
bool Pop(LinkStNode * &s,ElemType &e){
    LinkStNode *p;
    if(s->next==NULL)
        return false;
    p=s->next;
    e=p->data;
    s->next=p->next;
    free(p);
    return true;
}
bool GetTop(LinkStNode *s,ElemType &e){
    if(s->next==NULL)
        return false;
    e=s->next->data;
    return true;
}

bool Match(char exp[],int n){
    int i=0;
    char e;
    bool match=true;
    LinkStNode *st;
    InitStack(st);
    while (i<n && match)
    {
        if(exp[i]=='(')
            Push(st,exp[i]);
        else if(exp[i]==')'){
            if(GetTop(st,e)==true){
                if(e!='(')
                    match=false;
                else
                    Pop(st,e);
            }
            else match=false;
        }
        i++;
    }
    DestroyStack(st);
    return match;
    
}