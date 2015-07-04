class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // strings with different length are not isomophic
        if(s.length() != t.length())    return false;
        
        // build hash table for string s
        map<char, vector<int> >map_s, map_t;
        charCount(s, map_s);
        charCount(t, map_t);
        
        return checkReplacement(s, map_t) & checkReplacement(t, map_s);
    }
    
    // build a hash table for each string
    // key is the char, value is the index it appears in the string
    // output is stored in char_map
    void charCount(const string &s, map<char, vector<int> >& char_map){
        for(unsigned int i = 0; i < s.length(); i++){
            if(char_map.find(s.at(i)) != char_map.end())
                char_map[s.at(i)].push_back(i);
            else
                char_map[s.at(i)] = vector<int>(1, i);
        }
    }
    
    // compare the indices in string t, if all corresponding index has the same character
    bool checkReplacement(const string &t, const map<char, vector<int> >& char_map){
        for(map<char, vector<int> >::const_iterator it = char_map.begin();
            it != char_map.end(); ++it){
                vector<int> indices = it->second;
                // check if the character at the same index in t is also the same
                char c = t.at(indices[0]);
                // if the character appears more than once, check
                for(unsigned int i = 1; i < indices.size(); ++i)
                    if(t.at(indices[i]) != c)
                        return false;
            }
        return true;
    }
};