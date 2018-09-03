#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define mt make_tuple
#define eb emplace_back

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
const ll INF = numeric_limits<ll>::max();
const double EPS = std::numeric_limits<double>::epsilon();

std::map<char, float> probabilities;
std::vector<char> vowels({'a', 'e', 'i', 'o', 'u'});
std::vector<char> consonants;
std::map<char, ll> container;
std::vector<double> average(7);
std::vector<ll> allWords(7);
std::string word;
ll n;


double values[] = {
    12.53, 1.42, 4.68, 5.86, 13.68, 0.69,
    1.01, 0.70, 6.25, 0.44, 0.00, 4.97, 3.15,
    6.71, 8.68, 2.51, 0.88, 6.87, 7.98, 4.63,
    3.93, 0.90, 0.02, 0.22, 0.90, 0.52
};

void backtracking(ll index = 0, double accumBeauty = 0) {
    if (index == 7)
        return;

    std::vector<char> letters = (index + 1) % 2 == 0 ? vowels : consonants;

    for (auto letter : letters) {
        if (container[letter] < 2) {
            container[letter]++;
            average[index] += accumBeauty + (index + 1) * probabilities[letter];
            allWords[index]++;
            backtracking(
                index + 1,
                accumBeauty + (index + 1) * probabilities[letter]
            );
            container[letter]--;
        }
    }
}

double getBeauty() {
    double beauty = 0;
    for (int i = 0; i < word.length(); i++) {
        beauty += (i + 1) * probabilities[word[i]];
    }
    return beauty;
}


int main() {
      ios::sync_with_stdio(false);
      cin.tie(NULL);


    for (char i = 'a'; i <= 'z'; i++) {
        probabilities[i] = values[i - 'a'];
        container[i] = 0;
        if (find(all(vowels), i) == vowels.end())
            consonants.push_back(i);
    }

    std::map<char, vector<double>> answers;
    for (auto consonant : consonants) {
        fill(all(average), 0);
        fill(all(allWords), 0);

        container[consonant]++;
        backtracking(1, probabilities[consonant]);
        container[consonant]--;

        for (int i = 1; i < 7; ++i) {
            average[i] /= allWords[i];
        }
        answers[consonant] = vector<double>(all(average));
    }


    for (cin >> n; n > 0; n--) {
        cin >> word;
        if (word.length() == 1) {
            std::cout << "above or equal" << "\n";
            continue;
        }

        auto myBeauty = getBeauty();

        if (answers[word.front()][word.length() - 1] - myBeauty > EPS)
            std::cout << "below" << "\n";
        else
            std::cout << "above or equal" << "\n";
    }


    return 0;
}
