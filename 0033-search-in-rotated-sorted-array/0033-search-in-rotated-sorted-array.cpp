class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mini = INT_MAX, idx = -1;
        int i;
        for (i = 0; i<nums.size(); i++){
            if(mini>=nums[i]){
                idx = i;
                mini = min(mini,nums[i]);
            }
        }
        int low, high;
        if(idx == 0){
            low = 0;
            high = nums.size()-1;
        }
        else if(target >= nums[idx] && target <= nums.back()){
            low = idx;
            high = nums.size()-1;
        }
        else{
            low = 0;
            high = idx-1;
        }

        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target)
                return mid;

            if(nums[mid] > target)
                high = mid-1;
            else
                low = mid+1;
        }

        return -1;
    }
};