function [x,val,k]=grad(fun,gfun,x0)
%
maxk=5000;
rho=0.5; sigma=0.4;
k=0; epsilon=1e-5;
while(k<maxk)
    g=feval(gfun,x0);
    d=-g;
    if(norm(d)<epsilon),break; end
    m=0;mk=0;
    while(m<20)
        if(feval(fun,x0+rho^m*d)<feval(fun,x0)+sigma*rho^m*g'*d)
            mk=m;
            break;
        end
        m=m+1;
    end
    x0=x0+rho^mk*d;
    k=k+1;
end
x=x0;
val=feval(fun,x0);


%function f=fun(x)
%f=2*x(1)^2+x(2)^2;
%function g=gfun(x)
%g=[4*x(1),2*x(2)]';

