/*
 * Creation Date: 2016-07-19
 * Created By: alex4814
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;

class Twitter {
public:
  /** Initialize your data structure here. */
  Twitter() {
  }
  
  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    posts[userId].push_front(make_pair(cnt++, tweetId));
  }
  
  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    vector<int> tweets;
    int sz = follows[userId].size();
    vector<int> pointers(sz, 0);
    return tweets;
  }
  
  /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
  void follow(int followerId, int followeeId) {
    follows[followerId].insert(followeeId);
  }
  
  /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
  void unfollow(int followerId, int followeeId) {
    follows[followerId].erase(followeeId);
  }
private:
  unordered_map<int, unordered_set<int>> follows;
  unordered_map<int, deque<pair<int, int>>> posts;
  static int cnt = 0;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

int main() {

  return 0;
}
