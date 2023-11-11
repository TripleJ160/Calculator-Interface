/* 
 * Calculator Project using Linked Lists
 *
 * This program implements a calculator using linked lists data structure.
 * The calculator can perform addition, subtraction, multiplication, and division operations on decimal values.
 * 
*/
#ifndef CALCLIST_H // Header guard to prevent multiple inclusion
#define CALCLIST_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

enum FUNCTIONS {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION
};

//node class for linked list functions
class Node {
    public:
        double operation_result; // combines operand into number with type
        std::string type; //stores type
        double operand; //stores operand
        double total;   // keeps track of cumulative total
        double total_sum; // sum of results
        Node* next;

        Node() {
            operation_result = 0;
            next = NULL;
            type = "";
            operand = 0;
            total = 0;
            total_sum = 0.0;
        }

        Node(double data) {
            this->operation_result = data;
            next = NULL;
        }

};
class CalcList {
    private:
        //uses the node as an object
        Node* head;  
    public:
        CalcList() {
            head = NULL;
        }
        double total() const;
        void newOperation(const FUNCTIONS func, const double operand);
        void removeLastOperation();
        int getNodeCount() const;
        std::string toString(unsigned short precision) const;
};

#endif // End of header guard
