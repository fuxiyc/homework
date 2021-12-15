/*
 * @Author: your name
 * @Date: 2021-12-08 18:07:48
 * @LastEditTime: 2021-12-08 23:34:37
 * @LastEditors: Please set LastEditors
 * @Description: 邻接表
 * @FilePath: \c++\graph\adjList.cpp
 */
#include<iostream>
using namespace std;
#define MAXV 10     //最大顶点数;
typedef int InfoType;
#define INF 32767
typedef struct ANode{
    int adjvex;             //该边的邻接点编号
    struct ANode *nextarc;  //
    int weight;
}ArcNode;
typedef struct Vnode{
    InfoType info;
    ArcNode *firstarc;
}VNode;
typedef struct{
    VNode adjlist[MAXV];
    int n,e;
}AdjGraph;

void CreateAdj(AdjGraph * &G,int A[MAXV][MAXV],int n,int e){
    int i,j;
    ArcNode *p;
    G=(AdjGraph *)malloc(sizeof(AdjGraph));
    // G=new AdjGraph;   //delete 
    for(i=0;i<n;i++){
        
    }
}