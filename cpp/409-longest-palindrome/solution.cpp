class Solution {
public:
    int longestPalindrome(string s) {
        array<int, 58> counts = {0};
        int offset = 'A', result = 0;

        // Counts all characters
        for (auto& c : s) {
            counts[c - offset]++;
        }

        // Enumerates the pairs
        for (int i=0; i<58; i++) {
            result += (counts[i] / 2) * 2;
            counts[i] = counts[i] % 2;
        }

        // Add middle character if remaining
        for (int i=0; i<58; i++) {
            if (counts[i] > 0) {
                result++;
                break;
            }
        }
        
        return result;
    }
};