#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::vector;
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  int n = weights.size();
  vector <double> vw;
  for (int i = 0; i < n; i++)
  {
    double a = double(values[i]) / weights[i];
    vw.push_back(a);
  }
  int m = 0;
  for (int i = 1; i < n; i++)
  {
    if (vw[m] > vw[i])
    {
      m = i;
    }
  }

  while (capacity > 0 && weights[m] > 0)
  {
    int max = 0;
    for (int i = 1; i < n; i++)
    {
      if (vw[max] < vw[i] && weights[i] != 0)
      {
        max = i;
      }
    }
    if (capacity >= weights[max])
    {
      value += (vw[max] * weights[max]);
      capacity -= weights[max];
      weights[max] = 0;
    }
    else
    {
      int difference = capacity;
      value += (vw[max] * difference);
      weights[max] -= difference;
      capacity -= difference;
    }
  }

  return value;
}

int main() {
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
      std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
  }
  return 0;
}
