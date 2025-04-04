// **|**

// *|||*

// **|**

#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	N = 9;
	int no_of_pipes = 1;
	for (int i = 0; i < (N - 2) ; i++) {
		if (i < (N / 2)) {
			if (i == 0)
				no_of_pipes = 1;
			else
				no_of_pipes += 2;
			// cout << no_of_pipes << endl;
		}
		else {
			no_of_pipes -= 2;
			// cout << "~" << no_of_pipes << endl;
		}
		int no_of_stars = N - no_of_pipes;
		for (int j = 0; j < (no_of_stars / 2); j++) {
			cout << "*";
		}
		for (int j = 0; j < no_of_pipes; j++)
			cout << "|";
		for (int j = 0; j < (no_of_stars / 2); j++)
			cout << "*";

		cout << endl;
	}
}


// input = N

//         outout = pattern

//                  N = no.of cols
//                      N - 2 = no.of rows

//                              * * * | * * *
//                              * * | | | * *
//                              * | | | | | *
//                              * * | | | * *
//                              * * * | * * *

//                              n = no.of columns ->


//                                  at every row
//                                  row = 0 , (n - 1) stars ((n - r - 1) / 2) , 2 * r + 1, ((n - r - 1) / 2)
//                                        row = 1, ((n - r - 2)) / 2, 2 * r + 1, (n - r - 1) / 2
//                                                row = 2, ((n - r - 2)) / 2,


//                                                3, 1, 3
//                                                2, 3, 2
//                                                1, 5, 1 row <= (n / 2)
//                                                2, 3, 2
//                                                3, 1, 3

//                                                4, 1, 4
//                                                3, 3, 3
//                                                2, 3, 2
//                                                1, 5, 1
//                                                2, 3, 2
//                                                3, 1, 3


// 2*0+1 = 1
// 2*1+1 = 3
// 2*2+1 = 5


// correlate no. of stars and no. of
// n - no.of pipes will give you star
