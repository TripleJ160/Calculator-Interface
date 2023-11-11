# Calculator List

This is a C++ program that implements a calculator list. It allows you to perform basic arithmetic operations and keeps track of the history of the operations.

## Usage

To use this program, include the necessary header files and create an instance of the `CalcList` class. You can then call the `newOperation` method to add new operations, `removeLastOperation` to remove the last operation, and use `total` to get the total sum. The `toString` method can be used to get a string representation of the operations history.

You can compile using g++ CalcList.cpp CalcListInterface.hpp PP1Test.cpp to verify all test cases have passed. The main function will have to be commented out due to the main function in PP1Test.cpp

Example usage:

```cpp
#include <iostream>
#include "CalcList.hpp"

int main() {
    CalcList calc;

    calc.newOperation(ADDITION, 5.0);
    calc.newOperation(SUBTRACTION, 3.0);
    calc.newOperation(MULTIPLICATION, 2.0);
    calc.newOperation(DIVISION, 4.0);

    std::cout << calc.toString(2) << std::endl;
    std::cout << "Total: " << calc.total() << std::endl;

    return 0;
}
```

