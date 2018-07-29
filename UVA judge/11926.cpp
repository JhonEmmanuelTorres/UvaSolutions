#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef vector<pii> vii;

// constants
const ll MAX_N = ll(1e6);
bitset<MAX_N> schedule;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    ll n, m, l, r, inc;
    bool conflict;
    while (cin >> n >> m, n or m) {
        conflict = false; // without conflicts
        schedule.reset();

        // no repeat
        while (n) {
            n--;
            cin >> l >> r;

            for (ll i = l; i < r and !conflict; i++) {
                conflict = conflict or schedule[i];
                schedule[i] = true;
            }
        }

        // repeats
        while (m) {
            m--;
            cin >> l >> r >> inc;

            for (ll i = l, j = r; j <= MAX_N and !conflict; i += inc, j += inc)
                for (ll a = i; a < j and !conflict; a++) {
                    conflict = conflict or schedule[a];
                    schedule[a] = true;
                }

        }

        cout << (conflict ? "CONFLICT" : "NO CONFLICT") << '\n';
    }
    return 0;
}
