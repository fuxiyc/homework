#include<iostream>
#include<iomanip>
// #include<stdio.h>
// #include<malloc.h>
// #include<stdlib.h>
using namespace std;
//顺序表
#define MaxSize 50

typedef int ElemType;
typedef struct 
{
    ElemType data[MaxSize];
    int length;
} SqList;

void CreateList(SqList * &L,ElemType a[],int n)
{//创建线性表
    int i=0,k=0;
    L=(SqList *) malloc(sizeof(SqList));
    while (i<n)
    {
        L->data[k]=a[i];
        k++;i++;
    }
    L->length=k;

}


void InitList(SqList * &L)
{//初始化线性表
    L=(SqList *)malloc(sizeof(SqList));
    L->length=0;
}

void DestroyList(SqList * &L)
{//销毁线性表
    free(L);
}

bool ListEmpty(SqList * L)
{//判断线性表是否为空表
    return(L->length==0);
}

int ListLength(SqList * L)
{//求线性表长度
    return(L->length);
}

void DispList(SqList *L)
{//输出线性表
    for (int i = 0; i < L->length; i++)
    {
        // printf("%d",L->data[i]);
        cout<<L->data[i]<<" ";
    }
    printf("\n");
}

bool GetElem(SqList * L,int i,ElemType &e)
{//求线性表中某个数据元素值
    if (i<1 || i>L->length)
    {
        return false;
    }
    e=L->data[i-1];
    return true;
    
}

int LocateElem(SqList * L, ElemType e)
{//按元素值查找
    int i=0;
    while (i<L->length && L->data[i]!=e)
    {
        i++;
    }
    if (i>=L->length)
    {
        return 0;
    }else{
        return i+1;
    }
}

bool ListInsert(SqList * &L,int i,ElemType e)
{//插入数据元素
    int j;
    if (i<1 || i>L->length+1 || L->length==MaxSize)
    {
        return false;
    }
    i--;
    for ( j = L->length; j > i; j--)
    {
        L->data[j]=L->data[j-1];
    }
    L->data[i]=e;
    L->length++;
    return true;
}

bool ListDelete(SqList * &L,int i,ElemType &e)
{//删除数据元素
    int j;
    if (i<1 || i > L->length)
    {
        return false;
    }
    i--;
    e=L->data[i];
    for ( j = i; j < L->length-1; j++)
    {
        L->data[j] = L->data[j+1];

    }
    L->length--;
    return true;
    
}
void partition1(SqList * &L){
    int i=0,j=L->length-1;
    ElemType pivot = L->data[0];
    while (i<j)
    {
        while(i<j && L->data[j]>pivot)//找小于等于pivot的元素
            j--;
        while(i<j && L->data[i]<=pivot) //找大于pivot的元素
            i++;
        if(i<j)
            swap(L->data[i],L->data[j]);
    }
    // printf("%d \n",L->data[i]);
    swap(L->data[0],L->data[i]);
}
void partition2(SqList * &L){
    int i=0,j=L->length-1;
    ElemType pivot=L->data[0];
    while (i<j)
    {
        while(j>i&&L->data[j]>pivot)
            j--;
        L->data[i]=L->data[j];
        while(i<j&&L->data[i]<=pivot)
            i++;
        L->data[j]=L->data[i];
    }
    L->data[i]=pivot;
    
}
//8.
void partitionSwap(SqList * &L){
    int i=0,j=L->length-1;
    while (i<j)
    {
        while(i<j && L->data[j]>=0)//找小于0的元素
            j--;
        while(i<j && L->data[i]<0) //找大于等于0的元素
            i++;
        if(i<j)
            swap(L->data[i],L->data[j]);
    }
}



int main(){
    SqList *l1;
    ElemType a[]={1,2,-6,4,-9,8,-7,-8,9};
    int n = 9;
    CreateList(l1,a,n);
    printf("-----第8题修改前-----\n");
    DispList(l1);
    partitionSwap(l1);
    printf("-----第8题修改后-----\n");
    DispList(l1);
    DestroyList(l1);
    
}

// int main(){
//     SqList *l1;
//     ElemType a[]={7,9,8,6,4,1,2,2,1};
//     int n = 9;
//     //InitList(l1);
//     CreateList(l1,a,n);
//     DispList(l1);
//     partition2(l1);
    
//     DispList(l1);
//     DestroyList(l1);
    
// }
// int main(){
//     SqList *l1;
//     ElemType a[]={1,2,3,4,5,6,7,8,9};
//     int n = 9;
//     //InitList(l1);
//     CreateList(l1,a,n);
//     printf("");
//     DispList(l1);
//     ElemType x=67;
//     ListInsert(l1,5,x);
//     DispList(l1);
//     ListDelete(l1,6,x);
//     DispList(l1);
//     cout<<x;
//     DestroyList(l1);
    
// }
