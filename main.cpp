
#include <iostream>

using namespace std;


int sum(int n) {
  int total = 0;
  for (int i=1; i<=n; i++) {
    total += i;
  }
  return total;
}

int product(int n) {
  int total = 1;
  for (int i=1; i<=n; i++) {
    total *= i;
  }
  return total;
}

int main() {

  int n;

  cout << "Enter a number. Please?" << endl;
  cin >> n;

  cout << "Your sum is " << sum(n) << "! :)" << endl;
  cout << "Your product is " << product(n) << "! :)" << endl;
  
  return 0;
}
