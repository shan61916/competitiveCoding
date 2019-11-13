#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
const ll inf = (ll)(1e9 + 7);
string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
vector<vector<pair<int, int>>> adj[1001];
map<pair<int, int>> key;

/*
 * Complete the 'minCost' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

int minCost(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    for(ll i = 0; i < (ll)g_from.size(); i++) {
        adj[g_from[i]].pb(mp(g_to[i], g_weight[i]));
        key[mp(g_from[i], g_to[i])] = 1;
    }
    for(ll i = 1; i <= g_nodes; i++) {
        for(ll j = 1; j <= g_nodes; j++) {
            if(key[i][j] or key[j][i]) continue;
            adj[i].pb(mp(j, 1));
            adj[j].pb(mp(i, 1));
        }
    }
    set<pair<ll, ll>> q;
    vector<ll> dist(g_nodes + 1, inf);
    dist[1] = 0;
    q.insert({0, 1});
    while(!q.empty()) {
        ll u = q.begin()->second;
        q.erase(q.begin());
        for(auto it: adj[u]) {
            ll x = it.first;
            ll w = it.second;
            if(dist[x] > dist[u] + w) {
                q.erase(mp(dist[x], x));
                dist[x] = dist[u] + w;
                q.insert(mp(dist[x], x));
            }
        }
    }
        return dist[g_nodes];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    int result = minCost(g_nodes, g_from, g_to, g_weight);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
