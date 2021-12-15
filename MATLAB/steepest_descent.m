function [min_x,min_f,k]=steepest_descent(f,x0,var,eps)
%%%输入目标函数f,初始点x0,以及自变量var和精度eps
%%%利用Newton迭代法计算无约束目标函数极小值；
%%%输出最小值点min_x,最小值min_f以及迭代次数k。
syms a; %字符串或数值到符号的切换
ff=sym(f);
j=jacobian(f,var);                            %计算函数的雅可比矩阵，
falg=1;                           ... ！！！知识点：梯度恰好是雅可比矩阵的转置；
x=x0;
k=0;                                          %计数器；
while falg
    g=(double(subs(j,var,x)));       %subs函数；求pk没加负号  用x的值替换j中var的值
    if norm(g,2)>eps                 %算法停止标准；求范数
        f_a=subs(ff,var,x-a*g);   % f(x0+a*p0) 上面的pk没加负号在这加
        f_diff = simplify(diff(f_a,a));      %diff(s)差分求导数  simplify(s) 对表达式进行化简
        alpha = max(double(solve(f_diff)));   %solve 求解步长
        x=double(x-alpha*g);                  %产生新迭代点；
        k=k+1;
    else
        break
    end
end
min_x=x;                                      %最优解
min_f=subs(f,var,min_x);                      %目标函数最小值。


% syms x1 x2;
%f=2*x1^2+x2^2
%x0=[1 1];
% eps=0.1;
%var=[x1,x2];
%[min_x,min_f,k]=steepest_descent(f,x0,var,eps)
