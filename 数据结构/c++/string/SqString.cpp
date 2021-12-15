/*
 * @Author: your name
 * @Date: 2021-11-05 16:19:26
 * @LastEditTime: 2021-12-09 16:11:51
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \c++\string\SqString.cpp
 */
#include<iostream>
using namespace std;
#define MaxSize 10
typedef struct{//非紧缩格式的顺序串
    char data[MaxSize];
    int length;
}SqString;

void StrAssign(SqString &s,char cstr[]){
    int i;
    for(i=0;cstr[i]!='\0';i++)
        s.data[i]=cstr[i];    
    s.length=i;
}
void DestroyStr(SqString &s){
    
}

void StrCopy(SqString &s,SqString t){
    int i;
    for(i=0;i<t.length;i++)
        s.data[i]=t.data[i];
    s.length=t.length;
}
bool StrEqual(SqString s,SqString t){
    bool same = true; 
    int i;
    if(s.length!=t.length)
        same=false;
    else
        for ( i = 0; i < s.length; i++)
        {
            if (s.data[i]!=t.data[i])
            {
                same=false;
                break;
            }
            
        }
    return same;       
}
int StrLength(SqString s){
    return s.length;
}
SqString Concat(SqString s,SqString t){
    SqString str;
    int i;
    str.length=s.length+t.length;
    for ( i = 0; i < s.length; i++)
    {
        str.data[i]=s.data[i];
    }
    for ( i = 0; i < t.length; i++)
    {
        str.data[s.length+i]=t.data[i];
    }
    return str;
    
}

SqString SubStr(SqString s,int i,int j){//求子串
    int k;
    SqString str;
    str.length=0;
    if (i<0 || i>s.length || j<0 || i+j-1>s.length)
    {
        return str;
    }
    for(k=i-1;k<i+j-1;k++)
        str.data[k-i+1]=s.data[k];
    str.length=j;
    return str;
}

SqString InsStr(SqString s1,int i,SqString s2){
    int j;
    SqString str;
    str.length = 0;
    if (i<=0 || i>s1.length+1)
    {
        return str;
    }
    for(j=0;j<i-1;j++)
        str.data[j]=s1.data[j];
    for(j=0;j<s2.length;j++)
        str.data[i+j-1]=s2.data[j];
    for(j=i-1;j<s1.length;j++)
        str.data[s2.length+j]=s1.data[j];
    str.length=s1.length+s2.length;
    return str;
}
SqString DelStr(SqString s,int i, int j){
    int k;
    SqString str;
    str.length = 0;
    if(i<=0 || i>s.length ||i+j>s.length+1)//也可用 i+j-1>s.length
        return str;
    for(k=0;k<i-1;k++)
        str.data[k]=s.data[k];
    for(k=i+j-1;k<s.length;k++)
        str.data[k-j]=s.data[k];
    str.length=s.length-j;
    return str;
}

SqString RepStr(SqString s,int i,int j,SqString t){
    //把从i开始的j个字符用t替换
    int k;
    SqString str;
    str.length=0;
    if(i<=0 || i>s.length || i+j-1>s.length)
        return str;
    for(k=0;k<i-1;k++){
        str.data[k]=s.data[k];
    }
    for(k=0;k<t.length;k++)
        str.data[k+i-1]=t.data[k];
    for(k=i+j-1;k<s.length;k++)
        str.data[t.length+k-j]=s.data[k];
    str.length = s.length-j+t.length;
    return str;


}

void DispStr(SqString s){
    int i;
    if (s.length>0)
    {
        for(i=0;i<s.length;i++)
            printf("%c",s.data[i]);
        printf("\n");
    }
    
}

int BF(SqString s,SqString t){
    int i=0,j=0;
    while (i<s.length && j<t.length)
    {
        if(s.data[i]==t.data[j]){
            i++;
            j++;
        }else{
            i=i-j+1;
            j=0;
        }
    }
    if (j>=t.length)
    {
        return(i-t.length);
    }else
        return(-1);
    
}


void GetNext(SqString t,int next[]){
    int j,k;
    j=0;k=-1;next[0]=-1;
    while (j<t.length-1)//因为j<k
    {
       if(k==-1 || t.data[j]==t.data[k]){
           j++;k++;
           next[j]=k;
       }
       else k=next[k];
    }
    
}

int KMPIndex(SqString s,SqString t){
    int next[MaxSize],i=0,j=0;
    GetNext(t,next);
    while (i<s.length && j<t.length)
    {
        if (j == -1 || s.data[i]==t.data[j])
        {
            i++;
            j++;
        }
        else j = next[j];//模式串右滑
    }
    if (j>=t.length)
    {
        return(i-t.length);//返回子串位置
    }
    else
    {
        return(-1);
    }
    
}