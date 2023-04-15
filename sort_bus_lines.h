#ifndef EX2_REPO_SORTBUSLINES_H
#define EX2_REPO_SORTBUSLINES_H
// write only between #define EX2_REPO_SORTBUSLINES_H and #endif
// EX2_REPO_SORTBUSLINES_H

/**
 * Busline - a Struct that has three integer elements.
 */
typedef struct BusLine
{
    int line_number, distance, duration;
} BusLine;

/**
 * Bubble Sort function to sort the BusLine array by it's distance.
 * @param start Busline pointer - Starting index
 * @param end Busline pointer - Ending index
 */
void bubble_sort (BusLine *start, BusLine *end);

/**
 * Quick Sort function to sort the Busline array by it's duration.
 * The main function that implements QuickSort
 * @param start Busline pointer - Starting index
 * @param end Busline pointer - Ending index
 */
void quick_sort (BusLine *start, BusLine *end);

/**
 * A helper function of the Quick Sort function.
 * This function takes last element as pivot, places
 *  the pivot element at its correct position in sorted
 *  array, and places all smaller (smaller than pivot)
 *  to left of pivot and all greater elements to right
 *  of pivot.
 * @param start Busline pointer - Starting index
 * @param end Busline pointer - Ending index
 * @return A pointer to the current BusLine.
 */
BusLine *partition (BusLine *start, BusLine *end);
// write only between #define EX2_REPO_SORTBUSLINES_H and #endif
// EX2_REPO_SORTBUSLINES_H
#endif //EX2_REPO_SORTBUSLINES_H
