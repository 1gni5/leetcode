class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int total = 0;
        vector<int> sums = {};

        for (auto& value : nums) {
            total += value;
            sums.push_back(total);
        }

        return sums;
    }
};
