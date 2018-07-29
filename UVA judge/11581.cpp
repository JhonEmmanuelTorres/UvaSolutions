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

    vector<vi> grid(5, vi(5)), newGrid(5, vi(5)), indentity(5, vi(5, 0));

    ll dx[] = {0, 1,  0, -1};
    ll dy[] = {1, 0, -1,  0};
    string auxRow;
    ll t, index;
    for (cin >> t; t; t--) {

        for (ll i = 1; i < 4; i++) {
            cin >> auxRow;
            auxRow = ' ' + auxRow + ' ';
            for (ll j = 1; j < 4; j++)
                grid[i][j] = auxRow[j] - '0';
        }

        for (index = -1; grid != indentity; index++) {
            for (ll i = 1; i < 4; i++) {
                for (ll j = 1; j < 4; j++) {
                    newGrid[i][j] = 0;
                    for (ll k = 0; k < 4; k++)
                        newGrid[i][j] += grid[i + dx[k]][j + dy[k]];
                    newGrid[i][j] %= 2;
                }
            }
            grid = newGrid;
        }
        cout << index << '\n';
    }

    return 0;
}
