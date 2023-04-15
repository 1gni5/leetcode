class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // First sum all elements
        int left = 0, right = 0;
        for (auto& value : nums) {right += value;}

        // Check first element
        right -= nums[0];
        if (left == right){return 0;}

        // Search for pivot
        for (int i=1; i < nums.size(); i++) {
            right -= nums[i]; // Remove pivot from sum
            left += nums[i-1]; // Update sum
            if (left == right){return i;}
        }

        return -1;
    }
};
