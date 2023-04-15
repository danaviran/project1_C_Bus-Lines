#ifndef EX2_REPO_TESTBUSLINES_H
#define EX2_REPO_TESTBUSLINES_H
#include "sort_bus_lines.h"

// write only between #define EX2_REPO_TESTBUSLINES_H and #endif
// EX2_REPO_TESTBUSLINES_H

/**
 * Checks if the given BusLine array is sorted by distance.
 * @param start a pointer to first BusLine element in the sorted array
 * @param end a pointer to last BusLine element in the sorted array
 * @return success - 1, failure - 0, by instructions.
 */
int is_sorted_by_distance (BusLine *start, BusLine *end);

/**
 * Checks if the given BusLine array is sorted by duration.
 * @param start a pointer to first BusLine element in the sorted array
 * @param end a pointer to last BusLine element in the sorted array
 * @return success - 1, failure - 0, by instructions.
 */
int is_sorted_by_duration (BusLine *start, BusLine *end);

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
              BusLine *end_original);
// write only between #define EX2_REPO_TESTBUSLINES_H and #endif
// EX2_REPO_TESTBUSLINES_H
#endif //EX2_REPO_TESTBUSLINES_H
