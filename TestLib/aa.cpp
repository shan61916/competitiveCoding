//21171_somesh || asomesh999
 
#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i=a;i<b;i++)
#define io ios::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
long int mod=1000000007;
 
template<typename T>
void debug(T arr) {
  for(auto it : arr) {
    cout << it << ' ';
  }
  cout << '\n';
}
 
int main()
{ 
  int n;
  cin >> n;
  vl arr(n);
  set<int> odd, even;
  int oddSize = 0, evenSize = 0;
  fr(i, 0, n) {
    if ((i + 1) % 2 == 0)
      even.insert(i + 1);
    else 
      odd.insert(i + 1);
  }
  vector<pii> eveneven;
  vector<pii> oddodd;
  int count = 0;
  int prevPos = -1;
  int type = 0;
  fr(i, 0, n) {
    cin >> arr[i];
    if (arr[i] == 0) {
      count++;
      continue;
    }
    if (arr[i] % 2 == 0) {
      if (!type) {
        eveneven.push_back({prevPos, i});
      }
      if (type == 1) {
        eveneven.push_back({prevPos, i});
      }
      prevPos = i;
      type = 1;
      even.erase(even.find(arr[i]));
    } else {
      if (!type) {
        oddodd.push_back({prevPos, i});
      }
      if (type == 2) {
        oddodd.push_back({prevPos, i});
      }
      prevPos = i;
      type = 2;
      odd.erase(odd.find(arr[i]));
    }
    count = 0;
  }
  if (count) {
    if (type == 1) {
      eveneven.push_back({prevPos, n});
    } else {
      oddodd.push_back({prevPos, n});
    }
  }
  oddSize = (int) odd.size();
  evenSize = (int) even.size();
  sort(eveneven.begin(), eveneven.end(), [&] (pii a, pii b) {
    return (a.second - a.first) < (b.second - b.first);
  });
  sort(oddodd.begin(), oddodd.end(), [&] (pii a, pii b) {
    return (a.second - a.first) < (b.second - b.first);
  });
  // fr(i, 0, oddodd.size()) {
  //  cout << oddodd[i].first << ' ' << oddodd[i].second << '\n';
  // }
  // cout << '\n';
  // fr(i, 0, eveneven.size()) {
  //  cout << eveneven[i].first << ' ' << eveneven[i].second << '\n';
  // }
  fr(i, 0, eveneven.size()) {
    int req = eveneven[i].second - eveneven[i].first - 1;
    if (req <= evenSize) {
      fr(j, eveneven[i].first + 1, eveneven[i].second) {
        arr[j] = *even.begin();
        even.erase(even.begin());
        evenSize--;
      }
    } else {
      int temp = evenSize;
      if (eveneven[i].first == -1) {
        fr(j, eveneven[i].first + 1, eveneven[i].second - temp) {
          arr[j] = *odd.begin();
          odd.erase(odd.begin());
          oddSize--;
        }
        fr(j, eveneven[i].second - temp, eveneven[i].second) {
          arr[j] = *even.begin();
          even.erase(even.begin());
          evenSize--;
        }
      } else {
        fr(j, eveneven[i].first + 1, eveneven[i].first + 1 + temp) {
          arr[j] = *even.begin();
          even.erase(even.begin());
          evenSize--;
        }
        fr(j, eveneven[i].first + temp + 1, eveneven[i].second) {
          arr[j] = *odd.begin();
          odd.erase(odd.begin());
          oddSize--;
        }
      }
    }
  }
  fr(i, 0, oddodd.size()) {
    int req = oddodd[i].second - oddodd[i].first - 1;
    if (req <= oddSize) {
      fr(j, oddodd[i].first + 1, oddodd[i].second) {
        arr[j] = *odd.begin();
        odd.erase(odd.begin());
        oddSize--;
      }
    } else {
      int temp = oddSize;
      if (oddodd[i].first == -1) {
        fr(j, oddodd[i].first + 1, oddodd[i].second - temp) {
          arr[j] = *even.begin();
          even.erase(even.begin());
          evenSize--;
        }
        fr(j, oddodd[i].second - temp, oddodd[i].second) {
          arr[j] = *odd.begin();
          odd.erase(odd.begin());
          oddSize--;
        }
      } else {
        fr(j, oddodd[i].first + 1, oddodd[i].first + 1 + temp) {
          arr[j] = *odd.begin();
          odd.erase(odd.begin());
          oddSize--;
        }
        fr(j, oddodd[i].first + temp + 1, oddodd[i].second) {
          arr[j] = *even.begin();
          even.erase(even.begin());
          evenSize--;
        }
      }
    }
  }
  fr(i, 0, n) {
    if (arr[i] == 0) {
      if (arr[i - 1] % 2 == 0) {
        if (evenSize > 0) {
          arr[i] = *even.begin();
          even.erase(even.begin());
          evenSize--;
        } else {
          arr[i] = *odd.begin();
          odd.erase(odd.begin());
          oddSize--;
        }
      } else {
        if (oddSize > 0) {
          arr[i] = *odd.begin();
          odd.erase(odd.begin());
          oddSize--;
        } else {
          arr[i] = *even.begin();
          even.erase(even.begin());
          evenSize--;
        }
      }
    }
  }
  // debug(arr);
  int ans = 0;
  type = (arr[0] % 2 == 0) ? 1 : 2;
  fr(i, 1, n) {
    if (arr[i] % 2 == 0) {
      if (type == 2) {
        ans++;
        type = 1;
      }
    } else {
      if (type == 1) {
        ans++;
        type = 2;
      }
    }
  }
  cout << ans << '\n';
 
  #ifdef CODE
    cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
  #endif
  return 0;
}