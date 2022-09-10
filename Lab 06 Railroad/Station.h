//
//  Station.h
//  Lab 06 Railroad
//
//  Created by C/R

#ifndef Station_h
#define Station_h
#include "Deque.h"
template<typename T>
class Station
{
private:
    Vector<T> vector_;
    Stack<T> stack_;
    Queue<T> queue_;
    T turntable;
    bool empty;
public:
    Station(void) : empty(true) {}
    ~Station(void) {}
    
    // Adds a car to the turntable
    std::string addCar(const T& value)
    {
        if (empty)
        {
            empty = false;
            turntable = value;
            return "OK";
        }
        else return "Turntable occupied!";
    }
    
    // Removes the car from the turntable and outputs it to the vector
    std::string removeCar()
    {
        if (empty) return "Turntable empty!";
        else
        {
            vector_.push_back(turntable);
            empty = true;
            return "OK";
        }
        
    }
    
    // Returns the car on the turntable
    std::string topCar()
    {
        if (empty) return "Turntable empty!";
        else
        {
            std::ostringstream os;
            os << turntable;
            return os.str();
        }
    }
    
    // Adds to the stack from the turntable
    std::string addStack()
    {
        if (!empty)
        {
            stack_.push(turntable);
            empty = true;
            return "OK";
        }
        else return "Turntable empty!";
    }
    
    // Removes from the top oof the stack and outputs it to the turntable
    std::string removeStack()
    {
        if (stack_.empty()) return "Stack empty!";
        else
        {
            turntable = stack_.top();
            empty = false;
            stack_.pop();
            return "OK";
        }
    }
    
    // Returns the top of the stack
    std::string topStack()
    {
        if (stack_.empty()) return "Stack empty!";
        else
        {
            std::ostringstream os;
            os << stack_.top();
            return os.str();
        }
    }

    // Returns the size of the stack
    std::string sizeStack()
    {
        std::ostringstream os;
        if (stack_.empty()) os << "0";
        else os << stack_.size();
        return os.str();
    }

    // Adds to the top of the queue from the turntable
    std::string addQueue()
    {
        if (!empty)
        {
            queue_.push(turntable);
            empty = true;
            return "OK";
        }
        else return "Turntable empty!";
    }
    
    // Removes the top of the queue and moves it to the turntable
    std::string removeQueue()
    {
        if (queue_.empty()) return "Queue empty!";
        else
        {
            turntable = queue_.top();
            empty = false;
            queue_.pop();
            return "OK";
        }
    }

    // Returns the top of the queue
    std::string topQueue()
    {
        if (queue_.empty()) return "Queue empty!";
        else
        {
            std::ostringstream os;
            os << queue_.top();
            return os.str();
        }
    }

    // Returns the size of the queue
    std::string sizeQueue()
    {
        std::ostringstream os;
        if (queue_.empty()) os << "0";
        else os << queue_.size();
        return os.str();
    }

    // Returns the contents of the vector of trains leaving the station
    std::string toString() { return vector_.toString(); }

    
};

#endif /* Station_h */
