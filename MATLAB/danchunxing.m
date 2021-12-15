%求解单纯形,还没有理解
function [ X, Z] = danchunxing( A, B, C ,D)
flag = 1;
S=0;
Z=0;
[m, n] = size(A);
BIndex = n - m  + 1 : n;             
if D==0                            
C=-C;
    end
    if (n < m)
    disp('系数矩阵不符合要求！')
    else
        while flag
            Cb = C(BIndex);             
            Zj = (Cb)*A;
            Rj =C-Zj;                   
            X = zeros(1, n);
            if max(Rj)<=0
            for i=1:m
                   X(BIndex(i))=B(i);
            end
            for i=1:n
                Z=Z+(C(i)*X(i));
            end
               flag = 0;
               fprintf('迭代次数为:%d\n',S);
               disp('已找到最优解：')
               S=0;
               break;
            else
                S=S+1;
                 [~, k1] = max(Rj); 
                 for i=1:m
                     if A(i,k1)>0
                        P(i)=B(i)/A(i,k1);
                     else 
                        P(i)=inf;
                     end   
                 end
                [~, k2]=min(P);    
                BIndex(k2)=k1;    
                E=[B,A];          
                E(k2,:)=E(k2,:)/E(k2,k1+1); 
                for i=1:m                   
                  if(i==k2)
                      continue;
                  end
                    while(1)
                        E(i,:)= E(i,:)-E(i,k1+1)*E(k2,:);
                        if(E(i,k1+1)==0)
                        break;
                        end
                    end
                    B=E(1:m,1);
                    A=E(1:m,2:n+1);
               end
            end
        end
    end
end
% A=[3 2 -3 0;1 -2 1 1];
% B=[6;4];
% C=[-3 1 2 0];
% D=0;

% A=[1 1 -2 1;2 -1 4 0;-1 2 -4 0];
% B=[10;8;4];
% C=[1 -2 1 0];
%D=0;