#ifndef BASE_GATE_H
#define BASE_GATE_H

#include <vector>

class Gate {
public:
    virtual bool evaluate(const std::vector<bool>& inputs) = 0; 
};

#endif
