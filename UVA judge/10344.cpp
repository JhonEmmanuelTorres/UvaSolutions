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

ll a, b, c, d, e, value;
char operators[] = {'*', '+', '-'};
ll pos[] = {0, 1, 2, 3, 4};
vector<vi> cacheNumbers(120, vi(5));
ll number[5];
bool answer;

inline ll evaluate(ll a, ll b, char op) {
  if (op == '*') {
    return a * b;
  }
  return op == '+' ? a + b : a - b;
}

bool isPossible() {
  for (auto s: cacheNumbers) {
    tie(a, b, c, d, e) = mt(number[s[0]], number[s[1]], number[s[2]], number[s[3]], number[s[4]]);
    for (auto w: operators)
      for (auto x: operators)
        for (auto y: operators)
          for (auto z: operators) {
            value = evaluate(a, b, w);
            value = evaluate(value, c, x);
            value = evaluate(value, d, y);
            value = evaluate(value, e, z);
            if (value == 23)
              return true;
          }
  }

  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  a = 0;
  do {
    for (size_t i = 0; i < 5; i++) {
      cacheNumbers[a][i] = pos[i];
    }
    a++;
  } while(next_permutation(pos, pos + 5));


  while (cin >> number[0], number[0]) {
    for (size_t i = 1; i < 5; i++) {
      cin >> number[i];
    }
    answer = isPossible();
    std::cout << (answer ? "Possible" : "Impossible") << '\n';
  }

  return 0;
}
