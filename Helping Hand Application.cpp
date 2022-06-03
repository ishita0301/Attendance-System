#include <bits/stdc++.h>
#include<conio.h> //clscr()  getch() 
using namespace std;
vector<vector<string>>v;
vector<pair<string,string>>str;
vector<string>st;
vector<vector<string>>v1;
 
class application{ //ABSTRACT CLASS
protected:
    string user_name,password,email,gender,dob,phone;
    int follower,following;
public:
    virtual void create_account()=0;
    virtual string create(int)=0;
    virtual void search_account(string,string)=0;
    virtual void update_account(string)=0;//PURE VIRTUAL FUN
    virtual void delete_account(string)=0;
    virtual void follow(string,string)=0;
    virtual void Following(string)=0;
    virtual void back()=0;
    virtual void intro()//VIRTUAL FUNTION
    {
        cout<<"Intro\n";
        getch();
    }
    virtual void Helping_Hand()=0;
    virtual void login()=0;
    virtual void menu(string)=0;
    virtual int check(string,string)=0;
    virtual void view_following(string)=0;
    virtual void view_follower(string)=0;
};
class app:public application{//INHERITANCE
public:
    void showdata(int i)
    {
         cout<<"User Name(Without Quotes): "<<v[i][0]<<"\n\n";
       // cout<<"Email-id: "<<v[i][1]<<"\n\n";
        cout<<"Gender: "<<v[i][5]<<"\n\n";
        cout<<"Date of Birth(dd-mm-yy): "<<v[i][3]<<"\n\n";
        cout<<"Followers: "<<v[i][6]<<"\n\n";
        cout<<"Following: "<<v[i][7]<<"\n\n";
    }
     void * operator new(size_t size)//OPERATOR OVERLOADING
    {
        cout<< "Overloading new operator " ;
        getch();
        void * p = malloc(size);
        return p;
    }
    void create_account();
    string create(int);
    void search_account(string,string);
    void update_account(string);
    void delete_account(string);
    void follow(string,string);//FUNTION OVERRIDING
    void Following(string);
    void back();
    void intro();
    void Helping_Hand();
    void login();
    void menu(string);
    int check(string,string);
    void view_following(string);
    void view_follower(string);
    void message(string);
    void message(string,string);//FUNCTION OVERLOADING
};
void app::intro()
{
    cout<<"\n\n\n\n";
    cout<<"\t\t\t\t\t\t Helping_Hand Application";
    cout<<"\n\n\n";
    cout<<"\t\t\t\t\t\t Connect With Your Mentors";
    cout<<"\n\n\nPress any key to continue";
    getch();
    Helping_Hand();
}
void app::Helping_Hand()
{
    system("cls");
    int choice;
    cout<<"\n\n\n\t\t\t==========================================================";
    cout<<"\n\n\t\t\t\t             Helping_Hand Application              ";
    cout<<"\n\n\n\t\t\t==========================================================";
    cout<<"\n\n\n1. Create Account";
    cout<<"\n2. Login Account";
    cout<<"\n3. Exit";
    cout<<"\n\nEnter your choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        create_account();
        break;
    case 2:
        login();
        break;
    case 3:
        exit(0);
    default:
        cout<<"\n\n\nInvalid choice, Please Try Again";
        getch();
        Helping_Hand();
    }
    getch();
}
 
