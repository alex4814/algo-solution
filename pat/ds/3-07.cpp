#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

stack<double> num;
vector<string> prefix;
vector<string>::reverse_iterator it;
const double EPS = 1e-8;

inline int sgn(double x) {
	return (x > EPS) - (x < -EPS);
}
inline bool is_operator(string s) {
	if (s == "+" || s == "-") return true;
	if (s == "*" || s == "/") return true;
	return false;
}

int main() {
	bool error = false;
	string s;

	while (cin >> s) {
		prefix.push_back(s);
	}

	for (it = prefix.rbegin(); it != prefix.rend(); ++it) {
		if (is_operator(*it)) {
			//cout << "op : " << *it << endl;
			if (num.size() < 2) { error = true; break; }
			double n1 = num.top(); num.pop();
			double n2 = num.top(); num.pop();
			//cout << n1 << " " << *it << " " << n2 << endl;
			if (*it == "+") {
				num.push(n1 + n2);
			} else if (*it == "-") {
				num.push(n1 - n2);
			} else if (*it == "*") {
				num.push(n1 * n2);
			} else {
				if (sgn(n2) == 0) { error = true; break; }
				num.push(n1 / n2);
			}
		} else {
			//cout << "num : " << *it << endl;
			num.push(atof((*it).c_str()));
		}
	}
	if (!error && num.size() == 1) {
		printf("%.1f\n", num.top());
	} else {
		printf("ERROR\n");
	}
	return 0;
}
