//
//  main.cpp
//  Lab 06 Railroad
//
//  Created by C/R

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include "Deque.h"
#include "Vector.h"
#include "Stack.h"
#include "Queue.h"
#include "Station.h"

std::string getContainer(std::string line, size_t p)
{
    std::string container = "";
    size_t initSize = p;
    ++p;
    while(isalpha(line[p])) ++p;
    container = line.substr(initSize + 1, p - initSize);
    //std::cout << container << std::endl;
    return container;
}

int main(int argc, const char * argv[]) {
    //Checking for correct number of arguments
    if (argc < 3)
    {
        std::cerr << "Please provide the name of input and output files, thanks\n";
        return 1;
    }
       
    //Checking if input file opens
    std::ifstream in(argv[1]);
    if (!in)
    {
        std::cerr << "Failure to open input file: " << argv[1] << std::endl;
        return 2;
    }
       
    //Checking if output file opens
    std::ofstream out(argv[2]);
    if (!out)
    {
        in.close();
        std::cerr << "Failure to open output file: " << argv[1] << std::endl;
        return 3;
    }
    
    std::string container = "";
    Station<unsigned int> station;
       for (std::string line; getline(in, line);)
        {
            try
            {
                if (line == "") continue;
                std::string command = "";
                std::istringstream iss(line);
                iss >> command;
                out << command;
                if (command == "Add:station")
                {
                    try
                    {
                        unsigned int car;
                        iss >> car;
                        out << " " << car << " " << station.addCar(car);
                    } catch (std::string errorString)
                    {
                        out << errorString;
                    }
                }
                else if (command == "Add:stack")
                {
                    try
                    {
                        out << " " << station.addStack();
                    } catch (std::string errorString)
                    {
                        out << errorString;
                    }
                }
                else if (command == "Add:queue")
                {
                    try
                    {
                        out << " " << station.addQueue();
                    } catch (std::string errorString)
                    {
                        out << errorString;
                    }
                }
                else if (command == "Remove:station")
                {
                    try
                    {
                        out << " " << station.removeCar();
                    } catch (std::string errorString)
                    {
                        out << errorString;
                    }
                }
                else if (command == "Remove:stack")
                {
                    try
                    {
                        out << " " << station.removeStack();
                    } catch (std::string errorString)
                    {
                        out << errorString;
                    }
                }
                else if (command == "Remove:queue")
                {
                    try
                    {
                        out << " " << station.removeQueue();
                    } catch (std::string errorString)
                    {
                        out << errorString;
                    }
                }
                else if (command == "Top:station")
                {
                    try
                    {
                        out << " " << station.topCar();
                    } catch (std::string errorString)
                    {
                        out << errorString;
                    }
                }
                else if (command == "Top:stack")
                {
                    try
                    {
                        out << " " << station.topStack();
                    } catch (std::string errorString)
                    {
                        out << errorString;
                    }
                }
                else if (command == "Top:queue")
                {
                    try
                    {
                        out << " " << station.topQueue();
                    } catch (std::string errorString)
                    {
                        out << errorString;
                    }
                }
                else if (command == "Size:stack")
                {
                    try
                    {
                        out << " " << station.sizeStack();
                    } catch (std::string errorString)
                    {
                        out << errorString;
                    }
                }
                else if (command == "Size:queue")
                {
                    try
                    {
                        out << " " << station.sizeQueue();
                    } catch (std::string errorString)
                    {
                        out << errorString;
                    }
                }
                
                else if (command == "Find")
                {
                    try
                    {
                           
                    } catch (std::string errorString)
                    {
                        out << " " << errorString;
                    }
                }
                
                else if (command == "Train:")
                {
                    try
                    {
                        out << " " << station.toString();
                    } catch (std::string errorString)
                    {
                        out <<  errorString;
                    }
                }
                
                else
                {
                    throw std::string("**Error: " + line);
                }
                out << std::endl;
            } catch(std::string errorString)
                {
                    out <<  errorString << std::endl;
                }

        }
    
    return 0;
}

