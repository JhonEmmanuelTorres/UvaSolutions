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

string word, tmp;

void permutations(string current = "") {
  auto n = current.length();

  if (n == word.length()) {
    cout << current << '\n';
    return;
  }

  auto element = string(1, word[n]);
  for (ll i = 0; i <= n; i++) {
    tmp = current;
    tmp.insert(i, element);
    permutations(tmp);
  }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  auto spacesLines = false;
  while (cin >> word) {
    if (spacesLines)
      std::cout << '\n';
    spacesLines = true;
    permutations();
  }

  return 0;
}
