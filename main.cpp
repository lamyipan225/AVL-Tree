/*
* Do NOT submit this file.
* Your submitted file (number.cpp) should be able to compile with this file without any modification of this file.
*/

#include <iostream>
#include "number.h"

using namespace std;

/*
 * While you can modify the main function to test against your own test cases, make sure that your program can compile with the original main function.
 * Again, do NOT submit this main.cpp file.
 */
int main()
{
	//manually create a doubly linked list that represents the decimal number 34.56
	DecimalNode* n1 = new DecimalNode;
	n1->content = '3';
	DecimalNode* n2 = new DecimalNode;
	n2->content = '4';
	DecimalNode* n3 = new DecimalNode;
	n3->content = '.';
	DecimalNode* n4 = new DecimalNode;
	n4->content = '5';
	DecimalNode* n5 = new DecimalNode;
	n5->content = '6';
	n1->prev = NULL;
	n1->next = n2;
	n2->prev = n1;
	n2->next = n3;
	n3->prev = n2;
	n3->next = n4;
	n4->prev = n3;
	n4->next = n5;
	n5->prev = n4;
	n5->next = NULL;
	DecimalNode* nHead = n1;

	//manually create a doubly linked list that represents the decimal number 12.34
	DecimalNode* m1 = new DecimalNode;
	m1->content = '1';
	DecimalNode* m2 = new DecimalNode;
	m2->content = '2';
	DecimalNode* m3 = new DecimalNode;
	m3->content = '.';
	DecimalNode* m4 = new DecimalNode;
	m4->content = '3';
	DecimalNode* m5 = new DecimalNode;
	m5->content = '4';
	m1->prev = NULL;
	m1->next = m2;
	m2->prev = m1;
	m2->next = m3;
	m3->prev = m2;
	m3->next = m4;
	m4->prev = m3;
	m4->next = m5;
	m5->prev = m4;
	m5->next = NULL;
	DecimalNode* mHead = m1;

	cout << "Printing our manually created number..." << endl;
	cout << "printNumber: ";
	printNumber(nHead);
	cout << "printNumberReversed: ";
	printNumberReversed(nHead);
	cout << "printNumber: ";
	printNumber(mHead);
	cout << "printNumberReversed: ";
	printNumberReversed(mHead);

	cout << endl << "Testing createNumber..." << endl;
	DecimalNode* a1 = createNumber("123", "456");
	printNumber(a1);
	printNumberReversed(a1);
	DecimalNode* a2 = createNumber("0", "0");
	printNumber(a2);
	printNumberReversed(a2);
	DecimalNode* a3 = createNumber("1", "0");
	printNumber(a3);
	printNumberReversed(a3);
	DecimalNode* a4 = createNumber("0", "1");
	printNumber(a4);
	printNumberReversed(a4);
	DecimalNode* a5 = createNumber("01230", "04560");
	printNumber(a5);
	printNumberReversed(a5);

	cout << endl << "Testing search..." << endl;
	cout << "Test " << 1 << ": " << (search(nHead, '3')==n1?"passed":"failed") << endl;
	cout << "Test " << 2 << ": " << (search(nHead, '4')==n2?"passed":"failed") << endl;
	cout << "Test " << 3 << ": " << (search(nHead, '.')==n3?"passed":"failed") << endl;
	cout << "Test " << 4 << ": " << (search(nHead, '5')==n4?"passed":"failed") << endl;
	cout << "Test " << 5 << ": " << (search(nHead, '6')==n5?"passed":"failed") << endl;
	cout << "Test " << 6 << ": " << (search(nHead, '0')==NULL?"passed":"failed") << endl;

	cout << endl << "Testing getIntegerPartLength..." << endl;
	cout << getIntegerPartLength(mHead);
	cout << endl;

	cout << endl << "Testing getFractionalPartLength..." << endl;
	cout << getFractionalPartLength(mHead);
	cout << endl;

	cout << endl << "Testing compare..." << endl;
	DecimalNode* b1 = createNumber("123", "123");
	DecimalNode* b2 = createNumber("1123", "123");
	DecimalNode* b3 = createNumber("123", "1231");

	cout << "b1 vs b1:" << endl;
	cout << compare(b1, b1) << endl;

	cout << "b2 vs b1:" << endl;
	cout << compare(b2, b1) << endl;
	cout << compare(b1, b2) << endl;

	cout << "b3 vs b1:" << endl;
	cout << compare(b3, b1) << endl;
	cout << compare(b1, b3) << endl;

	cout << endl << "Testing multiply..." << endl;
	cout << "b1 *= 100:" << endl;
	multiply(b1, 2);
	printNumber(b1);
	printNumberReversed(b1);
	cout << "b1 *= 100:" << endl;
	multiply(b1, 2);
	printNumber(b1);
	printNumberReversed(b1);

	cout << endl << "Testing divide..." << endl;
	cout << "b1 /= 100:" << endl;
	divide(b1, 2);
	printNumber(b1);
	printNumberReversed(b1);
	cout << "b1 /= 100:" << endl;
	divide(b1, 2);
	printNumber(b1);
	printNumberReversed(b1);

	//delete the numbers
	deleteNumber(nHead); //it should delete all nodes to prevent any memory leak
	deleteNumber(mHead); //it should delete all nodes to prevent any memory leak
	deleteNumber(a1); //it should delete all nodes to prevent any memory leak
	deleteNumber(a2); //it should delete all nodes to prevent any memory leak
	deleteNumber(a3); //it should delete all nodes to prevent any memory leak
	deleteNumber(a4); //it should delete all nodes to prevent any memory leak
	deleteNumber(a5); //it should delete all nodes to prevent any memory leak
	deleteNumber(b1); //it should delete all nodes to prevent any memory leak
	deleteNumber(b2); //it should delete all nodes to prevent any memory leak
	deleteNumber(b3); //it should delete all nodes to prevent any memory leak

	cout << endl << "All testing done. Now design your own test cases. Good luck!" << endl;

	return 0;
}
