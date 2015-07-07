class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        q_in.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(this->empty())    return;
        
        if(q_out.empty()){
            while(!q_in.empty()){
                q_out.push(q_in.top());
                q_in.pop();
            }
        }
        q_out.pop();
    }

    // Get the front element.
    int peek(void) {
        if(this->empty())    return -1;
        
        if(q_out.empty()){
            while(!q_in.empty()){
                q_out.push(q_in.top());
                q_in.pop();
            }
        }
        return q_out.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (q_in.empty() & q_out.empty());
    }
private:
    std::stack<int> q_in, q_out;
};