#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef vector<pii> vii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, aux;
    const ll MAX_N = ll(3e3 + 1);
    bitset<MAX_N> consecutive;
    vi numbers(MAX_N);
    while (cin >> n) {
        for (ll i = 0; i < n; i++)
            cin >> numbers[i];

        consecutive.reset();
        for (ll i = 0; i < n - 1; i++) {
            aux = abs(numbers[i + 1] - numbers[i]);
            if (aux < n)
                consecutive.set(aux);
        }

        cout << (consecutive.count() == n - 1 ? "Jolly" : "Not jolly") << '\n';
    }

    return 0;
}
