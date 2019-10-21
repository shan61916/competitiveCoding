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


int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n, m;
  cin >> n >> m;
  vll arr(n);
  for(auto &x : arr) {
    cin >> x;
  }
  ll todo = n/m;
  vector<ll> ct(m, 0);
  vector<vll> adj(m);
  for(ll i = 0; i < n; i++) {
     ct[arr[i]%m]++;
     adj[arr[i]%m].pb(i);
  }
  queue<ll> qq;
  ll ans = 0;
  for(ll i = 0; i < m; i++) {
    if(ct[i] > todo) {
      ll xx = ct[i] - todo;
      for(ll j = 0; j < xx; j++) {
        qq.push(adj[i][j]);
      }
      ct[i] = todo;
    } else if(ct[i] < todo) {
      while(ct[i] < todo and qq.size() > 0) {
        ll xx = qq.front();
        // cout << arr[xx] << endl;
        qq.pop();
        if(arr[xx]%m < i) {
          ans+= (i - (arr[xx]%m));
          arr[xx]+= (i - (arr[xx]%m));
        } else {
          ans+= (i) + (m - (arr[xx]%m));
          arr[xx]+= (i) + (m - (arr[xx]%m));
        }
        ct[i]++;
      }
    }
  }
  for(ll i = 0; i < m; i++) {
      if(ct[i] < todo) {
      while(ct[i] < todo and qq.size() > 0) {
        ll xx = qq.front();
        qq.pop();
        if(arr[xx]%m < i) {
          ans+= (i - (arr[xx]%m));
          arr[xx]+= (i - (arr[xx]%m));
        } else {
          ans+= (i) + (m - (arr[xx]%m));
          arr[xx]+= (i) + (m - (arr[xx]%m));
        }
        ct[i]++;
      }
    }
  }

  cout << ans << endl;
  for(auto it: arr) cout << it << " ";
  return 0;
} //good night.