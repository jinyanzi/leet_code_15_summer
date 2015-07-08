class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        
        for(int i = 0; i < s.length(); ++i){
            sum = ((s.at(i)-'A'+1) + 26*sum);
        }
        return sum;
    }
};