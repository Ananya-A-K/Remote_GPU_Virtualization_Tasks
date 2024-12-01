#ifndef NOT_H
#define NOT_H

#include "base_gate.h"

class NOTGate : public Gate {
public:
    bool evaluate(const std::vector<bool>& inputs) override {
        if (inputs.size() != 1) {
            throw std::invalid_argument("NOT gate requires exactly one input.");
        }
        return !inputs[0]; 
    }
};

#endif
