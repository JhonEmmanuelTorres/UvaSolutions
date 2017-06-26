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

    ll n, k, m, answer;
    string line;
    getline(cin, line);
    map<char,ll> values;
    cout << fixed << setprecision(2);

    for(n = stoll(line); n; n--) {
        values.clear();

        getline(cin, line);
        for (k = stoll(line); k; k--) {
            getline(cin, line);
            values[line.front()] = stoll(line.substr(2));
        }

        answer = 0;
        getline(cin, line);
        for (m = stoll(line); m; m--) {
            getline(cin, line);
            for (char i: line)
                if (values.find(i) != values.end()) // key i in values
                    answer += values[i];
        }

        cout << answer / 100.0 << "$\n";
    }
    return 0;
}
