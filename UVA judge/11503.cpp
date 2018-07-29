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

class DisjointSet {
  private:
    map<string,string> parent;
    map<string,int> height;
    map<string,int> size;
    int sets;

  public:
    DisjointSet() {
      parent = map<string,string>();
      height = map<string,int>();
      size   = map<string,int>();
      sets = 0;
    }

    void add(string node) {
      if (parent.find(node) == parent.end()) {
        parent[node] = node;
        height[node] = 0;
        size[node]   = 1;
        sets        += 1;
      }
    }

    string findSet(string node) {
      string root = node;
      while (root != parent[root]) {
        root = parent[root];
      }

      string tmp;
      while (root != parent[node]) {
        tmp = parent[node];
        parent[node] = root;
        height[node] = 0;
        node = tmp;
      }

      return root;
    }

    bool isConnected(string nodeP, string nodeQ) {
      return findSet(nodeP) == findSet(nodeQ);
    }

    bool unionSet(string nodeP, string nodeQ) {
      string rootP = findSet(nodeP);
      string rootQ = findSet(nodeQ);

      if (rootP != rootQ) {
        if(height[rootP] < height[rootQ]) {
          parent[rootP] = rootQ;
          size[rootQ] += size[rootP];
        } else {
          parent[rootQ] = rootP;
          size[rootP] += size[rootQ];
          if (height[rootP] == height[rootQ]) {
            height[rootP]++;
          }
        }
        sets--;
        return true;
      }
      return false;
    }

    int sizeOfSet(string node) {
      string rootNode = findSet(node);
      return size[rootNode];
    }

    int numOfSets() {
      return sets;
    }
};

ll t, n;
string u, v;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  for (cin >> t; t > 0; t--) {
    DisjointSet *netWork = new DisjointSet();
    for (cin >> n; n > 0; n--) {
      cin >> u >> v;
      netWork->add(u);
      netWork->add(v);
      netWork->unionSet(u, v);
      std::cout << netWork->sizeOfSet(u) << '\n';
    }
  }

  return 0;
}
