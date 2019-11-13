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
ll n;
string s1, s2;
bool valid(ll x, ll y) {
	return (x >= 0 and x < n and y >= 0 and y < n);
}
bool can(ll x, ll y) {
	return (s1[x] == '0' and s2[x] == '0' and (s1[y] == '0' or s2[y] =='0'));
}
void fill(ll x, ll y) {
	if(s1[y] == '0') {
		s1[y]  = '1';
		s2[x] = '1';
		s1[x] = '1';
	} else if(s2[y] == '0') {
		s2[y]  = '1';
		s2[x] = '1';
		s1[x] = '1';
	}
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> s1 >> s2;
  ll ct = 0;
  n = (ll)s1.length();
  for(ll i = 0; i < n; i++) {
  	if(valid(i, i-1) and can(i, i-1))  {
  		fill(i, i-1);
  		ct++;
  	} else if(valid(i, i+1) and can(i, i+1)) {
  		fill(i, i+1);
  		ct++;
  	}
  }
  cout << ct << endl;
  return 0;
} //good night.