void app::create_account()
{
    system("cls");
     cin.ignore();
    cout<<"\n\n\t\t\tCreate Account: ";
    int i,flag=0,j;
    vector<string>s;
    for(i=0;i<7;i++)
    {
        if(i==0){
            try//EXCEPTIONAL HANDLING
            {
            cout<<"\n\n\nUser Name(Without Quotes): ";
            cin.ignore();
            getline(cin,user_name);
            for(j=0;j<st.size();j++){
                if(st[j]==user_name)
                    break;
            }
            if(j==st.size()){
                st.push_back(user_name);
            }
            else{
                throw user_name;
            }
        }
        catch(string user)
        {
            cout<<"This User Name Exists.....Change Your User Name";
            flag=1;
            getch();
            break;
        }
            s.push_back(user_name);
        }
        else if(i==1){
            cout<<"\n\nE-mail: ";
            cin.ignore();
            getline(cin,email);
            s.push_back(email);
        }
        else if(i==2){
            cout<<"\n\nEnter Password: ";
            cin.ignore();
            getline(cin,password);
            s.push_back(password);
        }
        else if(i==3){
            cout<<"\n\nEnter Date of Birth(dd-mm-yyyy): ";
            cin.ignore();
            getline(cin,dob);
            s.push_back(dob);
        }
        else if(i==4){
            cout<<"\n\nEnter Phone Number: ";
            cin.ignore();
            getline(cin,phone);
            s.push_back(phone);
        }
        else if(i==5){
            cout<<"\n\nEnter Gender (Male/Female/Other): ";
            cin.ignore();
            getline(cin,gender);
            s.push_back(gender);
        }
        else{
            cin.ignore();
            s.push_back("0");
            cin.ignore();
            s.push_back("0");
        }
    }
    if(flag==0){
      v.push_back(s);
    Helping_Hand();
    }
    else
        create_account();
}
void app::login()
{
    system("cls");
    int c=0,i;
    cout<<"\n\n\n\t\t\t\t\tEnter Password and Email to Login";
    string pass,e;
    cout<<"\n\n\nEnter Password: ";
    cin.ignore();
    getline(cin,pass);
    cout<<"\n\n\nEnter Email: ";
    cin.ignore();
    getline(cin,e);
    for(i=0;i<v.size();i++){
        if(v[i][1]==e && v[i][2]==pass){
            c++;
            menu(pass);
        }
    }
    if(c==0){
        cout<<"........Invalid User........";
        getch();
        Helping_Hand();
    }
}
void app::menu(string pass)
{
    system("cls");
    int choice;
    string s;
    for(int i=0;i<v.size();i++){
        if(pass==v[i][2]){
            cout<<"\n\n"<<"Login User Name: "<<v[i][0];
            break;
        }
    }
    string caller_user,user;
    cout<<"\n\n\n 1. Search Account";
    cout<<"\n 2. Update Account";
    cout<<"\n 3. Delete Account";
    cout<<"\n 4. Follow";
    cout<<"\n 5. View Following";
    cout<<"\n 6. View Followers";
    cout<<"\n 7. Messages";
    cout<<"\n 8. Reply Message";
    cout<<"\n 9. Back";
    cout<<"\n\nEnter your choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<"Enter User Name For Searching: ";
        cin.ignore();
        getline(cin,s);
        search_account(s,pass);
        break;
    case 2:
        cout<<"Enter password for Updating Your Account: ";
        cin.ignore();
        getline(cin,s);
        update_account(s);
        break;
    case 3:
        cout<<"Enter password for Deleting Your Account: ";
        cin.ignore();
        getline(cin,s);
        delete_account(s);
        break;
    case 4:
        cout<<"\nEnter User Name For Following: ";
        cin.ignore();
        getline(cin,s);
        follow(pass,s);
        break;
    case 5:
        view_following(pass);
        break;
    case 6:
        view_follower(pass);
        break;
    case 7:
        cout<<"Enter User Name Whom You Want To Message: ";
        cin.ignore();
        getline(cin,s);
        message(pass,s);
        break;
    case 8:
        message(pass);
        break;
    case 9:
        back();
        break;
    default:
        cout<<"Invalid choice,Try Again";
    }
}
void app::search_account(string s,string pass)
{
    system("cls");
    int i,c=0;
    for(i=0;i<v.size();i++){
        if(v[i][0]==s){
            c++;
            showdata(i);
            break;
        }
    }
    if(c==0)
        cout<<"\n\nInvalid User Name\n";
    getch();
    menu(pass);
 
}
void app::update_account(string pass)
{
    system("cls");
    string p;
    int c=0,i;
    for(i=0;i<v.size();i++){
        if(pass==v[i][2]){
            c++;
            p=create(i);
            break;
        }
    }
    if(c==0)
        cout<<"\n\nWrong Password";
    getch();
    menu(p);
}
string app::create(int j)
{
    int i;
    string s=v[j][0];
    for(i=0;i<st.size();i++){
        if(st[i]==v[j][0]){
            st.erase(st.begin()+i,st.begin()+1+i);
            break;
        }
    }
    for(i=0;i<6;i++)
    {
        if(i==0){
            cout<<"\n\n\nUser Name(Without Quotes): ";
            cin.ignore();
            getline(cin,user_name);
            v[j][i]=user_name;
        }
        else if(i==1){
            cout<<"\n\nE-mail: ";
            cin.ignore();
            getline(cin,email);
            v[j][i]=email;
        }
        else if(i==2){
            cout<<"\n\nEnter Password: ";
            cin.ignore();
            getline(cin,password);
            v[j][i]=password;
        }
        else if(i==3){
            cout<<"\n\nEnter Date of Birth(dd-mm-yy): ";
            cin.ignore();
            getline(cin,dob);
            v[j][i]=dob;
        }
        else if(i==4){
            cout<<"\n\nEnter Phone Number: ";
            cin.ignore();
            getline(cin,phone);
            v[j][i]=phone;
        }
        else if(i==5){
            cout<<"\n\nEnter Gender: ";
            cin.ignore();
            getline(cin,gender);
            v[j][i]=gender;
        }
    }
    for(i=0;i<str.size();i++){
        if(str[i].first==s)
            str[i].first=v[j][0];
        if(str[i].second==s)
            str[i].second=v[j][0];
    }
    for(i=0;i<v1.size();i++){
        if(v1[i][0]==s)
            v1[i][0]=v[j][0];
        if(v1[i][1]==s)
            v1[i][1]=v[j][0];
    }
    st.push_back(v[j][0]);
    getch();
    return v[j][2];
}
void app::delete_account(string pass)
{
    int i,c=0;
    for(i=0;i<v.size();i++){
        if(pass==v[i][2]){
            c++;
            v.erase(v.begin()+i,v.begin()+i+1);
            break;
        }
    }
    if(c==0)
        cout<<"\n\nWrong Password";
    getch();
    Helping_Hand();
}
void app::follow(string pass,string user)
{
    int c=0,i,x,count=2,flag=0;
    string a,b;
    for(i=0;i<v.size();i++){
        if(v[i][2]==pass){
            a=v[i][0];
            break;
        }
    }
    for(i=0;i<v.size();i++)
    {
        if(user==v[i][0])
            c++;
    }
    for(i=0;i<v.size();i++)
    {
        if(user==v[i][0] && v[i][2]!=pass){
            b=user;
            count=check(a,b);
            if(count==1){
            string s=v[i][6];
            x=stoi(s);
            x++;
            s=to_string(x);
            v[i][6]=s;
            break;
            }
            else
                break;
        }
        if(user==v[i][0] && v[i][2]==pass)
            flag=1;
    }
    if(count==0 && flag==0){
        getch();
        menu(pass);
    }
    else{
     if(flag==1)
        cout<<"\nYou Can't Follow Yourself";
    else if(c==0)
        cout<<"Invalid User Name\n";
    else
        Following(pass);
    getch();
    menu(pass);
    }
}
int app::check(string a,string b)
{
    int i;
    for(i=0;i<str.size();i++){
        if(str[i].first==a && str[i].second==b){
            cout<<"\nYou Already Follow This Account";
            return 0;
        }
    }
    if(i==str.size()){
        str.push_back({a,b});
        return 1;
    }
    return 1;
}
void app::Following(string pass)
{
    int i,c=0,x;
    cout<<"You Follow This Account Successfully";
    for(i=0;i<v.size();i++)
    {
        if(pass==v[i][2]){
            c++;
            string s=v[i][7];
            x=stoi(s);
            x++;
            s=to_string(x);
            v[i][7]=s;
            break;
        }
    }
}
void app::view_following(string pass)
{
    system("cls");
    int i,c=0;
   string user;
    for(i=0;i<v.size();i++){
        if(pass==v[i][2]){
            user=v[i][0];
            break;
        }
    }
    for(i=0;i<str.size();i++)
    {
        if(user==str[i].first){
            cout<<str[i].second<<endl;
            c++;
        }
    }
    if(c==0)
        cout<<"\nYou Don't Follow Anyone";
    getch();
    menu(pass);
}
void app::view_follower(string pass)
{
    system("cls");
    int i,c=0;
   string user;
    for(i=0;i<v.size();i++){
        if(pass==v[i][2]){
            user=v[i][0];
            break;
        }
    }
    for(i=0;i<str.size();i++)
    {
        if(user==str[i].second){
            cout<<str[i].first<<endl;
            c++;
        }
    }
    if(c==0)
        cout<<"\nYou Don't Have Follower";
    getch();
    menu(pass);
}
void app::message(string pass,string user)
{
    system("cls");
    string caller_user;
    vector<string>s1;
    int i,c=0;
    for(i=0;i<v.size();i++){
        if(pass==v[i][2]){
            caller_user=v[i][0];
            break;
        }
    }
    if(caller_user==user){
        cout<<"\n\nYou Can't Message Yourself";
        getch();
        menu(pass);
    }
    else{
     for(i=0;i<st.size();i++){
        if(user==st[i])
            break;
    }
    if(i==st.size()){
        cout<<"\n\nInvalid User";
        getch();
        menu(pass);
    }
    else{
     for(i=0;i<v.size();i++){
        if(pass==v[i][2]){
            caller_user=v[i][0];
            break;
        }
    }
    string s;
    cout<<"Enter Message: ";
    cin.ignore();
    getline(cin,s);
    for(i=0;i<v1.size();i++){
        if(v1[i][0]==caller_user && v1[i][1]==user){
            v1[i].push_back(s);
            break;
        }
    }
    if(i==v1.size()){
     s1.push_back(caller_user);
    s1.push_back(user);
    s1.push_back(s);
    v1.push_back(s1);
    }
    menu(pass);
    }
    }
}
void app::message(string pass)
{
    system("cls");
    int i,flag=0;
    string caller_user;
    for(i=0;i<v.size();i++){
        if(pass==v[i][2]){
            caller_user=v[i][0];
            break;
        }
    }
    for(i=0;i<v1.size();i++){
        if(caller_user==v1[i][1]){
            flag=1;
            cout<<v1[i][0]<<endl;
        }
    }
 
    if(flag==0){
        cout<<"\n\nNo Messages From Anyone";
        getch();
        menu(pass);
    }
    else{
      cout<<"\nEnter User Name Whom You Want To See Messages: ";
    string s;
    cin.ignore();
    getline(cin,s);
    flag=0;
    for(i=0;i<st.size();i++){
        if(st[i]==s){
            flag=1;
            break;
        }
    }
    if(s==caller_user){
        cout<<"\n\nYou Can't Reply Yourself";
        getch();
        menu(pass);
    }
    else if(flag==0){
        cout<<"\n\nInvalid User Name";
        getch();
        menu(pass);
    }
    else{
        flag=0;
      for(i=0;i<v1.size();i++){
        if(s==v1[i][0] && caller_user==v1[i][1]){
            for(int j=2;j<v1[i].size();j++){
                cout<<v1[i][j];
                cout<<endl;
            }
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"\n\nThere Is No Message From This User";
        getch();
        menu(pass);
    }
    else{
         cout<<"\n\nDo You Want To Reply This User(y/n): ";
    string s2;
    cin>>s2;
    if(s2[0]=='y'){
        vector<string>s1;
        s2.clear();
        cout<<"\n\nEnter Message: ";
        cin.ignore();
        getline(cin,s2);
        for(i=0;i<v1.size();i++){
            if(v1[i][1]==s && v1[i][0]==caller_user){
                v1[i].push_back(s2);
                break;
            }
        }
        if(i==v1.size()){
         s1.push_back(caller_user);
        s1.push_back(s);
        s1.push_back(s2);
        v1.push_back(s1);
        }
    }
    getch();
    menu(pass);
    }
    }
}
}
void app::back()
{
    system("cls");
    cout<<"Press any key to go main menu";
    getch();
    Helping_Hand();
}
int main()
{
    application *p=new app;//BASE POINTER
    p->intro();
    delete p;
}
