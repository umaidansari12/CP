#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Car {
public:
	string id;
	int x, y;
	Car(string id, int x, int y)
	{
		this->id = id;
		this->x = x;
		this->y = y;
	}
	int dist ()
	{
		return x * x + y * y;
	}
};

class CarCompare {
public:
	bool operator()(Car A, Car B) {
		return A.dist() < B.dist();
	}
};

void printNearestKCars(vector<Car> cars, int k)
{
	priority_queue < Car, vector<Car>, CarCompare> max_heap(cars.begin(), cars.begin() + k);
	for (int i = k; i < cars.size(); i++)
	{
		Car car = cars[i];
		Car top_car = max_heap.top();
		if (car.dist() < top_car.dist())
		{
			max_heap.pop();
			max_heap.push(car);
		}
	}
	vector<Car> output;
	while (!max_heap.empty())
	{
		Car car = max_heap.top();
		//cout << car.dist() << " " << car.id << endl;
		output.push_back(car);
		max_heap.pop();
	}
	reverse(output.begin(), output.end());
	for (auto i : output)
	{
		cout << i.id << " " << i.dist() << endl;
	}

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<Car> cars;
	int n, x, y, k;
	cin >> n >> k;
	string id;
	for (int i = 0; i < n; i++)
	{
		cin >> id >> x >> y;
		Car car(id, x, y);
		cars.push_back(car);
	}
	printNearestKCars(cars, k);


	return 0;
}