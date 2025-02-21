class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
        void quickSort(vector<int>& nums, int low, int high){
        if(low < high){
            int pivotIndex = partition(nums, low ,  high);
            quickSort(nums, low, pivotIndex - 1);
            quickSort(nums, pivotIndex + 1, high);
        }
    }
    int partition(vector<int>& nums, int low, int high){
        int pivotElement = nums[high];
        int i = low - 1;
        for(int j  = low ; j <= high - 1; j++){
            if(nums[j] <= pivotElement){
                i = i+1;
                swap(nums[j], nums[i]);
            }
        }
        swap(nums[i+1], nums[high]);
        return i+1;
    }
};