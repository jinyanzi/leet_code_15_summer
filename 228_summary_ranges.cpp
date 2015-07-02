class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty())
            return vector<string>();
        
        vector<string> summary;
        int last_start = nums[0];   // head of the segment
        int last_num = nums[0];     // last number appeared in the segment
        for(unsigned int i = 0; i < nums.size(); ++i){
                
            // if the number is not consecutive or the last number in the array
            // add a summary
            if(i == (nums.size() -1) || nums[i] > (last_num+1)){
                // if the current number is the last one or the number is not consecutive
                if(i == (nums.size() -1) && nums[i] == (last_num+1)){
                    summary.push_back(std::to_string(last_start) + "->" + std::to_string(nums[i]));
                }else{
                    // if only one number in the segment
                    if(last_start == last_num)
                        summary.push_back(std::to_string(last_num));
                    else
                        summary.push_back(std::to_string(last_start) + "->" + std::to_string(last_num));
                    
                    // add the last single number after adding the previous segment
                    // if the vector size is not 1
                    if( i == (nums.size() -1) && i > 0)
                        summary.push_back(std::to_string(nums[i]));
                }
                // start a new segment
                last_start = nums[i];
            }
            
            // remember the last number for later use
            last_num = nums[i];
        }
        
        return summary;
    }
};