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

ll problem(ll n) {
  ll len = 1;
  while (n != 1) {
    if (n % 2 == 1)
      n = 3 * n + 1;
    else
      n = n / 2;
    len++;
  }
  return len;
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll left, right, maxElement;

  while (cin >> left >> right) {
    ll auxi = left, auxj = right;
    if (left > right)
      swap(left, right);

    maxElement = 1;
    for (ll i = left; i <= right; i++) {
      maxElement = max(maxElement, problem(i));
    }
    std::cout << auxi << ' ' << auxj << ' ' << maxElement << '\n';
  }

  return 0;
}
