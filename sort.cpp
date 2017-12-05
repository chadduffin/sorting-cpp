#include "sort.h"

#include <iostream>

void Sort::MergeSort(int *list, int len) {
  Partition(list, 0, len);
}

void Sort::QuickSort(int *list, int len) {
  PivotAndSort(list, 0, len-1);
}

void Sort::Merge(int *list, int begin, int middle, int end) {
  int len = end - begin,
      *tmp = new int[len];

  for (int i = 0, j = begin, k = middle; i < len; i++) {
    if (j >= middle) {
      tmp[i] = list[k++];
    } else if (k >= end) {
      tmp[i] = list[j++];
    } else {
      tmp[i] = (list[k] < list[j]) ? list[k++] : list[j++];
    }
  }

  for (int i = 0; i < len; i++) {
    list[begin+i] = tmp[i];
  }

  delete[] tmp;
}

void Sort::Partition(int *list, int begin, int end) {
  if (end - begin > 1) {
    int middle = (end + begin)/2 + (end + begin)%2;

    Partition(list, begin, middle);
    Partition(list, middle, end);
  
    Merge(list, begin, middle, end);
  }
}

void Sort::PivotAndSort(int *list, int begin, int end) {
  int i = begin, j = end, pivot = (begin + end)/2;

  if (i >= j) { return; }

  while (i <= j) {
    while (list[i] < list[pivot]) {
      i++;
    }

    while (list[j] > list[pivot]) {
      j--;
    }

    if (i <= j) {
      int tmp = list[i];

      list[i] = list[j];
      list[j] = tmp;

      i++;
      j--;
    }
  }

  PivotAndSort(list, begin, i-1);
  PivotAndSort(list, i, end);
}
