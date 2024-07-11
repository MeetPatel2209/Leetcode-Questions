class Solution {
public:
    // Method 2: Recursive Solution with Memoization
    // This method optimizes the recursive solution by storing intermediate results.
    int numTreesMemoHelper(int n, vector<int>& memo) {
        if (n <= 1) return 1; // Base case: a tree with 0 or 1 node has only 1 structure.
        if (memo[n] != -1) return memo[n]; // Return the result if it's already computed.
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            // Calculate the number of unique BSTs with `i` as the root
            count += numTreesMemoHelper(i - 1, memo) * numTreesMemoHelper(n - i, memo);
        }
        memo[n] = count; // Store the result in the memo array.
        return count;
    }

    int numTrees(int n)  {
        vector<int> memo(n + 1, -1); // Initialize the memo array with -1.
        return numTreesMemoHelper(n, memo);
    }
};