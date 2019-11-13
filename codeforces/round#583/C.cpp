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
  if(n%2){
  	cout << "No";
  	return 0;
  }
  ll op = 0, cl = 0;
  for(auto it: s) {
  	if(it == '(')op++; 
  	else if(it == ')') {
  		if(op)op--;
  		else {
  			cl++;
  		}
  	}
  }
  if((op == 1 and cl == 1) or op + cl == 0) {
    cout << "Yes";
    return 0;
  }
  else {
  	cout << "No";
  	return 0;
  }
  return 0;
} //good night.