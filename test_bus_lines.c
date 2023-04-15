#include "test_bus_lines.h"
#define SUCCESS_BY_INSTRUCTIONS 1
#define FAILURE_BY_INSTRUCTIONS 0

/**
 * Checks if the given BusLine array is sorted by distance.
 * @param start a pointer to first BusLine element in the sorted array
 * @param end a pointer to last BusLine element in the sorted array
 * @return success - 1, failure - 0, by instructions.
 */
int is_sorted_by_distance (BusLine *start, BusLine *end)
{
  BusLine *ptr = start;
  int i = 0;
  while ((ptr+i) != end-1)
    {
      if ((ptr+i)->distance > (ptr+i+1)->distance)
        {
          return FAILURE_BY_INSTRUCTIONS;
        }
      i++;
    }
  return SUCCESS_BY_INSTRUCTIONS;
}

/**
 * Checks if the given BusLine array is sorted by duration.
 * @param start a pointer to first BusLine element in the sorted array
 * @param end a pointer to last BusLine element in the sorted array
 * @return success - 1, failure - 0, by instructions.
 */
int is_sorted_by_duration (BusLine *start, BusLine *end)
{
  BusLine *ptr = start;
  int i = 0;
  while ((ptr+i) != end-1)
    {
      if ((ptr+i)->duration > (ptr+i+1)->duration)
        {
          return FAILURE_BY_INSTRUCTIONS;
        }
      i++;
    }
  return SUCCESS_BY_INSTRUCTIONS;
}

/**
 * Checks if the two BusLine arrays contain the same elements,
 * not necessarily by order.
 * @param start_sorted a pointer to first BusLine element in the sorted array
 * @param end_sorted a pointer to last BusLine element in the sorted array
 * @param start_original a pointer to first BusLine element in the original
 * array
 * @param end_original a pointer to last BusLine element in the original array
 * @return success - 1, failure - 0, by instructions.
 */
int is_equal (BusLine *start_sorted,
              BusLine *end_sorted, BusLine *start_original,
              BusLine *end_original)
{
  if (end_sorted - start_sorted != end_original - start_original)
    {
      return 0;
    }
  BusLine *ptr1 = start_sorted;
  BusLine *ptr2;
  int flag;
  while (ptr1 != end_sorted)
    {
      flag = 0;
      ptr2 = start_original;
        while (ptr2 != end_original)
          {
            if (ptr1->line_number == ptr2->line_number
                && (ptr1->distance == ptr2->distance)
                && (ptr1->duration == ptr2->duration))
              {
                flag = 1;
                break;
              }
            ptr2++;
          }
        if (flag == 0)
          {
            return FAILURE_BY_INSTRUCTIONS;
          }
      ptr1++;
    }
  return SUCCESS_BY_INSTRUCTIONS;
}