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
  string s;
  int n, k;
  cin >> n >> k >> s;
  if (n == 1 and k == 1) {
  	cout << 0 << endl;
  	exit(0);
  }
  if (n == k) k--;
  if (k and s[0] != '1') s[0] = '1', k--;
  for (int i = 1; i < n; i++) {
  	if (s[i] != '0' and k > 0) s[i] = '0', k--;
  }
  cout << s << endl;
  return 0;
} //good night.