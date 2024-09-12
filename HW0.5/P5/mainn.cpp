/**
 * @file mainn.cpp
 * @author Anna Hensley 
 * @date 2024-09-11
 * @brief Quiz 0.5 Redo - Problem 5
 * 
 * This is a program that was copied from Quiz 0.5 Redo - Problem 3. This program should be sufficient in showing a code that can read a series of integers and stores them into an array, while having a max array length. This should also still be in compliance with guidelines on Canvas. 
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

/**
* This is a function that reads the integers from the file and stores them into the array. 
*
* @param int array[] Dynamic array that will contain integers or values in the file we'll be reading from. 
* @param int &size Stores the size of the array based on how many values are in the file we're reading from.
* @param maxSize This is the maximum number of integers/values that can be stored in the array. We are letting the user choose this.
* @param const char* fileName This is the file the user chooses for us to read and copy our integer values for our array. 
* @pre We need the user to enter a file that exists and is readable as well as the amount of values they want us to read from the file (more than zero)
* @return void 
* @post This function will read and copy integers from the file into the array. &Size will also store the size of the array. * */
void readingInts(int array[], int &size, int maxSize, const char* fileName);

/**
 * This is a function that prints the contents of the array, or all of the values from the file.
 *
 * @param const int array[] Array that contains the values read from our file. 
 * @param int size The size of the array, which is the numbers of values read/used in the file.
 * @pre The array should have been able to read from the file and store the data from the file.
 * @return void 
 * @post This function will print all values from the file.
 * 
 */
void printingInts(const int array[], int size);

/**
 * This is a function that will print the average of all the values from the file previously chosen. 
 *
 * @param consr int array[] This constant array contains integers/values that we read and stored from the file chosen.
 * @param int size This is used for calculating the average of the values read from the file.
 * @pre All values from the file need to be stored in the array. Size needs to be greater than zero.  
 * @return float This will return the average of the values from the file. This is a float to ensure that there will be no rounding in the answer.
 * @post This function will returb the average of the chosen amount of values from the file.  
 * 
 */
float average(const int array[], int size);

int main() {
  string fileName;
  cout << "Which file do you want to use? ";
  cin >> fileName;
  
  int maxSize;
  cout << "How many values do you plan to calculate? ";
  cin >> maxSize;

  // allocating dynamic array based on what the user inputs
  int* array = new int[maxSize];
  int size = 0;
  
  readingInts(array, size, maxSize, fileName.c_str());
  printingInts(array, size);

  if (size > 0) {
    cout << "Average of values in the file: " << fixed << setprecision(2) << average(array, size) << endl;
  } else {
    cout << "Please enter at least 1 or more for the amount of values wanted to average." << endl;
  }

  // deallocating
  delete[] array;
  
  return 0;
}

void readingInts(int array[], int &size, int maxSize, const char* fileName) {
  ifstream file(fileName);
  // checking for a file that is accessible  
  if (!file) {
    cout << "There is a problem opening the file." << endl;
    return;
  }

  int value;
  size = 0;

  // read integers from this file
  while (file >> value && size < maxSize) {
    array[size++] = value;
  }

  file.close();
}

void printingInts(const int array[], int size) {
  cout << "These are all of the values in the file:" << endl;
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}


float average(const int array[], int size) {
  if (size <= 0) {
    return 0.0;
  }
  
  float total = 0.0;
  // taking all the values in the file and adding them together as we go through each value 
  for (int i = 0; i < size; i++) {
    total += array[i];
  }
  return total / size;
}
