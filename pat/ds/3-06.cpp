#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <stack>
using namespace std;

#define MAXN 100
const string delim = "+-*/";

string expr, number, oper;
vector<string> suffix;
stack<char> op;
bool digit_encountered;

int priority(char c) {
	if (c == '*' || c == '/') return 2;
	if (c == '+' || c == '-') return 1;
	return 0;
}

int main() {
	cin >> expr;

	number = "";
	digit_encountered = false;
	int len = expr.size();
	for (int i = 0; i < len; ++i) {
		char c = expr[i];
		//cout << c << endl;
		if (delim.find(c) != string::npos && digit_encountered) {
			digit_encountered = false;
			if (op.empty() || priority(c) > priority(op.top())) {
				op.push(c);
			} else {
				while (!op.empty() && priority(c) <= priority(op.top())) {
					suffix.push_back(oper = op.top());
					op.pop();
				}
				op.push(c);
			}
		} else if (c == '(') {
			op.push(c);
		} else if (c == ')') {
			while (op.top() != '(') {
				suffix.push_back(oper = op.top());
				op.pop();
			}
			op.pop();
		} else {
			digit_encountered = true;
			number += c;
			//cout << "number = " << number << endl;
			if (i + 1 == len || delim.find(expr[i + 1]) != string::npos || expr[i + 1] == ')') {
				suffix.push_back(number);
				number = "";
			}
		}
	}
	while (!op.empty()) {
		suffix.push_back(oper = op.top());
		op.pop();
	}
	int n = suffix.size();
	for (int i = 0; i < n - 1; ++i) {
		while (suffix[i].size() > 1 && suffix[i][0] == '+') {
			suffix[i].erase(0, 1);
		}
		cout << suffix[i] << ' ';
	}
	cout << suffix[n - 1] << endl;
	return 0;
}
