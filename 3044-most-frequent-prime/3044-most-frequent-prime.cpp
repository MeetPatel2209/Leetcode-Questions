class Solution {
public:
   vector<vector<int>> DIRECTIONS = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

    int mostFrequentPrime(vector<vector<int>>& mat) {
        unordered_map<int, int> prime_counts;
        int rows = mat.size();
        int cols = mat[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                for (auto& dir : DIRECTIONS) {
                    string prime = "";
                    int x = i, y = j;
                    while (isValidCell(x, y, rows, cols)) {
                        prime += to_string(mat[x][y]);
                        int num = stoi(prime);
                        if (num > 10 && isprime(num)) {
                            prime_counts[num]++;
                        }
                        x += dir[0];
                        y += dir[1];
                    }
                }
            }
        }

        int max_frequency = 0;
        int max_prime = -1;

        for (auto& entry : prime_counts) {
            int prime = entry.first;
            int frequency = entry.second;
            if (frequency > max_frequency || (frequency == max_frequency && prime > max_prime)) {
                max_frequency = frequency;
                max_prime = prime;
            }
        }

        return max_prime;
    }

    bool isValidCell(int x, int y, int rows, int cols) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }

    bool isprime(int num) {
        if (num < 2) {
            return false;
        }
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
};