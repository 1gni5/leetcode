class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int _min = prices[0];
        int answer = 0;

        for (int i=1; i<prices.size(); i++) {
            answer = max(answer, prices[i] - _min);
            _min = min(_min, prices[i]);  
        }

        return answer;
    }
};