#include "sort.h"

void Sort::MergeSort(int *list, int len) {
  Partition(list, 0, len);
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
  if (end-begin > 1) {
    int middle = (end + begin)/2 + (end + begin)%2;

    Partition(list, begin, middle);
    Partition(list, middle, end);
  
    Merge(list, begin, middle, end);
  }
}
