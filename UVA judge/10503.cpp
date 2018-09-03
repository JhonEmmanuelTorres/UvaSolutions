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


ll n, m, a, b, c, d, u, v;
bool posibble;
vector<vi> graph(7);
map<string, ll> visited;

void dfs(ll node, ll step) {
  if (step == n) {
    if(node == c)
      posibble = true;
    return;
  }

  if (posibble)
    return;

  for (auto neighbor: graph[node]) {

    auto left = to_string(min(neighbor, node));
    auto right = to_string(max(neighbor, node));
    auto key = left + ' ' + right;

    if (visited[key]) {
      visited[key]--;
      dfs(neighbor, step + 1);
      visited[key]++;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n, n) {
    cin >> m >> a >> b >> c >> d;
    posibble = false;

    visited = map<string, ll>();
    for (size_t i = 0; i < 7; i++) {
      graph[i] = vi();
    }

    for (size_t i = 0; i < m; i++) {
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
      auto aux = to_string(min(u, v)) + ' ' + to_string(max(u, v));
      visited[aux]++;
    }

    dfs(b, 0);

    std::cout << (posibble ? "YES" : "NO") << flush << '\n';
  }


  return 0;
}
