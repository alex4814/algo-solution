/*
 * Creation Date: 2016-08-16
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

using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
  struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
    // Initialize any member here.
    // **DO NOT** save a copy of nums and manipulate it directly.
    // You should only use the Iterator interface methods.
    last = true;
    if (Iterator::hasNext()) {
      _peek = Iterator::next();
      last = false;
    }
  }

  // Returns the next element in the iteration without advancing the iterator.
	int peek() {
    if (hasNext()) {
      return _peek;
    }
    return -1;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
  int next() {
    int tmp = _peek;
    if (Iterator::hasNext()) {
      _peek = Iterator::next();
    } else {
      last = true;
    }
    return tmp;
	}

	bool hasNext() const {
    return !last;
	}
private:
  int _peek;
  bool last;
};

int main() {

  return 0;
}
