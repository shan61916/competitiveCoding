/*
Problem Statement :-
Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
*/

#include <bits/stdc++.h>
 using namespace std;

int main(){
  int n, k;
  cin >> n >> k; // n -> size of list and k -> target sum
  vector<int> arr(n);
  for(auto &it: arr) cin >> it;
  unordered_map<int, int> hash;
  for(auto it: arr) hash[it]++;
  for(auto it : arr) {
  	int rem = k - it;
  	if(hash[rem]) {
  		cout << "YES";
  		return 0;
  	}
  }
  cout << "NO";
  return 0;
} //good night.