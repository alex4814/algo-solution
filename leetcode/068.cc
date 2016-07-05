#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  string getLine(vector<string> &row, int maxWidth) {
    int n = row.size();
    if (n == 1) {
      string s(maxWidth, ' ');
      s.replace(0, row[0].size(), row[0]);
      return s;
    } else {
      string line;
      int cwidth = 0;
      for (auto str: row) {
        cwidth += str.size();
      }
      int q = (maxWidth - cwidth) / (n - 1);
      int r = (maxWidth - cwidth) % (n - 1);
      string s = row[0];
      for (int i = 1; i < n; ++i) {
        s += string(q, ' ');
        if (r-- > 0) {
          s += " ";
        }
        s += row[i];
      }
      return s;
    }
  }

  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ret;
    int width = 0;
    vector<string> row;
    for (auto it = words.begin(); it != words.end(); ++it) {
      if (row.empty()) {
        row.push_back(*it);
        width += it->size();
      } else if (width + 1 + it->size() > maxWidth) {
        string s = getLine(row, maxWidth);
        ret.push_back(s);
        // new line
        width = it->size();
        row.clear();
        row.push_back(*it);
      } else {
        row.push_back(*it);
        width += 1 + it->size();
      }
    }
    if (row.empty() == false) {
      ret.push_back(getLine(row, maxWidth));
    }
    // modify last line
    string &lline = *(ret.rbegin());
    int n = lline.size(), t = 0;
    for (int i = 0; i < n; ++i) {
      if (i && isspace(lline[i]) && isspace(lline[i - 1])) continue;
      lline[t++] = lline[i];
    }
    for (int i = t; i < n; ++i) {
      lline[i] = ' ';
    }
    return ret;
  }
};

int main() {
  vector<string> st = {"Don't","go","around","saying","the","world","owes","you","a","living;","the","world","owes","you","nothing;","it","was","here","first."};
  Solution s = Solution();
  vector<string> l = s.fullJustify(st, 30);
  for (auto str: l) {
    cout << str << endl;
  }
  return 0;
}
