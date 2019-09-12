//shan61916
#include<bits/stdc++.h>

typedef long long ll;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

vector<ll> countsort(vector<ll> arr) {
  ll n = arr.size();
  ll mx = *max_element(arr.begin(), arr.end());
  vector<ll> temp(mx+1, 0);
  vector<ll> ans(n);
  for (ll i = 0; i < n; i++) temp[arr[i]]++;
  for (ll i = 1; i <= mx; i++) {
    temp[i] += temp[i-1];
  }
  for (ll i = 0; i < n; i++) {
    ans[temp[arr[i]]-1] = arr[i];
    temp[arr[i]]--;
  }
  return ans;
}

int main() {
  cout << "Enter array size\n";
  ll n;
  cin >> n;
  vector<ll> arr(n);
  cout << "Enter array elements\n";
  for (ll i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << "Sorted array elements are ";
  vector<ll> sorted = countsort(arr);
  for (auto i : sorted) cout << i << ' ';
  return 0;
}