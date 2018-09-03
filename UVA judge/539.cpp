#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define mt make_tuple
#define eb emplace_back

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef pair<ll,bool> pib;
typedef vector<pii> vii;
typedef vector<pib> vib;
const ll INF = numeric_limits<ll>::max();

typedef struct {
  ll u, v, visited;
} Edge;

ll n, m, max_path;
vector<Edge> edges;
Edge tmp;


void dfs(ll node, ll accum) {
  max_path = max(accum, max_path);

  for (ll i = 0; i < edges.size(); i++) {
    if (edges[i].u == node || edges[i].v == node) {

      ll neighbor;
      if (edges[i].u == node)
        neighbor = edges[i].v;
      if (edges[i].v == node)
        neighbor = edges[i].u;

      auto visited =  edges[i].visited;

      if (!visited) {
        edges[i].visited = true;
        dfs(neighbor, accum + 1);
        edges[i].visited = false;
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n >> m, n or m) {

    edges = vector<Edge>();

    for (ll i = 0; i < m; i++) {
      cin >> tmp.u >> tmp.v;
      tmp.visited = false;
      edges.push_back(tmp);
    }



    max_path = 0;

    for (ll i = 0; i < m; i++) {
      dfs(i, 0);
    }

    std::cout << max_path << '\n';
  }


  return 0;
}
