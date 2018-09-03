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

ll t, n, tmp;
vi numbers(1000);
string aux;
bool possible;
set<string> answers;

void search(ll accum, ll index, string list) {
  if (accum == t) {
    possible = true;
    aux = list.substr(0, list.length() - 1);
    if (answers.find(aux) == answers.end()) {
      std::cout << aux << '\n';
    }
    answers.insert(aux);
    return;
  }

  if (accum > t or index == n)
    return;

  search(accum + numbers[index], index + 1, list + to_string(numbers[index]) + '+');
  search(accum, index + 1, list);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> t >> n, t or n) {
    for (ll i = 0; i < n; i++) {
      cin >> numbers[i];
    }
    answers = set<string>();

    std::cout << "Sums of " << t << ':' << '\n';
    possible = false;
    search(0, 0, "");

    if (!possible) {
      std::cout << "NONE" << '\n';
    }
  }

  return 0;
}
