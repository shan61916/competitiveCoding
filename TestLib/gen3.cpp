// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int n = rand(1, 4);
    int t = rand(0, 4);
    cout <<n + t << endl;
    vector<int> a(n + t);
    for(int i = 0; i < n; i++) a[i] = i + 1;
    for(int i = n; i < n + t; i++) a[i] = 0;
    random_shuffle(a.begin(), a.end());
    for(int i = 0; i < n + t; i++) cout << a[i] << " ";
}