function [min_x,min_f,k]=newtons(f,x0,var,eps)
%%%输入目标函数f,初始点x0,以及自变量var和精度eps
%%%利用Newton迭代法计算无约束目标函数极小值；
%%%输出最小值点min_x,最小值min_f以及迭代次数k。

j=jacobian(f,var);                            %计算函数的雅可比矩阵， 知识点：梯度恰好是雅可比矩阵的转置；;
h=jacobian(j,var);
falg=1;                          
x=x0;
k=0;                                          %计数器；
while falg
    g=(double(subs(j,var,x)));     %subs函数；求 梯度值g   用x的值替换j中var的值
    if norm(g,2)>eps                 %算法停止标准；求范数
        hh=inv((double(subs(h,var,x))));
        x=double(x'-hh*g')';                 %产生新迭代点；
        k=k+1;
    else
        break
    end
end
min_x=x';                                      %最优解
min_f=subs(f,var,min_x');                      %目标函数最小值。


% syms x1 x2;
%f=x1^2+2*x2^2
%x0=[2 2];
% eps=0.001;
%var=[x1,x2];
%[min_x,min_f,k]=newtons(f,x0,var,eps)
