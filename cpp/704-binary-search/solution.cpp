class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Initialize left and right marker
        int left = 0, right = nums.size() - 1;

        // While numbers between markers 
        while (left <= right) {
            // Middle of the section
            int middle = left + (right - left) / 2;

            // Found !
            if (nums[middle] == target) {
                return middle;
            
            // Adjust section
            } else if (nums[middle] > target) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        return -1;
    }
};