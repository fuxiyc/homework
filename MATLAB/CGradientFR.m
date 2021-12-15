function [min_x,min_f,k]=CGradientFR(f,x0,var,eps)
%f=matlabFunction(f);% 将符号表达式转换为函数句柄或文件
f_sym = sym(f);% 将符号表达式转换为函数句柄或文件
j=jacobian(f,var);
j_td=matlabFunction(j);
h=jacobian(j,var);
x=x0;
k=0;
g0=0;
flag=1;

while flag
    g=(double(subs(j,var,x)));
    k=k+1;
    hh=(double(subs(h,var,x)));
    if (norm(g,2)>eps )
        if(k==0)
            p=-g
        else
            a=norm(g,2)^2/norm(g0,2)^2;
            p=(-g'+a*p')'
        end
     %   f_a=subs(ff,var,x+alp*p);
      %  f_diff=simplify(diff(f_a,alp));
      %  alpha=max(double(solve(f_diff)));
        [alpha_armijo] = armijo(x,p,f,j);
        x=(x'+alpha_armijo*p')'; 
        
        g0=g;
    else 
        break
    end
end
min_x=x';
min_f=subs(f,var,min_x');


%syms x1 x2;
%f=100*(x1^2-x2)^2+(x1-1)^2;
%
%
%
%