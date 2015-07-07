class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        // at least one of q1, q2 is empty
        q2.empty() ? q1.push(x) : q2.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(this->empty())    return;
        
        // !!IMPORTANT: has to be reference
        std::queue<int> &q_empty = (q1.empty() ? q1 : q2);
        std::queue<int> &q_full = (q2.empty() ? q1 : q2);
        while(q_full.size() > 1){
            q_empty.push(q_full.front());
            q_full.pop();
        }
        // leave the last in q_full
        q_full.pop();
    }

    // Get the top element.
    int top() {
        if(this->empty())   return INT_MIN;
        
        std::queue<int> &q_empty = (q1.empty() ? q1 : q2);
        std::queue<int> &q_full = (q2.empty() ? q1 : q2);
        while(q_full.size() > 1){
            q_empty.push(q_full.front());
            q_full.pop();
        }
        // leave the last in q_full
        int top_ele = q_full.front();
        q_full.pop();
        q_empty.push(top_ele);
        return top_ele;
    }

    // Return whether the stack is empty.
    bool empty() {
        return (q1.empty() & q2.empty());
    }
    
private:
    std::queue<int> q1, q2;
};