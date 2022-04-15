import java.util.ArrayDeque;
import java.util.Deque;

class Main
{
    // Return true if there exists a sub-sequence of A[0..n] with given sum
    public static boolean subsetSum(int[] A, int n, int sum, Deque<Integer> subset)
    {
        // return true if sum becomes 0 (subset found)
        if (sum == 0) {
            return true;
        }

        // base case: no items left or sum becomes negative
        if (n < 0 || sum < 0) {
            return false;
        }

        // Case 1. include current item in the subset (A[n]) and recur
        // for remaining items (n - 1) with remaining sum (sum - A[n])
        subset.addLast(A[n]);
        boolean include = subsetSum(A, n - 1, sum - A[n], subset);

        // return true if we can get subset by including the current item
        if (include) {
            return true;
        }

        // Case 2. exclude current item n from subset and recur for
        // remaining items (n - 1)
        subset.removeLast();
        boolean exclude = subsetSum(A, n - 1, sum, subset);

        // return true if we can get subset by excluding the current item
        return exclude;
    }

    public static void main(String[] args)
    {
        // Input: set of items and a sum
        int[] A = { 7, 3, 2, 5, 8 };
        int sum = 14;

        // Deque to store the subset, if found
        Deque<Integer> subset = new ArrayDeque<>();

        if (subsetSum(A, A.length - 1, sum, subset)) {
            System.out.println("The subset is " + subset);
        }
        else {
            System.out.println("No subset with given sum found");
        }
    }
}