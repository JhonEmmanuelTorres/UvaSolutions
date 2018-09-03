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

ll n, t = 1, answer;
vi sequence;

bool isSorted() {
  for (size_t i = 0; i < n - 1; i++) {
    if (sequence[i] > sequence[i + 1])
      return false;
  }
  return true;
}

void seePair() {
  if (isSorted()) {
    answer++;
    return;
  }

  for (size_t i = 0; i < n - 1; i++) {
    if (sequence[i] > sequence[i + 1]) {
      swap(sequence[i], sequence[i + 1]);
      seePair();
      swap(sequence[i], sequence[i + 1]);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n, n) {

    answer = 0;
    sequence = vi(n);
    for (size_t i = 0; i < n; i++) {
      cin >> sequence[i];
    }
    if (!isSorted())
      seePair();
    cout << "There are " << answer << " swap maps for input data set " << t++ << ".\n";
  }
  return 0;
}
