#include<bits/stdc++.h>
#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
 
#define V 9
using namespace std;
int I=1;
 
/*bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
     return (a.second < b.second);
}
void sortbyname(vector<pair<int,string> > &vnid)
{
sort(vnid.begin(), vnid.end(), sortbysec);
}*/
void sortbyID(vector<pair<int,string> > &vnid)
{
sort(vnid.begin(), vnid.end());
}
void searchname(vector<pair<int,string> > vnid,string nm)
{
    int cnt=0;
    for(auto x:vnid)
    {
        int i=0,j=0;
        for(i=0;i<x.second.length();i++)
        {
            if(x.second[i]==nm[j])
            j++;
            else
            j=0;
            if(j==nm.length())
             {
            cnt++;
             }
        }
    }
    if(cnt){
    cout<<"Found!! There are "<<cnt<<" matches as follows:\n";
    int i=0,j=0;
    for(auto x:vnid){
        for(i=0;i<x.second.length();i++)
        {
            if(x.second[i]==nm[j])
            j++;
            else
            j=0;
            if(j==nm.length())
              {
            cout<<"ID: "<<x.first<<" , Name: "<<x.second<<endl;
              }
        }
    }
    }
    else
    cout<<"Not Found!!"<<endl;
}
void searchID(vector<pair<int,string>> vnid,int sid)
{
    bool flag=0;
    for(auto x:vnid)
    {
        if(x.first==sid)
        {
            flag=true;
            cout<<"Found!!\n";
            cout<<"ID: "<<x.first<<" , Name: "<<x.second<<endl;
            break;
        }
   }
   if(flag==false)
   cout<<"Not Found!!\n";
}
void deletebyID(vector<pair<int,string>> &vnid,int did)
{
    bool flag=0;
    for(auto it=vnid.begin();it!=vnid.end();it++)
    {
        if(it->first==did)
        {
            flag=true;
            cout<<"Deleting!!\n";
            vnid.erase(it);
            break;
        }
   }
   if(flag==false)
   cout<<"No participant by this ID\n";
}
void deletebyname(vector<pair<int,string>> &vnid,string dnm)
{
    bool flag=0;
    for(auto it=vnid.begin();it!=vnid.end();it++)
    {
        if(it->second==dnm)
        {
            flag=true;
            cout<<"Deleting!!\n";
            vnid.erase(it);
            break;
        }
   }
   if(flag==false)
   cout<<"No participant by this Name\n";
}
void dispqueue(queue<pair<int,string>> qf)
{
    while(!qf.empty())
    {
        cout<<"ID: "<<qf.front().first<<",Name: "<<qf.front().second<<endl;
        qf.pop();
    }
}
void showposter(stack<string> pst)
{
    while(!pst.empty())
    {
        cout<<"Poster Name: "<<pst.top()<<endl;
        pst.pop();
    }
}
int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
void printSolution(int dist[])
{
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout  << i << " \t\t"<<dist[i]<< endl;
}
void shortest(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
             if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
     printSolution(dist);
}
 
