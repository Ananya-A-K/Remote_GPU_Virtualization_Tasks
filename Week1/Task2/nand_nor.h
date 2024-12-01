#ifndef NAND_NOR_H
#define NAND_NOR_H

#include "base_gate.h"

class NANDGate : public Gate {
public:
    bool evaluate(const std::vector<bool>& inputs) override {
        if (inputs.size() == 1) {
            throw std::invalid_argument("NAND gate requires more than one input.");
        }
        bool result = true; 
        for (bool input : inputs) {
            result &= input; 
        }
        return !result; 
    }
};

class NORGate : public Gate {
public:
    bool evaluate(const std::vector<bool>& inputs) override {
        if (inputs.size() == 1) {
            throw std::invalid_argument("NOR gate requires more than one input.");
        }
        bool result = false; 
        for (bool input : inputs) {
            result |= input; 
        }
        return !result; 
    }
};

#endif
