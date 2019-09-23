  //shan61916
#include <bits/stdc++.h>
  using namespace std;

struct entity {
	double price;
	double weight;
};

vector<entity> objects;

bool comp (entity a, entity b) {
	return (a.price/a.weight) > (b.price/b.weight);
}

int main(){
  double sackSize;
  cout << "Enter the Sack Size" << endl;
  cin >> sackSize;
  int elements;
  cout << "Enter the number of elements" << endl;
  cin >> elements;
  objects.resize(elements);
  cout << "Enter the price and weight of each object" << endl;
  for(int i = 0; i < elements; i++) {
  	cin >> objects[i].price >> objects[i].weight;
  }
  sort(objects.begin(), objects.end(), comp); // comp is custom comparator such that the element with maximum value is at top.
  double ans = 0.00;
  for(int i = 0; i < elements; i++) {
  	if(sackSize >= objects[i].weight) {
  	  ans = ans + objects[i].price;
  	  sackSize = sackSize - objects[i].weight;
  	} else {
  	  ans = ans + (sackSize)*(objects[i].price/objects[i].weight);
  	  break;
  	}
  }
  cout << "The maximum profit is " << endl;
  cout << ans << endl;
  return 0;
} //good night.