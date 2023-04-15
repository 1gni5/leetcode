#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    bool inline hillOrValley(vector<int>& values, size_t index) {
        if (values[index - 1] < values[index]
            && values[index] > values[index + 1]) return true;
        if (values[index - 1] > values[index]
            && values[index] < values[index + 1]) return true;
        return false;
    }

    int countHillValley(vector<int>& nums) {
        int count = 0;

        // First filter values to keep unique ones
        vector<int> filtered = {nums[0]};
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] != nums[i-1]) {filtered.push_back(nums[i]);}
        }

        // Count hills and valleys
        for (int i=1; i<filtered.size() - 1; i++) {
            if (hillOrValley(filtered, i)) count++;
        } 

        return count;
    }
};
