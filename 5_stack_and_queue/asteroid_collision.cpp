// 3 cases are there
// 1 is the asteroids are moving in the opposite direction and they will meet and collide and now in this we are getting 3 cases
// either a<b -> b remains
// either b>a -> a remains
// either a==b -> nothing remains

// 2 is they are moving in same direction either both towards or both towards right if they are moving in the same direction they will never meet because they have same speed

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> s;
        for (auto ast : asteroids)
        {
            //we make every state stable recursively then move forward
            // case is when either of them is +ve and other one is -ve
            bool flag = true; //flag variable to check whether we need to insert or not in the stack
            while (!s.empty() and ast<0 and s.top()>0)
            {
                if (-ast > s.top()) {
                    s.pop();
                }
                else if (-ast < s.top()) {
                    flag = false;
                    break;
                }
                else if (-ast == s.top()) {
                    flag = false;
                    s.pop();
                    break;
                }
            }
            if (flag)
                s.push(ast);
        }
        vector<int> res;
        while (!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;

    }
};

class Solution {
public:
    //4 cases are there
    // a is moving right and b is moving left i.e both of the asteroids are moving in opposite direction and they will collide
    // a is moving left and b is moving right i.e both of the the asteroids are moving in opposite direction and they will never collide because there paths are different
    // a and b both are moving in left
    // a and b both are moving in right
    // in 2 of the above cases they will never meet because they are moving in the same direction with the same speed so they will never meet
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        // for every asteroid we are adding it in the row and making it stable recursively and then move forward to add another asteroid
        for (auto ast : asteroids)
        {
            bool blows = true;//a flag variable that tells us the case where asteroid is greater than top of stack that means we need to pop top of the stack and add the current asteroid into the stack
// an empty stack is always stable so we always add the asteroid in the stack row
// checking the condition if the asteroid is -ve that means moving to left and stack top is +ve that means moving to right this is the only case in which they are bound to collide
// if this condition satisfies then we check 3 condition of blowing
// if the -ast that is absolute value of asteroid is greater than the element at top of stack then we will pop the top of stack
// if the -ast is less than top of stack then we will not push the asteroid into the stack and we will mark blows as false this will tell that we dont need to insert the current asteroid into the stable row
// if the -ast is equal to stack top then we will not insert into the stack and also we will pop the stack top
            while (!s.empty() and ast<0 and s.top()>0)
            {
                if (-ast > s.top()) {
                    s.pop();
                }
                else if (-ast < s.top()) {
                    blows = false;
                    break;
                }
                else if (-ast == s.top()) {
                    s.pop();
                    blows = false;
                    break;
                }
            }
            if (blows)
                s.push(ast);
        }
        vector<int> res;
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

