#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 100005
#define MAXL 10
#define MAXT 105

typedef pair<int, int> pii;
typedef long long ll;

struct Player {
	int t_arr;	// arriving time
	int t_srv;	// serving time
	int dur;		// duration
	int vip;
	int get_waiting_time() {
		int w = t_srv - t_arr;
		return (w + 30) / 60;
	}
	bool operator < (const Player &b) const {
		return t_arr < b.t_arr;
	}
};

struct Table {
	int n_served;
	int t_end;
	int busy;
	int vip;
};

inline int time_to_sec(const char *time) {
	int h, m, s;
	sscanf(time, "%d:%d:%d", &h, &m, &s);
	return h * 3600 + m * 60 + s;
}

void sec_to_time(int sec, char *time) {
	int h = sec / 3600;
	int m = (sec - h * 3600) / 60;
	int s = sec - 3600 * h - 60 * m;
	sprintf(time, "%02d:%02d:%02d", h, m, s);
}

void assign(Table *t, Player *p, int t_cur) {
	p->t_srv = t_cur;
	t->n_served += 1;
	t->busy = 1;
	t->t_end = t_cur + p->dur;
}

bool srv_time_compare(const Player a, const Player b) {
	return (a.t_srv < b.t_srv) ||
				 (a.t_srv == b.t_srv && a.t_arr < b.t_arr);
}

const char *t_start = "08:00:00";
const char *t_close = "21:00:00";
const int start = time_to_sec(t_start);
const int close = time_to_sec(t_close);

Player p[MAXN];
Table tb[MAXT];
priority_queue<int, vector<int>, greater<int>> tb_ord, tb_vip;
queue<int> p_ord, p_vip;

int get_assigned_table() {
	int tid = -1;
	if (tb_ord.empty()) {
		tid = tb_vip.top(); tb_vip.pop();
	} else if (tb_vip.empty()) {
		tid = tb_ord.top(); tb_ord.pop();
	} else {
		int vid = tb_vip.top();
		int oid = tb_ord.top();
		tid = min(vid, oid);
		(vid < oid ? tb_vip : tb_ord).pop();
	}
	return tid;
}

int main() {
	int n, m = 0;
	scanf("%d", &n);
	char arr[MAXL];
	for (int i = 0, dur, vip; i < n; ++i) {
		scanf("%s %d %d", arr, &dur, &vip);
		int x = time_to_sec(arr);
		if (x >= start && x < close) {
			p[m].vip = vip;
			p[m].dur = min(120, dur) * 60;	 // no more than 2 hours
			p[m++].t_arr = x;
		}	// eliminate those whose arriving time is illegal
	}
	int nt, nt_vip;
	scanf("%d %d", &nt, &nt_vip);
	for (int i = 0, x; i < nt_vip; ++i) {
		scanf("%d", &x);
		tb[x - 1].vip = 1;
	}

	/* process */
	for (int i = 0; i < nt; ++i) {
		(tb[i].vip ? tb_vip : tb_ord).push(i);
	}	// initially all tables are available
	sort(p, p + m);
	int k = 0;
	for (int t_cur = start; t_cur < close; ++t_cur) {
		/* enque */
		if (p[k].t_arr == t_cur) {
			(p[k].vip ? p_vip : p_ord).push(k);
			k += 1;
		}	// it is guaranteed that there is at most one pair arrives every second
		/* check busy tables */
		for (int i = 0; i < nt; ++i) {
			if (tb[i].busy) {
				if (tb[i].t_end == t_cur) {
					(tb[i].vip ? tb_vip : tb_ord).push(i);
					tb[i].busy = 0;
				} // table i is available now
			}
		}
		/* assign table for players */
		int sz = min(tb_vip.size() + tb_ord.size(), p_vip.size() + p_ord.size());
		for (int i = 0; i < sz; ++i) {
			int tid, pid;
			if (!tb_vip.empty() && !p_vip.empty()) {
				tid = tb_vip.top(); tb_vip.pop();
				pid = p_vip.front(); p_vip.pop();
			} else {
				tid = get_assigned_table();
				if (p_vip.empty()) {
					pid = p_ord.front(); p_ord.pop();
				} else if (p_ord.empty()) {
					pid = p_vip.front(); p_vip.pop();
				} else {
					int vid = p_vip.front();
					int oid = p_ord.front();
					int varr = p[vid].t_arr;
					int oarr = p[oid].t_arr;
					pid = (varr < oarr ? vid : oid);
					(varr < oarr ? p_vip : p_ord).pop();
				}
			}
			assign(&tb[tid], &p[pid], t_cur);
		}
	}
	sort(p, p + m, srv_time_compare);
	for (int i = 0; i < m; ++i) {
		if (p[i].t_srv == 0) {	// not served
			continue;
		}
		char t_arr[MAXL], t_srv[MAXL];
		sec_to_time(p[i].t_arr, t_arr);
		sec_to_time(p[i].t_srv, t_srv);
		int t_wait = p[i].get_waiting_time();
		printf("%s %s %d\n", t_arr, t_srv, t_wait);
	}
	for (int i = 0; i < nt; ++i) {
		printf("%d%c", tb[i].n_served, i + 1 == nt ? '\n' : ' ');
	}
	return 0;
}


