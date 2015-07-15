class Solution {
public:
    int lengthOfLastWord(string s) {
        // remove spaces at tail
        int i = s.length()-1;
        for(; i >= 0; --i){
            if(s[i] != ' ') break;
        }
        s = s.substr(0, i+1);
        
        // find last space after removing 
        std::size_t last_space_pos = s.find_last_of(' ');   
        if( last_space_pos == string::npos )
            return s.length();
        else
            return s.substr(last_space_pos+1).length();
    }
};