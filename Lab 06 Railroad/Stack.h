//
//  Stack.h
//  Lab 06 Railroad
//
//  Created by C/R
#ifndef Stack_h
#define Stack_h
#include "Deque.h"

template<typename T>
class Stack
{
private:
    Deque<T> deque_;
public:
    Stack() {}
    ~Stack() {}
    void push(const T& value) { deque_.push_back(value); }
    void pop() { deque_.pop_back(); }
    T& top() { return deque_.back(); }
    size_t size() { return deque_.size(); }
    T& at(size_t index) { return deque_.at(index); }
    bool empty() { return deque_.empty(); }
     
    // Returns the contents of the stack
    std::string toString()
    {
        std::ostringstream os;
        os << "Stack: ";
        int i = deque_.currFront();
        for (int j = 0; j < deque_.size(); j++)
        {
            os << "[" << deque_.at(i)  << "] ";
            if (i == deque_.currCap() - 1) i = 0;
            else i++;
        }
        return os.str();
    }
        
        // Overrides the extraction operator
    friend std::ostream& operator<<(std::ostream& os, Stack& myClass)
    {
        return os << myClass.toString();
    }
};

#endif /* Stack_h */
