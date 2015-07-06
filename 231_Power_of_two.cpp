class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0)   return false;
        
        int bit_num = 0;
        int tmp = n;
        while(tmp){
            // check the number of bits
            tmp = tmp>>1;
            ++bit_num;
        }
            
        return (n == (1<<(bit_num-1)));
    }
};