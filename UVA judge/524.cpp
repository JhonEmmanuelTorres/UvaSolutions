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

vi primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
vi container(17);
vector<vi> graph(17, vi());
ll n;


void search(ll index) {
  if (index == 1 and container[index] != 0) {

    auto repeat = 0;
    for (size_t i = 1; i <= n; i++) {
      if (container[i] != 0) {
        repeat++;
      }
    }

    if (repeat == n) {
      auto aux = container[1];
      
      std::cout << 1;
      while (aux != 1) {
        std::cout << ' ' << aux;
        aux = container[aux];
      }
      std::cout << '\n';
    }

    return;
  }

  for (auto i: graph[index]) {
    if (i <= n and container[index] == 0) {
      container[index] = i;
      search(i);
      container[index] = 0;
    }
    else
      break;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  for (size_t i = 1; i < graph.size(); i++) {
    for (auto prime: primes)
      if (prime > i)
        graph[i].push_back(prime - i);
  }

  auto cas = 1;
  cin >> n;
  while (true) {

    for (size_t i = 1; i <= n; i++) {
      container[i] = 0;
    }

    std::cout << "Case " << cas << ':' << '\n';
    cas++;
    search(1);
    if (cin >> n)
      std::cout << '\n';
    else
      break;
  }


  return 0;
}
