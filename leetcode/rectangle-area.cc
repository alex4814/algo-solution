#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MAXN 100005
#define EPS 1e-8

struct Point {
  int x, y;
};
struct Rectangle {
  Point bottom_left;
  Point top_right;
  int area() {
    int width = top_right.x - bottom_left.x;
    int height = top_right.y - bottom_left.y;
    return width * height;
  }
  int intersect_area(Rectangle &b) {
    
  }
};

class Solution {
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    Rectangle r1 = 
  }
};

int main() {

  return 0;
}

