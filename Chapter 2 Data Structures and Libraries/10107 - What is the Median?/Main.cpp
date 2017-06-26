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

    vi container;
    ll number;
    while (cin >> number) {
        container.push_back(number);
        nth_element(container.begin(), container.begin() + container.size() / 2, container.end());
        number = container[ container.size() / 2 ];
        if (!(container.size() & 1)) { // even
            nth_element(container.begin(), container.begin() + container.size() / 2 - 1, container.end());
            number = (number + container[ container.size() / 2 - 1]) / 2;
        }
        cout << number << '\n';
    }
    return 0;
}
