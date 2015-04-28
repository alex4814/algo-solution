#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

#define MAXN 100005

struct User {
	long long id;
	char pw[20];
	bool operator < (const User &b) const {
		return id < b.id;
	}
};

int n;
User p;
set<User> account;
set<User>::iterator it;

main() {
	int i;
	long long id;
	char op[10], pw[20];

	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%s %lld %s", op, &id, pw);
		p.id = id;
		strcpy(p.pw, pw);

		if (op[0] == 'L') {
			if ((it = account.find(p)) == account.end()) {
				printf("ERROR: Not Exist\n");
			} else if (strcmp((*it).pw, pw) != 0) {
				printf("ERROR: Wrong PW\n");
			} else {
				printf("Login: OK\n");
			}
		} else if (op[0] == 'N') {
			if ((it = account.find(p)) != account.end()) {
				printf("ERROR: Exist\n");
			} else {
				printf("New: OK\n");
				account.insert(p);
			}
		}
	}
	return 0;
}
