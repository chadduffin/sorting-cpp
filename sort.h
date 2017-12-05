#ifndef __SORT__
#define __SORT__

class Sort {
  public:
    static void MergeSort(int *list, int len);

  private:
    static void Merge(int *list, int begin, int middle, int end);
    static void Partition(int *list, int begin, int end);
};

#endif /* SORT */
