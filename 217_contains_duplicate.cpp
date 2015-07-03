class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        // initialize a map for each numnber recording the time it appears
        map<int, int> num_times;
        
        for(unsigned int i = 0; i < nums.size(); ++i){
            // if the number has not appeared
            if(num_times.find(nums[i]) == num_times.end())
                num_times[nums[i]] = 0;
            else
                return true;
        }
        
        return false;
    }
};