class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        int index=0;
        for(int i=0; i<n; i++){
            if(i<n-1 && nums[i]==nums[i+1] && nums[i]!=0){
                nums[i]*=2;
                nums[i+1]=0;
            }
            if(nums[i]!=0){
                if(i!=index){
                    swap(nums[i], nums[index]);
                }
                index++;
            }
        }
        return nums;
    }
};