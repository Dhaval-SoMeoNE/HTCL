
/***************************************************************
*                       comments
***************************************************************/

/**********************************************************`*****
*                       LIST OF HEADER FILES                   *
***************************************************************/
#include<iostream.h>
#include<fstream.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<time.h>
#include<string.h>
#include<iomanip.h>
#include<math.h>
#include<process.h>
/***************************************************************
*                         GLOBAL VARIABLE                      *
***************************************************************/
int cor_x=-1,cor_y=-1,colour1=15,colour2=4,colour3=8,colour4=0;
time_t t;
/***************************************************************
*                       FUNCTION PROTOTYPE                     *
***************************************************************/
void mouse();
void exit_button();
int DetectMouse(void);
void InitMouse(void);
void ShowMouse(void);
void HideMouse(void);
void WhereMouse(int*,int*);
int ButtClicked(void);
int ButtReleased(void);
int book_display(int);
void ubuntu(int,int);
char mouse_click_for_dialoge_box(void);
int mouse_click_for_signin(void);
int mouse_click_for_setting(void);
int mouse_click_for_readbook(void);
int mouse_click_for_add_book(void);
int mouse_click_for_signup(void);
int mouse_click_for_regular_home(void);
int mouse_click_for_premium_home(void);
int mouse_click_for_admin_home(void);
int mouse_click_for_display(void);
int mouse_click_for_change_theme(void);
void loading(void);
void wrong_password(void);
void signin_sucess(void);
void issue_sucess(void);
void return_sucess(void);
void buy_sucess(void);
void sell_sucess(void);
void setting_button(int,int);
char return_confirm(void);
char sell_confirm(void);
char deletebook_confirm(void);
char deleteuser_confirm(void);
void logo(int,int,int,int);
void side_bar(void);
void account_created(void);
void book_added(void);
void credits(void);
void comment(int);
/***************************************************************
*                        CLASS DEFINATION                      *
***************************************************************/
class user
{
public:
    int user_id;
    char user_name[20];
    char user_pass[20];
    char contact[20];
    char dob[20];
    int member_type;
    long amount;
    int col[3];
    struct issue
    {
        int id;
        long double time;
    } book_issue[3];
    int book_buy_id[3];
    int liked[100];
    user(void);
    int get_data(void);
    void setting(void);
    void change_theme(void);
};
user::user()
{
    user_id=0;
    strcpy(user_name,"");
    strcpy(user_pass,"");
    strcpy(contact,"");
    strcpy(dob,"");
    member_type=-1;
    amount=0.0;
    book_issue[0].id=book_issue[1].id=book_issue[2].id=0;
    book_issue[0].time=book_issue[1].time=book_issue[2].time=0;
    book_buy_id[0]=book_buy_id[1]=book_buy_id[2]=0;
    col[0]=colour1;
    col[1]=colour2;
    col[2]=colour3;
    for(int i=0; i<100; i++)
        liked[i]=0;
}
int user::get_data()
{
    char pass[20],member[20],passch;
    strcpy(member,"");
    strcpy(pass,"");
    int x_out=120,y_out=100,i,mouse_signup=-1,dum=0,mouse_s=-1;
reenter:
    int check=0;
    clrscr();
    cleardevice();
    setcolor(1);
    settextstyle(0,0,3);
    outtextxy(240,40,"SIGN UP");
    rectangle(100,20,545,450);
    setcolor(5);
    for(i=94; i<=286; i+=32)
    {
        rectangle(275,i,520,i+19);
    }
    setcolor(9);
    settextstyle(0,0,1);
    outtextxy(x_out,y_out,"User_Name:");
    outtextxy(x_out,(y_out+32),"Password:");
    outtextxy(x_out,(y_out+64),"RE_Enter Password:");
    outtextxy(x_out,(y_out+98),"Contact_NO:");
    outtextxy(x_out,(y_out+125),"Date_Of_Birth:");
    outtextxy(x_out,(y_out+139),"(dd/mm/yyyy)");
    outtextxy(x_out,(y_out+157),"Membership_Type:");
    outtextxy(x_out,(y_out+170),"(regular,premium)");
    outtextxy(x_out,(y_out+191),"Enter Amount:");
    outtextxy(x_out,(y_out+205),"  (>5000)");
    setfillstyle(SOLID_FILL,8);
    bar(240,400,400,430);    //create account
    setcolor(15);
    outtextxy((x_out+135),(y_out+312),"Create_My_Account");
    exit_button();
signup_mouse:
    mouse();
    mouse_signup=mouse_click_for_signup();   //mouse for sinup
    switch( mouse_signup)
    {
    case 1:
        setfillstyle(SOLID_FILL,0);
        bar(278,96,518,110);
        gotoxy(36,7);
        cin.getline(user_name,20);
        break;
    case 2:
        setfillstyle(SOLID_FILL,0);
        bar(278,128,518,143);
        gotoxy(36,9);                                 //get password
        for(int dum1=0; dum1<20; dum1++)
            user_pass[dum1]='\0';
        dum=0;
        do
        {
            passch=getch();
            if(passch!=8&&passch!=13)
            {
                user_pass[dum++]=passch;
                cout<<"*";
            }
            else if(passch==8&&dum>0)
            {
                user_pass[--dum]='\0';
                setfillstyle(SOLID_FILL,0);
                bar(278,128,518,143);	 //password clear block
                gotoxy(36,9);
                for(dum1=0; dum1<dum; dum1++)
                {
                    cout<<"*";
                }
            }
        }
	while(passch!=13);
        break;
    case 3:
        setfillstyle(SOLID_FILL,0);
        bar(278,160,518,173);
        gotoxy(36,11);               //confir password
        for(dum1=0; dum1<20; dum1++)
            pass[dum1]='\0';
        dum=0;
        do
        {
            passch=getch();
            if(passch!=8&&passch!=13)
            {
                pass[dum++]=passch;
                cout<<"*";
            }
            else if(passch==8&&dum>0)
            {
                pass[--dum]='\0';
                setfillstyle(SOLID_FILL,0);
                bar(278,160,515,173);	 //password clear block
                gotoxy(36,11);
                for(dum1=0; dum1<dum; dum1++)
                {
                    cout<<"*";
                }
            }
        }
        while(passch!=13);
        break;
    case 4:
        setfillstyle(SOLID_FILL,0);
        bar(278,192,518,205);
        gotoxy(36,13);
        cin.getline(contact,20);
        break;
    case 5:
        setfillstyle(SOLID_FILL,0);
        bar(278,224,518,237);
        gotoxy(36,15);
        cin.getline(dob,20);
        break;
    case 6:
        setfillstyle(SOLID_FILL,0);
        bar(278,256,518,269);
        gotoxy(36,17);
        cin.getline(member,20);
        break;
    case 7:
        setfillstyle(SOLID_FILL,0);
        bar(278,288,518,301);
        gotoxy(36,19);
        cin>>amount;
        cin.ignore();
        break;
    case 8:
        return -1;
    case 9:
        goto check;
    default:
        goto  signup_mouse;
    }
    goto  signup_mouse;
signup_button:
    mouse();
    mouse_s=mouse_click_for_signup();
    switch( mouse_s)
    {
    case 8:
        return -1;
    case 9:
        goto check;
    default:
        goto  signup_button;
    }
check:
    cleardevice();
    user us;
    int check1=-1,checkd=0,d1;
    ifstream filinf2;
    filinf2.open("user",ios::in|ios::binary);
    filinf2.seekg(0);
    filinf2.read((char *) &us,sizeof(us));
    if(strcmp(user_name,us.user_name)==0)
    {
        check1=0;
    }
    filinf2.seekg(0);
    if(strcmp(member,"admin")==0)
    {
        while(filinf2)
        {
            filinf2.read((char *) &us,sizeof(us));
            if(us.member_type==0)
            {
                outtextxy(150,250,"ADMINISTRATOR ACCOUNT CANNTO BE CREATED");
                mouse();
                goto reenter;
            }
        }
    }
    if(check1==0)
    {
        check=0;
        outtextxy(150,250,"User name already used");
        mouse();
        goto reenter;
    }
    if(strcmp(user_name,"")==0||strcmp(user_pass,"")==0||
            strcmp(dob,"")==0||strcmp(member,"")==0||strcmp(pass,"")
            ==0||strcmp(contact,"")==0)
    {
        cout<<"\nPlease fill all details...";
        check=-1;
    }
    else if(strcmp(user_pass,pass)!=0)
    {
        cout<<"\nPassworddoes not match...";
        check=-1;
    }
    else if((strcmp(member,"regular")!=0)&&(strcmp(member,"premium")!=0)
            &&(strcmp(member,"admin")!=0))
    {
        cout<<"\nMembership type must be 'regular' or 'premium'...";
        check=-1;
    }
    else if(amount<5000)
    {
        cout<<"\nAmount must be greater than 5000.";
        check=-1;
    }
    else if(strlen(contact)!=10)
    {
        cout<<"\nInvalid contact number....";
        check=-1;
    }
    else if(strlen(dob)==10)
    {
        int day,mon,year,date[10];
        if(dob[2]!=47||dob[5]!=47)
        {
            checkd=-1;
            goto end;
        }
        for(i=0; i<10; i++)
        {
            date[i]=dob[i];
            date[i]-=48;
        }
        day=(date[0]*10)+date[1];
        mon=(date[3]*10)+date[4];
        year=(date[6]*1000)+(date[7]*100)+(date[8]*10)+date[9];
        switch(mon)
        {
        case 1:
            if(day>31)
                checkd=-1;
            break;
        case 2:
            if((year%4!=0&&day>28)||year%4==0&&day>29)
                checkd=-1;
            break;
        case 3:
            if(day>31)
                checkd=-1;
            break;
        case 4:
            if(day>30)
                checkd=-1;
        case 5:
            if(day>31)
                checkd=-1;
            break;
        case 6:
            if(day>30)
                checkd=-1;
            break;
        case 7:
            if(day>31)
                checkd=-1;
            break;
        case 8:
            if(day>31)
                checkd=-1;
            break;
        case 9:
            if(day>30)
                checkd=-1;
            break;
        case 10:
            if(day>31)
                checkd=-1;
            break;
        case 11:
            if(day>30)
                checkd=-1;
            break;
        case 12:
            if(day>31)
                checkd=-1;
            break;
        default:
            checkd=-1;
            break;
        }
end:
    }
    else if(strlen(dob)!=10||checkd==-1)
    {
        cout<<"\nInvalid DOB....";
    }
    for(d1=0; d1<10; d1++)
    {
        if(48>contact[d1]||contact[d1]>57)
        {
            cout<<"\nOnly numbers to be enterd for contact....";
            check=-1;
            break;
        }
    }
    int dumdob[10];
    for(d1=0; d1<10; d1++)
    {
        if(check!=0)
        {
            mouse();
            goto reenter;
        }
        else
        {
            if(strcmp(member,"regular")==0)
            {
                member_type=2;
                amount-=500;
            }
            else if(strcmp(member,"premium")==0)
            {
                member_type=1;
                amount-=1000;
            }
            else if(strcmp(member,"admin")==0)
            {
                member_type=0;
            }
        }
    }
    setcolor(15);
    account_created();
    return 0;
}
void user::setting()
{
    int i,ch_setting=-1,dum=0;
    char member[20],passch='\0';
start_setting:
    clrscr();
    cleardevice();
    setcolor(3);
    settextstyle(3,1,7);
    outtextxy(5,130,"SETTINGS");
    setcolor(15);
    settextstyle(0,0,1);
    setfillstyle(SOLID_FILL,9);
    bar(400,0,639,350);
    setfillstyle(SOLID_FILL,colour1);
    bar(10,40,90,120);
    setting_button(50,78);
    gotoxy(15,4);
    cout<<"USER NAME      :"<<user_name;
    gotoxy(15,7);
    cout<<"PASSWORD       :";
    for(i=0; i<strlen(user_pass); i++)
	cout<<"*";
    gotoxy(15,10);
    cout<<"DATE OF BIRTH  :"<<dob;
    gotoxy(15,13);
    cout<<"CONTACT NO.    :"<<contact;
    switch(member_type)
    {
    case 0:
	gotoxy(15,16);
	cout<<"MEMBERSHIP TYPE:ADMINISTRATOR";
	break;
    case 1:
	gotoxy(15,16);
	cout<<"MEMBERSHIP TYPE:PREMIUM";
	break;
    case 2:
	gotoxy(15,16);
	cout<<"MEMBERSHIP TYPE:REGULAR";
	break;
    }
    gotoxy(15,19);
    cout<<"ACCOUNT BALANCE:"<<amount;
    for(i=35; i<=340; i+=50)
    {
        setfillstyle(SOLID_FILL,8);
        bar(400,i,639,i+30);
    }
    exit_button();
    outtextxy(420,45,"CHANGE USERNAME");
    outtextxy(420,95,"CHANGE PASSWORD");
    outtextxy(420,145,"CHANGE DATE OF BIRTH");
    outtextxy(420,195,"CHANGE CONTACT NO.");
    outtextxy(420,245,"CHANGE MEMBERSHIP TYPE");
    outtextxy(420,295,"RECHARGE ACCOUNT");
    outtextxy(420,345,"CHANGE COLOUR");
mouse_pre:
    mouse();
    ch_setting=mouse_click_for_setting();
    switch(ch_setting)
    {
    case 1:
        gotoxy(10,23);
        cout<<"Enter your new user name:";
        gotoxy(37,23);
        cin>>user_name;
        cin.ignore();
        break;
    case 2:
        gotoxy(10,23);
        cout<<"Enter your new password:";
        gotoxy(35,23);
        for(int dum1=0; dum1<20; dum1++)
            user_pass[dum1]='\0';
        dum=0;
        do
        {
            passch=getch();
            if(passch!=8&&passch!=13)
            {
                user_pass[dum++]=passch;
                cout<<"*";
            }
            else if(passch==8&&dum>0)
            {
                user_pass[--dum]='\0';
                setfillstyle(SOLID_FILL,0);
                bar(270,350,400,365);	 //password clear block
                gotoxy(35,23);
                for(dum1=0; dum1<dum; dum1++)
                {
                    cout<<"*";
                }
            }
        }
        while(passch!=13);
        break;
    case 3:
        gotoxy(10,23);
        cout<<"Enter your new Date of birth:";
        gotoxy(41,23);
        cin>>dob;
        cin.ignore();
        break;
    case 4:
        gotoxy(10,23);
        cout<<"Enter your new contact no.:";
        gotoxy(39,23);
        cin>>contact;
        cin.ignore();
        break;
    case 5:
        gotoxy(10,23);
        cout<<"Enter your new membership type:";
        gotoxy(43,23);
        cin.getline(member,20);
        if(strcmp(member,"regular")==0)
        {
            member_type=2;
        }
        else if(strcmp(member,"premium")==0)
        {
            member_type=1;
        }
        break;
    case 6:
        int amt;
        gotoxy(10,23);
        cout<<"Enter the amount to recharge(<20000):";
        gotoxy(41,23);
        cin>>amt;
        if(amt<20000)
            amount+=(amt*0.9);
        else
            cout<<"Recharge amount must be less then 20000.";
        cin.ignore();
        break;
    case 7:
        return ;
    case 8:
        change_theme();
        break;
    default:
        goto mouse_pre;
    }
    goto start_setting;
}
void user::change_theme()
{
    int choice=-1,i,j=1,k=0;
start:
    clrscr();
    cleardevice();
    outtextxy(20,30,"BACKGROUND COLOUR");
    outtextxy(20,110,"ACCENT COLOUR");
    outtextxy(20,190,"SIDE BAR COLOUR");
    exit_button();
    for(i=10,j=1; j<=15; i+=30,j++)
        for(k=50; k<=220; k+=80)
        {
            setfillstyle(SOLID_FILL,j);
            bar(i,k,i+20,k+50);
        }
    mouse();
    choice=mouse_click_for_change_theme();
    if(choice==0)
        return;
    else if(choice<=15)
        col[0]=choice;
    else if(choice<=30)
        col[1]=choice-15;
    else if(choice<=45)
        col[2]=choice-30;
    clrscr();
    cleardevice();
    outtextxy(150,200,"CHANGE APPLIED SUCCESFULLY");
    delay(500);
    goto start;
}
class book
{
public:
    int book_id;
    char book_name[40];
    char author[20];
    float price;
    char content[2000];
    int issue_stock;
    int buy_stock;
    int like;
    void del_book(void);
    void read_book(int,int a1[]);
    book()
    {
        like=book_id=0;
        issue_stock=buy_stock=5;
        price=0.0;
        strcpy(book_name,"");
        strcpy(author,"");
        strcpy(content,"");
    }
};
void book::read_book(int id,int a1[])
{
    int check=0;
    book bk9;
    char exit_ans;
    if(id==0)
    {
        goto end_read_book;
    }
    else
    {
        ifstream filbookread;
        filbookread.open("book",ios::in|ios::binary);
        if(!filbookread)
        {
            cout<<"File Empty!!!!!!!";
        }
        filbookread.seekg(0);
        filbookread.read((char *) &bk9,sizeof(bk9));
        while(filbookread!=0)
        {
            if(id==bk9.book_id)
            {
                for(int i=0; i<100; i++)
                {
                    if(a1[i]==bk9.book_id)
                    {
                        check=1;
                        break;
                    }
                }
book_read:
                int exitid=-1;
                cleardevice();
                setfillstyle(SOLID_FILL,2);
                bar(15,25,106,157);
                setfillstyle(SOLID_FILL,9);
                bar(10,20,100,150);
                setfillstyle(SOLID_FILL,9);
                bar(20,175,80,195);
                if(check==1)
                    outtextxy(25,182,"UNLIKE       LIKES");
                else
                    outtextxy(30,182,"LIKE         LIKES");
                setcolor(15);
                rectangle(0,200,639,479);
                exit_button();
                setcolor(15);
                outtextxy(22,35,"BOOK");
                outtextxy(150,25,"BOOK NAME:");
                outtextxy(250,25,bk9.book_name);
                outtextxy(150,78,"AUTHOR   :");
                outtextxy(250,78,bk9.author);
                outtextxy(150,131,"PRICE    :");
                gotoxy(32,9);
                cout<<bk9.price;
                gotoxy(2,14);
                cout<<bk9.content;
                gotoxy(14,12);
                cout<<bk9.like;
                mouse();
                exitid=mouse_click_for_readbook();
                switch(exitid)
                {
                case 1:
                    filbookread.close();
                    goto end_read_book;
                case 2:
                    for(i=0; i<100; i++)
                    {
                        if(a1[i]==0&&check==0)
                        {
                            a1[i]=bk9.book_id;
                            ++bk9.like;
                            check=1;
                            goto book_read;
                        }
                        else if(a1[i]==bk9.book_id&&check==1)
                        {
                            a1[i]=0;
                            --bk9.like;
                            check=0;
                            goto book_read;
                        }
                    }
                default:
                    goto book_read;
                }
            }
            filbookread.read((char *) &bk9,sizeof(bk9));
        }
        filbookread.close();
    }
end_read_book:
    book bkl;
    fstream bookdata;
    bookdata.open("book",ios::in|ios::out|ios::binary|ios::ate);
    bookdata.seekg(0);
    while(bookdata)
    {
        bookdata.read((char *) &bkl,sizeof(bkl));
        if(bk9.book_id==bkl.book_id)
        {
            int pos;
            pos=bookdata.tellg();
            bookdata.seekp(pos-sizeof(bk9));
            bookdata.write((char *) &bk9,sizeof(bk9));
            break;
        }
    }
    bookdata.close();
    return;
}

