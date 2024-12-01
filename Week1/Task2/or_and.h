#ifndef OR_AND_H
#define OR_AND_H

#include "base_gate.h"

class ANDGate : public Gate {
public:
    bool evaluate(const std::vector<bool>& inputs) override {
        if (inputs.size() == 1) {
            throw std::invalid_argument("AND gate requires more than one input.");
        }
        bool result = true; 
        for (bool input : inputs) {
            result &= input; 
        }
        return result;
    }
};

class ORGate : public Gate {
public:
    bool evaluate(const std::vector<bool>& inputs) override {
        if (inputs.size() == 1) {
            throw std::invalid_argument("OR gate requires more than one input.");
        }
        bool result = false;
        for (bool input : inputs) {
            result |= input; 
        }
        return result;
    }
};

#endif