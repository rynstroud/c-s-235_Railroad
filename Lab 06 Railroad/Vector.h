//
//  Vector.h
//  Lab 06 Railroad
//
//  Created by C/R

#ifndef Vector_h
#define Vector_h
#include "Deque.h"

template<typename T>
class Vector
{
private:
    Deque<T> deque_;
public:
    Vector() {}
    ~Vector() {}
    void push_back(const T& value) { deque_.push_back(value); }
    void pop_back() { deque_.pop_back(); }
    T& back() { return deque_.back(); }
    size_t size() { return deque_.size(); }
    T& at(size_t index) { return deque_.at(index); }
    bool empty() { return deque_.empty(); }
    
     // Returns the contents of the vector
    std::string toString()
    {
        std::ostringstream os;
        //os << "Vector: ";
        int i = deque_.currFront();
        for (int j = 0; j < deque_.size(); j++)
        {
            os <<  deque_.at(i)  << " ";
            if (i == deque_.currCap() - 1) i = 0;
            else i++;
        }
        return os.str();
    }
    
    // Overrides the extraction operator
    friend std::ostream& operator<<(std::ostream& os, Vector& myClass)
    {
       return os << myClass.toString();
    }
};

#endif /* Vector_h */
