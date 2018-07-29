#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef vector<pii> vii;
const ll INF = numeric_limits<ll>::max();

ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};
bool visited[1005][1005];
ll depth[1005][1005], grid[1005][1005];
ll t, n, m;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  for (cin >> t; t > 0; t--) {
    cin >> n >> m;
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < m; j++) {
        cin >> grid[i][j];
        visited[i][j] = false;
        depth[i][j] = INF;
      }
    }

    depth[0][0] = grid[0][0];
    priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> node_list;

    node_list.push(make_pair(grid[0][0], make_pair(0, 0)));

    while (!node_list.empty()) {
      auto tmp = node_list.top();
      auto depth_node = tmp.ff;
      auto a = tmp.ss.ff;
      auto b = tmp.ss.ss;
      node_list.pop();

      if (visited[a][b])
        continue;

      visited[a][b] = true;

      for (size_t i = 0; i < 4; i++) {
        auto c = a + dx[i];
        auto d = b + dy[i];
        if (c < 0 or c >= n or d < 0 or d >= m)
          continue;

        auto weigth = grid[c][d];
        if(depth_node + weigth < depth[c][d]) {
          depth[c][d] = depth_node + weigth;
          node_list.push(make_pair(depth[c][d], make_pair(c, d)));
        }
      }

    }

    cout << depth[n - 1][m - 1] << '\n';

  }


  return 0;
}