class admin:public user
{
public:
    void delete_user(void);
    void delete_book(void);
    void bookadd(void);
};
void admin::bookadd(void)
{
    book bk,bkadd,dumy1;
    bk.book_id=1;
start:
    int x_out=30,y_out=100,i;
    clrscr();
    cleardevice();
    setcolor(11);
    settextstyle(0,0,3);
    outtextxy(240,40,"ADD BOOK");
    setcolor(5);
    rectangle(20,25,620,220);
    for(i=94; i<=190; i+=32)
    {
	rectangle(180,i,505,i+18);
    }
    rectangle(0,250,639,430);
    settextstyle(0,0,1);
    setcolor(11);
    outtextxy(x_out,y_out,"BOOK ID: ");
    outtextxy(x_out,(y_out+32),"BOOK NAME: ");
    outtextxy(x_out,(y_out+64),"AUTHOR NAME: ");
    outtextxy(x_out,(y_out+98),"BOOK PRICE: ");
    outtextxy(x_out,(y_out+130),"BOOK CONTENT: ");
    setfillstyle(SOLID_FILL,4);
    setcolor(0);
    bar(240,440,400,470);    //INSERT BOOK
    outtextxy(260,455,"Insert the Book");
    ifstream  filebookadd;
    filebookadd.open("book",ios::in|ios::binary|ios::ate);
    filebookadd.seekg(0);
    while(filebookadd)
    {
	filebookadd.read((char *) &bkadd,sizeof(bkadd));
	bk.book_id=bkadd.book_id+1;
    }
    filebookadd.close();
    gotoxy(24,7);
    cout<<bk.book_id;
    exit_button();
mouse_re:
    mouse();
    int choice=mouse_click_for_add_book();
    switch(choice)
    {
    case 1:
	goto out;
    case 2:
	return;
    default:
	goto mouse_re;
    }
out:
    fflush(stdin);
    gotoxy(24,9);
    cin.getline(bk.book_name,40);
    gotoxy(24,11);
    cin.getline(bk.author,20);
    gotoxy(24,13);
    cin>>bk.price;
    cin.ignore();
    gotoxy(2,17);
    cin.getline(bk.content,2000,'`');
    cin.ignore();
    fflush(stdin);
    if((strcmp(bk.book_name,"")==0||bk.price==0)
	    ||(strcmp(bk.author,"")==0)||(strcmp(bk.book_name,"")==0))
    {
	cleardevice();
	cout<<"No Entry can be left null";
	cin.ignore();
	goto start;
    }
    ifstream filebookch;
    filebookch.open("book",ios::in|ios::binary|ios::ate);
    filebookch.seekg(0);
    while(filebookch)
    {
	filebookch.read((char *) &dumy1,sizeof(dumy1));
	if(strcmp(dumy1.book_name,bk.book_name)==0)
	{
	    cleardevice();
	    outtextxy(200,200,"BOOK ALREADY EXIST!!!!");
	    mouse();
	    filebookch.close();
	    goto start;
	}
    }
    filebookch.close();
mouse_ag:
    mouse();
    int choice1=mouse_click_for_add_book();
    switch(choice1)
    {
    case 2:
	return;
    case 3:
	ofstream filbook3;
	filbook3.open("book",ios::app|ios::binary);
	filbook3.write((char *) &bk,sizeof(bk));
	filbook3.close();
	book_added();
        break;
    default:
        goto mouse_ag;
    }
    goto start;
}
void admin::delete_book()
{
    book bk6,bk7;
re_display:
    int buk_delete_id;
    char confirm='n';
    clrscr();
    cleardevice();
    buk_delete_id=book_display(4);
    if(buk_delete_id==0)
    {
        goto re_display;
    }
    else if(buk_delete_id==-1)
    {
        clrscr();
        cleardevice();
        return;
    }
    ifstream filbooktrans;
    filbooktrans.open("book",ios::in|ios::binary);
    ofstream bookdelete;
    bookdelete.open("temp",ios::out|ios::binary);
    filbooktrans.seekg(0);
    filbooktrans.read((char *) &bk7,sizeof(bk7));
    while(filbooktrans)
    {
        if(buk_delete_id==bk7.book_id)
        {
            confirm=deletebook_confirm();
            if(confirm=='n')
            {
                bookdelete.write((char *) &bk7,sizeof(bk7));
                filbooktrans.close();
                bookdelete.close();
                remove("temp");
                goto re_display;
            }
        }
        else
        {
            if(bk7.book_id>buk_delete_id)
            {
                bk7.book_id-=1;
            }
            bookdelete.write((char *) &bk7,sizeof(bk7));
        }
        filbooktrans.read((char *) &bk7,sizeof(bk7));
    }
    filbooktrans.close();
    bookdelete.close();
    remove("book");
    rename("temp","book");
    goto re_display;
}
void admin::delete_user()
{
    user ur1,ur2;
start:
    char confirm='n',usr_delete_name[20];
    int dumy=1,last=0,i,delete_id,pos=1,buk_id,dumy1=0;
re_display:
    dumy1=0;
    ifstream  fileuserdispdumy;
    fileuserdispdumy.open("user",ios::in|ios::binary|ios::ate);
    fileuserdispdumy.seekg(0);
    while(fileuserdispdumy)
    {
        fileuserdispdumy.read((char *) &ur1,sizeof(ur1));
        dumy1++ ;
    }
    fileuserdispdumy.close();
    clrscr();
    cleardevice();
    last=0;
    setcolor(15);
    setfillstyle(SOLID_FILL, BLUE);
    bar(0,0,639,90);
    settextstyle(0,0,4);
    outtextxy(160,30,"DELETE USER");
    settextstyle(0,0,1);
    outtextxy(50,100,"USER NAME");
    outtextxy(250,100,"ACCOUNT TYPE");
    outtextxy(510,100,"ACCOUNT BAL");
    ifstream  fileuserdisp;
    fileuserdisp.open("user",ios::in|ios::binary|ios::ate);
    exit_button();
    if(pos>4)
    {
        setfillstyle(SOLID_FILL,9);
        bar(39,330,130,360);
        outtextxy(55,342,"PREVIOUS");
    }
    if(dumy1>5)
    {
        setfillstyle(SOLID_FILL,1);
        bar(510,330,590,360);
        outtextxy(535,342,"NEXT");
    }
    fileuserdisp.seekg(0);
    setcolor(15);
    for(int k=0; k<pos; ++k)
    {
        fileuserdisp.read((char *) &ur1,sizeof(ur1));
    }
    int d,f=10;
    for(d=148,i=0; i<4&& fileuserdisp!=0; d+=48,++i)
    {
        rectangle(40,d-11,590,d+21);
        gotoxy(8,f);
        cout<<ur1.user_name;
        gotoxy(66,f);
        cout<<ur1.amount;
        gotoxy(42,f);
        cout<<ur1.member_type;
        f+=3;
        fileuserdisp.read((char *) &ur1,sizeof(ur1));
        ++pos;
        last++;
    }
re_ans:
    mouse();
    int choice=mouse_click_for_display();
    switch(choice)
    {
    case 0:
    case 1:
    case 2:
    case 3:
        if(choice>last)
        {
            pos-=last;
            goto re_ans;
        }
        delete_id=((pos+choice)-last);
        pos-=last;
        fileuserdisp.close();
        break;
    case 4:
        fileuserdisp.close();
        if(pos>8)
        {
            pos-=(4+last);
        }
        else
            pos=0;
        goto re_display;
    case 5:
        if(  fileuserdisp==0)
        {
            pos=1;
            fileuserdisp.close();
        }
        goto re_display;
    case 6:
        fileuserdisp.close();
        setcolor(15);
        return ;
    default:
        goto re_ans;
    }
    strcpy(usr_delete_name,"");
    ifstream filusertrans;
    filusertrans.open("user",ios::in|ios::binary);
    ofstream userdelete;
    userdelete.open("temp",ios::out|ios::binary);
    filusertrans.seekg(0);
    dumy=1;
    filusertrans.read((char *) &ur2,sizeof(ur2));
    while(filusertrans)
    {
        if(dumy==delete_id)
            strcpy(usr_delete_name,ur2.user_name);
        ++dumy;
        if(strcmp(usr_delete_name,ur2.user_name)==0)
        {
            confirm=deleteuser_confirm();
            if(confirm=='n')
            {
                userdelete.write((char *) &ur2,sizeof(ur2));
                filusertrans.close();
                userdelete.close();
                remove("temp");
                goto re_display;
            }
        }
        else
        {
            userdelete.write((char *) &ur2,sizeof(ur2));
        }
        filusertrans.read((char *) &ur2,sizeof(ur2));
    }
    filusertrans.close();
    userdelete.close();
    remove("user");
    rename("temp","user");
    goto start;
}
class regular:public user
{
public:
    void issue_book(void);
    void return_book(void);
};
void regular::issue_book()
{
    book bk2;
start:
    setcolor(7);
    int repeat=-1,buk_issue_id=-1,buk_id_check=-1;
    int buk_stock_check=-1,check=-1,i,pos,d;
    clrscr();
    cleardevice();
    buk_issue_id=book_display(1);
    if(buk_issue_id==-1)
    {
        clrscr();
        cleardevice();
        return;
    }
    ifstream filbookmatch;
    filbookmatch.open("book",ios::in|ios::binary);
    filbookmatch.seekg(0);
    filbookmatch.read((char *) &bk2,sizeof(bk2));
    while(filbookmatch)
    {
        if(bk2.book_id==buk_issue_id)
        {
            pos=filbookmatch.tellg();
            buk_id_check=0;
            buk_stock_check=bk2.issue_stock;
            break;
        }
        filbookmatch.read((char *) &bk2,sizeof(bk2));
    }
    filbookmatch.close();
    if(buk_stock_check==0&&buk_id_check==0)
    {
        cleardevice();
        outtextxy(200,350,"Sorry the book is out of stock");
        mouse();
    }
    else if(buk_id_check==0&&buk_stock_check!=0)
    {
        ofstream filbookissue;
        filbookissue.open("book",ios::in|ios::binary);
        for(i=0; i<3; ++i)
        {
            if(book_issue[i].id==buk_issue_id)
            {
                repeat=0;
                goto out;
            }
            if(book_issue[i].id==0)
            {
                book_issue[i].id=buk_issue_id;
                t = time(NULL);
                book_issue[i].time=t;
                amount-=bk2.price;
                check=0;
                bk2.issue_stock-=1;
                filbookissue.seekp(pos-sizeof(bk2));
                filbookissue.write((char *) &bk2,sizeof(bk2));
                filbookissue.close();
                break;
            }
        }
out:
        cleardevice();
        if(check==0)
            issue_sucess();
        else if(repeat==0)
        {
            outtextxy(200,200,"Book is already issued!!!");
            mouse();
        }
        else
        {
            outtextxy(200,200,"No more books can be issued!!!");
            mouse();
        }
    }
    goto start;
}
void regular::return_book()
{
    book bk3;
start:
    int i,d,return_id,book_return_index,pos;
return_book:
    int k=0;
    setcolor(7);
    cleardevice();
    setfillstyle(SOLID_FILL, BLUE);
    bar(0,0,639,90);
    settextstyle(0,0,4);
    outtextxy(160,30,"RETURN BOOK");
    settextstyle(0,0,1);
    exit_button();
    outtextxy(70,100,"BOOK NAME");
    outtextxy(350,100,"AUTHOR");
    outtextxy(510,100,"PRICE");
    ifstream filbookread;
    filbookread.open("book",ios::in|ios::binary);
    filbookread.seekg(0);
    filbookread.read((char *) &bk3,sizeof(bk3));
    int f=10,dumy[3]= {0,0,0};
    setcolor(15);
    for(d=148,i=0; i<3&&filbookread!=0;)
    {
        if(book_issue[i].id==bk3.book_id)
        {
            dumy[k]=bk3.book_id;
            rectangle(40,d-11,590,d+21);
            dumy[i]=bk3.book_id;
            gotoxy(8,f);
            cout<<bk3.book_name;
            gotoxy(66,f);
            cout<<bk3.price;
            gotoxy(42,f);
            cout<<bk3.author;
            f+=3;
            d+=48;
            ++i;
            ++k;
            filbookread.seekg(0);
        }
        if(book_issue[i].id==0)
        {
            break;
        }
        filbookread.read((char *) &bk3,sizeof(bk3));
    }
    filbookread.close();
return_mouse:
    mouse();
    int re_id=mouse_click_for_display();
    switch(re_id)
    {
    case 0:
    case 1:
    case 2:
        if(dumy[re_id]==0)
            goto return_mouse;
        return_id=dumy[re_id];
        break;
    case 6:
        return;
    default:
        goto return_mouse;
    }
    for(i=0; i<3; ++i)
    {
        if(return_id==book_issue[i].id)
        {
            book_return_index=i;
        }
    }
    ifstream filbookmatch;
    filbookmatch.open("book",ios::in|ios::binary);
    filbookmatch.seekg(0);
    filbookmatch.read((char *) &bk3,sizeof(bk3));
    while(filbookmatch)
    {
        if(bk3.book_id==return_id)
        {
            pos=filbookmatch.tellg();
            break;
        }
        filbookmatch.read((char *) &bk3,sizeof(bk3));
    }
    filbookmatch.close();
    ofstream filbookreturn;
    filbookreturn.open("book",ios::in|ios::binary);
    amount+=(0.9*bk3.price);
    t = time(NULL);
    int dumyt;
    dumyt=((t-book_issue[book_return_index].time)/604800);
    amount-=(dumyt*bk3.price)/10;
    book_issue[book_return_index].id=0;
    for(i=book_return_index; i<2; ++i)
    {
        book_issue[i].id=book_issue[i+1].id;
        book_issue[i].time=book_issue[i+1].time;
    }
    book_issue[2].id=book_issue[2].time=0;
    bk3.issue_stock+=1;
    filbookreturn.seekp(pos-sizeof(bk3));
    filbookreturn.write((char *) &bk3,sizeof(bk3));
    return_sucess();
    filbookreturn.close();
    goto start;
}
class premium:public regular
{
public:
    void buy_book(void);
    void sell_book(void);
};
void premium::buy_book()
{
    book bk4;
start:
    setcolor(7);
    int repeat=-1,buk_buy_id=-1,buk_id_check=-1;
    int buk_stock_check=-1,check=-1,i,pos,d;
    clrscr();
    cleardevice();
    buk_buy_id=book_display(2);
    if(buk_buy_id==-1)
    {
        clrscr();
        cleardevice();
        return;
    }
    ifstream filbookmatch;
    filbookmatch.open("book",ios::in|ios::binary);
    filbookmatch.seekg(0);
    filbookmatch.read((char *) &bk4,sizeof(bk4));
    while(filbookmatch)
    {
        if(bk4.book_id==buk_buy_id)
        {
            pos=filbookmatch.tellg();
            buk_id_check=0;
            buk_stock_check=bk4.buy_stock;
            break;
        }
        filbookmatch.read((char *) &bk4,sizeof(bk4));
    }
    filbookmatch.close();
    if(buk_stock_check==0&&buk_id_check==0)
    {
        outtextxy(200,350,"Sorry the book is out of stock");
        mouse();
    }
    else if(buk_id_check==0&&buk_stock_check!=0)
    {
        ofstream filbookbuy;
        filbookbuy.open("book",ios::in|ios::binary);
        for(i=0; i<3; ++i)
        {
            if(book_buy_id[i]==buk_buy_id)
            {
                repeat=0;
                goto out;
            }
            if(book_buy_id[i]==0)
            {
                book_buy_id[i]=buk_buy_id;
                check=0;
                bk4.buy_stock-=1;
                amount=amount-bk4.price;
                filbookbuy.seekp(pos-sizeof(bk4));
                filbookbuy.write((char *) &bk4,sizeof(bk4));
                filbookbuy.close();
                break;
            }
        }
out:
        cleardevice();
        if(check==0)
            buy_sucess();
        else if(repeat==0)
        {
            outtextxy(200,200,"Book is already buyed!!!");
            mouse();
        }
        else
            outtextxy(200,200,"No more books can be bought!!!");
        mouse();
    }
    goto start;
}
void premium::sell_book()
{
    book bk5;
start:
    int i,d,return_id,book_issue_index,pos;
return_book:
    int k=0;
    setcolor(7);
    cleardevice();
    setfillstyle(SOLID_FILL, BLUE);
    bar(0,0,639,90);
    settextstyle(0,0,4);
    outtextxy(180,30,"SELL BOOK");
    settextstyle(0,0,1);
    exit_button();
    outtextxy(70,100,"BOOK NAME");
    outtextxy(330,100,"AUTHOR");
    outtextxy(510,100,"PRICE");
    ifstream filbookread;
    filbookread.open("book",ios::in|ios::binary);
    filbookread.seekg(0);
    setcolor(15);
    filbookread.read((char *) &bk5,sizeof(bk5));
    int  f=10,dumy[3]= {0,0,0};
    for(d=148,i=0; i<3&&filbookread!=0;)
    {
        if(book_buy_id[i]==bk5.book_id)
        {
            dumy[k]=bk5.book_id;
            rectangle(40,d-11,590,d+21);
            dumy[i]=bk5.book_id;
            gotoxy(8,f);
            cout<<bk5.book_name;
            gotoxy(66,f);
            cout<<bk5.price;
            gotoxy(42,f);
            cout<<bk5.author;
            f+=3;
            d+=48;
            filbookread.seekg(0);
            ++i;
            ++k;
        }
        if(book_buy_id[i]==0)
        {
            break;
        }
        filbookread.read((char *) &bk5,sizeof(bk5));
    }
    filbookread.close();
return_mouse:
    mouse();
    int re_id=mouse_click_for_display();
    switch(re_id)
    {
    case 0:
    case 1:
    case 2:
        return_id=dumy[re_id];
        break;
    case 6:
        return;
    default:
        goto return_mouse;
    }
    if(return_id==0)
        goto return_book;
    for(i=0; i<3; ++i)
    {
        if(return_id==book_buy_id[i])
        {
            book_issue_index=i;
            char  sell_conf= sell_confirm();
            if(sell_conf=='n')
                goto return_book;
        }
    }
    ifstream filbookmatch;
    filbookmatch.open("book",ios::in|ios::binary);
    filbookmatch.seekg(0);
    filbookmatch.read((char *) &bk5,sizeof(bk5));
    while(filbookmatch)
    {
        if(bk5.book_id==return_id)
        {
            pos=filbookmatch.tellg();
            break;
        }
        filbookmatch.read((char *) &bk5,sizeof(bk5));
    }
    filbookmatch.close();
    ofstream filbooksell;
    filbooksell.open("book",ios::in|ios::binary);
    book_buy_id[book_issue_index]=0;
    for(i=book_issue_index; i<2; ++i)
    {
        book_buy_id[i]=book_buy_id[i+1];
    }
    book_buy_id[2]=0;
    bk5.buy_stock+=1;
    amount=amount+(bk5.price*0.8);
    filbooksell.seekp(pos-sizeof(bk5));
    filbooksell.write((char *) &bk5,sizeof(bk5));
    filbooksell.close();
    goto start;
}
/***************************************************************
*                     END OF CLASS DEFINATION                  *
***************************************************************/
user signin(void);
void admin_home_page(admin ad);
void premium_home_page(premium pre);
void regular_home_page(regular reg);
user us;
admin ad;
regular reg;
premium pre;
book bk;
/***************************************************************
*                          BODY OF MAIN                        *
***************************************************************/
void main()
{
    int member;
    int gdriver=DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "");
    cleardevice();
    setlinestyle(0,1,3);
    setfillstyle(SOLID_FILL,15);
    bar(0,0,640,480);
    setcolor(5);
    settextstyle(1,0,15);
    outtextxy(170,100,"HTCL");
    setcolor(9);
    settextstyle(0,0,2);
    outtextxy(95,300,"Hi-TECH COMPUTERISED LIBRARY");
    mouse();
