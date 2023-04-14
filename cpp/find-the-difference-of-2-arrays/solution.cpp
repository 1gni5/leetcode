#include <set>
using namespace std;

class Solution {
public:
    set<int> buildSet(vector<int>& vec) {
        set<int> res;
        for (auto& v : vec) {
            res.insert(v);
        }
        return res;
    }

    vector<int> findDifference(set<int>& a, set<int>& b) {
        vector<int> res;
        for (auto& value : a) {
            if (b.count(value) < 1) {
                res.push_back(value);
            }
        }
        return res;
    }

    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> solution {};
        set<int> set1 = buildSet(nums1), set2 = buildSet(nums2);

        solution.push_back(findDifference(set1, set2));
        solution.push_back(findDifference(set2, set1));

        return solution;
    }
};
