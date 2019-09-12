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
vll arr ;
ll n;
pll minmax(ll i, ll j) {
  if (i == j) {
    return {arr[i], arr[j]};
  }
  pll ans;
  ans.first = INT_MIN;
  ans.second = INT_MAX;
  pll pp;
  ll mid = (i+j)/2;
  pp = minmax(i, mid);
  ans.first = max(ans.first, pp.first);
  ans.second = min(ans.second, pp.second);
  pp = minmax(mid+1, j);
  ans.first = max(ans.first, pp.first);
  ans.second = min(ans.second, pp.second);
  return ans;
}

int main() {
  cout << "Enter size of array\n";
  cin >> n;
  arr.resize(n);
  cout << "Enter array elements\n";
  for (ll i = 0; i < n; i++) cin >>  arr[i];
  pll ans = minmax(0, n-1);
  cout <<  "Max element is " << ans.first <<  " and min element is " << ans.second;
  return 0;
}