loading();
main_start:
    clrscr();
    cleardevice();
    us=signin();
    cleardevice();
    colour1=us.col[0];
    colour2=us.col[1];
    colour3=us.col[2];
    switch(us.member_type)
    {
    case 0:
        strcpy(ad.user_name,us.user_name);
        strcpy(ad.user_pass,us.user_pass);
        strcpy(ad.contact,us.contact);
        strcpy(ad.dob,us.dob);
        ad.member_type=us.member_type;
        ad.amount=us.amount;
        ad.col[0]=us.col[0];
        ad.col[1]=us.col[1];
        ad.col[2]=us.col[2];
        admin_home_page(ad);
        break;
    case 1:
        strcpy(pre.user_name,us.user_name);
        strcpy(pre.user_pass,us.user_pass);
        strcpy(pre.contact,us.contact);
        strcpy(pre.dob,us.dob);
        pre.member_type=us.member_type;
        pre.amount=us.amount;
        for(int d=0; d<3; ++d)
        {
            pre.col[d]=us.col[d];
            pre.book_issue[d].id=us.book_issue[d].id;
            pre.book_issue[d].time=us.book_issue[d].time;
            pre.book_buy_id[d]=us.book_buy_id[d];
        }
        for(d=0; d<100; ++d)
            pre.liked[d]=us.liked[d];
        premium_home_page(pre);
        break;
    case 2:
        strcpy(reg.user_name,us.user_name);
        strcpy(reg.user_pass,us.user_pass);
        strcpy(reg.contact,us.contact);
        strcpy(reg.dob,us.dob);
        reg.member_type=us.member_type;
        reg.amount=us.amount;
        for(d=0; d<3; d++)
        {
            reg.col[d]=us.col[d];
            reg.book_issue[d].id=us.book_issue[d].id;
            reg.book_issue[d].time=us.book_issue[d].time;
        }
        for(d=0; d<100; ++d)
            reg.liked[d]=us.liked[d];
        regular_home_page(reg);
        break;
    }
    goto main_start;
}
/***************************************************************
*                         END OF MAIN                          *
***************************************************************/
/***************************************************************
*                          HOME PAGE                           *
***************************************************************/
void admin_home_page(admin ad)
{
    int mouse_check_ad=-1;
    char member[10];
user_homestart://7
    clrscr();
    cleardevice();
    ubuntu(232,280);
    setcolor(colour2);
    setfillstyle(SOLID_FILL,colour1);
    bar(9,0,79,80);
    bar(85,0,155,80);
    bar(161,0,231,80);
    bar(237,0,307,80);
    bar(313,0,383,80);
    bar(389,0,459,80);
    setfillstyle(SOLID_FILL,0);
    bar(464,1,639,189);
    side_bar();
    logo(44,35,1,1);
    setcolor(colour2);
    setfillstyle(SOLID_FILL,colour2);
    bar(107,10,132,50);             //issue
    bar(143,40,148,65);
    bar(137,50,154,55);
    bar(183,10,208,50);		   //delbook
    line(212,55,228,67);
    line(212,67,228,55);
    circle(272,12,10);              //remove
    circle(269,11,1);              //eye
    circle(275,11,1);
    line(272,22,272,52);            //body
    line(272,28,262,38);             // lh
    line(272,28,282,38);             //rh
    line(272,52,262,60);              //ll
    line(272,52,282,60);             //rl
    line(287,55,305,67);
    line(287,67,305,55);
    circle(348,30,20);
    line(348,40,348,60);
    setfillstyle(SOLID_FILL,colour1);
    bar(342,40,347,65);
    bar(349,40,353,65);
    setting_button(422,38);
    setfillstyle(SOLID_FILL,0);
    bar(480,20,620,170);
    logo(550,95,5,3);        //logo
    line(460,190,639,190);
    setcolor(colour4);
    outtextxy(14,70,"CREDITS");
    outtextxy(90,70,"ADD BOOK");
    outtextxy(165,70,"DEL BOOK");
    outtextxy(242,70,"DEL USER");
    outtextxy(317,70,"SIGN OUT");
    outtextxy(400,70,"SETTING");
    gotoxy(59,15);
    cout<<"USER_NAME :"<<ad.user_name;
    gotoxy(59,18);
    cout<<"MEMBERSHIP:Admin";
    gotoxy(59,21);
    cout<<"AMOUNT    :"<<ad.amount;
    gotoxy(59,24);
    cout<<"DOB       :"<<ad.dob;
mouse_ad:
    mouse();
    mouse_check_ad=mouse_click_for_admin_home();
    switch(mouse_check_ad)
    {
    case 1:
        credits();     //CREDITS
        break;
    case 2:
        ad.bookadd();      //ADD BOOK
        break;
    case 3:
        ad.delete_book();    //DELETE BOOK
        break;
    case 4:
        ad.delete_user();       //DELETE USER
        break;
    case 5:
        goto save_ad;
    case 6:
        ad.setting();
        break;
    default:
        goto mouse_ad;
    }
    settextstyle(0,0,1);
    goto user_homestart;
save_ad:
    //FINAL MODIFICATION AT END
    admin add;
    fstream userdata;
    userdata.open("user",ios::in|ios::out|ios::binary);
    userdata.seekg(0);
    while(userdata)
    {
        userdata.read((char *) &add,sizeof(add));
        if(strcmp(add.user_name,add.user_name)==0)
        {
            int pos;
            pos=userdata.tellg();
            userdata.seekp(pos-sizeof(add));
            userdata.write((char *) &add,sizeof(add));
            break;
        }
    }
    userdata.close();
}
void premium_home_page(premium pre)
{
    int mouse_check_pre=-1,i=0,j=0,book_id_display;
    char member[10];
    book bk_pre,bk12;
user_homestart:
    clrscr();
    cleardevice();
    setfillstyle(SOLID_FILL,15);      //background
    bar(3,86,459,476);
    setfillstyle(SOLID_FILL,colour1);
    bar(5,0,71,80);
    bar(76,0,136,80);
    bar(141,0,201,80);
    bar(206,0,266,80);
    bar(271,0,331,80);
    bar(336,0,399,80);
    bar(404,0,464,80);
    setfillstyle(SOLID_FILL,colour2);
    bar(464,1,639,189);
    side_bar();
    setcolor(colour4);
    logo(44,35,1,1);
    outtextxy(14,70,"CREDITS");
    setfillstyle(SOLID_FILL,colour2);
    bar(85,10,112,50);	      //issue
    bar(125,40,122,65);
    bar(115,50,132,55);
    outtextxy(86,70,"ISSUE");
    bar(150,10,175,50);	       //return
    bar(180,55,195,60);
    outtextxy(148,70,"RETURN");
    bar(219,25,254,55);		   //buy
    rectangle(229,15,244,25);
    outtextxy(225,70,"BUY");
    bar(284,18,319,45);
    rectangle(294,45,309,58);
    outtextxy(286,70,"SELL");
    setcolor(colour2);
    circle(366,30,20);             //sign_out
    line(366,40,366,60);
    setfillstyle(SOLID_FILL,colour1);
    bar(360,40,365,65);
    bar(367,40,372,65);
    outtextxy(337,70,"SIGN_OUT");
    outtextxy(408,70,"SETTING");
    setting_button(435,38);
    setfillstyle(SOLID_FILL,0);
    setlinestyle(SOLID_LINE,1,1);
    setcolor(colour4);
    outtextxy(190,90,"ISSUED BOOKS"); // ISSUED BOOKS
    line(0,100,462,100);
    bar(8,110,455,160);   //bar1
    bar(8,165,455,215);   //bar2
    bar(8,220,455,270);   //bar3
    line(0,280,462,280);
    outtextxy(190,285,"BUYED BOOKS");     // BUYED BOOKS
    line(0,300,462,300);
    setlinestyle(0,1,3);
    setfillstyle(SOLID_FILL,0);
    bar(8,310,455,360);              //bar4
    bar(8,365,455,415);              //bar5
    bar(8,420,455,470);              //bar6
    setcolor(5);
    for(book_id_display=0,i=130,j=330; book_id_display<3;
            ++book_id_display,i+=55,j+=55)
    {
        ifstream book_read;
	book_read.open("book",ios::in|ios::binary);
        book_read.seekg(0);
        book_read.read((char *) &bk12,sizeof(bk12));
        while(book_read)
        {
            if(bk12.book_id==pre.book_issue[book_id_display].id)
            {
                settextstyle(0,0,1);
                outtextxy(25,i,bk12.book_name);
            }
            if(bk12.book_id==pre.book_buy_id[book_id_display])
            {
                settextstyle(0,0,1);
                outtextxy(25,j,bk12.book_name);
            }
            book_read.read((char *) &bk12,sizeof(bk12));
        }
        book_read.close();
    }
    setcolor(15);
    gotoxy(59,15);
    cout<<"USER_NAME :"<<pre.user_name;
    gotoxy(59,18);
    cout<<"MEMBERSHIP:Premium";
    gotoxy(59,21);
    cout<<"AMOUNT    :"<<pre.amount;
    gotoxy(59,24);
    cout<<"DOB       :"<<pre.dob;
mouse_pre:
    mouse();
    mouse_check_pre=mouse_click_for_premium_home();
    switch(mouse_check_pre)
    {
    case 1:
    case 2:
    case 3:
        bk_pre.read_book(pre.book_issue[mouse_check_pre-1].id,pre.liked);
        goto user_homestart;
    case 4:
        bk_pre.read_book(pre.book_buy_id[0],pre.liked);
        goto user_homestart;
    case 5:
        bk_pre.read_book(pre.book_buy_id[1],pre.liked);
        goto user_homestart;
    case 6:
        bk_pre.read_book(pre.book_buy_id[0],pre.liked);
        goto user_homestart;
    case 7:
        credits(); //CREDITS
        break;
    case 8:
        pre.issue_book();       //ISSUE BOOK
        break;
    case 9:
        pre.return_book();    //RETURN BOOK
        break;
    case 10:
        pre.buy_book();       //BUY BOOK
        break;
    case 11:
        pre.sell_book();    //sell book
        break;
    case 12:
        goto save_pre;
    case 13:
        pre.setting();
        break;
    default:
        goto mouse_pre;
    }
    goto user_homestart;
save_pre:
    //FINAL MODIFICATION AT END
    premium pr;
    fstream userdata;
    userdata.open("user",ios::in|ios::out|ios::binary|ios::ate);
    userdata.seekg(0);
    while(userdata)
    {
        userdata.read((char *) &pr,sizeof(pr));
        if(strcmp(pre.user_name,pr.user_name)==0)
        {
            int pos;
            pos=userdata.tellg();
            userdata.seekp(pos-sizeof(pre));
            userdata.write((char *) &pre,sizeof(pre));
            break;
        }
    }
    userdata.close();
}
void regular_home_page(regular reg)
{
    char member[10];
    int check_mouse2=-1,i=0,book_id_display;
    book bk_reg,bk12;
user_homestart:
    clrscr();
    cleardevice();
    setcolor(colour2);
    setfillstyle(SOLID_FILL,15);
    bar(3,86,459,476);              //background
    setfillstyle(SOLID_FILL,colour1);
    bar(5,0,85,80);
    bar(95,0,175,80);
    bar(185,0,275,80);
    bar(285,0,365,80);
    bar(375,0,455,80);
    setcolor(colour2);       //CREDITS
    logo(44,35,1,1);
    outtextxy(14,70,"CREDITS");
    side_bar();
    setfillstyle(SOLID_FILL,colour2);
    bar(120,10,145,50);			//issue
    bar(160,40,157,65);
    bar(150,50,167,55);
    setcolor(colour2);
    outtextxy(95,70,"ISSUE BOOK");
    bar(217,10,242,50);               //return
    bar(247,55,262,60);
    outtextxy(188,70,"RETURN BOOK");
    circle(325,30,20);             //sign_out
    line(325,40,325,60);
    setfillstyle(SOLID_FILL,colour1);
    bar(320,40,324,65);
    bar(326,40,330,65);
    outtextxy(295,70,"SIGN OUT");
    outtextxy(388,70,"SETTING");
    setting_button(415,38);
    setfillstyle(SOLID_FILL,0);
    logo(550,95,5,3);        //logo
    setcolor(0);
    line(460,190,639,190);      //issue
    setlinestyle(SOLID_LINE,1,1);
    outtextxy(190,90,"ISSUED BOOKS");
    line(0,100,462,100);
    bar(8,110,453,220);     //bar1
    bar(8,230,453,340);     //bar2
    bar(8,350,453,460);     //bar3
    setlinestyle(0,1,3);
    setcolor(14);
    for(book_id_display=0,i=160; book_id_display<3; ++book_id_display,i+=120)
    {
        ifstream book_read;
        book_read.open("book",ios::in|ios::binary);
        book_read.seekg(0);
        book_read.read((char *) &bk12,sizeof(bk12));
        while(book_read)
        {
            if(bk12.book_id==reg.book_issue[book_id_display].id)
            {
                settextstyle(0,0,1);
                outtextxy(25,i,bk12.book_name);
                book_read.seekg(0);
                break;
            }
            book_read.read((char *) &bk12,sizeof(bk12));
        }
        book_read.close();
    }
    setcolor(15);
    gotoxy(59,15);
    cout<<"USER_NAME :"<<reg.user_name;
    gotoxy(59,18);
    cout<<"MEMBERSHIP:Regular";
    gotoxy(59,21);
    cout<<"AMOUNT    :"<<reg.amount;
    gotoxy(59,24);
    cout<<"DOB       :"<<reg.dob;
    //working starts:::::MENU
mouse_homeuser:
    mouse();
    check_mouse2=mouse_click_for_regular_home();
    switch(check_mouse2)
    {
    case 1:
    case 2:
    case 3:
        bk_reg.read_book(reg.book_issue[check_mouse2-1].id,reg.liked);
        goto user_homestart;
    case 4:
        credits();          //CREDITS
        break;
    case 5:
        reg.issue_book();       //ISSUE BOOK
        break;
    case 6:
        reg.return_book();    //RETURN BOOK
        break;
    case 7:
        goto end_home;          //SIGN OUT
    case 8:
        reg.setting();          //SETTINGS
        break;//settings
    default:
        goto mouse_homeuser;
    }
    goto user_homestart;
end_home:
    //FINAL MODIFICATION AT END
    regular urs;
    fstream userdata;
    userdata.open("user",ios::in|ios::out|ios::binary);
    userdata.seekg(0);
    while(userdata)
    {
        userdata.read((char *) &urs,sizeof(urs));
        if(strcmp(reg.user_name,urs.user_name)==0)
        {
            int pos;
            pos=userdata.tellg();
            userdata.seekp(pos-sizeof(reg));
            userdata.write((char *) &reg,sizeof(reg));
            break;
        }
    }
    userdata.close();
}
/***************************************************************
*                       END OF HOMEPAGE                        *
***************************************************************/
/***************************************************************
*                      FUNCTION DEFINATION                     *
***************************************************************/
/***************************************************************
*                     START OF MOUSE FUNCTION                  *
***************************************************************/
void mouse()
{
    int ch,a,b;
    DetectMouse();
    InitMouse();
    ShowMouse();
    void WhereMouse(int*,int*);
    ButtClicked();
    ButtReleased();
    while(ch!=27)
    {
        if(kbhit())
            ch=getch();
        WhereMouse(&a,&b);
        if(ButtReleased())
        {
            cor_x=a,cor_y=b;
            HideMouse();
            delay(40);
            goto out;
        }
    }
out:
}
int DetectMouse(void)
{
    union REGS in,out;
    in.x.ax=0;
    int86(0X33,&in,&out);
    if(out.x.ax==0)
        return(0);
    else
        return(1);
}
void InitMouse(void)
{
    union REGS in,out;
    in.x.ax=33;
    int86(0X33,&in,&out);
    return;
}
void HideMouse(void)
{
    union REGS in,out;
    in.x.ax=2;
    int86(0X33,&in,&out);
    return;
}
void ShowMouse(void)
{
    union REGS in,out;
    in.x.ax=1;
    int86(0X33,&in,&out);
    return;
}
void WhereMouse(int *x,int *y)
{
    union REGS in,out;
    in.x.ax=3;
    int86(0X33,&in,&out);
    *x=(int)out.x.cx;
    *y=(int)out.x.dx;
    return;
}
int ButtClicked(void)
{
    union REGS imouse,omouse;
    int mc,mr;
    imouse.x.ax = 3;
    int86(0X33,&imouse,&omouse);
    mc=omouse.x.bx;
    return(mc);
}
int ButtReleased(void)
{
    int br;
    br=ButtClicked();
    do {}
    while(ButtClicked()!=0);
    return br;
}
/***************************************************************
*                      END OF MOUSE FUNCTION                   *
***************************************************************/

