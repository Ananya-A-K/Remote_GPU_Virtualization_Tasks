#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>
#include "base_gate.h"
#include "not.h"
#include "xor_xnor.h"
#include "or_and.h"
#include "nand_nor.h"

// Struct to hold input values (Singleton pattern for T and F)
struct Input {
    int value;
    
    static Input& T() {
        static Input instance{1};
        return instance;
    }
    
    static Input& F() {
        static Input instance{0};
        return instance;
    }
    
    int getValue() const {
        return value;
    }
};

class Circuit {
private:
    std::vector<Gate*> gates;
public:
    void addGate(Gate* gate) {
        gates.push_back(gate);
    }
    bool evaluate(const std::vector<Input>& inputs) {
        bool result = inputs[0].getValue(); 
        size_t inputIndex = 1;  // Start with the second input
        for (auto& gate : gates) {
            std::vector<bool> gateInputs;
            gateInputs.push_back(result); // Add the current result
            if (inputIndex < inputs.size()) {
                gateInputs.push_back(inputs[inputIndex].getValue()); // Add next input
            }
            result = gate->evaluate(gateInputs); 
            inputIndex++;
        }
        return result;
    }
};

int main() {
    Gate* andGate  = new ANDGate();
    Gate* orGate   = new ORGate();
    Gate* xorGate  = new XORGate();
    Gate* xnorGate = new XNORGate();
    Gate* nandGate = new NANDGate();
    Gate* norGate  = new NORGate();
    Gate* notGate  = new NOTGate();
    
    // circuit1
    Circuit circuit1;
    circuit1.addGate(andGate);
    circuit1.addGate(orGate);
    circuit1.addGate(xorGate);
    
    std::vector<Input> inputs1;
    char inputChar1;
    std::cout << "Enter the inputs (T for True, F for False):\n";
    for (int i = 0; i < 4; ++i) { 
        std::cout << "Input " << i + 1 << ": ";
        std::cin >> inputChar1;
        if (inputChar1 == 'T' || inputChar1 == 't') {
            inputs1.push_back(Input::T());
        } else if (inputChar1 == 'F' || inputChar1 == 'f') {
            inputs1.push_back(Input::F());
        } else {
            std::cout << "Invalid input, please enter 'T' or 'F'." << std::endl;
            --i; 
        }
    }

    bool output1 = circuit1.evaluate(inputs1);
    std::cout << "Output1: " << (output1 ? "True" : "False") << std::endl;

    // circuit2
    Circuit circuit2;
    circuit2.addGate(nandGate);
    circuit2.addGate(norGate);
    circuit2.addGate(xnorGate);

    std::vector<Input> inputs2;
    char inputChar2;
    std::cout << "Enter the inputs (T for True, F for False):\n";
    for (int i = 0; i < 4; ++i) { 
        std::cout << "Input " << i + 1 << ": ";
        std::cin >> inputChar2;
        if (inputChar2 == 'T' || inputChar2 == 't') {
            inputs2.push_back(Input::T());
        } else if (inputChar2 == 'F' || inputChar2 == 'f') {
            inputs2.push_back(Input::F());
        } else {
            std::cout << "Invalid input, please enter 'T' or 'F'." << std::endl;
            --i; 
        }
    }

    bool output2 = circuit2.evaluate(inputs2);
    std::cout << "Output3: " << (output2 ? "True" : "False") << std::endl;

    // circuit3
    Circuit circuit3;
    circuit3.addGate(notGate);
    
    std::vector<Input> inputs3;
    char inputChar3;
    std::cout << "Enter the input (T for True, F for False):\n";
    std::cin >> inputChar3;
    if (inputChar3 == 'T' || inputChar3 == 't') {
        inputs3.push_back(Input::T());
    } 
    else if (inputChar3 == 'F' || inputChar3 == 'f') {
        inputs3.push_back(Input::F());
    } 
    else {
        std::cout << "Invalid input, please enter 'T' or 'F'." << std::endl;
    }

    bool output3 = circuit3.evaluate(inputs3);
    std::cout << "Output3: " << (output3 ? "True" : "False") << std::endl;
    return 0;
}
