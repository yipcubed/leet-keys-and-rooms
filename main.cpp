#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include "../utils/VectorUtils.hpp"

using namespace std;

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto x = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  return NULL;
}();

class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    unordered_set<int> reached;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int roomNumber = q.front();
      q.pop();
      reached.insert(roomNumber);
      // cout << "Reached " << roomNumber << endl;
      for (auto key : rooms[roomNumber]) {
        if (reached.count(key) == 0) {
          q.push(key);
        }
      }
    }
    return reached.size() == rooms.size();
  }
};

void test1() {
  Solution S;
  vector<vector<int>> v{vector<int>{1}, vector<int>{2}, vector<int>{3},
                        vector<int>{}};
  cout << boolalpha;
  cout << "v1 : " << S.canVisitAllRooms(v) << endl;
}

void test2() {}

void test3() {}

int main() {
  test1();
  test2();
  test3();
  cout << "Done!" << endl;

  return 0;
}