void side_bar(void)
{
    setfillstyle(SOLID_FILL,colour3);
    bar(464,1,639,189);
    setfillstyle(SOLID_FILL,0);
    bar(480,20,620,170);
    logo(550,95,5,3);        //logo
    setfillstyle(SOLID_FILL,colour3);  // gap bar
    bar(464,195,639,223);
    bar(464,240,639,268);
    bar(464,288,639,318);
    bar(464,337,639,367);
    bar(464,385,639,415);
    bar(464,440,639,470);
    setcolor(15);
    settextstyle(1,0,2);
    outtextxy(530,415,"HTCL");
    settextstyle(0,0,1);
    setcolor(0);
}
void ubuntu(int xu,int yu)
{
    //////////////////////////////////circle1
    setcolor(14);
    setfillstyle(1,14);
    sector(xu-10,yu,230,110,96,100);
//////////////////////////////////////////circle2
    setcolor(4);
    setfillstyle(1,4);
    sector(xu,yu+10,230,350,100,100);
////////////////////////////////////////////////circle3
    setcolor(12);
    setfillstyle(1,12);
    sector(xu+3,yu-5,0,110,100,100);
    sector(xu+3,yu-5,351,360,100,100);
    setcolor(0);
////////////////////////////////////////////////black
    setfillstyle(1,0);
    sector(xu,yu,0,360,80,80);
/////////////////////////////////////////smallcircle1
    sector(xu-120,yu-10,0,360,25,25);
    setcolor(4);
    setfillstyle(1,4);
    sector(xu-120,yu-10,0,360,15,15);
//////////////////////////////////////////////smallcircle2
    setcolor(0);
    setfillstyle(1,0);
    sector(xu+35,yu+117,0,360,25,25);
    setcolor(12);
    setfillstyle(1,12);
    sector(xu+35,yu+117,0,360,15,15);
////////////////////////////////////////////////////////smallcircle3
    setcolor(0);
    setfillstyle(1,0);
    sector(xu+65,yu-100,0,360,25,25);
    setcolor(14);
    setfillstyle(1,14);
    sector(xu+65,yu-100,0,360,15,15);
}
void wrong_password(void)
{
    clrscr();
    cleardevice();
    setfillstyle(SOLID_FILL,4);
    bar(180,140,420,290);
    settextstyle(0,0,9);
    setcolor(15);
    outtextxy(185,180,"!");
    settextstyle(0,0,2);
    outtextxy(285,195,"WRONG");
    outtextxy(260,220,"PASSWORD");
    settextstyle(0,0,1);
    mouse();
}
void credits(void)
{
    cleardevice();
    int i,j,k,x;
    settextstyle(1,0,2);
    for(x=0; x<350; x++)
    {
	k=random(15)+1;
	setcolor(k);
        i=random(600);
        j=random(460);
        outtextxy(i,j,"HTCL");
    }
    setfillstyle(SOLID_FILL,7);
    setcolor(1);
    settextstyle(0,0,1);
    bar(200,170,420,330);
    outtextxy(235,185,"      MADE BY");
    outtextxy(230,255,"   Special Thanks");
    outtextxy(230,270,"         TO");
    setcolor(4);
    outtextxy(230,215,"Master Dhaval Khatri");
    outtextxy(235,295,"  Mr.Vinod Mishra");
    mouse();
}

