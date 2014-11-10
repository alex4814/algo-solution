#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 10005
#define MAXL 265

typedef pair<int, int> pii;
typedef long long ll;

struct Node {
	string name;
	int depth;
	vector<Node *> cats;
	vector<Node *> files;
};

Node *root;

bool cmp(const Node *a, const Node *b) {
	return a->name < b->name;
}

void insert(Node *rt, string p) {
	if (p.empty()) return;
	size_t pos = p.find_first_of("\\");
	string name;
	if (pos != string::npos) {	// category
		int n = rt->cats.size();
		name = p.substr(0, pos);
		Node *ch = NULL;
		for (int i = 0; i < n; ++i) {
			if (rt->cats[i]->name == name) {
				ch = rt->cats[i];
				break;
			}
		}
		if (ch == NULL) {
			ch = new Node;
			ch->name = name;
			ch->depth = rt->depth + 1;
			rt->cats.push_back(ch);
		}
		insert(ch, p.substr(pos + 1));
	} else {	// file
		name = p;
		Node *ch = new Node;
		ch->name = name;
		ch->depth = rt->depth + 1;
		rt->files.push_back(ch);
	}
}

void print(Node *rt) {
	if (rt == NULL) return;
	for (int i = 0; i < rt->depth * 2; ++i) {
		putchar(' ');
	}
	cout << rt->name << endl;
	sort(rt->cats.begin(), rt->cats.end(), cmp);
	int n = rt->cats.size();
	for (int i = 0; i < n; ++i) {
		print(rt->cats[i]);
	}
	sort(rt->files.begin(), rt->files.end(), cmp);
	int m = rt->files.size();
	for (int i = 0; i < m; ++i) {
		print(rt->files[i]);
	}
}

int main() {
	int n;
	cin >> n;
	root = new Node;
	root->name = "root";
	root->depth = 0;
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		insert(root, s);
	}
	print(root);
	return 0;
}
