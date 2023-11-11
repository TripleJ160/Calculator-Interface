/* 
 * Calculator Project using Linked Lists
 *
 * This program implements a calculator using linked lists data structure.
 * The calculator can perform addition, subtraction, multiplication, and division operations on decimal values.
 * 
*/

#include <iostream>
#include <string>

#include <iomanip>
#include <sstream>

#include "CalcList.hpp"
using namespace std;


void CalcList::newOperation(const FUNCTIONS func, const double operand) {
        //Allocates space for node
        Node* newNode = new Node;
        //insert node and reset head
        newNode->next = head;
        head = newNode;

        //Case for 1 node (to handle 1 node total operation)
        if (head->next == NULL) {
            switch (func) {
                case ADDITION:
                    newNode->operation_result = 0 + operand;
                    newNode->type = "+";
                    newNode->total_sum = 0 + operand;
                    break;
                case SUBTRACTION:
                    newNode->operation_result = 0 - operand;
                    newNode->type = "-";
                    newNode->total_sum = 0 - operand;
                    break;
                case MULTIPLICATION:
                    newNode->operation_result = 0 * operand;
                    newNode->type = "*";
                    newNode->total_sum = 0 * operand;
                    break;
                case DIVISION:
                    if (operand == 0){
                        delete newNode;
                        throw std::runtime_error("Division by 0 is not allowed!");
                    }
                    //newNode->operation_result = head->next->operation_result / operand;
                    newNode->type = "/";
                    newNode->total_sum = 0 / operand;
                    break;
            }
        } else {
            //Case for more than 1 node (to handle total from continuous nodes)
            switch (func) {
                case ADDITION:
                    newNode->operation_result = head->next->operation_result + operand;
                    newNode->type = "+";
                    newNode->total = head->next->operation_result;
                    newNode->total_sum += head->operation_result;
                    break;
                case SUBTRACTION:
                    newNode->operation_result = head->next->operation_result - operand;
                    newNode->type = "-";
                    newNode->total = head->next->operation_result;
                    newNode->total_sum += head->operation_result;
                    break;
                case MULTIPLICATION:
                    newNode->operation_result = head->next->operation_result * operand;
                    newNode->type = "*";
                    newNode->total = head->next->operation_result;
                    newNode->total_sum += head->operation_result;
                    break;
                case DIVISION:
                    if (operand == 0){
                        delete newNode;
                        //throw exception
                        throw std::runtime_error("Division by 0 is not allowed!");
                    }
                    newNode->operation_result = head->next->operation_result / operand;
                    newNode->type = "/";
                    newNode->total = head->next->operation_result;
                    newNode->total_sum += head->operation_result;
                    break;
            }
        }
        newNode->operand = operand;
}

    
void CalcList::removeLastOperation() {
    //Can't remove without nodes in the list
    if (head == NULL) {
        throw std::runtime_error("Cannot remove operation from an empty list");
    }
    //Change head by 1 position and delete node at current
    Node* current = head;
    head = current->next;  // Move the head pointer to the next node
    delete current;  // Delete the previous head node
}

int CalcList::getNodeCount() const {
    //Iterates through node to get count.
    Node *current = head;
    int count = 1;
    while (current->next != NULL) {
        current = current->next;
        count += 1;
    }
    return count;
}



double CalcList::total() const{
    //Just returns total sum from node stored through newOperation()
    if (head == NULL) {
        return 0.0;
    } else {
        Node *current = head;
    return current->total_sum;
    }
}

std::string CalcList::toString(unsigned short precision) const {
    //Returns a string containing operations done in a node in descending order utilizing ostringstream.
    ostringstream oss;
    
    Node* current = head;
    unsigned int step = getNodeCount();
    
    while (current != NULL) {
        oss << step << ": ";
        
        // Set the precision for floating-point numbers
        oss.precision(precision);
        oss << std::fixed;
        
        if (current->type == "+") {
            oss << std::setprecision(precision) << current->total << "+" << std::setprecision(precision) << current->operand << "=" << std::setprecision(precision) << current->operation_result;
        } else if (current->type == "-") {
            oss << std::setprecision(precision) << current->total << "-" << std::setprecision(precision) << current->operand << "=" << std::setprecision(precision) << current->operation_result;
        } else if (current->type == "*") {
            oss << std::setprecision(precision) << current->total << "*" << std::setprecision(precision) << current->operand << "=" << std::setprecision(precision) << current->operation_result;
        } else if (current->type == "/") {
            if (current->operand == 0) {
                oss << std::setprecision(precision) << current->total << "/" << std::setprecision(precision) << current->operand << " cannot be calculated (division by zero)";
            } else {
                oss << std::setprecision(precision) << current->total << "/" << std::setprecision(precision) << current->operand << "=" << std::setprecision(precision) << current->operation_result;
            }
        }
        
        oss << "\n";
        
        current = current->next;
        step--;
    }
    
    return oss.str();
}



int main() {
    CalcList calc; // Total == 0 
    calc.newOperation(ADDITION, 10); // Total == 10 
    std::cout << calc.total() << '\n';
    calc.newOperation(MULTIPLICATION, 5); // Total == 50 

    calc.newOperation(SUBTRACTION, 15); // Total == 35 
    calc.newOperation(DIVISION, 7); // Total == 5 
    calc.removeLastOperation(); // Total == 35 
    calc.newOperation(SUBTRACTION, 30); // Total == 5 
    calc.newOperation(ADDITION, 5); // Total == 10 
    calc.removeLastOperation(); // Total == 5 
    // Should Return: 
    // 4: 35.00-30.00=5.00 
    // 3: 50.00-15.00=35.00 
    // 2: 10.00*5.00=50.00 
    // 1: 0.00+10.00=10.00 
    std::cout << calc.toString(2); 
    calc.removeLastOperation(); // Total == 35 
    // Should Return: 
    // 3: 50-15=35 
    // 2: 10*5=50 
    // 1: 0+10=10 
    std::cout << calc.toString(0);

    std::cout << calc.total() << '\n';

}

