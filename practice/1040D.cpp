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
#define   pll pair<ll, ll>
#define   all(x) x.begin(), x.end()
#define   vll vector<ll> 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool query(ll l, ll r) {
	cout << l << " " << r << endl;
	cout.flush();
	string s;
	cin >> s;
	if(s == "Yes") return 1;
	if(s == "Bad") exit(0); 
	return 0;
}

int main(){
  ll n, k;
  cin >> n >> k;
  ll l = 1, r = n;
  ll mid = n;
  ll tot = 0;
  while(1) {
     ll t = (r - l + 1);
     if(r - l + 1 <= 50) {
        mid = l + rng()%t;
        if(query(mid, mid)) exit(0);
        l = max(1ll, l - k), r = min(n, r + k);
     }
     mid = (l + r)/2;
     if(query(l, mid)) {
     	if(l == mid) return 0;
     	l = max(1ll, l - k);
     	r = min(n, mid + k);
     } else {
     	l = max(1ll, mid - k + 1);
     	r = min(n, r + k);
     } 
     tot++;
     assert(tot <= 4500);
  }

  return 0;
} //good night.