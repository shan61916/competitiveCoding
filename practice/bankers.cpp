#include<bits/stdc++.h>
using namespace std;
int main() 
{ 
    // P0, P1, P2, P3, P4 are the Process names here 
  
    int n, m, i, j, k; 
    cout << "Enter the Number of processes and number of resources ?";
    cin >> n >> m; 
    int alloc[n][m]; 
    int max[n][m];
    cout<< "Enter the allocation matrix" << endl;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) cin >> alloc[i][j];
    }
    cout << "Enter the maximum avaialble resource matrix" << endl;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) cin >> max[i][j];
    }
    int avail[m];
    cout << "\n Enter the number of available resource list ?";
    for(i = 0; i < m; i++) cin >> avail[i];
    int f[n], ans[n], ind = 0; 
    for (k = 0; k < n; k++) { 
        f[k] = 0; 
    } 
    int need[n][m]; 
    for (i = 0; i < n; i++) { 
        for (j = 0; j < m; j++) 
            need[i][j] = max[i][j] - alloc[i][j]; 
    } 
    int y = 0; 
    for (k = 0; k < n; k++) { 
        for (i = 0; i < n; i++) { 
            if (f[i] == 0) { 
  
                int flag = 0; 
                for (j = 0; j < m; j++) { 
                    if (need[i][j] > avail[j]){ 
                        flag = 1; 
                         break; 
                    } 
                } 

                if (flag == 0) { 
                    ans[ind++] = i; 
                    for (y = 0; y < m; y++) 
                        avail[y] += alloc[i][y]; 
                    f[i] = 1; 
                } 
            } 
        } 
    } 

    cout << "The correct sequence is " << endl;
    for (i = 0; i < n - 1; i++) cout << "P" << ans[i] << ", ";
    
    return (0); 
  
} 