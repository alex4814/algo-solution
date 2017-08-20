/*
 * Creation Date: 2016-07-06
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
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;

static struct TrieNode {
  static const int n = 26;

  TrieNode(): isWord(false) {
    for (int i = 0; i < n; ++i) {
      ch[i] = nullptr;
    }
  }

  ~TrieNode() {
    for (int i = 0; i < n; ++i) {
      if (ch[i]) {
        delete ch[i];
      }
    }
  }

  TrieNode *ch[n];
  bool isWord;
};

class Trie {
public:
  Trie() {
    root = new TrieNode();
  }

  ~Trie() {
    if (root) {
      delete root;
    }
  }

  // Inserts a word into the trie.
  void insert(string word) {
    auto p = root;
    for (const char c: word) {
      if (p->ch[c - 'a'] == nullptr) {
        p->ch[c - 'a'] = new TrieNode();
      }
      p = p->ch[c - 'a'];
    }
    p->isWord = true;
  }

  // Returns if the word is in the trie.
  bool search(string word) {
    auto p = root;
    for (const char c: word) {
      if (p->ch[c - 'a'] == nullptr) {
        return false;
      }
      p = p->ch[c - 'a'];
    }
    return p->isWord;
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    auto p = root;
    for (const char c: prefix) {
      if (p->ch[c - 'a'] == nullptr) {
        return false;
      }
      p = p->ch[c - 'a'];
    }
    return true;
  }

private:
  TrieNode* root;
};


int main() {
  // Your Trie object will be instantiated and called as such:
  Trie trie;
  trie.insert("somestring");
  trie.insert("all");
  trie.insert("alex");
  cout << trie.search("alex") << endl;
  cout << trie.startsWith("al") << endl;
  return 0;
}
