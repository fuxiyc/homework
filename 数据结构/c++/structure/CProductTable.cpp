#include<stdio.h>
#include<stdlib.h>
#define MAXCOL 10 //最大列数

typedef int ElemType;
typedef struct Node1{
    ElemType data[MAXCOL]; //存放一行的数据
    struct Node1 *next; //指向后继节点
}DList; //行节点类型
typedef struct Node2{
    int Row,Col;
    DList *next;
}HList; //头节点类型

//交互式创建单链表算法
void CreateTable(HList *&h){
    int i,j;
    DList *r,*s;
    h=(HList*)malloc(sizeof(HList)); //创建头节点
    h->next=NULL;

    printf("输入表的行数和列数：");
    scanf("%d%d", &h->Row, &h->Col); //输入表的行列数

    for(i=0; i<h->Row; i++){ //输入所有行的数据
        printf("第%d行：",i+1);
        s=(DList*)malloc(sizeof(DList));
        for(j=0; j<h->Col; j++){
            scanf("%d", &s->data[j]);
        }
        //下面采用尾插法建表（注意：与尾插法建立单链表有些不同，因为头节点与数据节点类型不同，r只能作为数据节点的指针！
        if(h->next==NULL){
            h->next=s;
        }
        else{
            r->next=s;
        }
        r=s;  
    }
    r->next=NULL;
}

//销毁单链表
void DestoryTable(HList *&h){
    DList *pre,*p;
    pre=h->next;
    p=pre->next;

    while(p!=NULL){
        free(pre);
        pre=p;
        p=p->next;
    }
    free(pre);
    free(h);
}

//输出单链表
void DispTable(HList *&h){
    int i;
    DList *p=h->next;
    while(p!=NULL){
        for(i=0; i<h->Col; i++)
            printf("%4d", p->data[i]);
        printf("\n");
        p=p->next;
    }
}
//表连接的运算算法
 void LinkTable(HList *h1, HList *h2, HList *&h){
    int i,k,j;
    DList *p=h1->next,*q,*s,*r;

    printf("连接字段：第一个表序号,第二个表序号：");
    scanf("%d%d",&i,&j);

    //创建头节点
    h=(HList*)malloc(sizeof(HList));
    h->next=NULL;
    h->Row=0;
    h->Col=h1->Col+h2->Col;

    while(p!=NULL){//扫描表1
        q=h2->next;
        while(q!=NULL){//扫描表2
            if(p->data[i-1]==q->data[j-1]){ //对应字段值相等，则创建一个节点s,复制表1表2的当前行到s
                s=(DList*)malloc(sizeof(DList));
                for(k=0; k<h1->Col; k++)
                    s->data[k]=p->data[k];
                for(k=0; k<h2->Col; k++)
                    s->data[h1->Col+k]=q->data[k];
                //尾插法建表
                if(h->next==NULL) h->next=s;
                else r->next=s;
                r=s;  

                h->Row++;              
            }
            q=q->next;
        }
        p=p->next;
    }
    r->next=NULL;
 }

int main(){
    HList *h1,*h2,*h;

    printf("表1：\n");
    CreateTable(h1);

    printf("表2：\n");
    CreateTable(h2);   

    LinkTable(h1,h2,h);
    printf("连接结果表：\n");
    DispTable(h);
    
    DestoryTable(h);
    DestoryTable(h1);     
    DestoryTable(h2);
    return 0;
 }
