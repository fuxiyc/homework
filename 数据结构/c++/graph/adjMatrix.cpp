/*
 * @Author: your name
 * @Date: 2021-12-08 17:58:11
 * @LastEditTime: 2021-12-08 21:13:16
 * @LastEditors: Please set LastEditors
 * @Description: 邻接矩阵
 * @FilePath: \c++\graph\adjMatrix.cpp
 */
#include<iostream>
using namespace std;
#define MAXV 10     //最大顶点数;
typedef char InfoType;
#define INF 32767   //定义最大值
typedef struct{
    int no;         //顶点的编号
    InfoType info;  //顶点的其他信息
}VertexType;        //顶点的类型
typedef struct{
    int edges[MAXV][MAXV];  //邻接矩阵数组
    int n,e;                //顶点数,边数
    VertexType vexs[MAXV];  //存放顶点信息
}MatGraph;                  //完整的图邻接矩阵类型

void CreateMathGraph(MatGraph *&G){
    int i,j,k,w;
    G=(MatGraph *)malloc(sizeof(MatGraph));
    cout<<"输入顶点数和边数"<<endl;
    cin>>G->n>>G->e;
    for(i = 0;i < G->n; i++){
        cout<<"输入第"<<i+1<<"个顶点的信息"<<endl;
        cin>>G->vexs[i].info;
        G->vexs[i].no=i;
    }
}
void CreateAdj(MatGraph *&G,int A[MAXV][MAXV],int numVertexes,int numEdges){
    G=(MatGraph *)malloc(sizeof(MatGraph));
    G->n=numVertexes;G->e=numEdges;
    
    for(int i=0;i<numVertexes;i++){
        G->vexs[i].no=i;
    }
    for (int i = 0; i < numVertexes; i++)
    {
        for (int j = 0; j < numVertexes; j++)
        {
            G->edges[i][j]=A[i][j];
        }
    }
}

void InDs(MatGraph *&g){
    int i,j,n;
    cout<<"各顶点入度:"<<endl;
    for(j=0;j<g->n;j++){  //看第j列有没有元素
        n=0;
        for(i=0;i<g->n;i++)
            if(g->edges[i][j]!=0)
                n++;
        cout<<"顶点"<<j<<":"<<n<<endl;
    }
        
}

void OutDs(MatGraph *&g){
    int i,j,n;
    cout<<"各顶点出度:"<<endl; //看第i行有没有元素
    for(i=0;i<g->n;i++){
        n=0;
        for(j=0;j<g->n;j++)
            if(g->edges[i][j]!=0)
                n++;
        cout<<"顶点"<<i<<":"<<n<<endl;
    }
        
}
void ZeroOutDs(MatGraph *&g){
    int i,j,n;
    cout<<"出度为0的顶点:";
    for(i=0;i<g->n;i++){
        n=0;
        for(j=0;j<g->n;j++)
            if(g->edges[i][j]!=0)
                i++;

        if(n==0)
            cout<<i<<'\t';
            
    }
    printf("\n");
}


int main(){
    int n=7,e=12;
    int A[MAXV][MAXV]={
        {0,2,5,3,0,0,0},
        {0,0,2,0,0,8,0},
        {0,0,0,1,3,5,0},
        {0,0,0,0,5,0,0},
        {0,0,0,0,0,3,9},
        {0,0,0,0,0,0,5},
        {0,0,0,0,0,0,0}
    };
    MatGraph *G;
    CreateAdj(G,A,n,e);
    InDs(G);
    OutDs(G);
    ZeroOutDs(G);
    
}