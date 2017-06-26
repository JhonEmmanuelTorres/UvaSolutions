#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef vector<pii> vii;

inline ll gaussBy2(ll n) {
	return (n * (n + 1));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	const ll MAX_N = 1e10;
    ll sz, p, x = 0, y = 0, step, currentPos;
	ll dx[] = {0, -1, 0, 1};
	ll dy[] = {1, 0, -1, 0};

	map<ll, tuple<ll,ll,ll>> container;
	for (ll i = 1, address = 0; gaussBy2(i - 1) < MAX_N; i++) {
		container[gaussBy2(i - 1) + 1] = make_tuple(x, y, i - 1);
		for (ll j = 0; j < 2; j++) {
			x += dx[address] * i;
			y += dy[address] * i;
			address = (address + 1) % 4;
		}
	}

	while(cin >> sz >> p, sz or p) {
		auto iter = container.lower_bound(p);
		sz = (sz / 2) + 1;
		currentPos = iter->ff;
		x = get<0>(iter->ss);
		y = get<1>(iter->ss);
		step = get<2>(iter->ss);

		if (step & 1) { // odd
			if (p <= currentPos - step) {
				x += step;
				currentPos -= step;
				y -= currentPos - p;
			}
			else
				x += currentPos - p;
		}
		else {
			if (p <= currentPos - step) {
				x -= step;
				currentPos -= step;
				y += currentPos - p;
			}
			else
				x -= currentPos - p;
		}

		cout << "Line = " << sz + y << ", column = " << sz + x << ".\n";
	}


    return 0;
}
