#include "Array.h"
#include "Stack.h"
#include "Queue.h"
#include "Fixed_Array.h"
#include "Array_Base.h"

void stackFunctions(void);
void queueFunctions(void);
void arrayFunctions(void);
void fixedArrayFunctions(void);

#include <iostream>
using namespace::std;
int main(void)
{
	stackFunctions();
	queueFunctions();
	arrayFunctions();
	fixedArrayFunctions();
	return 0;
}

void stackFunctions(void)
{

	cout << "*****************************************************************" << endl;
	cout << "*                                                               *" << endl;
	cout << "*                         STACK TESTS                           *" << endl;
	cout << "*                                                               *" << endl;
	cout << "*****************************************************************" << endl;
	Stack<int> st1;
	st1.push(0);
	st1.push(1);
	st1.push(2);
	st1.push(3);
	st1.push(4);

	cout << "Pushed 5 elements:\n";
	for (size_t i = 0; i < st1.size();i++)
		cout << "st1[" << i << "] = " << st1[i] << "...";

	cout << endl;

	st1.pop();
	st1.pop();
	cout << "Popped 2 elements:\n";
	for (size_t i = 0; i < st1.size(); i++)
		cout << "st1[" << i << "] = " << st1[i] << "...";

	cout << endl;

	Stack<int> st2 = st1;
	cout << "Stack<int> st2 = st1:\n";
	for (size_t i = 0; i < st2.size(); i++)
		cout << "st2[" << i << "] = " << st2[i] << "...";

	cout << endl;
}
void queueFunctions(void)
{

	cout << "*****************************************************************" << endl;
	cout << "*                                                               *" << endl;
	cout << "*                         QUEUE TESTS                           *" << endl;
	cout << "*                                                               *" << endl;
	cout << "*****************************************************************" << endl;
	Queue<int> qu1;
	qu1.enqueue(0);
	qu1.enqueue(1);
	qu1.enqueue(2);
	qu1.enqueue(3);
	qu1.enqueue(4);
	int k = qu1.dequeue();
	cout << k << endl;
	qu1.enqueue(5);
	qu1.enqueue(6);
	qu1.enqueue(7);
	qu1.enqueue(8);
	qu1.enqueue(9);
	int l = qu1.dequeue();
	cout << l << endl;

	return;

}
void arrayFunctions(void)
{

	cout << "*****************************************************************" << endl;
	cout << "*                                                               *" << endl;
	cout << "*                         ARRAY TESTS                           *" << endl;
	cout << "*                                                               *" << endl;
	cout << "*****************************************************************" << endl;
	cout << "*****************************************" << endl;
	cout << "Test 1: Default Constructor" << endl;
	cout << "Array ar1;";
	Array<int> ar1;
	cout << endl << "*****************************************" << endl;

	cout << "Test 2: Initializing Constructor #1" << endl;
	Array<int> ar2(10);
	ar2.fill(3);
	cout << "Array ar2(10);" << endl << "ar2.fill(3);" << endl;
	cout << "ar2: ";
	for (size_t i = 0; i < ar2.size(); i++)
		cout << ar2[i] << " ";
	cout << endl << "*****************************************" << endl;

	cout << "Test 3: Initializing Constructor #2" << endl;
	Array<int> ar3(10, 8);
	cout << "Array ar3(10, 8);" << endl;
	cout << "ar3: ";
	for (size_t i = 0; i < ar3.size(); i++)
		cout << ar3[i] << " ";
	cout << endl << "*****************************************" << endl;

	cout << "Test 4: Copy Constructor" << endl;
	Array<int> ar4(ar2);
	cout << "Array ar4(ar2);" << endl;
	cout << "ar4: ";
	for (size_t i = 0; i < ar4.size(); i++)
		cout << ar4[i] << " ";
	cout << endl << "*****************************************" << endl;

	cout << "Test 5: Overload Operator (=)" << endl;
	Array<int> ar5 = ar3;
	cout << "Array ar5 = ar3;" << endl;
	cout << "ar5: ";
	for (size_t i = 0; i < ar5.size(); i++)
		cout << ar5[i] << " ";
	cout << endl << "*****************************************" << endl;

	cout << "Test 6: Overload Operator ([]) #1" << endl;
	cout << "ar5[5] = " << ar5[5];
	cout << endl << "*****************************************" << endl;

	cout << "Test 7: Overload Operator ([]) #2" << endl;
	cout << "ar5[15];" << endl;
	try
	{
		cout << "ar5[15] = " << ar5[15];
	}
	catch (...)
	{
		cout << "Exception caught";
	}
	cout << endl << "*****************************************" << endl;

	cout << "Test 8: Overload Operator ([]) #3" << endl;
	cout << "ar5[-1];" << endl;
	try
	{
		cout << "ar5[-1] = " << ar5[-1];
	}
	catch (...)
	{
		cout << "Exception caught";
	}
	cout << endl << "*****************************************" << endl;

	cout << "Test 9: get(size_t index) #1" << endl;
	cout << "ar5.get(0) = " << ar5.get(0);
	cout << endl << "*****************************************" << endl;

	cout << "Test 10: get(size_t index) #2" << endl;
	cout << "ar5.get(15);" << endl;
	try
	{
		cout << "ar5.get(15) = " << ar5.get(15);
	}
	catch (...)
	{
		cout << "Exception caught";
	}
	cout << endl << "*****************************************" << endl;

	cout << "Test 11: get(size_t index) #3" << endl;
	cout << "ar5.get(-1);" << endl;
	try
	{
		cout << "ar5.get(-1) = " << ar5.get(-1);
	}
	catch (...)
	{
		cout << "Exception caught";
	}
	cout << endl << "*****************************************" << endl;

	cout << "Test 12: set(size_t index, char value) #1" << endl;
	cout << "ar5.set(8,'t')" << endl;
	ar5.set(8, 't');
	cout << "ar5.get(8) = " << ar5.get(8);
	cout << endl << "*****************************************" << endl;

	cout << "Test 13: set(size_t index, char value) #2" << endl;
	cout << "ar5.set(-1,'t');" << endl;
	try
	{
		ar5.set(-1, 't');
	}
	catch (...)
	{
		cout << "Exception caught";
	}
	cout << endl << "*****************************************" << endl;

	cout << "Test 14: resize(size_t new_size) #1" << endl;
	cout << "ar5.size() = " << ar5.size() << endl;
	cout << "ar5.max_size() = " << ar5.max_size() << endl;
	cout << "ar5: ";
	for (size_t i = 0; i < ar5.size(); i++)
		cout << ar5[i] << " ";
	cout << endl;
	cout << "ar5.resize(5)" << endl;
	ar5.resize(5);
	cout << "ar5.size() = " << ar5.size() << endl;
	cout << "ar5.max_size() = " << ar5.max_size() << endl;
	cout << "ar5: ";
	for (size_t i = 0; i < ar5.size(); i++)
		cout << ar5[i] << " ";
	cout << endl;
	cout << "ar5.resize(10)" << endl;
	ar5.resize(10);
	cout << "ar5.size() = " << ar5.size() << endl;
	cout << "ar5.max_size() = " << ar5.max_size() << endl;;
	cout << "ar5: ";
	for (size_t i = 0; i < ar5.size(); i++)
		cout << ar5[i] << " ";
	cout << endl;
	cout << "*****************************************" << endl;

	cout << "Test 15: resize(size_t new_size) #2" << endl;
	cout << "ar5.size() = " << ar5.size() << endl;
	cout << "ar5.max_size() = " << ar5.max_size() << endl;
	cout << "ar5: ";
	for (size_t i = 0; i < ar5.size(); i++)
		cout << ar5[i] << " ";
	cout << endl;
	cout << "ar5.resize(15)" << endl;
	ar5.resize(15);
	cout << "ar5.size() = " << ar5.size() << endl;
	cout << "ar5.max_size() = " << ar5.max_size() << endl;
	cout << "ar5: ";
	for (size_t i = 0; i < ar5.size(); i++)
		cout << ar5[i] << " ";
	cout << endl;
	cout << "ar5.fill('z');" << endl;
	ar5.fill('z');
	cout << "ar5: ";
	for (size_t i = 0; i < ar5.size(); i++)
		cout << ar5[i] << " ";
	cout << endl;
	cout << "ar5.resize(10);" << endl;
	ar5.resize(10);
	cout << "ar5.size() = " << ar5.size() << endl;
	cout << "ar5.max_size() = " << ar5.max_size() << endl;
	cout << "ar5: ";
	for (size_t i = 0; i < ar5.size(); i++)
		cout << ar5[i] << " ";
	cout << endl;
	cout << "ar5.resize(15)" << endl;
	ar5.resize(15);
	cout << "ar5.size() = " << ar5.size() << endl;
	cout << "ar5.max_size() = " << ar5.max_size() << endl;
	cout << "ar5: ";
	for (size_t i = 0; i < ar5.size(); i++)
		cout << ar5[i] << " ";
	cout << endl;
	cout << "*****************************************" << endl;

	cout << "Test 16: find(char ch) #1" << endl;
	cout << "ar5.find('c') = " << ar5.find('c');
	cout << endl << "*****************************************" << endl;

	cout << "Test 17: find(char ch) #2" << endl;
	cout << "ar5.find('z') = " << ar5.find('z');
	cout << endl << "*****************************************" << endl;

	cout << "Test 18: find(char ch, size_t start) #1" << endl;
	cout << "ar5.find('c', 0) = " << ar5.find('c', 0);
	cout << endl << "*****************************************" << endl;

	cout << "Test 19: find(char ch, size_t start) #2" << endl;
	cout << "ar5.find('b', 0) = " << ar5.find('b', 0);
	cout << endl << "*****************************************" << endl;

	cout << "Test 20: find(char ch, size_t start) #3" << endl;
	cout << "ar5.find('b', 20);" << endl;
	try
	{
		cout << "ar5.find('b', 20) = " << ar5.find('b', 20);
	}
	catch (...)
	{
		cout << "Exception caught";
	}
	cout << endl << "*****************************************" << endl;

	cout << "Test 21: Overload Operator (==) #1" << endl;
	if (ar5 == ar5)
		cout << "ar5 == ar5 = true";
	else
		cout << "ar5 == ar5 = false";
	cout << endl << "*****************************************" << endl;

	cout << "Test 22: Overload Operator (==) #2" << endl;
	if (ar5 == ar4)
		cout << "ar5 == ar4 = true";
	else
		cout << "ar5 == ar4 = false";
	cout << endl << "*****************************************" << endl;

	cout << "Test 23: Overload Operator (==) #3" << endl;
	if (ar2 == ar3)
		cout << "ar2 == ar3 = true";
	else
		cout << "ar2 == ar3 = false";
	cout << endl << "*****************************************" << endl;

	cout << "Test 24: Overload Operator (!=) #1" << endl;
	if (ar5 != ar5)
		cout << "ar5 == ar5 = true";
	else
		cout << "ar5 == ar5 = false";
	cout << endl << "*****************************************" << endl;

	cout << "Test 25: Overload Operator (!=) #2" << endl;
	if (ar5 != ar4)
		cout << "ar5 == ar4 = true";
	else
		cout << "ar5 == ar4 = false";
	cout << endl << "*****************************************" << endl;

	cout << "Test 26: Overload Operator (!=) #3" << endl;
	if (ar2 != ar3)
		cout << "ar2 == ar3 = true";
	else
		cout << "ar2 == ar3 = false";
	cout << endl << "*****************************************" << endl;

	cout << "Test 27: fill(char ch)" << endl;
	cout << "ar2: ";
	for (size_t i = 0; i < ar2.size(); i++)
		cout << ar2[i] << " ";
	cout << endl;
	cout << "ar2.fill('z')" << endl;
	ar2.fill('z');
	cout << "ar2: ";
	for (size_t i = 0; i < ar2.size(); i++)
		cout << ar2[i] << " ";
	cout << endl << "*****************************************" << endl;
	return;
}
void fixedArrayFunctions(void) 
{

	cout << "*****************************************************************" << endl;
	cout << "*                                                               *" << endl;
	cout << "*                   FIXED ARRAY TESTS                           *" << endl;
	cout << "*                                                               *" << endl;
	cout << "*****************************************************************" << endl;
	Fixed_Array<int, 5>far1;
	far1.fill(5);
	cout << "*******Default Constructor*******\n";
	cout << "Fill with 5's:\n";
	for (size_t i = 0; i < far1.size(); i++)
		cout << "far1[" << i << "] = " << far1[i] << "...";

	cout << endl;

	Fixed_Array<int, 5>far2(7);
	cout << "*******Fill Constructor*******\n";
	cout << "Filled with 7's:\n";
	for (size_t i = 0; i < far2.size(); i++)
		cout << "far2[" << i << "] = " << far2[i] << "...";

	cout << endl;

	far2 = far1;
	cout << "******* = operator Constructor*******\n";
	cout << "far2 = far1:\n";
	for (size_t i = 0; i < far2.size(); i++)
		cout << "far2[" << i << "] = " << far2[i] << "...";

	cout << endl;

}