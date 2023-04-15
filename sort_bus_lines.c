#include "sort_bus_lines.h"

/**
 * A swapping function of two BusLine elements in an array.
 * @param x_p first BusLine element.
 * @param y_p second BusLine element.
 */
void swap(BusLine *x_p, BusLine *y_p)
{
  BusLine temp = *x_p;
  *x_p = *y_p;
  *y_p = temp;
}

/* Documentation in the header file. */
void bubble_sort (BusLine *start, BusLine *end)
{
  BusLine *start_p = start;
  int arr_len = (int)(end - start);
  int i, j;
  for (i = 0; i < arr_len - 1; i++)
    {
      // Last i elements are already in place
      for (j = 0; j < arr_len - i - 1; j++)
        {
          if ((start_p+j)->distance > (start_p+(j + 1))->distance)
            {
              swap((start_p+j), (start_p+(j + 1)));
            }
        }
    }
}

/* Documentation in the header file. */
void quick_sort (BusLine *start, BusLine *end)
{
  BusLine *arr_p = start;
  BusLine *end_p = end-1;
  int arr_len = (int)(end - start);
  if (arr_len > 0)
    {
      /* pi is partitioning index, arr[p] is now
      at right place */
      BusLine *pi = partition(arr_p, end_p);

      // Separately sort elements before
      // partition and after partition
      quick_sort(arr_p, pi - 1);
      quick_sort(pi + 1, end_p);
    }
}

/* Documentation in the header file. */
BusLine *partition (BusLine *start, BusLine *end)
{
  BusLine *start_p = start;
  BusLine *end_p = end;
  BusLine *ptr = start;
  int pivot = end->duration; // pivot
  int i = -1; // Index of smaller element and indicates the right position
  // of pivot found so far
  int j = 0;
  while ((ptr+j) != end_p)
    {
        if ((ptr+j)->duration < pivot) // If current element is smaller
          // than the pivot
          {
            i++; // increment index of smaller element
            BusLine *cur = ptr;
            swap(cur+i, cur+j);
          }
        j++;
    }
  swap(start_p+i+1, end_p);
  return start_p + i + 1;
}
