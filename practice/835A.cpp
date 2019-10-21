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
  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  int a = 2*t1 + (v1 * s);
  int b = 2*t2 + (v2 * s);
  if(a == b) {
  	cout << "Friendship";
  } else if(a < b)  cout << "First" << endl;
    else cout << "Second";
  return 0;
} //good night.