#include<bits/stdc++.h>
using namespace std;

class SortedStack {
public:
  stack<int> s;
  void sort();
};

void printStack(stack<int> s)
{
  while (!s.empty())
  {
    printf("%d ", s.top());
    s.pop();
  }
  printf("\n");
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    SortedStack *ss = new SortedStack();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      int k;
      cin >> k;
      ss->s.push(k);
    }
    ss->sort();
    printStack(ss->s);
  }
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
  stack<int> s;
  void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack :: sort()
{
  vector<int> a;
  //Your code here
  while (!s.empty())
  {
    a.push_back(s.top());
    s.pop();
  }
  int n = a.size();
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (a[j] > a[j + 1])
        swap(a[j], a[j + 1]);
    }
  }
  for (int i = 0; i < n; i++)
    s.push(a[i]);
}
void SortedStack :: sort()
{
  //Your code here
  stack<int> t;
  while (!s.empty())
  {
    int temp = s.top();
    s.pop();
    while (!t.empty() && temp > t.top())
    {
      s.push(t.top());
      t.pop();
    }
    t.push(temp);
  }
  while (!t.empty())
  {
    s.push(t.top());
    t.pop();
  }
}