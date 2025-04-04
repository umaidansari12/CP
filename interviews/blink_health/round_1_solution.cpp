#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {


  // Test Cases

  // vector<int> pos = {1, 10, 15};
  vector<int> pos = {1, 2, 5, 6};

  // vector<int> health = {10, 5, 7};
  vector<int> health = {10, 10, 11, 11};

  // vector<char> dir = {'R', 'L', 'L'};
  vector<char> dir = {'R', 'L', 'R', 'L'};


  int _size = pos.size();

  // stack will be pair(health, position)
  stack<pair<int, int>> stk;
  for (int idx = _size - 1; idx >= 0; idx--) {
    if (dir[idx] == 'R') {
      cout << health[idx] << endl;
      cout << stk.empty() << endl;
      while (!stk.empty() and health[idx] != -1) {
        pair<int, int> left_eligible_element = stk.top();
        stk.pop();
        // cout << "popped\n";
        int health_left_eligible_element = left_eligible_element.first;
        int position_left_eligible_element = left_eligible_element.second;
        if (health[idx] > health_left_eligible_element) {
          health[idx] = health[idx] - 1;
          health[position_left_eligible_element] = -1;
        }
        else if (health[idx] == health_left_eligible_element) {
          health[idx] = -1;
          health[position_left_eligible_element] = -1;
        }
        else {
          health[idx] = -1;
          health[position_left_eligible_element] = health[position_left_eligible_element] - 1;
          stk.push(make_pair(health[position_left_eligible_element], position_left_eligible_element));
        }
      }
    }
    else {
      stk.push(make_pair(health[idx], idx));
    }
  }

  for (int i = 0; i < _size; i++)
    cout << health[i] << " ";
  cout << endl;

  return 0;
}
