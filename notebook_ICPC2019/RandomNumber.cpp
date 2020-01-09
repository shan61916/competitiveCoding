
// METHOD 1:- long long or need to be taken care of.
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);

int myrand(int mod) {
    return mt()%mod;
}

// METHOD 2 :- Not very preffered, but nice to have
inline int myrand(int mod) {
  return (((long long )rand() << 15) + rand()) % mod;
}

// METHOD 3 :- Again 1 more method but 1st one is still the best.
int myrand(int mod) {
    int t = rand() % mod;
    t = (1LL*t*RAND_MAX + rand()) % mod;
    return t;
}

// Method 4 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}