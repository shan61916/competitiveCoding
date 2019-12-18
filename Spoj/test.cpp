#include<bits/stdc++.h>
using namespace std;
  
#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define inf 1e18
#define PB push_back
#define POPB  pop_back
#define pf printf
#define sf scanf
#define ALL(c) c.begin(),c.end()
#define TR(v,it) for(auto it=v.begin();it!=v.end();it++)
#define FT(i,n) for(ll i=0;i<n;i++)
#define FTR(i,n) for(ll i=n;i>=0;i--)
#define FTG(i,a,b) for(ll i=a;i<=b;i++)
#define FTGR(i,a,b) for(ll i=a;i>=b;i--)
#define MP make_pair
#define F first
#define S second
#define endl "\n"
ll mod =1e9+7;
#define err1(x) cout<<"**"<<x<<endl;
#define err2(x,y) cout<<"**"<<x<<" **"<<y<<endl;
#define err3(x,y,z) cout<<"**"<<x<<" **"<<y<<" **"<<z<<endl;
#define TCS int t;cin>>t;while(t--)
#define boost std::ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

vector<int> graph[100002];
ll in[100002],out[100002];
int a[100002];
void dfs1(int root,int par)
{
  in[root]=0;
  for(int child:graph[root])
  {
    if(child==par)continue;
    dfs1(child,root);

    ll ut=0; 
    if(a[child]-a[root]>0)
    ut=a[child]-a[root];

    in[root]=max(in[root],in[child]+ut);
  }
}

void dfs2(int root,int par)
{
    ll mx1=-1,mx2=-1;
  ll use;
  for(int child:graph[root])
  {
    if(par==child)continue;
    use=0;
    if(a[child]-a[root]>0)use=a[child]-a[root];
    if(in[child]+use>=mx1)mx2=mx1,mx1=in[child]+use;
    else if(in[child]+use>mx2)mx2=in[child]+use;
  }
  for(int child:graph[root])
  {
    if(par==child)continue;
    use=mx1;
    ll ut=0;
    if(a[child]-a[root]>0)
    ut=a[child]-a[root];
    if(ut+in[child]==mx1)
    use=mx2;
    ut=0;
    if(a[root]-a[child]>0)ut=a[root]-a[child];
    out[child]=max(ut+out[root],ut+use);
    dfs2(child,root);
  }
}

int main()
{
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  // ----------------------------------------
  boost;
  int n;
  cin>>n;
  int q;
  cin>>q;
  
  FT(i,n)cin>>a[i];

  int s,d;
  FT(i,n-1)cin>>s>>d,graph[s].PB(d),graph[d].PB(s);

  dfs1(0,-1);

  dfs2(0,-1);
  
  while(q--)
  {
    cin>>s;

    cout<<max(in[s],out[s])<<endl;
  }
  return 0;
}