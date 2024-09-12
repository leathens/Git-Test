/**
 * @file mainn.cpp
 * @author Anna Hensley 
 * @date 2024-09-11
 * @brief Quiz 0.5 Redo - Problem 1
 * 
 * This is a program that contains functions that reads data from a file to use as the values we'll calculate an average for, prints the contents of the file's data, and finds the average of all the values in the file. This program should adhere to the guidelines provided on Canvas.
 */

#include <iostream>
#include <fstream>

using namespace std;

const int MAX_ARRAY = 1000;

/**
* This is a function that reads the integers from the file and stores them into the array. 
*
* @param int array[] Static array that contains integers or values in the file we'll be reading from. 
* @param int &size Stores the size of the array based on how many values are in the file we're reading from. 
* @param const char* fileName This is the file we are reading and copying our integer values for our array.
* @pre We need a file that exists and is readable.
* @return void 
* @post This function will read and copy integers from the file into the array. &Size will also store the size of the array. * */ 
void readingInts(int array[], int &size, const char* fileName);

/**
 * This is a function that prints the contents of the array, or all of the values from the file.
 *
 * @param const int array[] Array that contains the values read from our file. 
 * @param int size The size of the array, which is the numbers of values in the file.
 * @pre The array should have been able to read from the file and store the data from the file.
 * @return void 
 * @post This function will print all values from the file.
 * 
 */
void printingInts(const int array[], int size);

/**
 * This is a function that will print the average of all the values from the file previously chosen. 
 *
 * @param int array[] 
 * @param int size This is used for calculating the average of the values read from the file.
 * @pre All values from the file need to be stored in the array. Size needs to have the correct amount of values in file. 
 * @return float This will return the average of the values from the file. This is a float to ensure that there will be no rounding in the answer.
 * @post This function will print the average of all the values in the file. 
 * 
 */
float average(int array[], int size);

int main() {
  static int array[MAX_ARRAY];
  int size = 0;

  readingInts(array, size, "fileWithValues.txt");
  printingInts(array, size);

  cout << "Average of values in the file: " << average(array, size) << endl;
  
  return 0;
}

void readingInts(int array[], int &size, const char* fileName) {
  ifstream file(fileName);
  // checking for file availability and accessibility 
  if (!file) {
    cout << "There is a problem opening the file." << endl;
    return;
  }

  int value;
  size = 0;

  // read integers from this file
  while (file >> value && size < MAX_ARRAY) {
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


float average(int array[], int size) {
  float total = 0.0;
  // taking all the values in the file and adding them together as we go through each value 
  for (int i = 0; i < size; i++) {
    total += array[i];
  }
  // as long as there is at least one value, we can calculate the average.
  return size > 0 ? total / size : 0.0;
}
