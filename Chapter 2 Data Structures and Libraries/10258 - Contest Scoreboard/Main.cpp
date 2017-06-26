#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef vector<pii> vii;

bool myfunction (vi i, vi j) {
    if (i[0] != j[0])
        return i[0] < j[0];
    if (i[1] != j[1])
        return i[1] > j[1];
    return i[2] > j[2];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char l;
    string line;
    ll pt, c, p, t, tmp, attemps;
    stringstream split;
    map<ll, map<ll,ll>> score;

    getline(cin, line);
    pt = stoll(line);
    getline(cin, line);
    vector<vi> answer;

    while (true) {

        score.clear();
        answer.clear();
        while (getline(cin, line), !line.empty()) {

            split = stringstream(line);
            split >> c >> p >> t >> l;

            if (score.find(c) == score.end()) // c not in score
                score[c] = map<ll,ll>();

            if (l == 'I') { // incorrect
                if (score[c][p] >= 0)
                    score[c][p] += 20;
            }
            else if (l == 'C') {
                if (score[c][p] >= 0) {
                    score[c][p] = -score[c][p] - t;
                }
            }
        }


        for (auto& i: score) {
            tmp = 0;
            attemps = 0;
            for (auto j: i.ss)
                if (j.ss <= 0) {
                    tmp += -j.ss;
                    attemps++;
                }

            answer.push_back(vi({attemps, tmp, i.ff}));
        }

        sort(all(answer), myfunction);
        reverse(all(answer));
        for (auto i: answer)
            cout << i[2] << ' ' << i[0] << ' ' << i[1] << '\n';

        pt--;
        if (pt == 0)
            break;
        cout << '\n';
    }

    return 0;
}
