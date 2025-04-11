For a rectangular matrix of integers, a cross is a figure formed by joining one row and one column. A cross is considered to be regular if all the elements in it are equal.
A cross is called nearly regular if all of its elements are equal except for, at times, the element in the intersection of the row and the column which form the cross.

You are given a rectangular matrix of integers matrix. Your task is to return the number of nearly regular crosses within matrix. Note that by definition the regular cross is also considered to be a nearly regular cross.

Note: You are not expected to provide the most optimal solution, but a solution with time complexity not worse than O(matrix.length · matrix[0].length · (matrix.length + matrix[0].length)) will fit within the execution time limit.

Example

For

matrix = [
  [1, 1, 1, 1],
  [2, 3, 1, 1],
  [1, 1, 1, 0],
  [1, 4, 1, 1]
]
the output should be solution(matrix) = 2.

Explanation:
The only two nearly regular crosses are:

The cross formed by the first row and the third column;

The cross formed by the third row and the last column.

For

matrix = [
  [1, 2],
  [2, 1]
]
the output should be solution(matrix) = 4.

Explanation:
All possible combinations of one row and one column form a nearly regular cross.

For

matrix = [[2, 3]]
the output should be solution(matrix) = 2.

Explanation:
All possible combinations of one row and one column form a nearly regular cross.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[memory limit] 1 GB

[input] array.array.integer matrix

A rectangular matrix of integers.

Guaranteed constraints:
1 ≤ matrix.length ≤ 50,
1 ≤ matrix[i].length ≤ 50,
0 ≤ matrix[i][j] ≤ 1000.

[output] integer

The number of nearly regular crosses within the matrix.

[C++] Syntax Tips

// Prints help message to the console
// Returns a string
string helloWorld(string name) {
    cout << "This prints to the console when you Run Tests" << endl;
    return "Hello, " + name;
}

Saved

