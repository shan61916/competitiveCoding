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

const ll inf = (ll)(1e17 + 17);
const ll mod = (ll)(1e9 + 7);


int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
ll T;
cin >> T;
map<ll, char> val;
ll zzz = 0;
for(ll i = 0; i <= 9; i++) {
  val[++zzz] = (char)('0' + i);
}
for(ll i = 0; i < 26; i++) {
  val[++zzz] = (char)('a' + i);
  val[++zzz] = (char)('A' + i);
}
while(T--) {
  ll r, c, k;
  cin >> r >> c >> k;
  vector<string> grid(r);
  ll tot = 0;
  for(ll i = 0; i < r; i++) {
    cin >> grid[i];
    for(auto it: grid[i]) if(it == 'R') tot++;
  }
  ll xx = tot/k;
  vll rc(k, xx);
  xx = tot%k;
  for(ll i = 0; i < xx; i++) rc[i]++;
  vector<vector<char>> ng(r, vector<char> (c));
  ll curr = 0; 
  ll req = rc[curr];
  ll done = 0;
  for(ll i = 0; i < r; i++) {
    if(i%2 == 0) {
      for(ll j = 0; j < c; j++) {
        // cout << curr << endl;
        if(grid[i][j] == 'R') {
          done++; 
        }
        ng[i][j] = val[curr + 1];
        if(done == req) {
          curr++;
          curr = min(curr, k-1);
          req = rc[curr];
          done = 0;
        }
      }
    } else {
      for(ll j = c-1; j >= 0; j--) {
        // cout << curr << endl;
        if(grid[i][j] == 'R') {
          done++; 
        }
        ng[i][j] = val[curr + 1];
        if(done == req) {
          curr++;
          curr = min(k-1, curr);
          req = rc[curr];
          done = 0;
        }
      }
    }
  }
  for(ll i = 0; i < r; i++) {
    for(ll j = 0; j < c; j++) {
      cout << ng[i][j];
    }
    cout << endl;
  } 
}
  return 0;
} //good night.