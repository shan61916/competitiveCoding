/* qidx -> current index 
 * f1  -> if there is any i < idx s.t st[i] < b[i];
 * f2  -> if there is any i < idx s.t st[i] > a[i];
 * b   -> upper bound sequence 
 * a   -> lower bound sequence
*/
ll digitdp(ll idx, ll f1, ll f2) {
  if(idx == n) return 1;
  ll &ans = dp[idx][f1][f2];
  if(ans != -1) return ans;
  ans = 0;
  ll start = 0, end = 9;
  if(f1 == 0) end = b[idx];
  if(f2 == 0) start = a[idx];
  for(ll i = start; i <= end; i++) {
    ll b1 = f1|(i < b[idx]);
    ll b2 = f2|(i > b[idx]);
    ans += digitdp(idx+1, b1, b2);
  }
}