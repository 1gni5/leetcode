class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        enum state {free, first, second, common, used};

        vector<vector<int>> solution {{}, {}};
        array<state, 2001> states = {free}; size_t offset = 1000;

        // Register all numbers presents in first array
        for (auto& value : nums1) {
            states[value + offset] = first;
        }

        // Add the numbers in the second array
        // and remove the ones present in both.
        for (auto& value : nums2) {
            if (states[value + offset] == first){
                states[value + offset] = common;
            } else if(states[value + offset] == free) {
                // Update solution array and mark as common
                solution[1].push_back(value);
                states[value + offset] = second;
            }
        }

        // Build the solution for the first array
        for (auto& value : nums1) {
            if (states[value + offset] == first) {
                solution[0].push_back(value);
                states[value + offset] = used;
            }
        }

        return solution;
    }
};
