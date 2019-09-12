  //shan61916
#include <bits/stdc++.h>
  using namespace std;


void merge(vector<int> &arr, int start, int mid, int end){
	int sz = (end - start + 1);
	vector<int> temp(sz);
	int p = start, q = mid+1;
	int k = 0;
	for(int i = start; i <= end; i++) {
		if(p > mid) {
			temp[k++] = arr[q++]; // if the first half is exhausted
		} else if(q > end) {
			temp[k++] = arr[p++]; // if the second half is exhausted
		} else if(arr[p] < arr[q]) { 
			temp[k++] = arr[p++];
		} else {
			temp[k++] = arr[q++];
		}
	}
	for(int i = 0; i < k; i++) {
		arr[start++] = temp[i];
	}
}
void merge_sort(int low, int high, vector<int> &arr) {
   if(low < high){
	 int mid = (low + high)/2;
	 merge_sort(low, mid, arr);
	 merge_sort(mid+1, high, arr);
	 merge(arr, low, mid, high);
 }
}

int main(){
  int n;
  cout << "Enter the size of the array : " << endl;
  cin >> n
  vector<int> arr(n);
  cout << "Enter the array elements : " << endl;
  for (int i = 0; i < n; i++) cin >> arr[i];
  merge_sort(0, n-1, arr);
  cout << "The array sorted in ascending order is : " << endl;
  for(auto it: arr) cout << it << " ";
  return 0;
} //good night.