
disp('...Zbus Matrix...');
n=input('Enter the number of Buses :');
Zbus=zeros(n,n);
t=1;
while t==1
    Zbus
    s=menu('Specify case no','New bus to ref bus','old bus to new bus','two old buses','old bus to ref bus','print','quit');
    switch s
        case{1}%%New bus to ref bus
            Zb=input('Enter the Impedance value :');
            Zbus=Zb;
        case{2}%%old bus to new bus
            k=input("Enter the starting bus no :");
            n=input('Enter the new Bus no :');
            Zb=input('Enter the impedance value :');
            for i=1:n
                if i==n
                    Zbus(n,n)=Zbus(k,k)+Zb;
                else
                    Zbus(i,n)=Zbus(i,k);
                    Zbus(n,i)=Zbus(k,i);
                end
            end
        case{3}%%Between two old buses
            a=input('Enter the 1st bus :');
            b=input('Enter the 2nd bus :');
            Zb=input('Enter the Impedance value :');
            m1=Zb+Zbus(a,a)+Zbus(b,b)-(2*Zbus(a,b));
            Ztemp=(1/m1)*((Zbus(:,a)-Zbus(:,b)))*((Zbus(a,:))-Zbus(b,:));
            Zbus=Zbus-Ztemp;
        case{4}%%Old bus to ref bus
            k=input('Enter the Starting bus :');
            Zb=input('Enter the impedance value :');
            m2=Zb+Zbus(k,k);
            Ztemp=(1/m2)*(Zbus(:,k))*(Zbus(k,:));
            Zbus=Zbus-Ztemp;
        case{5}%%print
            Zbus
        case{6}%%Quit
            'end program';
            t=0;
    end 
end