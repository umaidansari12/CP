class Solution {
public:
    int minOperations(int n) {
        vector<int> pows{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536};
        int operations_count = 0;

        while (n != 0) {
            int min_diff = INT_MAX, closest = -1;
            for (int p : pows) {
                if (abs(n - p) < min_diff) {
                    min_diff = abs(n - p);
                    closest = p;
                }
            }
            n = abs(n - closest);
            operations_count += 1;
        }


        return operations_count;

    }
};

// class Solution:
//     def minOperations(self, n: int) -> int:

//         # Powers of 2:
//         pows = [1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536]  # SC = O(17) = O(1)
//         # Why required till 65536 only?
//         # Because n <= 100000.

//         ops = 0

//         # While `n` doesn't become 0:
//         while n:  # TC = O(1) because it doesn't matter what `n` is, we're directly subtracting the closest power of 2 from it, so, it will fall to 0 in a couple of ops only (take a big number and check yourself to get the hang of it)

//             # Find the power of 2 which is closest to n:
//             min_diff, closest = float('inf'), None
//             for p in pows:  # TC = O(17) = O(1)
//                 if abs(p-n) < min_diff:
//                     min_diff, closest = abs(p-n), p

//             # (Absolute) Subtract it (closest power of 2):
//             n = abs(n-closest)

//             ops += 1

//         return ops