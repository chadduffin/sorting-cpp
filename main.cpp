#include "sort.h"

#include <iostream>

int main(int argc, char **argv) {
  int array[10] = {1, 5, 3, 7, 2, 9, 10, 4, 6, 8};

  Sort::MergeSort(array, 10);

  for (int i = 0; i < 10; i++) {
    std::cout << array[i] << " ";
  }

  std::cout << std::endl;

  return 0;
}
