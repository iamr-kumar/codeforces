#include "bits/stdc++.h"
using namespace std;

#define MOD 1e9 + 7
#define INF 1e18
#define nline '\n'
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void solve() {
  int n, m;
  cin >> n;
  vector<int> a(n);
  FOR(i, 0, n) {
    cin >> a[i];
  }
  cin >> m;
  vector<string> b(m);
  FOR(i, 0, m) {
    cin >> b[i];
    // cout << b[i] << nline;
  }
  unordered_map<char, int> umapOne;
  unordered_map<int, char> umapTwo;
  for(auto s: b) {
    if(s.length() != n) {
      cout << "NO" << nline;
      continue;
    }
    bool flag = true;
    FOR(i, 0, n) {
      if(umapOne.find(s[i]) == umapOne.end() and umapTwo.find(a[i]) == umapTwo.end()) {
        umapOne[s[i]] = a[i];
        umapTwo[a[i]] = s[i];
      } 
      else if(umapOne.find(s[i]) != umapOne.end() and umapOne[s[i]] != a[i]) {
        flag = false;
        break;
      }
      else if(umapTwo.find(a[i]) != umapTwo.end() and umapTwo[a[i]] != s[i]) {
        flag = false;
        break;
      }
    }
    if(flag) {
      cout << "YES" << nline;
    } else {
      cout << "NO" << nline;
    }
    umapOne.clear();
    umapTwo.clear();
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}