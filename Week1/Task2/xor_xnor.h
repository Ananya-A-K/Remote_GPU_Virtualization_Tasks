#ifndef XOR_XNOR_H
#define XOR_XNOR_H

#include "base_gate.h"

class XORGate : public Gate {
public:
    bool evaluate(const std::vector<bool>& inputs) override {
        if (inputs.size() == 1) {
            throw std::invalid_argument("XOR gate requires more than one input.");
        }
        bool result = false; 
        for (bool input : inputs) {
            result ^= input; 
        }
        return result;
    }
};

class XNORGate : public Gate {
public:
    bool evaluate(const std::vector<bool>& inputs) override {
        if (inputs.size() == 1) {
            throw std::invalid_argument("XNOR gate requires more than one input.");
        }
        bool result = false; 
        for (bool input : inputs) {
            result ^= input; 
        }
        return !result; 
    }
};

#endif 