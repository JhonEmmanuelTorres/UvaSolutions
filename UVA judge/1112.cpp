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

ll c, n, e, m, t, u, v, w;
std::map<ll, std::vector<pii>> maze;
std::vector<bool> visited(101);
std::vector<ll> depth(101);
pii tmp;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  for (std::cin >> c; c > 0; c--) {
    cin >> n >> e >> t >> m;

    for (size_t i = 0; i < n + 1; i++) {
      maze[i] = std::vector<pii>();
      visited[i] = false;
      depth[i] = INF;
    }

    for (size_t i = 0; i < m; i++) {
      cin >> u >> v >> w;
      tmp = {w, u};
      maze[v].eb(tmp);
    }

    priority_queue<pii, vector<pii>, greater<pii>> node_list;
    tmp = {0, e};
    node_list.push(tmp);

    depth[e] = 0;

    while (!node_list.empty()) {
      auto _edge = node_list.top();
      auto depth_node = _edge.ff;
      auto current_node = _edge.ss;
      node_list.pop();

      if (visited[current_node])
        continue;

      visited[current_node] = true;

      for (auto _neighbor: maze[current_node]) {
        auto weight = _neighbor.ff;
        auto link = _neighbor.ss;

        if (depth[link] > depth_node + weight) {
          depth[link] = depth_node + weight;

          tmp = {depth[link], link};
          node_list.push(tmp);
        }
      }
    }

    auto answer = 0;
    for (size_t i = 0; i < n + 1; i++) {
      if (depth[i] <= t)
        answer++;
    }

    std::cout << answer << '\n';
    if (c != 1)
      std::cout << '\n';

  }



  return 0;
}
