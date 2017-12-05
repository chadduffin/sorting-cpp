#include "sort.h"

void Sort::MergeSort(int *list, int len) {
  Partition(list, 0, len);
}

void Sort::QuickSort(int *list, int len) {
  PivotAndSort(list, 0, len-1);
}

void Sort::Merge(int *list, int begin, int middle, int end) {
  int len = end - begin,
      *tmp = new int[len];

  // iterate through subarrays
  // place values into tmp[] in sorted order
  for (int i = 0, j = begin, k = middle; i < len; i++) {
    if (j >= middle) {
      tmp[i] = list[k++];
    } else if (k >= end) {
      tmp[i] = list[j++];
    } else {
      tmp[i] = (list[k] < list[j]) ? list[k++] : list[j++];
    }
  }

  // copy sorted array to list[]
  for (int i = 0; i < len; i++) {
    list[begin+i] = tmp[i];
  }

  delete[] tmp;
}

void Sort::Partition(int *list, int begin, int end) {
  // if the subarray size is greater than 1
  // partition into two, afterwards merge them together
  if (end - begin > 1) {
    int middle = (end + begin)/2 + (end + begin)%2;

    Partition(list, begin, middle);
    Partition(list, middle, end);
  
    Merge(list, begin, middle, end);
  }
}

void Sort::PivotAndSort(int *list, int begin, int end) {
  int i = begin, j = end, pivot = (begin + end)/2;

  // if out left iterator is greater than our right iterator, exit
  if (i >= j) { return; }

  // loop until our iterators cross
  while (i <= j) {
    // increment our left iterator until we find a value to swap
    while (list[i] < list[pivot]) {
      i++;
    }

    // decrement our right iterator until we find a value to swap
    while (list[j] > list[pivot]) {
      j--;
    }

    // if our iterators should be swapped, swap them
    if (i <= j) {
      int tmp = list[i];

      list[i] = list[j];
      list[j] = tmp;

      i++;
      j--;
    }
  }

  // recursively call this function on subarrays
  PivotAndSort(list, begin, i-1);
  PivotAndSort(list, i, end);
}
