class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(),amount.end());
        return max(amount[2], (amount[0] + amount[1] + amount[2]+1) / 2); 
    }
};