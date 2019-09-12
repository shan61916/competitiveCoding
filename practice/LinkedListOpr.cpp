  //shan61916
#include <bits/stdc++.h>
  using namespace std;
typedef   long long ll;
typedef   unsigned long long ull ;
typedef   double dll ;

#define   mp make_pair
#define   pb push_back
#define   ff first 
#define   ss second
#define   IOS ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define   endl "\n" 
#define   pll pair<ll, ll>
#define   all(x) x.begin(), x.end()
#define   vll vector<ll> 

struct node
{
    int data;
    node* next;
};

node* head;

void insert(int data)
{
    node* tmp=new node;
    tmp->data=data;
    tmp->next=NULL;
    if(head==NULL)
    {
        head=tmp;
    }
    else
    {
        node* tt;
        tt=head;
        while(tt->next!=NULL)
        {
            tt=tt->next;
        }
        tt->next=tmp;
    }
}

void printlist()
{
  cout<<endl;
  cout<<"The linked list is ";
    node* tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}

void insert_at_pos(int data, int pos)
{
    node* tmp=new node;
    tmp->data=data;
    tmp->next=NULL;
    node* tt=head;
    if(pos==1)
    {
        tmp->next=head;
        head=tmp;
    }
    else
    {
        node* prev=head;
        for(int i=1; i<pos; i++)
        {
                        if(tt==NULL)
            {
                node* att=new node;
                att->data=0;
                att->next=NULL;
                tt=att;
                prev->next=att;
            }

            prev=tt;
            tt=tt->next;
        }
        tmp->next=tt;
        prev->next=tmp;
    }
}

void remove(int pos)
{
  int i;
  node* tmp;
  if(pos==1)
  {
    tmp=head;
    head=head->next;
    delete tmp;
  }
  else
  {
    node* prev;
    prev=head;
    node* tt=head;
    for(i=1; i<pos; i++)
    {
      prev=tt;
      tt=tt->next;
      if(tt==NULL)
      {
        cout<<"Position doesn't exist"<<endl;
        return;
      }
    }
    prev->next=tt->next;
    delete tt;
  }
}

int main()
{
    head=NULL;
    int x,y,p1,p2;
    while(1)
    {
    cout<<"0 for creating linked list"<<endl;
    cout<<"1 for inserting a node at given position"<<endl;
    cout<<"2 for deleting a node from given position"<<endl;
    cout<<"3 to display linked list"<<endl;
    cout<<"4 to exit"<<endl;
    cin>>x;
    if(x==4)
      break;
    else if(x==0)
    {
      cout<<"Enter the data value"<<endl;
      cin>>y;
      insert(y);
    }
    else if(x==1)
    {
  cout<<"Enter the data value and position to insert node"<<endl;
  cin>>p1>>p2;
  insert_at_pos(p1, p2);
    }
    else if(x==2)
    {
      cout<<"Enter the position number to delete node"<<endl;
      cin>>y;
      remove(y);
    }
    else if(x==3) {
        printlist();
      cout<<endl;
    }
    }
    return 0;
}