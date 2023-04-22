class Solution {
public:
    int climbStairs(int N) {
        array<size_t, 2> base {1, 2};
        array<size_t, 50> solutions {0};
        solutions = {0}; // Initialize all solutions to 0

        size_t n = 0; // Complete all steps
        while (n <= N) {
            n += 1;

            // Try every vector from base
            for (auto& b : base) {
                long result = n - b;
                if (result == 0) {solutions[n] += 1;}
                if (result >= 0 && solutions[result] > 0) {
                    solutions[n] += solutions[result];
                }
            }
        }
        
        return solutions[N];
    }
};