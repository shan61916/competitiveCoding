const ll mxn = (ll)(2.1e5);
const ll bits = 23;
vll arr(mxn, 0);
vll logs(mxn, 0);
ll table[bits][mxn];
/* compute logs beforehand.For true O(1) queries.
   0 based indexing.
*/
void pre_log() {
  logs[1] = 0;
  for(ll i = 2; i < mxn; i++)  logs[i] = logs[i/2] + 1;
}
void build(ll n) {
  for(ll i = 0; i <= logs[n]; i++) {
    ll len = (1LL << i);
    for(ll j = 0; j + len <= n; j++) {
      if(len == 1) {
        table[i][j] = arr[j]; 
      } else {
        table[i][j] = min(table[i-1][j], table[i-1][j + (len/2)]);
      }
    }
  }
}
ll query(ll l, ll r) {
  ll p = logs[r - l + 1];
  ll len = (1LL << p);
  return min(table[p][l], table[p][r - len + 1]);
}
