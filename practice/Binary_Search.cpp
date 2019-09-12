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
  cout << "Enter the array elements";
  cin >> n;
  vll a(n);
  for(ll i = 0; i < n; i++) {
  	cin >> a[i];
  }
  sort(all(a));
  ll q;
  cin >> q;
  ll low = 0, high = n-1, mid;
  while(low <= high) {
  	mid = (low + high) / 2;
  	if(a[mid] < q) {
        high = mid - 1;
  	} else if(a[mid] > q){
  		low = mid + 1;
  	} else {
  		cout << "Element present at " << mid << endl;
  		return 0; 
  	}
  }
  cout << "Element not found" ;
  return 0;
} //good night.