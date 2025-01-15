class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> indx;
        int i = 0;
        int j = numbers.size()-1;
        while(i<j)
        {
            int sum = numbers[i]+numbers[j];

            if(sum == target)
            {
                indx.push_back(i+1);
                indx.push_back(j+1);
                break;
            }
            else if(sum<target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return indx;
    }
};