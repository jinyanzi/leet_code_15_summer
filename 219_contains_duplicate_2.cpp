class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // initialize a map for each numnber recording the index it appears in vector nums
        map<int, vector<int> > num_index;
        
        for(unsigned int i = 0; i < nums.size(); ++i){
            // if the number has not appeared
            if(num_index.find(nums[i]) == num_index.end())
                num_index[nums[i]] = vector<int>(1, i);
            else{
                // add the index to the corresponding vector
                num_index[nums[i]].push_back(i);
            }
        }
        
        for(map<int, vector<int> >::iterator it = num_index.begin();
            it != num_index.end(); ++it){
                vector<int> indexes = it->second;
                // if the number appears more than once
                if(indexes.size() > 1){
                    // sort the indexes in ascending order
                    std::sort(indexes.begin(), indexes.end());
                    // check the pairs 
                    for(unsigned i = 0; i < indexes.size(); ++i)
                        for(unsigned j = i+1; j < indexes.size(); ++j)
                            if(indexes[j] - indexes[i] <= k )
                                return true;
                }
            }
        
        return false;
    }
};