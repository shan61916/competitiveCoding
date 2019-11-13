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
  ll T;
  cin >> T;
  while(T--){
   string a, b;
   cin >> a >> b;
   bool foo = false;
   for(ll i = 0; i < 26; i++) {
   	 char x = (char)('a' + i);
   	 if(count(all(a), x) > 0 and count(all(b), x) > 0) {
   	 	foo = true;
   	 }
   }
   foo ? cout << "Yes" : cout << "No" ;
   cout << endl;
  }
  return 0;
} //good night.