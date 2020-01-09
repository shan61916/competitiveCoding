const ll p = 257;             // base for the hash. (alpha)
ll pow_p[mxn];
void prep() {
  pow_p[0] = 1;               // pre-calculated powers of the base.
  for(ll i = 1; i < mxn; i++) {
    pow_p[i] = modmul(pow_p[i-1], p);
  }
}

ll addlast(ll currhash, ll val) {
  currhash = modmul(currhash, p);
  currhash = modadd(currhash,val);
  return currhash;
}
ll removelast(ll currhash, ll val){
  currhash = modsub(currhash, val);
  currhash = moddiv(currhash, p);
  return currhash;
}
ll addfirst(ll currhash, ll val, ll len) {
  // len is the current length, before adding.
  ll toadd = modmul(val, pow_p[len]);
  currhash = modadd(currhash, toadd);
  return currhash;
}
ll removefirst(ll currhash, ll val, ll len){
  ll torem = modmul(val, pow_p[len]);
  currhash = modsub(currhash, torem);
  return currhash;
}