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
ll a, b, c;
bool can(ll mid) {
   ll rem = 0;
   if(a >= mid) {
   	rem+= a-mid;
   }else return false;

   if(b >= mid) {
   	rem+= b-mid;
   } else return false;

   if(rem+c >= mid) {
   	return true;
   } 
   
   return false;
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--){
  cin >> a >> b >> c;
  ll low = 0, high = a+b+c, mid, ans = 0;
  while(low <= high) {
  	mid = (low + high)/2;
  	if(can(mid)) {
  		ans = mid;
  		low = mid+1;
  	} else {
  		high = mid-1;
  	}
  }
  cout << ans << endl;
  }
  return 0;
} //good night.