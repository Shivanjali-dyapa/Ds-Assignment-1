#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

#include <iostream>
#include<utility>

using namespace std;
/*Constants*/
const int MAX_SIZE = 1000; 
const int sizeOfArray = 101;

/*Function declarations*/
int function1(int arr[], int size, int number);
int function2(int arr[], int size, int index, int newValue, int &oldValue);
int function3(int arr[], int size, int newValue);
void function4(int arr[], int index, int &arraySize);

#endif

