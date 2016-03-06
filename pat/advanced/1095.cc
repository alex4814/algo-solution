#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int N = 10005;

typedef pair<int, int> pii;

struct Record {
  string id;
  int timestamp;
  int inout; // 1 for in, 0 for out
};

vector<Record> r;
vector<int> q;
map<string, pii> rh;
bool valid[N];

bool operator<(const Record &a, const Record &b) {
  return a.timestamp < b.timestamp;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  char name[10], status[5];
  Record rec;
  for (int i = 0, x, y, z; i < n; ++i) {
    scanf("%s %d:%d:%d %s", name, &x, &y, &z, status);
    rec.id = name;
    rec.timestamp = x * 60 * 60 + y * 60 + z;
    rec.inout = status[0] == 'i' ? 1 : 0;
    r.push_back(rec);
  }
  for (int i = 0, x, y, z; i < k; ++i) {
    scanf("%d:%d:%d", &x, &y, &z);
    q.push_back(x * 60 * 60 + y * 60 + z);
  }
  sort(r.begin(), r.end());
  for (int i = 0; i < n; ++i) {
    auto it = rh.find(r[i].id);
    valid[i] = true;
    if (it != rh.end()) {
      if (it->second.first == 1 && r[i].inout == 1) {
        valid[it->second.second] = false;
        it->second.second = i;
      } else if (it->second.first == 0 && r[i].inout == 0) {
        valid[i] = false;
      } else {
        it->second.first = r[i].inout;
        it->second.second = i;
      }
    } else {
      if (r[i].inout == 0) {
        valid[i] = false;
      } else {
        rh[r[i].id] = make_pair(1, i);
      }
    }
  }
  for (auto &x: rh) {
    if (x.second.first == 1) {
      valid[x.second.second] = false;
    }
    x.second = make_pair(0, -1);
  }

  int kp = 0;
  int curr_cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (!valid[i]) {
      continue;
    }
    while (kp < k && r[i].timestamp > q[kp]) {
      printf("%d\n", curr_cnt);
      ++kp;
    }
    if (rh[r[i].id].second == -1) {
      rh[r[i].id].second = r[i].timestamp;
      ++curr_cnt;
    } else {
      rh[r[i].id].first += r[i].timestamp - rh[r[i].id].second;
      rh[r[i].id].second = -1;
      --curr_cnt;
    }
  }
  while (kp++ < k) {
    printf("%d\n", curr_cnt);
  }
  int maxt = 0;
  for (auto &x: rh) {
    if (x.second.first > maxt) {
      maxt = x.second.first;
    }
  }
  for (auto &x: rh) {
    if (x.second.first == maxt) {
      printf("%s ", x.first.c_str());
    }
  }
  printf("%02d:%02d:%02d\n", maxt / 3600, maxt % 3600 / 60, maxt % 60);
  return 0;
}
