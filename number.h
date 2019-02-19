/*
* Do NOT submit this file. Do NOT modify this file.
* Your submitted file (number.cpp) should be able to compile with this file without any modification of this file.
 */
#include <iostream>
using namespace std;

//This is the struct that you have to use for all parts of this assignment
//This is a node in the doubly linked list that represents a decimal number
//Each node can only be a single decimal-digit, i.e., '0', '1', ..., '9', or a decimal point '.'
struct DecimalNode
{
	char content; //can only be a single decimal-digit, i.e., '0', '1', ..., '9', or a decimal point '.'; note that it stores a char
	DecimalNode* next; //the pointer that points to the next node; points to NULL if and only if this node is the last (tail) node
	DecimalNode* prev; //the pointer that points to the previous node; points to NULL if and only if this node is the first (head) node
};

//Implement all the following functions, except PrintNumber, printNumberReversed, and deleteNumber which are already implemented, in the number.cpp (the only file you submit)
//Refer to the assignment webpage and sample output for supplementary information and examples if any requirement is unclear to you

/*
 * Return the head node of the doubly linked list that is created to represent the decimal number according to the given integer part and fractional part
 * (via "integerPart" and "fractionalPart" which are pointers that point to null-terminated strings)
 * Dynamically allocate all the nodes needed to represent the decimal number
 * See the assignment webpage for the specification of the linked list that you need to generate
 * See sample output for examples
 *
 * You can assume both pointer parameters won't be NULL
 *
 * Return NULL if either of the strings is empty or contain anything other than just digits
 * For example, createNumber("123.", "123") should return NULL
 * For example, createNumber("123", "") should return NULL
 * For example, createNumber("abc123abc", "123") should return NULL
 *
 * However, even when the parameters are valid (i.e. contain just digits), if the created number is of an invalid representation
 * (according to our specification), you will need to fix it
 * For example, createNumber("01230", "01230") should return a doubly-linked list that represents "1230.0123"
 * (have to remove those extra zeros at the beginning and at the end)
 */
DecimalNode* createNumber(const char* integerPart, const char* fractionalPart);

/*
 * Search for the character (as specified by the parameter "c") in the given linked list (as specified by the parameter "headNode")
 * Return the first (leftmost) node that contains the character as content in the linked list
 * Return NULL if such node cannot be found in the linked list
 * Return NULL if c is not a digit character or '.'
 */
DecimalNode* search(DecimalNode* headNode, char c);

/*
 * Return the number of digits that are in the integer part of the given linked list (via the "headNode" parameter)
 * Return 0 if headNode is NULL
 */
int getIntegerPartLength(const DecimalNode* headNode);

/*
 * Return the number of digits that are in the fractional part of the given linked list (via the "headNode" parameter)
 * Return 0 if headNode is NULL
 */
int getFractionalPartLength(const DecimalNode* headNode);

/*
 * Given two decimal number "a" and "b" (which are pointers that point to the head nodes of the two numbers)
 * Return 1 if a > b
 * Return -1 if a < b
 * Return 0 if a == b
 * Return 999 if either of the parameters is NULL
 */
int compare(const DecimalNode* a, const DecimalNode* b);

/*
 * Multiply the given decimal number (via the head node pointer "headNode") by '10 to the power of n'
 * See sample output for examples
 *
 * Do nothing if headNode is NULL
 */
void multiply(DecimalNode* headNode, int n);

/*
 * Divide the given decimal number (via the head node pointer "headNode") by '10 to the power of n'
 * You will need to make sure the headNode is pointing to the head node of the modified linked list at the end of the function
 * See sample output for examples
 *
 * Do nothing if headNode is NULL
 */
void divide(DecimalNode*& headNode, int n);

/*
 * Print the represented decimal number on the console using cout, when given a linked list
 * (represented by "headNode" parameter, i.e., a pointer that points to the head node in the linked list)
 *
 * Note: its implementation is already given in the provided number.cpp file and should not be modified
 * Note: it would only work if you use it with a correct doubly-linked list
 */
void printNumber(const DecimalNode* headNode);

/*
 * Do what printNumber does but the printing is reversed
 * So, for example, if printNumber prints 12.345, printNumberReversed prints 543.21
 *
 * Note: its implementation is already given in the provided number.cpp file and should not be modified
 * Note: it would only work if you use it with a correct doubly-linked list
 */
void printNumberReversed(const DecimalNode* headNode);

/*
 * Deallocate all the dynamically allocated memory for the given linked list
 * (represented by "headNode" parameter, i.e., a reference to a pointer that points to the head node in the linked list)
 * You are also required to set headNode to NULL after the memory deallocation is done
 * Do nothing if the parameter "headNode" is NULL
 *
 * Note: its implementation is already given in the provided number.cpp file and should not be modified
 */
void deleteNumber(DecimalNode*& headNode);
