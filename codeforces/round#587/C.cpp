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
  ll x1, x2, y1, y2, x3, x4, x5, x6, y3, y4, y5, y6;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
  ll giv = (x2 - x1) * (y2 - y1);
  ll firx1, firx2, firy1, firy2; 
  ll secx1, secx2, secy1, secy2; 
  firx1 = min(max(x1, x3), x2); 
  firx2 = max(x1, min(x4, x2)); 
  firy1 = min(y2, max(y1, y3));
  firy2 = max(y1, min(y2, y4));
  secx1 = min(x2, max(x1, x5)); 
  secx2 = max(x1, min(x2, x6));
  secy1 = min(y2, max(y5, y1)); 
  secy2 = max(y1, min(y6, y2));

  if(firx2 <= x1 or firx1 >= x2 or firy2 <= y1 or firy1 >= y2) {
    firx2 = 0;
    firx1 = 0;
    firy1 = 0;
    firy2 = 0;
  }
  if(secx1 >= x2 or secx2 <= x1 or secy1 >= y2 or secy2 <= y1) {
  	secx1 = 0;
  	secx2 = 0;
  	secy1 = 0;
  	secy2 = 0;
  }
  ll cx1, cx2, cy1, cy2; 
  cx1 = max(firx1, secx1);
  cx2 = min(firx2, secx2);
  cy1 = max(firy1, secy1);
  cy2 = min(firy2, secy2);
  ll comar = (cx2 - cx1) * (cy2 - cy1);
  if(secx1 >= firx2 or firx1 >= secx2) comar = 0;
  if(secy1 >= firy2 or firy1 >= secy2) comar = 0;
  ll sectot = (firx2 - firx1) * (firy2 - firy1); 
  sectot+= (secx2 - secx1) * (secy2 - secy1);
  sectot-=comar;
  // cout << giv << " " << sectot << endl;
  if(sectot >= giv) cout << "NO" ;	
  else cout << "YES" ;
  return 0;
} //good night.