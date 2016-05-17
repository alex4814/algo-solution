/*
 * Creation Date: 2016-04-20
 * Created By: alex4814
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;

struct TrieNode {
  int cnt = 0;
  vector<shared_ptr<TrieNode>> ch = vector<shared_ptr<TrieNode>>(26, nullptr);
};

class Trie {
  shared_ptr<TrieNode> root;
public:
  Trie(shared_ptr<TrieNode> root): root(root) {}
  void insert(string);
  int count_words_with_prefix(string);
};

void Trie::insert(string word) {
  auto p = root;
  for (const char &c: word) {
    auto &l = p->ch[c - 'a'];
    if (l == nullptr) {
      l = make_shared<TrieNode>();
    }
    ++l->cnt;
    p = l;
  }
}

int Trie::count_words_with_prefix(string word) {
  auto p = root;
  for (const char &c: word) {
    p = p->ch[c - 'a'];
    if (p == nullptr) {
      return 0;
    }
  }
  return p->cnt;
}

Trie trie(make_shared<TrieNode>());

int main() {
  int n, m;
  cin >> n;
  string word;
  for (int i = 0; i < n; ++i) {
    cin >> word;
    trie.insert(word);
  }
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> word;
    cout << trie.count_words_with_prefix(word) << endl;
  }
  return 0;
}
