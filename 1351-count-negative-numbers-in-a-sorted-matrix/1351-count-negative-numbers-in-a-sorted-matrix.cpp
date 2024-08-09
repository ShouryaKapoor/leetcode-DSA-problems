class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            int low = 0, high = n;
            while (low < high) {
                int mid = low + (high - low) / 2;
                if(grid[i][mid] < 0){
                    high = mid; 
                }else{
                    low = mid + 1;
                }
            }
            count += n - low; 
        }

        return count;
    }
};