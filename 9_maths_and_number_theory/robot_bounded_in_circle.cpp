// Intuition
// Let chopper help explain.

// Starting at the origin and face north (0,1),
// after one sequence of instructions,

// if chopper return to the origin, he is obvious in an circle.
// if chopper finishes with face not towards north,
// it will get back to the initial status in another one or three sequences.

// Explanation
// (x,y) is the location of chopper.
// d[i] is the direction he is facing.
// i = (i + 1) % 4 will turn right
// i = (i + 3) % 4 will turn left
// Check the final status after instructions.


// Complexity
// Time O(N)
// Space O(1)


class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, i = 0;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        for (auto ins : instructions) {
            if (ins == 'R') {
                i = (i + 1) % 4;
            }
            else if (ins == 'L') {
                i = (i + 3) % 4;
            }
            else {
                x += dx[i];
                y += dy[i];
            }
        }

        return x == 0 and y == 0 or i > 0;

    }
};