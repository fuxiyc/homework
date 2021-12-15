function [min_x,min_f,k]=ConjugateGradient(f,x0,var,eps)

j=jacobian(f,var);
h=jacobian(j,var);
x=x0;
k=0;
flag=1;  
while flag
    g=(double(subs(j,var,x)));
    hh=(double(subs(h,var,x)));
    if (norm(g,2)>eps )
        if(k==0)
            p=-g;
            k=1;
        else
            a=(g*hh*p')/(p*hh*p');
            p=(-g'+a*p')';
        end
        alpha=-(g*(p'))/(p*hh*(p'));
        x=(x'+alpha*p')';
        %if(k==2)
       %     break
       % end
        k=k+1;
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