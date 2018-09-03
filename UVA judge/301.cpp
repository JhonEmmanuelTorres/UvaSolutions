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

vi city, limitLeft, rightLimit, pass;
ll capacity, Bstation, ticket, maxEarning, tmp;


void sumSegment(ll left, ll right, ll quantity) {
  for (ll i = left; i <= right; i++)
    city[i] += quantity;
}

void dfs(ll route, ll allSum) {
  maxEarning = max(allSum, maxEarning);
  if (route == ticket)
    return;


  sumSegment(limitLeft[route], rightLimit[route], pass[route]);

  if (*max_element(all(city)) <= capacity)
    dfs(route + 1, allSum + (rightLimit[route] - limitLeft[route] + 1) * pass[route]);

  sumSegment(limitLeft[route], rightLimit[route], -pass[route]);
  dfs(route + 1, allSum);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> capacity >> Bstation >> ticket, capacity or Bstation or ticket) {
    limitLeft = vi(ticket);
    rightLimit = vi(ticket);
    pass = vi(ticket);
    city = vi(Bstation);

    for (size_t i = 0; i < ticket; i++) {
      cin >> limitLeft[i];
      cin >> rightLimit[i];
      cin >> pass[i];
      rightLimit[i]--;
    }

    maxEarning = 0;
    dfs(0, 0);

    std::cout << maxEarning << '\n';
  }
  return 0;
}
