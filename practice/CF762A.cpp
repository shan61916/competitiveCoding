#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include<bits/stdc++.h>
typedef int ll;
using namespace std;
ll n, sum;
ll dp[100001][1001]; 

ll recurse(ll idx, ll s, vector<ll>&arr) {
   if(idx == n) {
   	 return abs(s - (sum-s));
   }
   ll &ans = dp[s][idx];
   if(ans != -1) return ans; 
   ans = INT_MAX;
   ans = min(ans, recurse(idx+1, s + arr[idx], arr));
   ans = min(ans, recurse(idx+1, s, arr));
   return ans;
}
int solution(vector<int> A)
{
  sum = 0;
  n = (ll)A.size();
  // for(auto it: A) cout << it << " ";
  for(auto it :A) sum+=it;
  memset(dp, -1, sizeof(dp));
  ll ans = recurse(0, 0, A);
  return ans; 
}

vector<int> toIntVector(string str)
{
  std::vector<int> out;
  std::string i;
  std::istringstream tokenStream(str);
  while (std::getline(tokenStream, i, ','))
  {
    out.push_back(atoi(i.c_str()));
  }
  return out;
}

int main()
{
  // Read in from stdin, solve the problem, and write answer to stdout.
  string AS;
  cin >> AS;
  cout << solution(toIntVector(AS));
}