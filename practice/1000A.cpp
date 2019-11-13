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
  int n;
  cin >> n;
  unordered_map<string, ll> key;
  for(ll i = 0; i < n; i++) {
  	string x;
  	cin >> x;
  	key[x]++;
  }
  int ct = 0;
  for(int i = 0; i < n; i++) {
  	string x;
  	cin >> x;
  	if(key[x]) key[x]--;
  	else ct++;
  }
  cout << ct << endl;
  return 0;
} //good night.