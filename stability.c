clc
clear all
E=1.35;
V=1;
Pm=0.6;
X=0.65;
H=9.94;
D=0.138;
fo=60;
Pmax=E*V /X;
do=asin(Pm/Pmax);
Ps=Pmax*cos(do);
disp('Ps =' );
disp(Ps);
Wn=sqrt((3.14*60) / (H*Ps));
disp('Wn = ');
disp(Wn);
Z=D/2*sqrt((3.14*60) / (H*Ps));
disp('Z =');
disp(Z);
Wd=Wn*sqrt(1-Z^2);
disp('Wd =');
disp(Wd);
tan=1/(Wn*Z);
disp('tan =');
disp(tan);
th=acos(Z);
disp('th =');
disp(th);
Ddo=10*3.14 /180;
disp('Ddo =');
disp(Ddo);
t=0:0.01:3;
Dd=Ddo/sqrt(1-Z^2)*exp(-Z*Wn*t).*sin(Wn*t+th);
d=(do+Dd)*(180/3.14);
Dw=Wn*Ddo/sqrt(1-Z^2)*exp(-Z*Wn*t).*sin(Wd*t)
f=fo+Dw/(2*3.14);
subplot(2,1,1)
plot(t,d);
grid on
xlabel('time')
ylabel('delta degree ')
title('Vriation of rotor angle')
subplot(2,1,2)
plot(t,f);
grid on
xlabel('time')
ylabel('freq in hz ')
title('Vriation of generator freq')

