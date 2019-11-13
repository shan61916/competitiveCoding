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
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll s1 = 0, pos1 = 0, s2 = 0, pos2 = 0;
  for(ll i = 0; i < n/2; i++) {
  	if(s[i] == '?') pos1++;
  	else s1+= s[i]-'0';
  }
  for(ll i = n/2; i < n; i++) {
  	  if(s[i] == '?') pos2++;
  	  else s2+= s[i]-'0';
  }
  if(pos1 > pos2)  {
  	swap(s1, s2);
  }
  if(pos1 == pos2 and s1 == s2) {
  	cout << "Bicarp";
  } else if(pos1 == pos2 and s1!=s2) {
  	cout << "Monocarp" ;
  } else if(pos1 != pos2) {
       if(s1 < s2) {
           cout << "Monocarp";
       } else if(s1 > s2) {
       	  ll x1 = s1 + (ll)(ceil(pos1/2))*9 ;
       	  ll x2 = s2 + (ll)(ceil(pos2/2))*9;
       	  if(x2 <= x1) cout << "Bicarp";
       	  else cout << "Monocarp";
       } else if(s1 == s2) {
       	cout << "Monocarp";
       }
  }
  return 0;
} //good night.