user signin(void)
{
    user ur;
    int check_pass,check_save,dum=0;
    int check=-1,check1=-1,check_mouse=-1;
    char dob[15],username[20],password[20],passch='\0';
refill:
    check_mouse=-1;
    check1=-1;
    clrscr();
    cleardevice();
    setfillstyle(SOLID_FILL,7);
    bar(140,70,365,150);
    setfillstyle(SOLID_FILL,15);
    bar(145,50,215,160);
    settextstyle(3,0,11);
    setcolor(5);
    outtextxy(152,23,"H");
    setcolor(4);
    settextstyle(1,0,8);
    outtextxy(225,60,"T");
    outtextxy(275,60,"C");
    outtextxy(320,60,"L");
    settextstyle(0,0,0);
    setfillstyle(SOLID_FILL,14);         //SIGNIN BOX
    bar(130,200,370,350);
    setfillstyle(SOLID_FILL,0);
    bar(225,222,360,240);            //USERNAME
    bar(225,255,360,273);            //PASSWORD
    setfillstyle(SOLID_FILL,7);         //SIDEBAR
    bar(499,0,639,479);
    setfillstyle(SOLID_FILL,0);
    bar(505,20,635,170);
    logo(568,95,5,3);        //logo
    setfillstyle(SOLID_FILL,4);
    bar(220,300,280,325);	//SIGN UP BUTTON
    bar(499,215,639,235);	//CREATE ACCOUNT
    bar(499,265,639,285);       //FORGOT PASSWORD
    bar(499,315,639,335);       //EXIT
    setcolor(14);
    outtextxy(222,310,"SIGN_IN");
    setcolor(0);
    outtextxy(138,228,"User_name");
    outtextxy(138,261,"Password");
    outtextxy(513,222,"CREATE ACCOUNT");
    outtextxy(512,272,"FORGOT PASSWORD");
    outtextxy(550,322,"EXIT");
mouse_signin:
    mouse();
    check_mouse=mouse_click_for_signin();
    switch(check_mouse)
    {
    case 1:
	gotoxy(30,15);
	cin.getline(username,20);
	gotoxy(30,17);
	dum=0;
	for(int dum1=0; dum1<20; dum1++)
	    password[dum1]='\0';
	do
	{
	    passch=getch();
	    if(passch!=8&&passch!=13)
	    {
		password[dum++]=passch;
		if(dum<16)
		cout<<"*";
	    }
	    else if(passch==8&&dum>0)
	    {
		password[--dum]='\0';
		setfillstyle(SOLID_FILL,0);
		bar(225,255,360,273);         //password clear block
		gotoxy(30,17);
		for(dum1=0; dum1<dum; dum1++)
		{
		    cout<<"*";
		}
	    }
	}
	while(passch!=13&&dum<20);
	goto mouse_signin;
    case 2:
	goto out;
    case 3:
	check_save=ur.get_data();
	if(check_save==0)
	{
	    ofstream filout;
	    filout.open("user",ios::app|ios::binary);
	    filout.write((char *) &ur,sizeof(ur));
	    filout.close();
	}
	goto refill;
    case 4:
    {
	setfillstyle(SOLID_FILL,0);
	bar(225,222,360,240);           //USERNAME
	bar(225,255,360,273);           //DOB
	setfillstyle(SOLID_FILL,7);         //SIDEBAR
	bar(499,200,639,479);
	setfillstyle(SOLID_FILL,4);         //ENTER BUTTON
	bar(220,300,280,325);
	setcolor(15);
	outtextxy(230,310,"ENTER");
	setcolor(0);
	outtextxy(138,228,"User_name");
	setfillstyle(SOLID_FILL,14);
	bar(130,260,220,280);
	outtextxy(140,261,"DOB");
se_signin:
	mouse();
	int check=mouse_click_for_signin();
	if(check!=1)
	    goto se_signin;
	gotoxy(30,15);
	cin.getline(username,20);
	gotoxy(30,17);
	cin.getline(dob,15);
again:
	mouse();
	int check5=mouse_click_for_signin();
	if(check5!=2)
	    goto again;
	ifstream filinf;
	filinf.open("user",ios::in|ios::binary);
	filinf.seekg(0);
	while(filinf)
	{
	    filinf.read((char *) &ur,sizeof(ur));
	    if(strcmp(username,ur.user_name)==0&&strcmp(dob,ur.dob)==0)
	    {
		check1=0;
		break;
	    }
	}
	filinf.close();
	if(check1==0)
	{
	    cleardevice();
	    setfillstyle(SOLID_FILL,7);
	    bar(180,120,420,300);
	    setcolor(0);
	    settextstyle(0,0,2);
	    outtextxy(250,150,"YOUR");
	    outtextxy(210,200,"PASSWORD IS");
	    setcolor(9);
	    outtextxy(240,260,ur.user_pass);
	    delay(3000);
	    settextstyle(0,0,1);
	    cleardevice();
	    setcolor(15);
	    goto refill;
	}
	else
	{
	    cleardevice();
	    setcolor(4);
	    settextstyle(0,0,3);
	    outtextxy(100,230,"WRONG INFO!!!!!!");
	    mouse();
	    settextstyle(0,0,1);
	    goto refill;
	}
    }
    case 5 :
	exit(0);
    default:
	goto mouse_signin;
    }
out:
    cleardevice();
    ifstream filin;
    filin.open("user",ios::in|ios::binary);
    filin.seekg(0);
    while(filin)
    {
	filin.read((char *) &ur,sizeof(ur));
	if(strcmp(username,ur.user_name)==0&&strcmp(password,ur.user_pass)==0)
        {
            signin_sucess();
            check=0;
            break;
        }
    }
    if(check!=0)
    {
	wrong_password();
	mouse();
	goto refill;
    }
    filin.close();
    return ur;
}
int book_display(int operation)
{
    book bk8;
    int last=0,i,buk_issue_id,pos=1,buk_id,dumy1=0;
re_diplay:
    dumy1=0;
    ifstream  filebookdispdumy;
    filebookdispdumy.open("book",ios::in|ios::binary|ios::ate);
    filebookdispdumy.seekg(0);
    while(filebookdispdumy)
    {
	filebookdispdumy.read((char *) &bk8,sizeof(bk8));
	dumy1++ ;
    }
    filebookdispdumy.close();
    clrscr();
    cleardevice();
    last=0;
    ifstream  filebookdisp;
    filebookdisp.open("book",ios::in|ios::binary|ios::ate);
    setcolor(15);
    outtextxy(70,100,"BOOK NAME");
    outtextxy(350,100,"AUTHOR");
    outtextxy(510,100,"PRICE");
    setfillstyle(SOLID_FILL, BLUE);
    bar(0,0,639,90);
    settextstyle(0,0,4);
    switch(operation)
    {
    case 1:
        outtextxy(160,30,"ISSUE BOOK");
        break;
    case 2:
        outtextxy(180,30,"BUY BOOK");
        break;
    case 3:
        outtextxy(180,30,"READ BOOK");
        break;
    case 4:
        outtextxy(170,30,"DELETE BOOK");
        break;
    }
    settextstyle(0,0,1);
    exit_button();
    if(pos>4)
    {
        setfillstyle(SOLID_FILL,9);
        bar(39,330,130,360);
        outtextxy(55,342,"PREVIOUS");
    }
    if(dumy1>5)
    {
        setfillstyle(SOLID_FILL,1);
        bar(510,330,590,360);
        outtextxy(535,342,"NEXT");
    }
    setfillstyle(SOLID_FILL,1);
    filebookdisp.seekg(0);
    for(int k=0; k<pos; ++k)
    {
        filebookdisp.read((char *) &bk8,sizeof(bk8));
    }
    setcolor(15);
    int dumy[4]= {0,0,0,0};
    int d,f=10;
    for(d=148,i=0; i<4&&filebookdisp!=0; d+=48,f+=3,++i)
    {
        rectangle(40,d-11,590,d+21);
        dumy[i]=bk8.book_id;
        gotoxy(8,f);
        cout<<bk8.book_name;
        gotoxy(65,f);
        cout<<bk8.price;
        gotoxy(42,f);
        cout<<bk8.author;
        filebookdisp.read((char *) &bk8,sizeof(bk8));
        ++pos;
        last++;
    }
re_ans:
    mouse();
    buk_issue_id=mouse_click_for_display();
    switch(buk_issue_id)
    {
    case 0:
    case 1:
    case 2:
    case 3:
        if(dumy[buk_issue_id]==0)
            goto re_ans;
        buk_id=dumy[buk_issue_id];
        filebookdisp.close();
        break;
    case 4:
        filebookdisp.close();
        if(pos>8)
            pos-=(4+last);
        else
            pos=1;
        goto re_diplay;
    case 5:
        if( filebookdisp==0)
        {
            pos=1;
            filebookdisp.close();
        }
        goto re_diplay;
    case 6:
        filebookdisp.close();
        return -1;
    default:
        goto re_ans;
    }
    return buk_id;
}
void setting_button(int xu,int yu)
{
    setcolor(colour2);
    setfillstyle(1,colour2);
    sector(xu,yu,0,360,15,19);
//////////////////////////////////////////white circle
    setcolor(colour1);
    setfillstyle(1,colour1);
    sector(xu,yu,0,360,7,11);
////////////////////////////////////////////////3
    setcolor(colour2);
    setfillstyle(1,colour2);
    sector(xu,yu-21,0,360,2,2);
////////////////////////////////////////////////black
    sector(xu,yu+21,0,360,2,2);
/////////////////////////////////////////s1
    sector(xu-17,yu,0,360,2,2);
//////////////////////////////////////////////s2
    sector(xu+17,yu,0,360,2,2);
    sector(xu-12,yu-14,0,360,2,2);
////////////////////////////////////////////////////////s3
    sector(xu+12,yu-14,0,360,2,2);
    sector(xu-12,yu+14,0,360,2,2);
    sector(xu+12,yu+14,0,360,2,2);
}
void signin_sucess(void)
{
    cleardevice();
    setfillstyle(SOLID_FILL,7);
    bar(180,120,420,300);
    setcolor(1);
    settextstyle(0,0,2);
    outtextxy(235,150,"YOU HAVE");
    outtextxy(205,200,"SUCCESSFULLY");
    outtextxy(230,260,"LOGGED IN");
    mouse();
    settextstyle(0,0,1);
    setcolor(15);
}
void account_created(void)
{
    cleardevice();
    setfillstyle(SOLID_FILL,7);
    bar(180,120,420,300);
    setcolor(1);
    settextstyle(0,0,2);
    outtextxy(250,150,"ACCOUNT");
    outtextxy(205,200,"SUCCESSFULLY");
    outtextxy(250,260,"CREATED");
    mouse();
    settextstyle(0,0,1);
    setcolor(15);
}
void book_added(void)
{
    cleardevice();
    setfillstyle(SOLID_FILL,7);
    bar(180,120,420,300);
    setcolor(1);
    settextstyle(0,0,2);
    outtextxy(270,150,"BOOK");
    outtextxy(205,200,"SUCCESSFULLY");
    outtextxy(260,260,"ADDED");
    mouse();
    settextstyle(0,0,1);
    setcolor(15);
}

