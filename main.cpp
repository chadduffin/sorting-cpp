#include "sort.h"

#include <iostream>

int main(int argc, char **argv) {
  int array[10] = {6, 2, 8, 5, 7, 1, 4, 3, 10, 9};

  Sort::QuickSort(array, 10);

  for (int i = 0; i < 10; i++) {
    std::cout << array[i] << " ";
  }

  std::cout << std::endl;

  return 0;
}
