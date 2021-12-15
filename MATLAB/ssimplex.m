%  求解标准型线性规划:max c*x;s.t. A*x=b;x>=0 吧max加负号转换成min
% 本函数中的A是单纯初始表，包括:第一行为c，最后一行是初始的检验数，最后一列是资源向量b
%  N是初始的基变量的下标

%输出变量sol是最优解 val是最优值，kk是迭代次数

%%求最小值好像没问题了
function [sol,val,kk]=ssimplex(A,N)
[mA,nA]=size(A);%求行列大小
kk=0;    %  迭代次数
flag=1;
while flag
   kk=kk+1;
    if A(mA,:)<=0     %  已找到最优解 (第m行的元素小于零)
       flag=0;              %退出循环
       sol=zeros(1,nA-1);
       for i=1:mA-1
           sol(N(i))=A(i,nA);
       end
       val=A(mA,nA);   %加不加负号 题目求最小值val不加负号,求最大值val加负号
   else
       for i=1:nA-1 %从一开始循环到nA-1
           if A(mA,i)>0&A(1:mA-1,i)<=0   %  问题有无界解  有入基 无出基
               disp('have infinite solution!');
               flag=0;
               break;
           end
       end
       if flag       %   还不是最优表，进行转轴运算
           temp=0;
           for i=1:nA-1
               if A(mA,i)>temp  %求min 用大于  求max用小于
                   temp=A(mA,i);
                   inb=i;  %   进基变量的下标
               end
           end
           sita=zeros(1,mA-1);
           for i=1:mA-1
               if A(i,inb)>0
                   sita(i)=A(i,nA)/A(i,inb);
               end
           end
           temp=inf;
           for i=1:mA-1
               if sita(i)>0&temp>sita(i)       %找到最小的值           
                   temp=sita(i);
                   outb=i;   % 出基变量下标
               end
           end
           %  以下更新N
           for i=1:mA-1
               if i==outb
                   N(i)=inb;
               end
           end
           %  以下进行转轴运算
           A(outb,:)=A(outb,:)/A(outb,inb);
           for i=1:mA
               if i~=outb
                   A(i,:)=A(i,:)-A(outb,:)*A(i,inb);
               end
           end
       end
   end
end
% M=1000000;%求MIN用极大值,求max用极小值-M
% A=[3 2 -3 1 0 6;1 -2 1 0 1 4;4*M+3 -1 -2*M-2 0 0 10*M]
% N=[4 5]
% A=[1 1 -2 1 0 0 10;2 -1 4 0 1 0 8;-1 2 -4 0 0 1 4;-1 2 -1 0 0 0 0];
% N=[4 5 6];