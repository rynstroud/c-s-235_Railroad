//
//  Deque.cpp
//  Lab 06 Railroad
//
//  Created by C/R
#ifndef DEQUE_H
#define DEQUE_H
#include <string>

#define DEFAULT_CAPACITY 4

template<typename T>
class Deque
{
private:
    size_t capacity;
    size_t numItems;
    int frontIndex;
    int rearIndex;
    T* theData;
    
    // Gives more space to the circular array
    void reallocate()
    {
       size_t newCapacity = 2 * capacity;
       T* newData = new T[newCapacity];
       size_t old = frontIndex;
       for (size_t i = 0; i < numItems; ++i)
       {
          newData[i] = theData[old];
          old = (old + 1) % capacity;
       }
       frontIndex = 0;
        rearIndex = numItems - 1;
        capacity = newCapacity;
    
        std::swap(theData, newData);
        delete[] newData;
    }

public:
    Deque(void) : frontIndex(0), rearIndex(DEFAULT_CAPACITY - 1), numItems(0), capacity(DEFAULT_CAPACITY),
    theData(new T[DEFAULT_CAPACITY]) {}
    
     ~Deque(void)
    {
        delete[] theData;
    }

    // Insert item at front of deque
    void push_front(const T& value)
    {
        if (numItems == capacity)
        {
           reallocate();
        }
        ++numItems;
        if (frontIndex == 0) frontIndex = capacity - 1;
        else frontIndex--;
        theData[frontIndex] = value;
    }

    // Insert item at rear of deque  
     void push_back(const T& value)
    {
        if (numItems == capacity)
        {
           reallocate();
        }
        ++numItems;
        rearIndex = (rearIndex + 1) % capacity;
        theData[rearIndex] = value;
    }

    // Remove the front item of the deque  
     void pop_front(void)
    {
        numItems--;
        if (frontIndex == capacity - 1) frontIndex = 0;
        else frontIndex++;
        //frontIndex = (frontIndex + 1) % capacity;
        return;

    }

    // Remove the rear item of the deque  
     void pop_back(void)
    {
        numItems--;
         if (rearIndex == 0) rearIndex = capacity - 1;
        else rearIndex--;
        return;
    }

    // Return the front item of the deque (Do not remove)  
    T& front(void) { return theData[frontIndex]; }

    // Return the rear item of the deque (Do not remove)  
     T& back(void)
    {
        if (empty()) throw std::string ("Empty!");
        return theData[rearIndex];
    }

    // Return the number of items in the deque  
     size_t size(void) const
    {
        return numItems;
     }

    // Return true if deque is empty  
     bool empty(void) const
    {
        return (numItems == 0);
    }

    // Return item in deque at index (0 based)  
    T& at(size_t index)
    {
        if (index >= numItems) throw std::out_of_range("Invalid index");
        return theData[index];
    }

    size_t currFront() { return frontIndex; }
    size_t currCap() { return capacity; }
    
    // Return the deque items  
     std::string toString(void) const
    {
        std::ostringstream os;
        os << "Deque: ";
        int i = frontIndex;
        for (int j = 0; j < numItems; j++)
        {
            os << "[" << theData[i]  << "] ";
            if (i == capacity - 1) i = 0;
            else i++;
        }
        return os.str();
    }
    
    // Overrides the extraction operator
    friend std::ostream& operator<<(std::ostream& os, const Deque& myClass)
    {
       return os << myClass.toString();
    }
};
#endif // DEQUE_H
