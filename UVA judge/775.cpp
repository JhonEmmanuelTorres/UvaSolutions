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
typedef vector<pii> vii;
const ll INF = numeric_limits<ll>::max();

string line;
ll n, u, v;
bool possible;
vector<vi> graph;
vector<bool> visited;

void dfs(ll node, ll pathLen, string path) {
  if (pathLen == n - 1) {
    auto haveOne = false;
    for (auto i: graph[node])
      if (i == 1) {
        haveOne = true;
        break;
      }
    if (haveOne) {
      possible = true;
      path += '1';
      std::cout << path << '\n';
    }
    return;
  }

  visited[node] = true;

  for (auto neighbor: graph[node]) {
    if (possible) return;

    if (!visited[neighbor]) {
      dfs(neighbor, pathLen + 1, path + to_string(neighbor) + ' ');
    }
  }
  visited[node] = false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while (getline(cin, line)) {

    n = stol(line);
    graph = vector<vi>(n + 1, vi());
    visited = vector<bool>(n + 1, false);

    while (getline(cin, line), line != "%") {
      sscanf(line.c_str(), "%lld%lld", &u, &v);
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    possible = false;
    dfs(1, 0, "1 ");
    if (!possible)
      std::cout << "N" << '\n';
  }



  return 0;
}
