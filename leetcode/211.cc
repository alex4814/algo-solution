#include <cstdio>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

using namespace std;

class WordDictionary {
public:
  // Initialize
  WordDictionary() {
  }

  // Adds a word into the data structure.
  void addWord(string word) {
    for (int i = 0; i < word.size(); ++i) {
      if (i < m) {
        g[word[i] - 'a'][i]->push_back(n);
      } else {
        vector<int> c = { n };
        g[word[i] - 'a'].push_back(&c);
      }
    }
    n += 1;
    m = max(m, (int)word.size());
  }

  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool search(string word) {
    if (word.size() > m) return false;

    vector<int> ws;
    for (int i = 0; i < n; ++i) {
      //ws.push_back(i);
    }
    for (int i = 0; i < word.size(); ++i) {
      //if (word[i] == '.') continue;
      //printf("n = %d, m = %d\n", n, m);
      printf("ch = %c, i = %d\n\n", word[i], i);
      //auto x = g[word[i] - 'a'][i];
      //auto it = set_intersection(ws.begin(), ws.end(), x.begin(), x.end(), ws.begin());
      //ws.resize(it - ws.begin());
      //if (ws.empty()) return false;
    }
    return true;
  }

private:
  vector<vector<int>*> g[26];
  int n = 0; // number of words
  int m = 0; // max length of word
  void print(vector<int> &a) {
    for (int i = 0; i < a.size(); ++i) {
      printf(" %d", a[i]);
    }
    putchar('\n');
  }
};


int main() {
  // Your WordDictionary object will be instantiated and called as such:
  WordDictionary wordDictionary;
  wordDictionary.addWord("word");
  wordDictionary.addWord("rd");
  wordDictionary.addWord("rd");
  wordDictionary.addWord("rd");
  wordDictionary.addWord("rd");
  wordDictionary.addWord("rd");
  wordDictionary.addWord("rd");
  wordDictionary.addWord("rd");
  wordDictionary.addWord("rd");
  wordDictionary.addWord("rd");
  wordDictionary.addWord("rd");
  wordDictionary.addWord("rd");
  wordDictionary.addWord("rd");
  wordDictionary.addWord("rd");
  wordDictionary.addWord("rd");
  wordDictionary.addWord("rd");
  //wordDictionary.search("rd");
  return 0;
}
