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
ll m, n;
vector<string> giv;
unordered_map<string, ll> stll; 
unordered_map<ll, string> llts;
ll counter = 1;
vector<vll> adj1(200010),adj2(200010);
vector<bool> visited(200010, false);
vector<ll> order;
unordered_map<ll, ll> component; 
vector<vll> condense(200010);
vector<pll> comp_val(200001);

auto mini(pll a, string b) -> pll {;
   ll len = b.length();
   ll rc = count(all(b), 'r');
   if(a.ff == rc) {
     return mp(a.ff, min(a.ss, len));
   } 
   if(a.ff < rc) return a;
   return mp(rc, len);
}

auto lower(string x) -> string {
   transform(all(x), x.begin(), ::tolower);
   return x;
}

auto dfs1(ll idx) -> void{
  visited[idx] = true;
  for(auto it : adj1[idx]) {
    if(!visited[it] and it!= 0) {
      dfs1(it);
    }
  }
  order.pb(idx);
}

pll component_answer;

auto dfs2(ll idx) -> void {
  visited[idx] = true;
  component_answer = mini(component_answer, llts[idx]);
  component[idx] = counter;
  for(auto it: adj2[idx]) {
    if(!visited[it] and it != 0) {
      dfs2(it);
  }
 }
}
 
auto minpair(pll a, pll b) -> pll {
  if(a.ff == b.ff) {
    if(a.ss < b.ss) return a;
    return b;
  }
  if(a.ff < b.ff) return a;
  return b;
}
auto calcmin(ll idx) -> void {
  pll a = comp_val[idx]; 
  visited[idx] = true;
  for(auto it: condense[idx]) {
    if(!visited[it]) {
      calcmin(it);
    }
    a = minpair(a, comp_val[it]);
  }
  comp_val[idx] = a;
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> m ;
  giv.resize(m+1) ;
  ll ct = 1;
  for(ll i = 1; i <= m; i++) {
    cin >> giv[i];
    giv[i] = lower(giv[i]);
    llts[ct] = giv[i];
    stll[giv[i]] = ct++;
  }
  cin >> n;
  string x, y;
  for(ll i = 1; i <= n; i++) {
    cin >> x >> y;
    x = lower(x);
    y = lower(y);
    if(stll[x] == 0){
     llts[ct] = x;
     stll[x] = ct++;
   } 
   if(stll[y] == 0) {
    llts[ct] = y;
    stll[y] = ct++;
   }
    adj1[stll[x]].pb((stll[y])); 
    adj2[stll[y]].pb((stll[x]));
  }
  visited.assign(ct, false);
  order.push_back(1);
  for(ll i = 1; i < ct; i++) {
    if(!visited[i]) {
      dfs1(i);
    }
  } 
  reverse(order.begin()+1, order.end());
  visited.assign(ct, false);
  for(ll i = 1; i < ct; i++) {
    component_answer = mp(INT_MAX, INT_MAX);
    if(!visited[order[i]]) {
      dfs2(order[i]); 
      comp_val[counter++] = component_answer;
  }
}
  for(ll i = 1; i < ct; i++) {
      for(auto it: adj1[i]) {
      if(component[i] == component[it]) continue;
       condense[component[i]].push_back(component[it]);
      }
  }
  visited.assign(ct, false);
  for(ll i = 1; i < counter; i++) {
    if(!visited[i]) {
        calcmin(i);
    }
  }
  ll mrc = 0, mlen = 0;
  for(ll i = 1; i <= m; i++) {
     mrc+= comp_val[component[stll[giv[i]]]].ff;
     mlen+= comp_val[component[stll[giv[i]]]].ss;
  } 
  cout << mrc << " " << mlen << endl;
  return 0;
} 