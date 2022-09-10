//
//  Queue.hpp
//  Lab 06 Railroad
//
//  Created by C/R

#ifndef Queue_h
#define Queue_h
#include "Deque.h"

template<typename T>
class Queue
{
private:
    Deque<T> deque_;
public:
    Queue() {}
    ~Queue() {}
    void push(const T& value) { deque_.push_back(value); }
    void pop() { deque_.pop_front(); }
    T& top() { return deque_.front(); }
    size_t size() { return deque_.size(); }
    T& at(size_t index) { return deque_.at(index); }
    bool empty() { return deque_.empty(); }
    
     // Returns the contents of the queue
    std::string toString()
    {
        std::ostringstream os;
        os << "Queue: ";
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
    friend std::ostream& operator<<(std::ostream& os, Queue& myClass)
    {
        return os << myClass.toString();
    }
};

#endif /* Queue_h */
