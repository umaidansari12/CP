// ask about devops
// ec2 instance - server hosted on aws, gcp

// There is a number line where robots are kepts. you will get position array for it
// There is one more array called health of a robot
// There is one more array of chars telling where the robot is facing (L, R)
// Each robot moves at same speed.
// When they collide, the robot which has lower health it gets removed from the match. The higher health's robot gets decreased by 1. Same health both will be removed
// No robots have same position
// -1,

// [5, -1, 4, -1]
// pos[1,10, 15]
// health [10, 5, 7]
// direc [R, L, L]
// output [8, -1, -1]

// [L,R]

// (L,R), will never collide
// <<- -->>
// only (R,L) will collide

// direc [R1, L1, R2, L2] --> (R1>L1) --> [R1-1,-1,  ] , R1 and R2 will never collide as they are in same position with say x dist of gap
// R1 <> L2 --> R1 > L2  output --> [R1-2, -1, R2, -1]
//          --> R1 < L2  output --> [-1, -1, (R2-1 / -1),(L2-1/-1)]
//          --> R1 == L2
//                    -->

// find R and L pair
// and collide them on basis



// assume they're sorted

// if we pick 1 (pos[0])
// and see it's direction which is R in this case, if R is there that means robot will move to +ve side on number line
// so we need to find first robot which is facing to L, then only it will collide otherwise it will always take a gap (pos[1]-pos[0])
// if any L is found we'll place a check to see lesser health robot, and eliminate lesser health robot as well as decrease the health of larger robot

// one element should be picked until it gets eliminated or there are no sufficient robots to be collided
// one element which has greater health can be collided multiple times but one with lesser health can only be collided once and gets eliminated

// dry run


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// To execute C++, please define "int main()"
int main() {
  // auto words = { "Hello, ", "World!", "\n" };
  // for (const char* const& word : words) {
  // cout << word;
  // }
// [R1, R2, R3, L1]

// [R1, R2, L1, R3, L2, R4]

// (r3, l2)
// (r2, l1)

// (r1, l2/l1 or both)

// [.. r1,l1,l2,l3]
// [.. 5, 1,2,3]



// (5, 1)
// (5, 2)
// (5, 3)


// Time complexity - O(N) * (O(max(H, number of Ls))*O(N))

// O(N)

// pseudocode
// start from last index of the array
// find first R
// find its corresponding L pair on right of it
// if it is found then apply collision
// ?? how do we come to same element if its not eliminated

// pseucode - 2
// if we encounter L then we'll push that into stack
// onto stack if we
// if R is encountered then we'll pop from stack

// collision
// r1 > l1 -> on r1's position health will be decrease by -1 and l1 health's will be -1
// r1 == l1 -> both will eliminated and we'll move onto next eligible R
// r1 < l1 -> r1 will be eliminated, l1's health decrease by 1 and l1 will again be pushed into stack so as for it to be consumed by next eligible R


  // int _size = pos.size();

  // while(idx<_size){

  // }

  // if(dir[idx]=='R'){

  // }
  // }

  // Test Cases

  vector<int> pos = {1, 10, 15};
  vector<int> health = {10, 5, 7};
  vector<char> dir = {'L', 'R', 'L'};

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

// while (!stk.empty()) {
// auto ele = stk.top();
// cout << ele.first << "-" << ele.second << endl;
// stk.pop();
// }


  return 0;
}
