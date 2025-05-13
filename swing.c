E=input("Enter E :");
V=input("enter V : ");
pm=input("Enter Mechanical power : ");
H=input("Enter inertia constant :");
Xs=input('enter steady state reactance :');
Xdf=input('enter during fault reactance :');
Xaf=input('enter after fault reactance :');
tc=input('enter clearing time :');
tf=input('enter final time :');
delt=0.01;
pi=E*V / Xs;
paf= E*V / Xaf;
pdf = E*V / Xdf;
delw(1)=0;
t=0;
T(1)=0;
delc=asin(pm/pi);
delwc(1)=0;
i=2;
while(t <=tc)
    pa(i)=pm-(pdf*sin(delc(i-1)));
    delp(i)=delc(i-1)+delwc(i-1)*delt;
    delwp(i)=delwc(i-1)+(3.14*50 / H)*pa(i)*delt;
    pap(i)=pm-(pdf*sin(delp(i)));
    delc(i)=delc(i-1)+ 0.5*(delwc(i-1)+delwp(i))*delt;
    delwc(i)=delwc(i-1)+ 0.5*(3.14*50 / H)*(pa(i)+pap(i))*delt;
    t=t+delt;
    T(i)=t;
    i=i+1;
end
while(t > tc && t <= tf )
    pa(i)=pm-(paf*sin(delc(i-1)));
    delp(i)=delc(i-1)+delwc(i-1)*delt;
    delwp(i)=delwc(i-1)+(3.14*50 / H)*pa(i)*delt;
    pap(i)=pm-(paf*sin(delp(i)));
    delc(i)=delc(i-1)+ 0.5*(delwc(i-1)+delwp(i))*delt;
    delwc(i)=delwc(i-1)+ 0.5*(3.14*50 / H)*(pa(i)+pap(i))*delt;
    t=t+delt;
    T(i)=t;
    i=i+1;
end
plot(T,delc*180/3.14)
grid on
xlabel('time seconds');
ylabel('detla in radians');
title('SWING CURVE');

