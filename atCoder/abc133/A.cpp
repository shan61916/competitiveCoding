  //shan61916
#include <bits/stdc++.h>
    using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
typedef long long ll;
typedef unsigned long long ull ;
typedef double dll ;

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n, a, b;
  cin >> n >> a >> b;
  cout << min(n*a, b) ;
  return 0;
} //good night.
