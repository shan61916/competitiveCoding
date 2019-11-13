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
  ll a, b, x;
  cin >> a >> b >> x;
  ll st = 0;
  string s = "";
  if(a < b) st = 1;
  for(ll i = 0; i < x+1; i++) {
       s+= (char)(st+'0');
       if(st) b--;
       else a--;
       st^=1;
  }  
  for(ll i = 0; i < (ll)s.length(); i++) {
  	cout << s[i]; 
  	if(s[i] == '1') {
  		while(b){
  			cout << "1";
  			b--;
  		}
  	} if(s[i] == '0') {
  		while(a){
  			cout << 0;
  		    a--;
  		}
  	}
  }
  return 0;
} //good night.