int main()
{
    vector<pair<int,string>> vnid;
    int wish1,wish2,wish3,wish4;
    system("cls");
   // cout<<"\n\n\n\n";
    cout<<"*********************MADE BY ARYAN KARKRA AND ISHITA********************\n\n";
    cout<<"********************WELCOME TO THE OPEN COLLEGE DRIVE*******************\n";
    cout<<"****************Real World Application of Data Structures***************\n\n";
    cout<<"*******************************Press Enter******************************";
    getche();
    do{
    system("cls");
    cout<<"********************WELCOME TO THE OPEN COLLEGE DRIVE*******************\n\n";
    cout<<"1.Enter new participant\n";
    cout<<"2.Check participants list\n";
    cout<<"3.Enter the Rally\n";
    cout<<"4. Exit\n";
    cout<<"Enter an option\n";
    int i1;
    cin>>i1;
    switch(i1)
    {
        case 1:{
               cout<<"Enter the name of the participant: ";
               string n;
               fflush(stdin);
 
               getline(cin,n);
               cout<<"Name has been added, allotted ID is "<<I<<endl;
               vnid.push_back({I++,n});
               break;}
 
        case 2:
               {cout<<"";
               for(auto x:vnid)
               cout<<"ID: "<<x.first<<" , Name: "<<x.second<<endl;
               break;}
 
        case 3:
               {goto rally;
               break;}
 
        case 4:
               {goto end;
               break;}
 
        default:
               {cout<<"Choose correct option\n";
               break;}
    }
    cout<<"Do you to visit this section again?1/0\t";
    cin>>wish1;
    }while(wish1==1);
    rally:{
    do{
    system("cls");
    cout<<"********************WELCOME TO THE OPEN COLLEGE DRIVE*******************\n\n";
    cout<<"1.Sort the participants by their ID\n";
    cout<<"2.Sort the participants by their name\n";
    cout<<"3.Search for an participant on basis of id\n";
    cout<<"4.Search for an participant on basis of name\n";
    cout<<"5.New participant\n";
    cout<<"6.Removal of participant\n";
    cout<<"7.Submission of funds (Queues)\n";
    cout<<"8.Poster collection (Stacks)\n";
    cout<<"9.Rally route\n";
    cout<<"10.See all participants\n";
    cout<<"Enter an option\n";
    int i2;
    cin>>i2;
    switch(i2){
        case 1:
               {
               cout<<"These are all the participants present:-\n";
               for(auto x:vnid)
               cout<<"ID: "<<x.first<<",Name: "<<x.second<<endl;
               cout<<"Now we will sort them according to their IDs:";
               sortbyID(vnid);
               break;
               }
        case 2:
               {cout<<"These are all the participants present:-\n";
               for(auto x:vnid)
               cout<<"ID: "<<x.first<<",Name: "<<x.second<<endl;
               cout<<"Now we will sort them according to their names:";
            //    sortbyname(vnid);
               break;
               }
               
        case 3:
               {
                   cout<<"Enter the ID to search with: ";
                   int sid;
                   cin>>sid;
                   searchID(vnid,sid);
                   break;
               } 
        case 4: 
               {
                   cout<<"Enter the name/part of name to search with: ";
                   string nm;
                   cin>>nm;
                   searchname(vnid,nm);
                   break;
               }
               
        case 5: 
               {
               cout<<"Enter the name of the participant: ";
               string n;
               fflush(stdin);
               getline(cin,n);
               cout<<"Name has been added, allotted ID is "<<I<<endl;
               vnid.push_back({I++,n});
               break;
               }
            
        case 6: 
               {
                   cout<<"Delete the participant record by:\n1:ID 2:Name\nEnter a choice: ";
                   int ch;
                   cin>>ch;
                   switch(ch)
                   {
                       case 1:
                              {
                                  cout<<"Enter the ID of the participant: ";
                                  int did;
                                  cin>>did;
                                  deletebyID(vnid,did);
                                  break;
                              }
                       case 2:
                              {
                                  cout<<"Enter the Name of the participant: ";
                                  string dnm;
                                  getline(cin,dnm);
                                  deletebyname(vnid,dnm);
                                  break;
                              }
                       default:
                               {
                                   cout<<"Enter a correct option";
                               }
                   }
               }
               break;
 
        case 7: 
               {
                   cout<<"Welcome to the Funds Department, Your assistance is highly appreciated!\n\nYou are requested to form a queue and wait for your turn, you will recieve a certifcate for the fund donation\n";
                   queue<pair<int,string>> qfund;
                   do
                   {
                   cout<<"1:Push into queue\n2:Pop from queue\n3:Check members of the queue\n4:Check who is at the first in the queue\n5:Exit Funds Department";
                   cout<<"\nEnter a choice: ";
                   int qch;
                   cin>>qch;
                   switch(qch)
                   {
                       case 1: 
                              {
                                  cout<<"Enter the ID of the participant in the queue: ";
                                  int qid;
                                  cin>>qid;
                                  cout<<"Enter the Name of the participant in the queue: ";
                                  string qnm;
                                  fflush(stdin);
                                  getline(cin,qnm);
                                  if(qid>=I)
                                  {
                                      I=qid;
                                      vnid.push_back({qid,qnm});
                                  qfund.push({qid,qnm});
                                  }
                                  else
                                  cout<<"Enter unique personal IDs\n";
                                  break;
                              }
                       case 2:
                              {
                                 if(qfund.empty())
                                 cout<<"The queue at the funds department is already empty\n";
                                 else
                                  qfund.pop();
                                  break;
                              }
                       case 3:
                              {
                                  cout<<"Displaying the participants in the queue\n";
                                  dispqueue(qfund);
                                  break;
                              }
                       case 4:
                              {
                                  cout<<"Displaying the details of the first person in the queue\n";
                                  cout<<"ID: "<<qfund.front().first<<",Name: "<<qfund.front().second<<endl;
                                  break;
                              }
                       case 5: 
                              cout<<"Exiting the Funds Department";
                              break;
                        
                       default:
                               cout<<"Please Enter a correct choice\n";
                   }
                   if(qch==4)
                   break;
                   else{
                   cout<<"Do you want this section again?1/0\t";
                   cin>>wish3;
                   }
               }while(wish3);
               break;
               }
 
        case 8: 
               {
                   cout<<"Welcome to the Advertising Department, we here collect new posters and put them up for public awareness\n";
                   stack<string> poster;
                   do{
                   cout<<"1:Collect a new poster\n2:Put up a Poster\n3:Count of remaining poster\n4:current poster on top\n5:Show all posters\n6:thrw all posters away\n7:Exit the Advertising Department\nEnter choice: ";
                   int sch;
                   cin>>sch;
                   switch(sch)
                   {
                       case 1:
                              {
                                string pnm;
                                cout<<"Enter the new poster name: ";
                                fflush(stdin);
                                cin>>pnm;
                                poster.push(pnm);
                                cout<<"   size  "<<poster.size()<<endl;
                                break;
                              }
 
                              case 3:
                              {
                                  cout<<"Count of the remaining posters are: ";
                                  cout<<poster.size()<<endl;
                                  break;
                              }
                            
                       case 4:
                              {
                                  cout<<"The current poster on the top is: ";
                                  cout<<poster.top()<<endl;
                                  break;
                              }
                       case 5:
                              {
                                  cout<<"Showing all the posters in order: \n";
                                  showposter(poster);
                                  break;
                              }
                       case 6:
                              {
                                  cout<<"throwing all the posters away!!\nDo you want to see them before throwing??1/0";
                                  int thrw;
                                  cin>>thrw;
                                  if(thrw)
                                  showposter(poster);
                                  while (poster.size() > 0) 
                                   {
                                  poster.pop();
                                   }
                                  cout<<"All posters have been thrwn away";
                                  break;
                              }
 
                        case 7:
                               {
                                   cout<<"Exiting the Poster Department";
                                   break;
                               }
                       default: cout<<"Please enter a correct choice";
                                break;
                   }
                   if(sch==7)
                     break;
                   else{
                   cout<<"Do you want to enter this section again?1/0\t";
                   cin>>wish4;
                   }
               }while(wish4);
               break;
               }
 
        case 9:
               {
                   cout<<"Welcome to the Rally, We will be going through various locations throughout our rally, we will depict them with the help of a graph\n";
                   cout<<"Enter number of locations: ";
                   int loc;
                   cin>>loc;
                   int arr[V][V];
                   cout<<"Enter the distance of each location from each resprective location if there exists a direct path, else enter 0\n";
                   for(int i=0;i<V;i++)
                   {
                       cout<<"Enter distances from Location:"<<i+1<<" to other locations from 1 to "<<V<<endl;
                       for(int j=0;j<V;j++)
                       cin>>arr[i][j];
                   }
                   cout<<"Calculating Shortest paths for each location from the starting location\n";
                   shortest(arr,0);
               break;
               }
 
        case 10:
                {
                    if(vnid.empty())
                     cout<<"No participants!!\n";
                     else{
                cout<<"";
                for(auto x:vnid)
                cout<<"ID: "<<x.first<<" , Name: "<<x.second<<endl;
                     }
 
                break;
                }
 
         default:
                 {
                   cout<<"Please Enter a correct option";
                   break;
                 }  
                 
    }
    cout<<"Do you to enter this section again?1/0\t";
    cin>>wish2;
    }while(wish2);
    }
    end:
    exit(0);
    return 0;
}
