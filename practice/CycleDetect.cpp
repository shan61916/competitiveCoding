  //shan61916
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


struct node {
  int data;
  node* nxt;
};

node* head, * curr;

node* fetch_node(int n) {
  node* tmp = new node;
  tmp->data = n;
  tmp->nxt = NULL;
  return tmp;
}

void insert(int n) {
  node* tmp = fetch_node(n);
  if (head == NULL) {
    head = curr = tmp;
    return;
  }
  curr->nxt = tmp;
  tmp->nxt = head;
  curr = curr->nxt; 
}

bool find_cycle() {
  node* h1, *h2;
  h1 = h2 = head;
  while (1) {
    h1 = h1->nxt;
    h2 = h2->nxt->nxt;
    if (h1 == h2) return true;
    if (h2 == NULL or h1 == NULL) return false;
  }
}

int main() {
  head = curr = NULL;
  insert(2);
  insert(10);
  insert(12);
  insert(1290);
  int ans = find_cycle();
  ans == 1? cout << "Cycle present" : cout << "Cycle not present";
  return 0;
}