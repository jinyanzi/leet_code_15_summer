class Solution {
public:
    int hammingWeight(uint32_t n) {
        int one_bit_num = 0;
        
        // check each bit from right to left
        for(int i = 0; i < 32; ++i){
            // check the next bit on the left
            if((n & (1<<i)) != 0)  ++one_bit_num;
        }
        
        return one_bit_num;
    }
};