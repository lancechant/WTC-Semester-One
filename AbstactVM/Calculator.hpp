#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include "IOperand.hpp"
#include "Factory.hpp"
#include "Stack.hpp"
#include <vector>
#include <algorithm>
#include <cfloat>

class Calculator {

public:
    Calculator();
    Calculator(Calculator const & obj);
    ~Calculator();
    Calculator &operator=(Calculator const &value);

    void    Start(std::string input);
    void    Push(std::string value);
    void    Assert(std::string input);
    void    pop(void);
    void    dump(void);
    void    print(void);

    // bool    verbrose;
    // bool    cont_on_error;

private:
    Stack<IOperand const*> stack;
    Factory factory;
};

#endif