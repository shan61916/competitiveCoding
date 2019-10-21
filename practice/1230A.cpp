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
vll a(4);
bool recurse(ll idx, ll sum1, ll sum2) {
	if(idx == 4) {
	if(sum1 == sum2) return true;
    return false;
	}
	return (recurse(idx+1, sum1 + a[idx], sum2)||recurse(idx+1, sum1, sum2+ a[idx]));
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  for(ll i = 0; i < 4; i++) cin >> a[i];
 
  ll s = accumulate(all(a), 0);
  if(s%2) cout << "NO";
  else {
     bool ans = recurse(0, 0, 0); 
     ans ? cout << "YES" : cout << "NO" ;
  }
  return 0;
} //good night.