#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 1000;
int arr[MAX_SIZE];

int size = 0;
const int sizeOfArray = 101;

           
            
/*Function to check a integer exists */
int function1(int arr[], int size, int number) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == number) {
            return i;
        }
    }
    return -1;
}
/*Function to modify the value of an integer*/
int function2(int arr[], int size, int index, int newValue, int &oldValue) {
    if (index >= 0 && index < size) {
        oldValue = arr[index];
        arr[index] = newValue;
        return newValue;
    } else {
        return -1;
    }
}
/*Function to add a new integer to the end*/
int function3(int arr[], int size, int newValue) {
    if (size < sizeOfArray) {
        arr[size] = newValue;
        size++;
        return size;
    } else {
        return -1;
    }
}

/*Function which intakes an index of an array and replaces the value with either 0 or removes*/
void function4(int arr[], int index, int &arraySize) {
   if (index >= 0 && index < arraySize) {
        int userChoice;
        cout << "Enter 1 to replace with zero, 2 to remove the element: ";
        cin >> userChoice;

        if (userChoice == 1) {
            arr[index] = 0;
        } else if (userChoice == 2) {
            for (int i = index; i < arraySize - 1; ++i) {
                arr[i] = arr[i + 1];
            }
            arraySize--; 
        } else {
            cout << "Invalid user choice." << endl;
        }
    } else {
        cout << "Invalid index." << endl;
    }
}


int main() {
    
	
    ifstream inputFile("input.txt"); 
    if (!inputFile) {
        cout << "Unable to open the file.\n";
        return 1; 
    }
    // Reading the data
    while (inputFile >> arr[size]) {
        size++;
        if (size >= MAX_SIZE) {
            cout << "File exceeds array size.\n";
            return 1; 
        }
    }

    inputFile.close(); 
    int choice;
    cout<<"1.To check if a certain integer exists\n2.To modify the value of an integer\n3.To add a new integer to the end\n4.To replace the value with either 0 or removes the integer\n";
    cout << "Enter choice: ";
    cin >> choice;

    if(choice==1){
    	cout << "Check if a certain integer exists\n";
        int searchNumber;
        cout << "Enter a number to search: ";
        cin >> searchNumber;
		int index = function1(arr, size, searchNumber);

        if (index == -1) {
                cout << "Number not found." << endl;
        } else {
                cout << "Number found at index: " << index << endl;
        }
	}
	else if(choice==2){
	try {
    
        int oldvalue;
   		 int index;
   		 cout<<"Enter index";
   		 
   		 cin>>index;
   		 int valueToUpdate;
   		 cout<<"Enter value to update";
   		 cin>>valueToUpdate;
   		 int newValue = function2(arr, 100, index, valueToUpdate, oldvalue);

        if (newValue == -1) {
            cout << "Invalid index." << endl;
        } else {
            cout << "Old Value : " << oldvalue << endl;
            cout << "New Updated Value : " << newValue << endl;
        }
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
	}
	else if(choice==3){
		try {
        cout << "Enter the element to add in the last: " << endl;

        int lastElementToAdd;
        if (!(cin >> lastElementToAdd)) {
            cout<<"Invalid input for the last element. Please enter an integer.";
        }
        int newSize = function3(arr, 100, lastElementToAdd);

        if (newSize != -1) {
            cout << "Array elements after adding a new value at the end: " << endl;
            for (int i = 0; i < newSize; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Array is full. Cannot add more elements." << endl;
        }
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

	}
	else if(choice==4){
		int replaceIndex;
    cout << "Enter the index to replace or remove: ";
    cin >> replaceIndex;

    function4(arr, replaceIndex, size);
    
    cout << "Array elements after replacement or removal:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
	
	}

    return 0; // Return success
}

