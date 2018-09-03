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
typedef pair<string,string> pss;
typedef vector<pii> vii;
const ll INF = numeric_limits<ll>::max();

ll n, limit;
string character, value, objetiveWord;
vector<pss> container;
pss tmp;

void dfs(string current, ll node = 0, string pattern = "") {
  if (pattern.length() == 101 || limit == 100)
    return;

  if (current.empty()) {
    cout << pattern << '\n';
    limit++;
    return;
  }


  for (size_t i = 0; i < container.size(); i++) {
    character = container[i].ff;
    value = container[i].ss;
    if (value.length() <= current.length()) {
      if (value == current.substr(0, value.length())) {
        dfs(current.substr(value.length()), i, pattern + character);
      }
    }
    if (current.front() == '0') {
      string tmpCurrent = current;
      tmpCurrent.erase(0, tmpCurrent.find_first_not_of('0'));
      if (value.length() <= tmpCurrent.length()) {
        if (value == tmpCurrent.substr(0, value.length())) {
          dfs(tmpCurrent.substr(value.length()), i, pattern + character);
        }
      }
    }
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  auto cases = 1;
  while (cin >> n, n) {
    container.clear();

    while (n--) {
      cin >> character >> value;
      tmp = { character, value };
      container.push_back(tmp);
    }
    cin >> objetiveWord;

    sort(all(container));
    limit = 0;

    std::cout << "Case #" << cases++ << '\n';
    dfs(objetiveWord);
    std::cout << '\n';
  }
  return 0;
}
