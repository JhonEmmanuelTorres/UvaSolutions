#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    string word;
    while (cin >> word, word != "#")
        cout << (next_permutation(word.begin(), word.end()) ? word : "No Successor") << '\n';

    return 0;
}
