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
  string a, b;
  cin >> a >> b;
  ll n = a.length();
  ll o = 0, t = 0, bo = 0, z = 0;
  for(ll i = 0; i < n; i++) {
     if(a[i] == '#' and b[i] == '#') bo++ ;
     else if(a[i] == '#' and b[i] != '#') o++;
     else if(a[i] != '#' and b[i] == '#') t++;
     else z++;
  }
    if(bo == 0 and o and t) {
      cout << "NO" ;
      return 0;
    }
  string a1 = "", a2 = "";
  for(ll i = 0; i < o; i++) {
    a1.push_back('#');
    a2.pb('.');
  }
  for(ll i = 0; i < bo; i++) {
    a1.pb('#');
    a2.pb('#');
  }
  for(ll i = 0; i < t; i++) {
    a1.pb('.');
    a2.pb('#');
  }
  for(ll i = 0; i < z; i++) {
    a1.pb('.');
    a2.pb('.');
  }
  cout << "YES" << endl;
    cout << a1 << endl << a2;
  return 0;
} //good night.