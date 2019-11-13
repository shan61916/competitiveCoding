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
  ll n, k;
  cin >> n >> k;
  string s; 
  cin >> s;
  ll curr = 0;
  ll i = 0;
  while(i < n and k > 0) {
    if(s[i] == '0') {
      if(k >= (i - curr)) {
        k-= (i - curr);
        swap(s[i], s[curr]);
      } else {
          swap(s[i], s[i-k]);
          k = 0;
        }
      curr++;
    }
    i++;
  }
cout << s << endl;
}
return 0;
} //good night.