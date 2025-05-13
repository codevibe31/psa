Zdata=[0 1 0 0.1
    0 2 0 0.8
    1 2 0 0.4
    1 3 0 0.2
    2 3 0 0.2
    3 4 0 0.8];
nl=Zdata(:,1);
nr=Zdata(:,2);
R=Zdata(:,3);
X=Zdata(:,4);
nbr=length(Zdata(:,1));
nbus=max(max(nl,max(nr)));
Z=R+j*X;
y=1./Z;
Y=zeros(nbus,nbus);
for k=1:nbr
    if(nl(k)>0 && nr(k)>0)
        Y(nl(k),nr(k))=Y(nl(k),nr(k))-y(k);
        Y(nr(k),nl(k))=Y(nl(k),nr(k));
    end
end
for n=1:nbus
    for k=1:nbr
        if (nl(k)==n||nr(k)==n)
            Y(n,n)=Y(n,n)+y(k);
        end
    end
end
fprintf('The Y Bus Matrix is :');
disp(Y);