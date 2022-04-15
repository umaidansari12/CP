#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
Disappeared shopping options question, retrieved from google cache

A customer wants to buy a pair of jeans, a pair of shoes, a skirt, and a top but has a limited budget in dollars. Given different pricing options for each product, determine how many options our customer has to buy 1 of each product. You cannot spend more money than the budgeted amount.

Example
priceOfJeans = [2, 3]
priceOfShoes = [4]
priceOfSkirts = [2, 3]
priceOfTops = [1, 2]
budgeted = 10

The customer must buy shoes for 4 dollars since there is only one option. This leaves 6 dollars to spend on the other 3 items. Combinations of prices paid for jeans, skirts, and tops respectively that add up to 6 dollars or less are [2, 2, 2], [2, 2, 1], [3, 2, 1], [2, 3, 1]. There are 4 ways the customer can purchase all 4 items.

Function Description

Complete the getNumberOfOptions function in the editor below. The function must return an integer which represents the number of options present to buy the four items.

getNumberOfOptions has 5 parameters:
int[] priceOfJeans: An integer array, which contains the prices of the pairs of jeans available.
int[] priceOfShoes: An integer array, which contains the prices of the pairs of shoes available.
int[] priceOfSkirts: An integer array, which contains the prices of the skirts available.
int[] priceOfTops: An integer array, which contains the prices of the tops available.
int dollars: the total number of dollars available to shop with.

Constraints

1 ≤ a, b, c, d ≤ 103
1 ≤ dollars ≤ 109
1 ≤ price of each item ≤ 109
Note: a, b, c and d are the sizes of the four price arrays
*/

int shoppingOptionsBrute(int jeans, int priceJeans[], int shoes, int priceShoes[], int skirts, int priceSkirts[], int tops, int priceTops[], int budget) {
	int answer = 0;
	for (int i = 0; i < jeans; i++) {
		for (int j = 0; j < shoes; j++) {
			for (int k = 0; k < skirts; k++) {
				for (int l = 0; l < tops; l++) {
					if ((priceJeans[i] + priceShoes[j] + priceSkirts[k] + priceTops[l]) <= budget)
						answer++;
				}
			}
		}
	}
	return answer;
}

int shoppingOptions(int jeans, int priceJeans[], int shoes, int priceShoes[], int skirts, int priceSkirts[], int tops, int priceTops[], int budget) {
	int answer = 0;
	unordered_map<int, int> freq;
	for (int i = 0; i < jeans; i++) {
		for (int j = 0; j < shoes; j++) {
			freq[priceJeans[i] + priceShoes[j]]++;
		}
	}
	for (int i = 0; i < skirts; i++) {
		for (int j = 0; j < tops; j++) {
			int sum = budget - (priceSkirts[i] + priceTops[j]);
			for (auto i : freq) {
				if (i.first <= sum) {
					answer += freq[i.first];
				}
			}
		}
	}
	return answer;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int jeans, shoes, skirts, tops, budget;
		cin >> jeans >> shoes >> skirts >> tops >> budget;
		int priceJeans[jeans] = {0}, priceShoes[shoes] = {0}, priceSkirts[skirts] = {0}, priceTops[tops] = {0};
		for (int i = 0; i < jeans; i++)
			cin >> priceJeans[i];
		for (int i = 0; i < shoes; i++)
			cin >> priceShoes[i];
		for (int i = 0; i < skirts; i++)
			cin >> priceSkirts[i];
		for (int i = 0; i < tops; i++)
			cin >> priceTops[i];
		cout << shoppingOptions(jeans, priceJeans, shoes, priceShoes, skirts, priceSkirts, tops, priceTops, budget) << endl;
	}


	return 0;
}