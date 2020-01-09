vll segtree[400001];
vll arr(100001);

void build(ll t, ll tl, ll tr){
  if(tl == tr) {
    segtree[t].pb(arr[tl]);
    return;
  }
  ll mid = (tl + tr)/2;
  build(2*t, tl, mid);
  build(2*t+1, mid+1, tr);
  merge(all(segtree[2*t]), all(segtree[2*t+1]), back_inserter(segtree[t]));
}
/* query can't work just like the regular Segtree, use binsearch
or maybe trim each array(ex- phstrg (codechef)),
or any other query optimisation */
ll query(ll t, ll tl, ll tr, ll l, ll r, ll k) {
 if(tl > tr or l > tr or tl > r) return 0;
 if(l <= tl and r >= tr) {
   return segtree[t].end() - upper_bound(all(segtree[t]), k);
 }
 ll mid = (tl + tr)/2;
 return query(2*t, tl, mid, l, r, k) + query(2*t+1, mid+1, tr, l, r, k);
}