void issue_sucess(void)
{
    cleardevice();
    setfillstyle(SOLID_FILL,7);
    bar(180,120,420,290);
    setcolor(1);
    settextstyle(0,0,2);
    outtextxy(235,150,"YOU HAVE");
    outtextxy(205,200,"SUCCESSFULLY");
    outtextxy(180,250,"ISSUED THE BOOK");
    mouse();
    settextstyle(0,0,1);
}
void buy_sucess(void)
{
    cleardevice();
    setfillstyle(SOLID_FILL,7);
    bar(180,120,420,290);
    setcolor(1);
    settextstyle(0,0,2);
    outtextxy(235,150,"YOU HAVE");
    outtextxy(205,200,"SUCCESSFULLY");
    outtextxy(190,250,"BUYED THE BOOK");
    mouse();
    settextstyle(0,0,1);
}
void return_sucess(void)
{
    cleardevice();
    setfillstyle(SOLID_FILL,7);
    bar(170,120,450,290);
    setcolor(1);
    settextstyle(0,0,2);
    outtextxy(240,150,"YOU HAVE");
    outtextxy(210,200,"SUCCESSFULLY");
    outtextxy(175,250,"RETURNED THE BOOK");
    mouse();
    settextstyle(0,0,1);
    setcolor(15);
}
char return_confirm(void)
{
    cleardevice();
    setfillstyle(SOLID_FILL,7);
    bar(200,130,410,280);
    setfillstyle(SOLID_FILL,1);
    bar(230,230,280,260);
    bar(330,230,380,260);
    setcolor(4);
    settextstyle(0,0,1);
    outtextxy(255,150,"Are You Sure ");
    outtextxy(225,190,"to RETURN the book  ?");
    outtextxy(245,240,"YES");
    outtextxy(350,240,"NO");
mouse_return:
    mouse();
    char return_choice=mouse_click_for_dialoge_box();
    if(return_choice!='y'&&return_choice!='n')
        goto mouse_return;
    else
        settextstyle(0,0,1);
    return return_choice;
}
void sell_sucess(void)
{
    cleardevice();
    setfillstyle(SOLID_FILL,7);
    bar(180,120,420,290);
    setcolor(1);
    settextstyle(0,0,2);
    outtextxy(235,150,"YOU HAVE");
    outtextxy(205,200,"SUCCESSFULLY");
    outtextxy(200,250,"SOLD THE BOOK");
    mouse();
    settextstyle(0,0,1);
}
char sell_confirm(void)
{
    cleardevice();
    setfillstyle(SOLID_FILL,7);
    bar(200,130,410,280);
    setfillstyle(SOLID_FILL,4);
    bar(230,230,280,260);
    bar(330,230,380,260);
    setcolor(0);
    settextstyle(0,0,1);
    outtextxy(255,150,"Are You Sure ");
    outtextxy(225,190,"to SELL the book  ?");
    outtextxy(245,240,"YES");
    outtextxy(350,240,"NO");
mouse_sell:
    mouse();
    char sell_choice=mouse_click_for_dialoge_box();
    if(sell_choice!='y'&&sell_choice!='n')
        goto mouse_sell;
    else
        settextstyle(0,0,1);
    return sell_choice;
}
char deletebook_confirm(void)
{
    cleardevice();
    setfillstyle(SOLID_FILL,7);
    bar(200,130,410,280);
    setfillstyle(SOLID_FILL,4);
    bar(230,230,280,260);
    bar(330,230,380,260);
    setcolor(0);
    settextstyle(0,0,1);
    outtextxy(255,150,"Are You Sure ");
    outtextxy(225,190,"to DELETE the Book  ?");
    outtextxy(245,240,"YES");
    outtextxy(350,240,"NO");
mouse_del:
    mouse();
    char del_choice=mouse_click_for_dialoge_box();
    if(del_choice!='y'&&del_choice!='n')
        goto mouse_del;
    else
        return del_choice;
}
char deleteuser_confirm(void)
{
    cleardevice();
    setfillstyle(SOLID_FILL,7);
    bar(200,130,410,280);
    setfillstyle(SOLID_FILL,4);
    bar(230,230,280,260);
    bar(330,230,380,260);
    setcolor(0);
    settextstyle(0,0,1);
    outtextxy(255,150,"Are You Sure ");
    outtextxy(225,190,"to REMOVE the user  ?");
    outtextxy(245,240,"YES");
    outtextxy(350,240,"NO");
mouse_deluser:
    mouse();
    char deluser_choice=mouse_click_for_dialoge_box();
    if(deluser_choice!='y'&&deluser_choice!='n')
        goto mouse_deluser;
    else
        settextstyle(0,0,1);
    setcolor(15);
    return deluser_choice;
}
void logo(int x,int y,int xrad1,int diff)
{
    setlinestyle(SOLID_LINE,1,0);
    int xrad2,xrad3,xrad4,xrad5;
    xrad2=xrad1+(3*diff);
    xrad3=xrad2+(4*diff);
    xrad4=xrad3+(5*diff);
    xrad5=xrad4+(6*diff);
    setcolor(0);
    //FIRST
    setfillstyle(SOLID_FILL, 0);
    sector(x,y, 0, 90, xrad5, xrad5);
    setfillstyle(SOLID_FILL, 6);
    sector(x,y, 0, 90, xrad4, xrad4);
    setfillstyle(SOLID_FILL, 0);
    sector(x,y, 0, 90, xrad3, xrad3);
    setfillstyle(SOLID_FILL, 6);
    sector(x,y, 0, 90, xrad2, xrad2);
    setfillstyle(SOLID_FILL, 0);
    sector(x,y, 0, 90, xrad1, xrad1);
    //SECOND
    setfillstyle(SOLID_FILL, 15);
    sector(x, y, 90, 180, xrad5, xrad5);
    setfillstyle(SOLID_FILL, 0);
    sector(x, y, 90, 180, xrad4, xrad4);
    setfillstyle(SOLID_FILL, 6);
    sector(x, y, 90, 180, xrad3, xrad3);
    setfillstyle(SOLID_FILL, 0);
    sector(x, y, 90, 180, xrad2, xrad2);
    setfillstyle(SOLID_FILL, 0);
    sector(x, y, 90, 180, xrad1, xrad1);
    //THIRD
    setfillstyle(SOLID_FILL, 0);
    sector(x, y, 180, 270, xrad5, xrad5);
    setfillstyle(SOLID_FILL, 6);
    sector(x, y, 180, 270, xrad4, xrad4);
    setfillstyle(SOLID_FILL, 0);
    sector(x, y, 180, 270, xrad3, xrad3);
    setfillstyle(SOLID_FILL, 6);
    sector(x, y, 180, 270, xrad2, xrad2);
    setfillstyle(SOLID_FILL, 0);
    sector(x, y, 180, 270, xrad1, xrad1);
    //FOURTH
    setfillstyle(SOLID_FILL, 15);
    sector(x, y, 270, 360, xrad5, xrad5);
    setfillstyle(SOLID_FILL, 0);
    sector(x, y, 270, 360, xrad4, xrad4);
    setfillstyle(SOLID_FILL, 6);
    sector(x, y, 270, 360, xrad3, xrad3);
    setfillstyle(SOLID_FILL, 0);
    sector(x, y, 270, 360, xrad2, xrad2);
    setfillstyle(SOLID_FILL, 0);
    sector(x, y, 270, 360, xrad1, xrad1);
    setlinestyle(0,1,3);
}
void loading(void)
{
    clrscr();
    cleardevice();
    setlinestyle(SOLID_LINE,1,0);
    int x=320,y=200,xrad1=10,diff=5,xrad2,xrad3,xrad4,xrad5;
    xrad2=xrad1+(3*diff);
    xrad3=xrad2+(4*diff);
    xrad4=xrad3+(5*diff);
    xrad5=xrad4+(6*diff);
    delay(200);
    //FIRST
    for(int i=0; i<3; ++i)
    {
	cleardevice();
	setcolor(2);
	settextstyle(0,0,2);
	outtextxy(235,380,"LOADING");
	setcolor(0);
	setfillstyle(SOLID_FILL, 0);
	sector(x,y, 0, 90, xrad5, xrad5);
	setfillstyle(SOLID_FILL, 6);
	sector(x,y, 0, 90, xrad4, xrad4);
	setfillstyle(SOLID_FILL, 0);
	sector(x,y, 0, 90, xrad3, xrad3);
	setfillstyle(SOLID_FILL, 6);
	sector(x,y, 0, 90, xrad2, xrad2);
	setfillstyle(SOLID_FILL, 0);
	sector(x,y, 0, 90, xrad1, xrad1);
	delay(500);
	//SECOND
	setcolor(4);
	settextstyle(0,0,2);
	outtextxy(345,380,".");
	setcolor(0);
	setfillstyle(SOLID_FILL, 15);
	sector(x, y, 90, 180, xrad5, xrad5);
	setfillstyle(SOLID_FILL, 0);
	sector(x, y, 90, 180, xrad4, xrad4);
	setfillstyle(SOLID_FILL, 6);
	sector(x, y, 90, 180, xrad3, xrad3);
	setfillstyle(SOLID_FILL, 0);
	sector(x, y, 90, 180, xrad2, xrad2);
	setfillstyle(SOLID_FILL, 0);
	sector(x, y, 90, 180, xrad1, xrad1);
	delay(500);
	//THIRD
	setcolor(4);
	settextstyle(0,0,2);
	outtextxy(355,380,".");
	setcolor(0);
	setfillstyle(SOLID_FILL, 0);
	sector(x, y, 180, 270, xrad5, xrad5);
	setfillstyle(SOLID_FILL, 6);
	sector(x, y, 180, 270, xrad4, xrad4);
	setfillstyle(SOLID_FILL, 0);
	sector(x, y, 180, 270, xrad3, xrad3);
	setfillstyle(SOLID_FILL, 6);
	sector(x, y, 180, 270, xrad2, xrad2);
	setfillstyle(SOLID_FILL, 0);
	sector(x, y, 180, 270, xrad1, xrad1);
	delay(500);
	//FOURTH
	setcolor(4);
	settextstyle(0,0,2);
	outtextxy(365,380,".");
	setcolor(0);
	setfillstyle(SOLID_FILL, 15);
	sector(x, y, 270, 360, xrad5, xrad5);
	setfillstyle(SOLID_FILL, 0);
	sector(x, y, 270, 360, xrad4, xrad4);
	setfillstyle(SOLID_FILL, 6);
	sector(x, y, 270, 360, xrad3, xrad3);
	setfillstyle(SOLID_FILL, 0);
	sector(x, y, 270, 360, xrad2, xrad2);
	setfillstyle(SOLID_FILL, 0);
	sector(x, y, 270, 360, xrad1, xrad1);
	delay(500);
    }
    setlinestyle(0,1,3);
}
void exit_button(void)
{
    setfillstyle(SOLID_FILL,4);
    bar(600,0,639,20);
    setcolor(15);
    settextstyle(0,0,1);
    outtextxy(615,8,"X");
}
/***************************************************************
*              FUNCTION TO CHECK MOUSE CORDINATES              *
***************************************************************/
int mouse_click_for_change_theme()
{
    int i,j,k,l;
    if(cor_x>=600&&cor_x<639&&cor_y>0&&cor_y<20)
	return 0;
    for(i=10,j=1; j<=15; i+=30,j++)
	for(k=50,l=0; k<=220; k+=80,l++)
	{
	    if(cor_x>=i&&cor_x<=i+20&&cor_y>=k&&cor_y<=k+50)
		return ((15*l)+j);
	}
    return 50;
}
int mouse_click_for_setting(void)
{
    if(cor_x>=400&&cor_x<639&&cor_y>35&&cor_y<65)
	return 1;
    else if(cor_x>=400&&cor_x<639&&cor_y>85&&cor_y<115)
	return 2;
    else if(cor_x>=400&&cor_x<639&&cor_y>135&&cor_y<165)
	return 3;
    else if(cor_x>=400&&cor_x<639&&cor_y>185&&cor_y<215)
	return 4;
    else if(cor_x>=400&&cor_x<639&&cor_y>235&&cor_y<265)
	return 5;
    else if(cor_x>=400&&cor_x<639&&cor_y>285&&cor_y<315)
	return 6;
    else if(cor_x>=600&&cor_x<639&&cor_y>0&&cor_y<20)
	return 7;
    else if(cor_x>=400&&cor_x<639&&cor_y>335&&cor_y<365)
	return 8;
    else
	return 0;
}
int mouse_click_for_signin (void)
{
    if(cor_x>=215 && cor_x<350 && cor_y>220&& cor_y<241)
	return 1;
    else if(cor_x>=210 && cor_x<270 && cor_y>300&& cor_y<325)
	return 2;
    else if(cor_x>=499 && cor_x<639 && cor_y>215&& cor_y<235)
	return 3;
    else if(cor_x>=499 && cor_x<640 && cor_y>265&& cor_y<285)
	return 4;
    else if(cor_x>=499 && cor_x<639 && cor_y>315&& cor_y<335)
	return 5;
    else
	return 0;
}
char mouse_click_for_dialoge_box (void)
{
    if(cor_x>=230 && cor_x<280 && cor_y>230&& cor_y<260)
	return 'y';
    else if(cor_x>=330 && cor_x<380 && cor_y>230&& cor_y<260)
	return 'n';
    else
	return 'r';
}
int mouse_click_for_signup (void)
{
    if(cor_x>=275 && cor_x<520 && cor_y>94&& cor_y<112)
	return 1;
    else if(cor_x>=275 && cor_x<520 && cor_y>126&& cor_y<144)
	return 2;
    else if(cor_x>=275 && cor_x<520 && cor_y>158&& cor_y<176)
	return 3;
    else if(cor_x>=275 && cor_x<520 && cor_y>190&& cor_y<208)
	return 4;
    else if(cor_x>=275 && cor_x<520 && cor_y>222&& cor_y<240)
	return 5;
    else if(cor_x>=275 && cor_x<520 && cor_y>254&& cor_y<272)
	return 6;
    else if(cor_x>=275 && cor_x<520 && cor_y>286&& cor_y<304)
	return 7;
    else if(cor_x>=600 && cor_x<639 && cor_y>0&& cor_y<20)
	return 8;
    else if(cor_x>=240 && cor_x<400 && cor_y>400&& cor_y<430)
        return 9;
    else
        return 0;
}
int mouse_click_for_display(void)
{
    if(cor_x>=40 && cor_x<590 && cor_y>=137&& cor_y<=169)
        return 0;
    else if(cor_x>=40 && cor_x<590 && cor_y>=185&& cor_y<=217)
        return 1;
    else if(cor_x>=40 && cor_x<590 && cor_y>=233&& cor_y<=265)
        return 2;
    else if(cor_x>=40 && cor_x<590 && cor_y>=281&& cor_y<=313)
        return 3;
    else if(cor_x>=39 && cor_x<130 && cor_y>=330&& cor_y<=360)
        return 4;
    else if(cor_x>=510 && cor_x<590 && cor_y>=330&& cor_y<=360)
        return 5;
    else if(cor_x>=600 && cor_x<639 && cor_y>0&& cor_y<20)
        return 6;
    else
        return -1;
}
int mouse_click_for_readbook(void)
{
    if(cor_x>=600 && cor_x<639 && cor_y>0&& cor_y<20)
        return 1;
    else if(cor_x>=20 && cor_x<80 && cor_y>170&& cor_y<200)
        return 2;
    else
        return -1;
}
int mouse_click_for_add_book(void)
{
    if(cor_x>=80 && cor_x<505 && cor_y>126&& cor_y<144)
        return 1;
    else if(cor_x>=600 && cor_x<639 && cor_y>0&& cor_y<20)
        return 2;
    else if(cor_x>=240 && cor_x<440 && cor_y>400&& cor_y<470)
        return 3;
    else
        return 0;
}
int mouse_click_for_regular_home(void)
{
    if(cor_x>=12 && cor_x<460 && cor_y>110&& cor_y<220)
        return 1;
    else if(cor_x>=12 && cor_x<460 && cor_y>230&& cor_y<340)
        return 2;
    else if(cor_x>=12 && cor_x<460 && cor_y>350&& cor_y<460)
        return 3;
    else if(cor_x>=5 && cor_x<85 && cor_y>0&& cor_y<80)
        return 4;
    else if(cor_x>=95 && cor_x<175 && cor_y>0&& cor_y<80)
        return 5;
    else if(cor_x>=185 && cor_x<275 && cor_y>0&& cor_y<80)
        return 6;
    else if(cor_x>=285 && cor_x<365 && cor_y>0&& cor_y<80)
        return 7;
    else if(cor_x>=375 && cor_x<455 && cor_y>0&& cor_y<80)
        return 8;
    else
        return 0;
}
int mouse_click_for_premium_home(void)
{
    if(cor_x>=12 && cor_x<460 && cor_y>110&& cor_y<160)
        return 1;
    else if(cor_x>=12 && cor_x<460 && cor_y>165&& cor_y<215)
        return 2;
    else if(cor_x>=12 && cor_x<460 && cor_y>220&& cor_y<270)
        return 3;
    else if(cor_x>=12 && cor_x<460 && cor_y>310&& cor_y<360)
        return 4;
    else if(cor_x>=12 && cor_x<460 && cor_y>365&& cor_y<415)
        return 5;
    else if(cor_x>=12 && cor_x<460 && cor_y>420&& cor_y<470)
        return 6;
    else if(cor_x>=5 && cor_x<71 && cor_y>0&& cor_y<80)
        return 7;
    else if(cor_x>=76 && cor_x<136 && cor_y>0&& cor_y<80)
        return 8;
    else if(cor_x>=141 && cor_x<201 && cor_y>0&& cor_y<80)
        return 9;
    else if(cor_x>=206 && cor_x<271 && cor_y>0&& cor_y<80)
        return 10;
    else if(cor_x>=271 && cor_x<336 && cor_y>0&& cor_y<80)
        return 11;
    else if(cor_x>=336 && cor_x<399 && cor_y>0&& cor_y<80)
        return 12;
    else if(cor_x>=404 && cor_x<455 && cor_y>0&& cor_y<80)
        return 13;
    else
        return 0;
}
int mouse_click_for_admin_home(void)
{
    if(cor_x>=9 && cor_x<79 && cor_y>0&& cor_y<80)
        return 1;
    else if(cor_x>=85 && cor_x<155 && cor_y>0&& cor_y<80)
        return 2;
    else if(cor_x>=161 && cor_x<231 && cor_y>0&& cor_y<80)
        return 3;
    else if(cor_x>=237 && cor_x<307 && cor_y>0&& cor_y<80)
        return 4;
    else if(cor_x>=313 && cor_x<383 && cor_y>0&& cor_y<80)
        return 5;
    else if(cor_x>=389 && cor_x<459 && cor_y>0&& cor_y<80)
        return 6;
    else
        return 0;
}
/***************************************************************
*          END OF FUNCTION TO CHECK MOUSE CORDINATES           *
***************************************************************/
/***************************************************************
*                  END OF FUNCTION DEFINATION                  *
***************************************************************/
/***************************************************************
*                          END OF PROGRAM                      *
***************************************************************/
