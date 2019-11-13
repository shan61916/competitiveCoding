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
  ll a, b;
  cin >> a >> b;
  if(a == 9 and b == 1) {
  	cout << 9 << " " << 10 << endl;
  	return 0;
  }
  if(abs(a-b) > 1 or a > b) {
  	cout << -1;
  	return 0;
  }
  if(a == b) {
  	cout << a*10 << " " << a*10 + 1 << endl;
  } else {
  	if(a < b) {
  		cout << a << " " << b << endl;
  	}
  }

  return 0;
} //good night.