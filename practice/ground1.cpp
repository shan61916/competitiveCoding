#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split_string(const string &str) {
  vector<string> vec;
  string curr = "";
  for(char x: str) {
    if(x == ',') {
      vec.push_back(curr);
      curr.clear();
    } else {
      curr += x;
    }
  }
  if(!curr.empty()) {
    vec.push_back(curr);
  }
  return vec;
}

int get_min_count(const string &str) {
  char c = 'z';
  for(char x: str) {
    c = min(c, x);
  }
  return (int) count(str.begin(), str.end(), c);
}
const int sz = 100; // for processing count of smallest character
vector<int> solution(string A, string B) {
  vector<string> X = split_string(A), Y = split_string(B);
  vector<int> frequency(sz);
  for(auto str: X) {  
    frequency[get_min_count(str)]++;
  }
  for(int i = 1; i < sz; ++i) {
    frequency[i] += frequency[i - 1];
  }
  vector<int> solution;
  for(auto str: Y) {
    solution.push_back(frequency[get_min_count(str) - 1]);
  }
  return solution; 
}

string fromIntVector(vector<int> arr)
{
  string out = "";
  for (int i=0; i<arr.size(); i++) {
    out += to_string(arr[i]);
    if (i != arr.size() - 1) {
      out += ",";
    }
  }
  return out;
}

int main()
{
  // Read in from stdin, solve the problem, and write answer to stdout.
  string A, B;
  cin >> A >> B;
  cout << fromIntVector(solution(A, B));
}