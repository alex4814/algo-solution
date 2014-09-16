#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define MAXN 10005
#define MAXM 105

int N, M, K;

struct Player {
	char arrive_time[10];
	char serve_time[10];
	int play_time;
	int vip;
	bool operator < (const Player &b) const {
		return strcmp(arrive_time, b.arrive_time) < 0;
	}
};

struct Table {
	int vip;
	bool occupied;
};

Player p[MAXN];
Table t[MAXM];
queue<int> waiting_queue, vip_queue;

int all_table_occupied() {
	for (int i = 1; i <= K; ++i) {
		if (t[i].occupied == false) return i;
	}
	return 0;
}

int vip_table_open() {
	for (int i = 1; i <= K; ++i) {
		if (t[i].vip && t[i].occupied == false) return i;
	}
	return 0;
}

void serve(int ix, int tix) {
	
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%s%d%d", p[i].arrive_time, &p[i].play_time, &p[i].vip);
	}
	scanf("%d%d", &K, &M);
	for (int i = 0, a; i < M; ++i) {
		scanf("%d", &a);
		t[a].vip = 1;
	}

	int o, v;
	sort(p, p + N);
	for (int i = 0; i < N; ++i) {
		if (i) { update(i); }
		if (o = all_table_occupied()) {
			waiting_queue.push_back(i);
		} else if (v = vip_table_open()) {
			if (vip_queue.size() > 0) {
				serve(vip_queue.front(), v);
			} else if (waiting_queue.size() > 0) {
				serve(waiting_queue.front(), v);
			} else {
				serve(i, v);
			}
		} else {
			serve(cur_player(), o);
		}
	}
	
	return 0;
}
