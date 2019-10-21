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
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  ll ct = 0;
  if(n == 1 and k) {
  	cout << 0;
  	return 0;
  }
  for(ll i = 0; i < n; i++) {
  	if(ct == k) break;
  	if(i == 0 and s[i] == '1') continue; 
  	else {
  		if(i == 0) {
  			s[i] = '1';
  			ct++;
  		}
        if(i != 0) {
        	if(s[i] == '0') continue;
        	else {
        		s[i] = '0';
        		ct++;
        	}
        }
  	}
  }
  cout << s << endl;
  return 0;
} //good night.