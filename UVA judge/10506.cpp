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

ll n, m;
string number;
bool answer;
string answerString;
vector<string> container;
map<string, bool> visited;

void generate(ll index = 0) {
  if (index == m) {
    container.push_back(number);
    return;
  }

  for (char i = '0'; i < '0' + n; i++) {
    number[index] = i;
    generate(index + 1);
  }
}


void dfs(string node, string ouroboros) {
  visited[node] = true;

  auto countFalse = 0;
  for (auto element: visited)
    countFalse += element.second == false;

  if (countFalse == 0) {
    if (ouroboros.substr(0, m - 1) == ouroboros.substr(ouroboros.length() - m + 1)) {
      answer = true;
      answerString = ouroboros.substr(0, ouroboros.length() - m + 1);
    } else {
      visited[node] = false;
    }
    return;
  }


  for (auto neighbor: container) {
    if (!visited[neighbor] and ouroboros.substr(ouroboros.length() - m + 1) == neighbor.substr(0, m - 1)) {
      dfs(neighbor, ouroboros + neighbor.back());
    }
    if (answer) return;
  }

  visited[node] = false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);



  while (cin >> m >> n) {
    number = string(m, '0');
    container.clear();
    visited.clear();
    generate();
    for (auto i: container) {
      visited[i] = false;
    }

    answer = false;
    number = string(m, '0');

    dfs(number, number);
    std::cout << answerString << endl;
  }
  return 0;
}
