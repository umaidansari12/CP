stack<int> s;
stack<int> m;
MinStack::MinStack() {
    while (!s.empty())
    {
        s.pop();
        m.pop();
    }
}

void MinStack::push(int x) {
    s.push(x);
    if (m.empty())
        m.push(x);
    else
    {
        if (x < m.top())
            m.push(x);
        else
            m.push(m.top());
    }
}

void MinStack::pop() {
    if (s.size() != 0)
    {
        s.pop();
        m.pop();
    }
}

int MinStack::top() {
    if (s.size() == 0)
        return -1;
    return s.top();
}

int MinStack::getMin() {
    if (m.size() == 0)
        return -1;
    return m.top();
}

