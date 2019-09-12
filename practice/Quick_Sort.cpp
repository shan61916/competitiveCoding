  //shan61916
#include <bits/stdc++.h>
  using namespace std;
typedef   long long ll;
typedef   unsigned long long ull ;
typedef   double dll ;
int partition(int low, int high, vector<int> &arr) {
	int pivot = arr[high];   // pivoting the last element
	int j = low - 1;
	for(int i = low; i < high; i++) {
		if(arr[i] <= pivot) {
			++j;
			swap(arr[j], arr[i]);
		}
	}
	swap(arr[j+1], arr[high]);
    return j+1;
}

void quick_sort(int low, int high, vector<int> &arr){
	if(low < high){
		int idx = partition(low, high, arr);
		quick_sort(low, idx-1, arr);
		quick_sort(idx+1, high, arr);
	}
}

int main(){
  int n;
  cout << "Enter the size of the array : " << endl;
  cin >> n;
  vector<int> arr(n);
  cout << "Enter the array elements : " << endl;
  for (int i = 0; i < n; i++) cin >> arr[i];
  quick_sort(0, n-1, arr);
  cout << "The array sorted in ascending order is : " << endl;
  for(auto it: arr) cout << it << " ";
  return 0;
} //good night.	