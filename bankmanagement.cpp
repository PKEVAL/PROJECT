#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
struct Bank{
     string f_name,l_name,ph_no,address,cnic;
     int amount;
     Bank():f_name(""),l_name(""),ph_no(""),address(""),cnic(""),amount(0){

     }

       void welcome()
       {
        cout<<"\t\t\t\t\tMy Banking System\t\t\t\t\t \n"<<endl;
       }
       void info()
       {
        cout<<"Enter Your First Name: "; cin>>f_name;
        cout<<"Enter Your Last Name: "; cin>>l_name;
        cout<<"Enter Your Phone No Name: "; cin>>ph_no;
        cout<<"Enter Your Address: "; cin>>address;
        cout<<"Enter Your CNIC: "; cin>>cnic;

       }
       void display()
       {
        cout<<"Your First Name: "<< f_name <<endl;
        cout<<"Your Last Name: "<< l_name<<endl;
        cout<<"Your Phone No Name: " << ph_no<<endl;
        cout<<"Your Address: " << address<<endl;
        cout<<"Your CNIC: " << cnic<<endl;
        cout<<"Your Current Amount: "<<amount<<endl;
       } 
};
int main()
{
    int key;
    Bank b;
    do{
    b.welcome();
    cout<<"Please select one option from below menu. \n\n";
   c: cout<<"1. Account Open. \n2. Deposit Amount. \n3. Withdraw Amount. \n4. Check Balance. \n";
    cout<<"5. Upadate Record. \n6. Delete Record. \n7. Search Record. \n8. Exit."<<endl;
    
        cout<<"Please Enter Your Choice : ";
        cin>>key;
        if(key == 1)
        {
            b.info();
            ofstream f("D:\\C++\\PROJECT2\\Reg_user.dat",ios::app);
            f.write((char*)&b,sizeof(b));
            f.close();
            b.display();
            Sleep(5000);
            system("cls");
        }
        else if(key==2)
        {
            string nam;
            int am,count=0;
            cout<<"Please Enter Your First Name :"; cin>>nam;
            ifstream u("D:\\C++\\PROJECT2\\Reg_user.dat");
            while(u.read((char*)&b,sizeof(b)))
            {
                if(nam== b.f_name)
                {
                    ofstream f("D:\\C++\\PROJECT2\\Reg_user1.dat",ios::app);
                    cout<<"Name of account holeder is: "<<b.f_name <<" "<<b.l_name <<endl;
                    cout<<"Current amount: "<<b.amount<<endl;
                    cout<<"Please enter new amount: "; cin>>am;
                    b.amount += am;
                    
                    f.write((char*)&b,sizeof(b));
                    ifstream u("D:\\C++\\PROJECT2\\Reg_user.dat");
                    while(u.read((char*)&b,sizeof(b)))
                    {
                        if(nam != b.f_name )
                        {
                                f.write((char*)&b,sizeof(b));
                        }
                    }f.close();count+=1;
                }
                else
                {
                    cout<<"Computer iS either serching or wasn't able to find your record. \n";
                }
            }
            Sleep(5000);
            system("cls");
            u.close();
            if(count>=1)
            {
            remove("D:\\C++\\PROJECT2\\Reg_user.dat");
            rename("D:\\C++\\PROJECT2\\Reg_user1.dat","D:\\C++\\PROJECT2\\Reg_user.dat");
            }
        }
        else if(key==3)
        {
             string nam;
            int am,count=0;
            cout<<"Please Enter Your First Name :"; cin>>nam;
            ifstream u("D:\\C++\\PROJECT2\\Reg_user.dat");
            while(u.read((char*)&b,sizeof(b)))
            {
                if(nam== b.f_name)
                {
                    ofstream f("D:\\C++\\PROJECT2\\Reg_user1.dat",ios::app);
                    cout<<"Name of account holeder is: "<<b.f_name <<" "<<b.l_name <<endl;
                    cout<<"Current amount: "<<b.amount<<endl;
               a:     cout<<"Please enter withdraw amount: "; cin>>am;
                    if(am < b.amount)
                    {
                    b.amount -= am;
                    count+=1;
                    }
                    else
                    {
                        cout<<"Withdraw amout is more than available amount.\n";
                        goto a;
                    }
                    f.write((char*)&b,sizeof(b));
                    ifstream u("D:\\C++\\PROJECT2\\Reg_user.dat");
                    while(u.read((char*)&b,sizeof(b)))
                    {
                        if(nam != b.f_name )
                        {
                                f.write((char*)&b,sizeof(b));
                        }
                    }f.close();
                }
                else
                {
                    cout<<"Computer iS either serching or wasn't able to find your record. \n";
                }
            }
            Sleep(5000);
            system("cls");
            u.close();
            if(count>=1)//if name is not serach then file not delete
            {
            remove("D:\\C++\\PROJECT2\\Reg_user.dat");
            rename("D:\\C++\\PROJECT2\\Reg_user1.dat","D:\\C++\\PROJECT2\\Reg_user.dat");
            }
        }
        else if(key==4)
        {
            string nam;
            cout<<"Please Enter Your First Name :"; cin>>nam;
            ifstream u("D:\\C++\\PROJECT2\\Reg_user.dat");
            while(u.read((char*)&b,sizeof(b)))
            {
                if(nam== b.f_name)
                {
                    cout<<"Name of account holeder is: "<<b.f_name <<" "<<b.l_name <<endl;
                    cout<<"Current amount: "<<b.amount<<endl;
                }
                else
                {
                    cout<<"Computer iS either serching or wasn't able to find your record. \n";
                }
            }
            Sleep(5000);
            system("cls");
            u.close();
           
        }
        else if(key==5)
        {
                string nam;
                char ke,option;
            int am,count=0;
            cout<<"Please Enter Your First Name :"; cin>>nam;
            ifstream u("D:\\C++\\PROJECT2\\Reg_user.dat");
            while(u.read((char*)&b,sizeof(b)))
            {
                if(nam== b.f_name)
                {
                    b.display();
                    cout<<"==========================================================================================================\n";
                    ofstream f("D:\\C++\\PROJECT2\\Reg_user1.dat",ios::app);
             b:       cout<<"To upadate first name (press 'f'). \nTo upadate last name (press 'l'). \nTo upadate phone no (press 'p'). \nTo upadate address (press 'a'). \nTo upadate CNIC (press 'c'). \n";
                    cin>>ke;
                    if(ke=='f')
                    {
                        cout<<"Please enter your new first name: ";
                        cin>>b.f_name;
                    
                    f.write((char*)&b,sizeof(b));
                    ifstream u("D:\\C++\\PROJECT2\\Reg_user.dat");
                    while(u.read((char*)&b,sizeof(b)))
                    {
                        if(nam != b.f_name )
                        {
                                f.write((char*)&b,sizeof(b));
                        }
                    }
                    }
                    else if(ke=='l')
                    {
                      cout<<"Please enter your new last name: ";
                        cin>>b.l_name;
                    
                    f.write((char*)&b,sizeof(b));
                    ifstream u("D:\\C++\\PROJECT2\\Reg_user.dat");
                    while(u.read((char*)&b,sizeof(b)))
                    {
                        if(nam != b.f_name )
                        {
                                f.write((char*)&b,sizeof(b));
                        }
                    }   
                    }
                    else if(ke=='p')
                    {
                         cout<<"Please enter your new phoneno: ";
                        cin>>b.ph_no;
                    
                    f.write((char*)&b,sizeof(b));
                    ifstream u("D:\\C++\\PROJECT2\\Reg_user.dat");
                    while(u.read((char*)&b,sizeof(b)))
                    {
                        if(nam != b.f_name )
                        {
                                f.write((char*)&b,sizeof(b));
                        }
                    }
                    }
                    else if(ke=='a')
                    {
                         cout<<"Please enter your new address: ";
                        cin>>b.address;
                    
                    f.write((char*)&b,sizeof(b));
                    ifstream u("D:\\C++\\PROJECT2\\Reg_user.dat");
                    while(u.read((char*)&b,sizeof(b)))
                    {
                        if(nam != b.f_name )
                        {
                                f.write((char*)&b,sizeof(b));
                        }
                    }
                    }
                    else if(ke=='c')
                    {
                         cout<<"Please enter your new CNIC: ";
                        cin>>b.cnic;
                    
                    f.write((char*)&b,sizeof(b));
                    ifstream u("D:\\C++\\PROJECT2\\Reg_user.dat");
                    while(u.read((char*)&b,sizeof(b)))
                    {
                        if(nam != b.f_name )
                        {
                                f.write((char*)&b,sizeof(b));
                        }
                    }
                    }
                    cout<<"Do you want to upadate your record again ('y' / 'n'): ";
                    cin>>option;
                    if(option=='y')
                    {
                        goto b;
                    }
                    else
                    {
                    f.close();
                    count+=1;
                    }
                }
                else
                {
                    cout<<"Computer iS either serching or wasn't able to find your record. \n";
                }
            }
            Sleep(5000);
            system("cls");
            u.close();
            if(count>=1)//if name is not serach then file not delete
            {
            remove("D:\\C++\\PROJECT2\\Reg_user.dat");
            rename("D:\\C++\\PROJECT2\\Reg_user1.dat","D:\\C++\\PROJECT2\\Reg_user.dat");
            }
        
        }
        else if(key==6)
        {
          string nam;
          char ans;
            int count=0;
            cout<<"Please Enter Your First Name :"; cin>>nam;
            ifstream u("D:\\C++\\PROJECT2\\Reg_user.dat");
            while(u.read((char*)&b,sizeof(b)))
            {
                if(nam== b.f_name)
                {
                    ofstream f("D:\\C++\\PROJECT2\\Reg_user1.dat",ios::app);
                    cout<<"Name of account holeder is: "<<b.f_name <<" "<<b.l_name <<endl;
                    cout<<"Current amount is: "<<b.amount<<endl;
                    cout<<"Do you really want to delete the record ('y'/'n'): ";
                    cin>>ans;
                    if(ans=='y')
                    {
                    ifstream u("D:\\C++\\PROJECT2\\Reg_user.dat");
                    while(u.read((char*)&b,sizeof(b)))
                    {
                        if(nam != b.f_name )
                        {
                                f.write((char*)&b,sizeof(b));
                        }
                    }
                    }
                    else
                    {
                        goto c;
                    }
                    f.close();
                    count+=1;
                }
                else
                {
                    cout<<"Computer iS either serching or wasn't able to find your record. \n";
                }
            }
            Sleep(5000);
            system("cls");
            u.close();
            if(count>=1)//if name is not serach then file not delete
            {
            remove("D:\\C++\\PROJECT2\\Reg_user.dat");
            rename("D:\\C++\\PROJECT2\\Reg_user1.dat","D:\\C++\\PROJECT2\\Reg_user.dat");
            }
        }
        else if(key==7)
        {
            string nam;
            cout<<"Please Enter Your First Name :"; cin>>nam;
            ifstream u("D:\\C++\\PROJECT2\\Reg_user.dat");
            while(u.read((char*)&b,sizeof(b)))
            {
                if(nam== b.f_name)
                {
                   b.display();
                }
                else
                {
                    cout<<"Computer iS either serching or wasn't able to find your record. \n";
                }
            }
            Sleep(5000);
            system("cls");
            u.close();
        }
    }while(key != 8);
    system("cls");
    cout<<"\t\t\t\t Thank You Visiting Our Bank.\n\t\t\t\t\t\t";
    
}