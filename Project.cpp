#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class hotel
{
public:
    int rno;
    char type,vac;
    double price;
    void inm()
    {   cout<<"Enter room number \n";
        cin>>rno;
        cout<<"Enter type of room R/D \n";
        cin>>type;
        cout<<"Enter vacancy status V/O \n";
        cin>>vac;
        cout<<"Enter price \n";
        cin>>price;
    }
    void modm()
    {
    	cout<<"Type R/D \n";
    	cin>>type;
    	cout<<"Price \n";
    	cin>>price;
    }
    int rtn()
    {
    	return rno;
    }
    char rtv()
    {
    	return vac;
    }
    void outm()
    {
    	cout<<"\nRoom No. "<<rno<<endl<<"Type "<<type<<endl;
    	cout<<"Vacancy "<<vac<<endl<<"Price "<<price<<"\n"<<endl;
    }
}h;
class customer : public hotel
{
	int id,meal;
	long long int phno;
	char name[30];
public:
	void inc(hotel h)
    {
    	cout<<"\nEnter name \n";
    	fflush(stdin);
    	gets(name);
    	cout<<"Enter identification number \n";
    	cin>>id;
    	cout<<"Enter phone number \n";
    	cin>>phno;
    	h.vac='o';
    	rno=h.rno;
    	type=h.type;
    	price=h.price;
    }
    void outc()
    {
    	cout<<"\nRoom No. "<<rno<<endl<<"Type "<<type<<endl;
    	cout<<"Occupied by "<<name<<endl<<"Phone No."<<phno<<"\n"<<endl;
    }
    void modc()
    {
    	cout<<"Enter identification number \n";
    	cin>>id;
    	cout<<"Enter phone number \n";
    	cin>>phno;
    }
    float bill()
    {
    	cout<<"Cost of meals eaten + Cost of lodging. \n";
    	cout<<"Number of meals eaten = \n";
    	cin>>meal;
    	cout<<"Cost per meal = ";
    	if(h.type=='D' || h.type=='d')
			cout<<"1000";
		else
			cout<<"700";
        cout<<"\n";
    	cout<<"Cost of Room = "<<price<<"\n";
    	cout<<"Your total bill is : \n";
    	if(h.type=='D' || h.type=='d')
			return (price+(700*float(meal)));
		else
			return (price+(700*float(meal)));
    }
}c;
main()
{
    int a,b,n,no;
    char y,z;
    fstream afile,bfile;
A:  system("cls");
	cout<<"Welcome to C Group of Hotels. - CO21340\n1: Manager \n2: Customer \n";
    cin>>a;
    switch(a)
    {
        case 1: system("cls");
				B: cout<<"1: Add rooms, 2: Modify details of the rooms, 3: Delete rooms, 4: View the details of all the rooms, 5: Delete All Data \n";
                cin>>b;
                switch(b)
                {
                    case 1: cout<<"Number of rooms? \n";
							cin>>n;
							afile.open("Manager.dat",ios::binary | ios::app | ios::out);
							for(int i=0;i<n;i++)
							{
								h.inm();
								afile.write((char*)&h,sizeof(hotel));
							}
							afile.close();
							cout<<"Do you want to continue as manager? Y/N ";
							cin>>y;
							if(y=='Y' || y=='y')
								goto B;
							else
								break;
					case 2: cout<<"Room to be modified? \n";
							cin>>no;
							afile.open("Manager.dat",ios::binary | ios::in);
							bfile.open("Temp.dat",ios::binary | ios::app | ios::out);
							while(afile.read((char*)&h,sizeof(hotel)))
							{
								if(h.rtn()==no)
									h.modm();
								bfile.write((char*)&h,sizeof(hotel));
							}
							afile.close();
							bfile.close();
							cout<<"Details modified";
							remove("Manager.dat");
							rename("Temp.dat","Manager.dat");
							cout<<"\nDo you want to continue as manager? Y/N ";
							cin>>y;
							if(y=='Y' || y=='y')
								goto B;
							else
								break;
					case 3: cout<<"Which Room is to be deleted? \n";
							cin>>no;
							afile.open("Manager.dat",ios::binary | ios::in);
							bfile.open("Temp.dat",ios::binary | ios::app | ios::out);
							while(afile.read((char*)&h,sizeof(hotel)))
								if(h.rtn()!=no)
									bfile.write((char*)&h,sizeof(hotel));
							afile.close();
							bfile.close();
							cout<<"Room deleted";
							remove("Manager.dat");
							rename("Temp.dat","Manager.dat");
							cout<<"\nDo you want to continue as manager? Y/N ";
							cin>>y;
							if(y=='Y' || y=='y')
								goto B;
							else
								break;
					case 4: afile.open("Manager.dat",ios::binary | ios::in);
							while(afile.read((char*)&h,sizeof(hotel)))
								h.outm();
							afile.close();
							cout<<"Do you want to continue as manager? Y/N ";
							cin>>y;
							if(y=='Y' || y=='y')
								goto B;
							else
								break;

                    case 5: cout<<"Are you sure?";
                            cin>>y;
							if(y=='Y' || y=='y')
                                {
                                    remove("Manager.dat");
                                    remove("Customer.dat");
                                    remove("Temp.dat");
								goto A;
                                }
							else
								break;
                }
                cout<<"Do you want to continue the program? Y/N ";
				cin>>z;
				if(z=='y' || z=='Y')
					goto A;
				else
					exit(0);
		case 2: system("cls");
				C: cout<<"1: Check in, 2: View guest list, 3: Modify own details, 4: Generate bill \n";
				cin>>b;
				switch(b)
				{
					case 1: D: cout<<"Which of the following room are you interested in? \nThe price of the room is flat rate as mentioned\nThe price per meal in Room is 700\n";
                            afile.open("Manager.dat",ios::binary | ios::in);
							while(afile.read((char*)&h,sizeof(hotel)))
								h.outm();
							afile.close();
							cin>>no;
							afile.open("Manager.dat",ios::binary | ios::in);
							bfile.open("Customer.dat",ios::binary | ios::app | ios::out);
							while(afile.read((char*)&h,sizeof(hotel)))
							{
								if(h.rtn()==no)
                                {   if(h.rtv()=='o' || h.rtv()=='O')
									{
										cout<<"Room unavailable, please choose another \n";
										afile.close();
                                        bfile.close();
										goto D;
									}
									else
									{
										c.inc(h);
										bfile.write((char*)&c,sizeof(customer));
										goto S;
									}
                                }
							}
							if(h.rtn()!=no)
                                {
                                    cout<<"There is no room number "<<no<<" \n";
                                    afile.close();
                                    bfile.close();
                                    cout<<"Do you want to choose another room? Y/N ";
                                        cin>>y;
                                        if(y=='Y' || y=='y')
                                            goto D;
                                        else
                                            {
                                                cout<<"Do you want to continue as customer? Y/N ";
                                                cin>>y;
                                                if(y=='Y' || y=='y')
                                                    goto C;
                                                else
                                                    goto F;
                                            };
                                }
							S:afile.close();
							bfile.close();
							afile.open("Manager.dat",ios::binary | ios::in);
							bfile.open("Temp.dat",ios::binary | ios::app | ios::out);
							while(afile.read((char*)&h,sizeof(hotel)))
							{
								if(h.rtn()==no)
									h.vac='o';
								bfile.write((char*)&h,sizeof(hotel));
							}
							afile.close();
							bfile.close();
							cout<<"Details modified\n";
							remove("Manager.dat");
							rename("Temp.dat","Manager.dat");
							cout<<"Do you want to continue as customer? Y/N ";
							cin>>y;
							if(y=='Y' || y=='y')
								goto C;
							else
								break;
					case 2:	afile.open("Customer.dat",ios::binary | ios::in);
							while(afile.read((char*)&c,sizeof(customer)))
								c.outc();
							afile.close();
							cout<<"Do you want to continue as customer? Y/N ";
							cin>>y;
							if(y=='Y' || y=='y')
								goto C;
							else
								break;
					case 3: cout<<"Room number? ";
							cin>>no;
							afile.open("Customer.dat",ios::binary | ios::in);
							bfile.open("Temp.dat",ios::binary | ios::app | ios::out);
							while(afile.read((char*)&c,sizeof(customer)))
							{
								if(c.rtn()==no)
									c.modc();
								bfile.write((char*)&c,sizeof(customer));
							}
							afile.close();
							bfile.close();
							remove("Customer.dat");
							rename("Temp.dat","Customer.dat");
							cout<<"Do you want to continue as customer? Y/N ";
							cin>>y;
							if(y=='Y' || y=='y')
								goto C;
							else
								break;
					case 4: cout<<"Room number? ";
							cin>>no;
							afile.open("Customer.dat",ios::binary | ios::in);
							while(afile.read((char*)&c,sizeof(customer)))
								if(c.rtn()==no)
									cout<<"\nTotal bill = "<<c.bill();
							afile.close();
							afile.open("Manager.dat",ios::binary | ios::in);
							bfile.open("Temp.dat",ios::binary | ios::app | ios::out);
							while(afile.read((char*)&h,sizeof(hotel)))
							{
								if(h.rtn()==no)
									h.vac='v';
								bfile.write((char*)&h,sizeof(hotel));
							}
							afile.close();
							bfile.close();
							remove("Manager.dat");
							rename("Temp.dat","Manager.dat");
							afile.open("Customer.dat",ios::binary | ios::in);
							bfile.open("Temp.dat",ios::binary | ios::app | ios::out);
							while(afile.read((char*)&c,sizeof(customer)))
								if(c.rtn()!=no)
                                    bfile.write((char*)&c,sizeof(customer));
							afile.close();
							bfile.close();
							remove("Customer.dat");
							rename("Temp.dat","Customer.dat");
							cout<<"\nDo you want to continue as customer? Y/N ";
							cin>>y;
							if(y=='Y' || y=='y')
								goto C;
							else
								break;
				}
				F:cout<<"Do you want to continue the program? Y/N ";
				cin>>z;
				if(z=='y' || z=='Y')
					goto A;
				else
					exit(0);
    }
}
