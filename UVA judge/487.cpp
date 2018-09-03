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

ll t, n;
char aux;
set<string> container;
vector<vi> visited, grid;

ll dx[] = {0, 0, 1, -1, -1, 1,  1, -1 };
ll dy[] = {1, -1, 0, 0, 1, 1, -1, -1 };

void dfs(ll x, ll y, string legal) {
  if (legal.length() >= 3)
    container.insert(legal);


  for (ll i = 0; i < 8; i++) {
    auto newX = x + dx[i];
    auto newY = y + dy[i];
    if (!visited[newX][newY] and grid[x][y] < grid[newX][newY]) {
      visited[newX][newY] = 1; // visited

      aux = char(grid[newX][newY]);
      string a = "";
      a += aux;

      dfs(newX, newY, legal + a);
      visited[newX][newY] = 0; // no visited
    }
  }
}

bool myCompator(string a, string b) {
  if (a.length() == b.length()) {
    for (ll i = 0; i < b.length(); i++)
      if (a[i] <= b[i])
        return true;
    return false;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  for (cin >> t; t > 0; t--) {
    cin >> n;
    grid = vector<vi>(n + 2, vi(n + 2, 0));
    container.clear();

    // read grid
    for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= n; j++) {
        cin >> aux;
        grid[i][j] = (int)aux;
      }
    }


    for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= n; j++) {

        visited = vector<vi>(n + 2, vi(n + 2, 0));
        for (ll i = 0; i <= n + 1; i++)
          visited[i][0] = visited[0][i] = visited[n + 1][i] = visited[i][n + 1] = 1;

        visited[i][j] = 1; // visited

        aux = char(grid[i][j]);
        string a = "";
        a += aux;
        dfs(i, j, a);
      }
    }

    bool flag = true;
    for (size_t i = 3; flag; i++) {
      flag = false;
      for (auto j: container)
        if (j.length() == i) {
          flag = true;
          std::cout << j << '\n';
        }
    }

    if (t != 1)
      std::cout << '\n';

  }


  return 0;
}
