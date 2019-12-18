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
const ll limit = 401;
string s1, s2;
ll n1, n2;
ll dp[402][201][201];

ll recurse(ll idx, ll fir, ll sec) {
  if(fir == n1 and sec == n2 and idx == 0) {
    return 0;
  }
  if(fir > n1 or sec > n2 or idx >= limit) return inf;
  ll &ans = dp[idx][fir][sec];
  if(ans != -1) return ans;
  ans = inf;
  ll to1 = (fir < n1 and s1[fir] == '('); 
  ll to2 = (sec < n2 and s2[sec] == '(');
  ans = min(ans, 1 + recurse(idx + 1, fir + to1, sec + to2)); 
  if(idx > 0) {
  if(fir < n1)to1 = (s1[fir] != '('); 
  if(sec < n2)to2 = (s2[sec] != '(');
  ans = min(ans, 1 + recurse(idx-1, fir + to1, sec + to2));
  }
  return ans;
}

void trace(ll idx, ll fir, ll sec) {
  if(fir == n1 and sec == n2 and idx == 0) return;
  ll ans = recurse(idx, fir, sec);
  ll to1 = (fir < n1 and s1[fir] == '('); 
  ll to2 = (sec < n2 and s2[sec] == '(');
  if(ans == (1 + recurse(idx + 1, fir + to1, sec + to2))) {
    cout << '(';
    trace(idx+1, fir+to1, sec + to2);
    return;
  } 
  if(idx > 0) {
  if(fir < n1)to1 = (s1[fir] != '('); 
  if(sec < n2)to2 = (s2[sec] != '(');
  if(ans == min(ans, 1 + recurse(idx-1, fir + to1, sec + to2))) {
    cout << ')';
    trace(idx-1, fir + to1, sec + to2);
    return;
  }
  }
  return;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> s1 >> s2;
  n1 = s1.length();
  n2 = s2.length();
  memset(dp, -1, sizeof dp);
  recurse(0, 0, 0);
  trace(0, 0, 0);
  return 0;
} //good night.