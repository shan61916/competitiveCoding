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
struct entity {
	dll price;
	dll weight;
};

vector<entity> objects;

bool comp (entity a, entity b) {
	return (a.price/a.weight) > (b.price/b.weight);
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  dll sackSize;
  cin >> sackSize;
  ll elements;
  cin >> elements;
  objects.resize(elements);
  for(ll i = 0; i < elements; i++) {
  	cin >> objects[i].price >> objects[i].weight;
  }
  sort(all(objects), comp); 
  dll ans = 0.00;
  for(ll i = 0; i < elements; i++) {
  	if(sackSize >= objects[i].weight) {
  	  ans = ans + objects[i].price;
  	  sackSize = sackSize - objects[i].weight;
  	} else {
  	  ans = ans + (sackSize)*(objects[i].price/objects[i].weight);
  	  break;
  	}
  }
  cout << ans << endl;
  return 0;
} //good night.