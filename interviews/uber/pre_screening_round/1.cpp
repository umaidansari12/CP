Imagine that you are going fishing at the local pond. The size of the bait must be strictly smaller than the size of the fish for it to catch. Once the fish is caught, it is removed from the pond and cannot be caught again. However, each bait can be used up to 3 times before depletion.

Given two arrays of fish and baits, where fish[i] corresponds to the size of the ith fish in the pond, and baits[j] corresponds to the size of the jth bait, your task is to return the maximum number of fish you can catch from the pond with the given baits.

To compute the answer, you need to use each bait to its possible extent, going from the largest bait to the smallest bait. Use each bait to catch the largest fish remaining in the pond and move to the next bait if the current bait was used three times or if it is not strictly smaller than the largest remaining fish. When you run out of baits, return the number of caught fish.

Note: You are not expected to provide the most optimal solution, but a solution with time complexity not worse than O(max(fish.length, baits.length)3) will fit within the execution time limit.

Example

For fish = [1, 2, 3] and baits = [1], the output should be solution(fish, baits) = 2.

Explanation:
Using baits[0] = 1, it is possible to catch 2 fish fish[2] = 3 and fish[1] = 2, since 1 < 3 and 1 < 2. The remaining fish fish[0] = 1 can't be caught using the given bait.

For fish = [2, 2, 3, 4] and baits = [1], the output should be solution(fish, baits) = 3.

Explanation:
Since there is only one bait, it is possible to catch only three fish (any of the given four since the bait has a smaller size than any of the fish) because the bait can only be used three times.

For fish = [1, 4, 3, 2] and baits = [1, 1], the output should be solution(fish, baits) = 3.

Explanation:
While there are two baits available, it is only possible to catch three fish since both baits are not strictly smaller than the first fish, which has a size of fish[0] = 1.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[memory limit] 1 GB

[input] array.integer fish

An array of integers representing the sizes of fish available in the pond.

Guaranteed constraints:
1 ≤ fish.length ≤ 100,
1 ≤ fish[i] ≤ 109.

[input] array.integer baits

An array of integers representing the sizes of baits you have available.

Guaranteed constraints:
1 ≤ baits.length ≤ 100,
1 ≤ baits[i] ≤ 109.

[output] integer

The maximum number of fish you can catch from the pond.

[C++] Syntax Tips

// Prints help message to the console
// Returns a string
string helloWorld(string name) {
    cout << "This prints to the console when you Run Tests" << endl;
    return "Hello, " + name;
}
