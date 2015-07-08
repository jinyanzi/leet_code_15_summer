class MinStack {
public:
    MinStack():min_element(INT_MAX){}
    
    void push(int x) {
        s.push_back(x);
        if(x < min_element) min_element = x;
    }

    void pop() {
        if(!s.empty()){
            // if the minimal element is the top
            // find the next minimal one
            if(min_element == s.back()){
                int new_min = INT_MAX;
                for(int i = 0; i < (s.size() -1); ++i)
                    if(s[i] < new_min)
                        new_min = s[i];
                min_element = new_min;
            }
            s.pop_back();
        }
    }

    int top() {
        if(!s.empty())   return s.back();
    }

    int getMin() {
        return min_element;
    }
private:
    std::vector<int> s;
    int min_element;
};