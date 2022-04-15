/*Having two extra-variable for storing leftmost non-full stack and right most non-empty stack.
Leftmost non-full stack variable will show the index of the leftmost stack which is not fully filled means that stack size is not equal to capacity, so I can use this variable to push the value to the leftmost stack efficiently.
Rightmost non-empty stack variable will show the index of the rightmost stack which is not empty so using that variable we can efficiently perform the pop from the rightmost stack.
I will try to update these two variables in all functions so we can implement this method easily.'
*/class DinnerPlates {
public:
    int cap, leftmost, rightmost = 0;
    vector<stack<int>> stacks;
    DinnerPlates(int capacity) {
        cap = capacity;
        leftmost = 0;
        rightmost = 0;
    }

    void push(int val) {
        while (leftmost < stacks.size() && stacks[leftmost].size() == cap)
            leftmost++;
        if (leftmost == stacks.size())
        {
            stack<int> s;
            s.push(val);
            stacks.push_back(s);
        }
        else
        {
            stacks[leftmost].push(val);
        }
        rightmost = max(rightmost, leftmost);

    }

    int pop() {
        while (rightmost >= 0 && stacks[rightmost].empty())
            rightmost--;
        if (rightmost < 0)
            return -1;
        int top = stacks[rightmost].top();
        stacks[rightmost].pop();
        leftmost = min(rightmost, leftmost);
        return top;
    }

    int popAtStack(int index) {
        if (stacks.size() <= index)
            return -1;
        if (stacks[index].empty())
            return -1;
        int top = stacks[index].top();
        stacks[index].pop();
        leftmost = min(leftmost, index);
        return top;

    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */

class DinnerPlates {
public:
    vector<stack<int>> stacks;
    int capacity;
    DinnerPlates(int capacity) {
        this->capacity = capacity;
    }

    void push(int val) {
        if (stacks.size() == 0)
        {
            stack<int> s;
            s.push(val);
            stacks.push_back(s);
            return;
        }
        if (stacks[stacks.size() - 1].size() == this->capacity)
        {
            stack<int> s;
            s.push(val);
            stacks.push_back(s);
        }
        else
        {
            stacks[stacks.size() - 1].push(val);
        }
    }

    int pop() {
        if (stacks.size() == 0)
            return -1;
        int ans;
        if (stacks[stacks.size() - 1].size() == 0)
        {
            stacks.pop_back();
            ans = stacks[stacks.size() - 1].top();
            stacks[stacks.size() - 1].pop();
        }
        else
        {
            ans = stacks[stacks.size() - 1].top();
            stacks[stacks.size() - 1].pop();
        }
        return ans;

    }

    int popAtStack(int index) {
        if (stacks[index].size() == 0)
            return -1;
        int ans = stacks[index].top();
        stacks[index].pop();
        return ans;

    }
};

class DinnerPlates {
    int cap;
    vector<stack<int>> stks;
    int leftMost, rightMost;
public:
    DinnerPlates(int capacity) {
        cap = capacity;
        leftMost = 0;
        rightMost = 0;
    }

    void push(int val) {
        // traverse the leftMost
        while (leftMost < stks.size() and stks[leftMost].size() == cap) {
            leftMost++;
        }

        // at the end
        if (leftMost == stks.size()) {
            stack<int> stk;
            stk.push(val);
            stks.push_back(stk);
        }
        else { // stack already created
            stks[leftMost].push(val);
        }

        // finally update the rightMost value
        rightMost = max(leftMost, rightMost);
    }

    int pop() {
        while (rightMost >= 0 and stks[rightMost].empty()) {
            rightMost--;
        }

        if (rightMost < 0) return -1;

        int top = stks[rightMost].top();
        stks[rightMost].pop();
        leftMost = min(leftMost, rightMost);
        return top;
    }

    int popAtStack(int index) {
        //if the particular stack is not present in stks
        if (stks.size() <= index) {
            return -1;
        }

        // if the stack is empty at given index
        if (stks[index].empty()) {
            return -1;
        }

        // if stack is not empty then return the value
        int tp = stks[index].top();
        stks[index].pop();

        leftMost = min(leftMost, index);

        return tp;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */