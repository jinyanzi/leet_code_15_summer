class Solution {
public:
    bool isHappy(int n) {
        if(n <= 0)  return false;
        
        map<unsigned int, int> sum_map;
        
        int tmp = n;
        int sq_sum = 0;

        while(1){
            sq_sum = 0;
            
            // compute square sum of digits
            while(tmp){
                int i = tmp%10;
                sq_sum += (i*i);
                tmp /= 10;
            }
            
            // return true if the sq_sum = 1
            if(sq_sum == 1)
                return true;
            
            // return false if the sum has computed, endless loop otherwise
            if(sum_map.find(sq_sum) != sum_map.end())
                return false;
            else    // put the sq_sum in hashMap
                sum_map[sq_sum] = 1;
                
            tmp = sq_sum;
        }
    }
};