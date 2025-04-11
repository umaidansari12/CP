A group of intrepid adventurers is on a quest to decode a mysterious artifact that has a series of unique symbols etched along its circular edge. The order of these symbols has long been lost, but a collection of symbol pairs known to be adjacent to each other was found. Unfortunately, the pairs of symbols became jumbled over time, meaning each pair (x, y) could be recorded either as (x, y) or (y, x). You are given an array symbolPairs representing these shuffled pairs, and your task is to rediscover the original sequence of symbols on the artifact's circular edge.

Remember that any cyclic rotation of the sequence can be considered a correct solution, and the order of the sequence can be reversed as well because the circle has no fixed start or end. Please return any of the valid arrangements.

Example

For symbolPairs = [[3, 5], [1, 4], [2, 4], [1, 5], [2, 3]], the output can be solution(symbolPairs) = [3, 5, 1, 4, 2].

example 1

Different rotations or reversals are also valid solutions. For example, [1, 4, 2, 3, 5] and [5, 3, 2, 4, 1] are also acceptable.
Input/Output

[execution time limit] 0.5 seconds (cpp)

[memory limit] 1 GB

[input] array.array.integer symbolPairs

A list of pairs of symbols that are adjacent on the artifact. All symbols on the original circle are guaranteed to be distinct.

Guaranteed constraints:
2 ≤ symbolPairs.length ≤ 105,
symbolPairs[i].length = 2,
1 ≤ symbolPairs[i][j] ≤ 106.

[output] array.integer

The order of symbols restored to its circular arrangement.

[C++] Syntax Tips

// Prints help message to the console
// Returns a string
string helloWorld(string name) {
    cout << "This prints to the console when you Run Tests" << endl;
    return "Hello, " + name;
}
