function [fv, bestx, iter_num] = conjungate_gradient(f, x, x0, epsilon, show_detail)
%% conjungate gradient method
% by TomHeaven, hanlin_tan@nudt.edu.cn, 2015.08.25
% Input: 
%   f - syms function  初始函数
%   x - row cell arrow for input syms variables  x1 x2  哪几个变量
%   $x_0$ - init point 初始值点
%   epsilon - tolerance 误差大小
%   show_detail - a boolean value for wether to print details是否打印详细信息的布尔值
% Output:
%   fv - minimum f value 最小值
%   bestx - mimimum point 最小点
%   iter_num - iteration count 迭代次数

%% init
syms lambdas  % suffix s indicates this is a symbol variable

% n is the dimension
n = length(x);

% compute differential of function f stored in cell nf
nf = cell(1, n); % using row cells, column cells will result in error
for i = 1 : n
    nf{i} = diff(f, x{i});
end

% $\nabla f(x_0)$
nfv = subs(nf, x, x0);
% init $\nabla f(x_k)$
nfv_pre = nfv;
% init count, k and xv for x value.
count = 0;
k = 0;
xv = x0;
% initial search direction
d = - nfv; 
% show initial info
if show_detail
    fprintf('Initial:\n');
    fprintf('f = %s, x0 = %s, epsilon = %f\n\n', char(f), num2str(x0), epsilon);
end

%% loop
while (norm(nfv) > epsilon)
    %% one-dimensional search
    % define $x_{k+1} = x_{k} + \lambda d$
    xv = xv+lambdas*d;
    % define $\phi$ and do 1-dim search
    phi = subs(f, x, xv);
    nphi = diff(phi); % $\nabla \phi$
    lambda = solve(nphi);
    % get rid of complex and minus solution
    lambda = double(lambda);  
    if length(lambda) > 1
        lambda = lambda(abs(imag(lambda)) < 1e-5);
        lambda = lambda(lambda > 0);
        lambda = lambda(1);
    end
    % if $\lambda$ is too small, stop iteration
    if lambda < 1e-5
        break;
    end

    %% update
    % update $x_{k+1｝ = x_{k} + \lambda d$
    xv = subs(xv, lambdas, lambda); 
    % convert sym to double
    xv = double(xv);
    % compute the differential
    nfv = subs(nf, x, xv);   
    % update counters
    count = count + 1;
    k = k + 1; 
    % compute alpha based on FR formula
    alpha = sumsqr(nfv) / sumsqr(nfv_pre);

    % show iteration info
    if show_detail
        fprintf('Iteration: %d\n', count);
        fprintf('x(%d) = %s, lambda = %f\n', count, num2str(xv), lambda);
        fprintf('nf(x) = %s, norm(nf) = %f\n', num2str(double(nfv)), norm(double(nfv)));
        fprintf('d = %s, alpha = %f\n', num2str(double(d)), double(alpha));
        fprintf('\n');
    end

    % update conjungate direction
    d = -nfv + alpha * d;
    % save the previous $$\nabla f(x_k)$$
    nfv_pre = nfv;
    % reset the conjungate direction and k if k >= n
    if k >= n
        k = 0;
        d = - nfv;
    end
end % while

%% output
fv = double(subs(f, x, xv));
bestx = double(xv);
iter_num = count;

end