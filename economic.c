alpha=[500;400;200];
beta=[5.3;5.2;5.8];
gamma=[0.004;0.006;0.009];
PD=800;
DelP=10;
lamda=input('Enter the Estimated value of lamda :');
fprintf('');
disp(['lamda P1 P2 P3 DP grad Delamda']);
iter=0;
while (abs(DelP)>=0.001)
    iter=iter+1;
    P=(lamda-beta)./(2*gamma);
    DelP=PD-sum(P);
    j=sum(ones(length(gamma),1)./(2*gamma));
    Delamda=DelP/j;
    disp([lamda,P(1),P(2),P(3),DelP,j,Delamda]);
    lamda=lamda+Delamda;
end
totalcost=sum(alpha+beta.*P + gamma.*P.^2)
