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
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll a = 0, b = 0;
  string res = "";
  ll ct = 0;
  for(ll i = 0; i < n; i++) {
  	 if(s[i] == 'a') a++;
  	 else b++;
     if(i != 0 and i%2 and a!=b) {
         if(s[i] == 'a'){
         	res+= 'b';
         	b++;
         	a--;
         }
         else{
          res+='a';
          a++;
          b--;
        }
         ct++;
     } else {
     	res+= s[i];
     }
  }
  cout << ct << endl;
  cout << res << endl;
  return 0;
} //good night.