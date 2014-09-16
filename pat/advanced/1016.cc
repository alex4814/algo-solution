#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 1000

struct Record {
	char name[21];
	char date_and_time[12];
	char state;
	bool operator < (const Record &b) const {
		if (strcmp(name, b.name) == 0) {
			return strcmp(date_and_time, b.date_and_time) < 0;
		}
		return strcmp(name, b.name) < 0;
	}
};

struct Bill {
	char beginning[9];
	char ending[9];
	int lasting;
	int charge;
};

Record r[MAXN];
int toll[24], sum[24];
int n;

int charge(char *t, int &lasting) {
	int d, h, m;
	sscanf(t, "%d:%d:%d", &d, &h, &m);
	lasting = d * 24 * 60 + h * 60 + m;
	int ret = d * sum[23] + sum[h - 1];
	return ret + toll[h] * m;
}
int charge_between(char *b, char *e, int &lasting) {
	int lb, le;
	int cb = charge(b, lb);
	int ce = charge(e, le);
	lasting = le - lb;
	return ce - cb;
}

void print(int s, int t) {
	char *name = r[s].name;
	vector<Bill> bill;
	for (int i = s; i + 1 < t; ++i) {
		if (r[i].state == 0) continue;
		if (r[i + 1].state == 1) continue;
		Bill p;
		strcpy(p.beginning, r[i].date_and_time + 3);
		strcpy(p.ending, r[i + 1].date_and_time + 3);
		p.charge = charge_between(p.beginning, p.ending, p.lasting);
		bill.push_back(p);
	}
	if (bill.size() == 0) return;

	printf("%s %c%c\n", name, r[s].date_and_time[0], r[s].date_and_time[1]);
	int tot = 0;
	for (int i = 0; i < (int)bill.size(); ++i) {
		printf("%s %s %d $%.2f\n", 
			   bill[i].beginning, bill[i].ending, bill[i].lasting, bill[i].charge / 100.0); 
		tot += bill[i].charge;
	}
	printf("Total amount: $%.2f\n", tot / 100.0);
}

int main() {
	char s[10];

	for (int i = 0; i < 24; ++i) {
		scanf("%d", &toll[i]);
		sum[i] = toll[i] * 60 + (i ? sum[i - 1] : 0);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s %s %s", r[i].name, r[i].date_and_time, s);
		r[i].state = (s[1] == 'n' ? 1 : 0);
	}

	sort(r, r + n);
	int b = 0;
	for (int i = 1; i < n; ++i) {
		if (strcmp(r[b].name, r[i].name) != 0) {
			print(b, i); b = i;
		}
	}
	print(b, n);

	return 0;
}
