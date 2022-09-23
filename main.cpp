#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <windows.h>

void menu();
void pascode();
void cpascode();


using namespace std;


class one {
public:
    virtual void get()=0;
    virtual void show()=0;
};


class info :public one{

public:
    char name[50],time[50];
    int num,age;
    void get(){

    system("cls");
    cin.sync();
    cout<<"\n enter the name = ";
    cin.getline(name,50);
    cout<<"\n enter the time = ";
    cin.getline(time,50);
    cout<<"\n enter the age = ";
    cin>>age;
    cout<<"\n enter the appoinment no = ";
    cin>>num;
    }
    void show(){
    cout<<"\n name = "<<name;
    cout<<"\n age = "<<age;
    cout<<"\n no = "<<num;
    cout<<"\n time = "<<time;
    }
};





class rana:public info {

public:
    info a1;
    void get ()
    {
        system("cls");
        ofstream out("rana.txt",ios:: app|ios::binary);
        a1.get();
        out.write((char*)&a1,sizeof(info));
        out.close();
        cout<<"your entry saved";
        getch();
        menu();


    }
    void show(){
    ifstream in("rana.txt");
    in.seekg(0, ios::end);
    if(in.tellg() == 0)
        {
        cout<<"\n\n no data in file";
        getch();
        menu();
    }
    else {
        while(!in.eof())
        {
            in.read((char*)&a1,sizeof(a1));
            a1.show();
        }
        in.close();
        getch();
        menu();
        }
    }
    };



    class ahmed:public info {

public:
    info a1;
    void get ()
    {
        system("cls");
        ofstream out("ahmed.txt",ios:: app|ios::binary);
        a1.get();
        out.write((char*)&a1,sizeof(info));
        out.close();
        cout<<"your entry saved";
        getch();
        menu();


    }
    void show(){
    ifstream in("ahmed.txt");
    in.seekg(0, ios::end);
    if(in.tellg() == 0)
        {
        cout<<"\n\n no data in fild";
        getch();
        menu();
    }
    else {
        while(!in.eof())
        {
            in.read((char*)&a1,sizeof(a1));
            a1.show();
        }
        in.close();
        getch();
        menu();
        }
    }
    };






    class moha:public info {

public:
    info a1;
    void get ()
    {
        system("cls");
        ofstream out("moha.txt",ios:: app|ios::binary);
        a1.get();
        out.write((char*)&a1,sizeof(info));
        out.close();
        cout<<"your entry saved";
        getch();
        menu();


    }
    void show(){
    ifstream in("moha.txt");
    in.seekg(0, ios::end);
    if(in.tellg() == 0)
        {

        cout<<"\n\n no data in fild";
        getch();
        menu();
    }
    else {
        while(!in.eof())
        {
            in.read((char*)&a1,sizeof(a1));
            a1.show();
        }
        cout<<"press enter to continue "<<endl;
        in.close();
        getch();
        menu();
        }
    }
    };

class staff : public one {

char all[999];
char name[50],age[20],sal[30],pos[20];
void get(){
ofstream out("staff.txt",ios::app);
{
    system("cls");
    cin.sync();
    cout<<"\n enter the name = ";
    cin.getline(name,50);
    cout<<"\n enter the age = ";
    cin.getline(age,20);
    cout<<"\n enter salary = ";
    cin.getline(sal,30);
    cout<<"\n enter the working position = ";
    cin.getline(pos,20);
}
    out<<"\n name = "<<name<<"\n age "<<age<<"\n salary"<<sal<<"\n working position"<<pos;
    out.close();
    cout<<"your information has saved\n";
    getch();
    menu();
}
void show()
{

    ifstream in("staff.txt");

    if(!in)
        {
        cout<<"\n\n no data in fild";
    }
    while(!(in.eof()))
        {
            in.getline(all,999);
            cout<<all<<endl;
        }

        in.close();
        cout<<"press enter to continue "<<endl;
        getch();
        menu();
        }

};
void call_dr(){
int choice;
cout<<"\n press 1 for rana \n press 2 for ahmed \n press 3 for moha ";
cin>>choice;
one *ptr;
rana s3;
ahmed s4;
moha s5;
if (choice == 1){
    ptr = &s3;
    ptr ->get();
}
else if (choice == 2){
    ptr = &s4;
    ptr ->get();
}
else if (choice == 3){
    ptr = &s5;
    ptr ->get();
}
else {cout<<"sorry invalid choise"<<endl;}
}




void menu()
{
    system ("cls");
    system("color FC");
    cout<<"1 for available doctor \n 2 for doctor appoinment \n 3 for saving staff \n 4 for checking patient \n 5 for checking staff info \n "<<endl;
    cout <<"enter your choise "<<endl;
    info a1;
    one *ptr;
    staff a2;
    int a;
    cin >>a;
    if (a==1){
        a1.get();
    }
    else if (a==2){
        call_dr();
    }
    else if (a==3){
        ptr = &a2;
        ptr->get();
    }
    else if (a==4){
        a1.show();
    }
    else if (a==5){
        ptr = &a2;
        ptr ->show();
    }
}


















int main()
{
    menu();
    return 0;
}
