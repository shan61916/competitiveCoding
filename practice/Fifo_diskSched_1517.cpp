  //17bcs1517
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
  cout << "Enter the Number of incoming I/O requests \n";

  int n;
  cin >> n;

  cout << "Enter the maximum number of tracks on the disk \n";

  int tracks;
  cin >> tracks;

  cout << "Enter the tracks that are requested in order \n";

  vector<int> requests(n);
  for(auto &x : requests) cin >> x;

  int previous = 0, seekmoments = 0; 

  cout << "Enter the initial position of I/O head" << endl;

  cin >> previous;

  cout << "IN a FCFS environment the I/O head moves in the following way : \n"; 

  for(int i = 0; i < n; i++) {
  	cout << "The head moves from " << previous << " to " << requests[i]; 
    cout << endl;

    seekmoments+= abs(previous - requests[i]);
    previous = requests[i];

  }

  cout << endl;

  cout << "The total seek moments encountered for the given requests are :" << seekmoments << endl; 
  
  cout << "The average seek moment for each request is :" << (dll)(seekmoments)/(dll)(n) << endl;
  
  return 0;
} //good night.

/* SAMPLE INTERACTION 

Enter the Number of incoming I/O requests 
5
Enter the maximum number of tracks on the disk 
200
Enter the tracks that are requested in order 
23 89 132 42 187
Enter the initial position of I/O head
100
IN a FCFS environment the I/O head moves in the following way : 
The head moves from 100 to 23
The head moves from 23 to 89
The head moves from 89 to 132
The head moves from 132 to 42
The head moves from 42 to 187

The total seek moments encountered for the given requests are :421
The average seek moment for each request is :84.2


*/