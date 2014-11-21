#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define EPS 1e-8
#define MAXN 100005
#define MAXL 85

typedef pair<int, int> pii;
typedef long long ll;

vector<int> ids;
unordered_multimap<string, int> m_ii[4];
unordered_multimap<int, int> m_yi;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int id;
		cin >> id;
		ids.push_back(id);

		getchar();
		string info[4];
		for (int j = 0; j < 4; ++j) {
			getline(cin, info[i]);
			if (j != 2) {
				m_ii[j].insert(make_pair(info[i], id));
			} else {
				size_t s = 0, p = 0;
				while ((p = info[i].find_first_of(' ', s)) != string::npos) {
					//cout << "keys: " << info[i].substr(s, p - s) << endl;
					m_ii[j].insert(make_pair(info[i].substr(s, p - s), id));
					s = p + 1;
				}
				//cout << "keys: " << info[i].substr(s) << endl;
				m_ii[j].insert(make_pair(info[i].substr(s), id));
			}
		}

		int py;
		cin >> py;
		m_yi.insert(make_pair(py, id));
	}
	int m;
	cin >> m;
	getchar();
	for (int i = 0; i < m; ++i) {
		string line;
		getline(cin, line);
		cout << line << endl;
		string query = line.substr(3);
		int type = line[0] - '0' - 1;
		//cout << type << " " << query << endl;
		if (type == 4) {
			int y = atoi(query.c_str());
			if (m_yi.count(y) > 0) {
				auto range = m_yi.equal_range(y);
				vector<int> ans;
				for (auto it = range.first; it != range.second; ++it) {
					ans.push_back(it->second);
				}
				sort(ans.begin(), ans.end());
				for (auto& x: ans) {
					cout << x << endl;
				}
			} else {
				cout << "Not Found" << endl;
			}
		} else {
			if (m_ii[type].count(query) > 0) {
				auto range = m_ii[type].equal_range(query);
				vector<int> ans;
				for (auto it = range.first; it != range.second; ++it) {
					ans.push_back(it->second);
				}
				sort(ans.begin(), ans.end());
				for (auto& x: ans) {
					cout << x << endl;
				}
			} else {
				cout << "Not Found" << endl;
			}
		}
	}
	return 0;
}


