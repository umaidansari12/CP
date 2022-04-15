class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> s1;

    MinStack() {

    }

    void push(int x) {
        s.push(x);
        if (s1.empty())
        {
            s1.push(x);
        }
        else
        {
            if (x < s1.top())
            {
                s1.push(x);
            }
            else
            {
                s1.push(s1.top());
            }
        }

    }

    void pop() {
        s.pop();
        s1.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return s1.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */