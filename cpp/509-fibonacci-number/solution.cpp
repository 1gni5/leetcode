class Solution {
public:
    int fib(int n) {
        vector<int> f {0, 1};

        while (f.size() <= n) {
            f.push_back(f[f.size() - 1] + f[f.size() - 2]);
        } 

        return f[n];
    }
};