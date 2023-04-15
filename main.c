#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sort_bus_lines.h"
#include "test_bus_lines.h"

#define BUBBLE 2
#define QUICK 3
#define TEST 4
#define COMMA_ASCII 44
#define SPACE_ASCII 32
#define MAX_ELEMENT 20
#define MAX_ROW 60
#define BASE 10
#define MIN_LINE 0
#define MAX_LINE 1999
#define MIN_DURATION 10
#define MAX_DURATION 100
#define MIN_DISTANCE 0
#define MAX_DISTANCE 1000

/**
 * Replaces all commas in a string with space marks.
 * @param str - a char array.
 */
void replace_chars(char *str)
{
  for (int i =0; i< (int) strlen (str); i++)
    {
      if (*(str+i) == COMMA_ASCII)
        {
          *(str+i) = SPACE_ASCII;
        }
    }
}

/**
 * Gets an input that represents the number of buses from the user.
 * @param num_of_buses a pointer to an integer.
 */
void get_num_of_buses(int* num_of_buses)
{
  printf("Enter number of lines. Then enter\n");
  char str_num_of_buses[MAX_ELEMENT];
  fgets (str_num_of_buses, MAX_ELEMENT, stdin);
  *num_of_buses = (int) strtol(str_num_of_buses, NULL, BASE);
  if (*num_of_buses <= 0)
    {
      printf ("ERROR: Bus line has to be positive.\n");
    }
}

/**
 * Gets the current bus input: three integers - Line, Distance and Duration.
 * @param cur_bus
 * @param i an integer. represents the number of bus that it's input is given.
 * @return success (0) or failure (1) of function.
 */
int get_bus_info(BusLine **cur_bus, int i)
{
  BusLine *cur_bus_p = *cur_bus + i;
  char str_cur_bus_data[MAX_ROW];
  printf("Enter line info. Then enter\n");
  fgets (str_cur_bus_data, MAX_ROW, stdin);
  replace_chars (str_cur_bus_data);
  char *next_elements = 0;
  int line = 0, duration=0, distance=0;
  line = (int) strtol(str_cur_bus_data, &next_elements, BASE);
  distance = (int) strtol(next_elements, &next_elements,
                          BASE);
  duration = (int) strtol(next_elements, &next_elements,
                          BASE);
  if (line<MIN_LINE || line>MAX_LINE || duration<MIN_DURATION ||
  duration>MAX_DURATION ||
  distance<MIN_DISTANCE || distance>MAX_DISTANCE)
    {
      printf ("ERROR: Format allowed is 0<=line<=2000,0<=distance<=1000"
              ",10<=duration<=100\n");
      return EXIT_FAILURE;
    }
  (cur_bus_p)->line_number = line;
  (cur_bus_p)->distance = distance;
  (cur_bus_p)->duration = duration;
  return EXIT_SUCCESS;
}

/**
 * Checks argument validity - that there is only one argument given bu user.
 * if there is less or more that that, we print an informative message about
 * the usage of the program.
 * @param argc number of arguments
 * @param arg1 array of the chars given
 * @return success (0) or failure (1) of function.
 */
int arguments_validity(int argc, char *arg1)
{
  if (argc != 2)
    {
      printf ("USAGE: Enter one of the following: bubble, quick or "
              "test\n");
      return EXIT_FAILURE;
    }

  if (strcmp (arg1, "bubble") == 0)
    {
      return BUBBLE;
    }
  if (strcmp (arg1, "quick") == 0)
    {
      return QUICK;
    }
  if (strcmp (arg1, "test")==0)
    {
      return TEST;
    }
  printf ("USAGE: Enter one of the following: bubble, quick or test\n");
  return EXIT_FAILURE;
}

/**
 * Copies the values given in the array arr to the array called orig_arr.
 * The allocation of memory in the heap for both of these arrays is allocated
 * before, in a specific function. the length of both arrays is num.
 * @param arr the array to be copied to the next
 * @param orig_arr the value to copy the values of the first to
 * @param num integer, represents the length of arrays
 */
void copy_array (BusLine *arr, BusLine** orig_arr, int num)
{
  for (int i=0; i<num;i++)
    {
      (*orig_arr+i)->line_number = (arr+i)->line_number;
      (*orig_arr+i)->distance = (arr+i)->distance;
      (*orig_arr+i)->duration = (arr+i)->duration;
    }
}

/**
 * Frees the allocation in the heap of the array that is sent to it.
 * @param arr_p a pointer to an array to free and nullify.
 */
void free_bus_line_alloc(BusLine** arr_p)
{
  if (*arr_p != NULL)
    {
      free(*arr_p);
    }
  *arr_p = NULL;
}

/**
 * Prints the BusLine arr by order of it's elements.
 * @param arr the arr to be printed
 * @param n the length of the arr
 */
void print_arr(BusLine *arr, int n)
{
  BusLine *ptr = arr;
  for (int i =0;i< n; i++)
    {
      printf ("%d,%d,%d\n", (ptr+i)->line_number, (ptr+i)->distance,
              (ptr+i)->duration);
    }
}

/**
 * Allocates the memory in the heap that is used for the BusLine arrays.
 * If it does not succeed, returns EXIT FAILURE.
 * @param arr_p a pointer to the array that we allocate the memory for
 * @param num_of_buses the wanted length to allocate
 * @return Exit Failure or Exit Success (int)
 */
int alloc_bus_line_arr(BusLine** arr_p, int num_of_buses)
{
  *arr_p = calloc((unsigned long) num_of_buses,sizeof(BusLine));
  if (*arr_p == NULL)
    {
      printf ("ERROR: The allocation of Buses Array did not succeed\n");
      return EXIT_FAILURE;
    }
  return EXIT_SUCCESS;
}

/**
 * The Test mode of the program, tests the SORT functions.
 * @param bus_arr the BusLine array to sort
 * @param orig_arr the original BusLine array
 * @param num_of_buses length of array
 */
void test_function(BusLine *bus_arr, BusLine *orig_arr, int num_of_buses)
{
  bubble_sort (bus_arr, (bus_arr+(num_of_buses)));
  int check1 = is_sorted_by_distance (bus_arr,
                                      (bus_arr+(num_of_buses)));
  if (check1 == 1)
    {
      printf ("TEST 1 PASSED: The arr is indeed sorted by distance.\n");
    }
  else
    {
      printf ("TEST 1 FAILED: The arr is NOT sorted by distance.\n");
    }
  int check2 = is_equal (bus_arr,(bus_arr+
  (num_of_buses)), orig_arr, orig_arr+(num_of_buses));
  if (check2 == 1)
    {
      printf ("TEST 2 PASSED: The arrays have same elements.\n");
    }
  else
    {
      printf ("TEST 2 FAILED: The arrays DO NOT have same elements.\n");
    }
  BusLine *quick_sort_arr = {0};
  alloc_bus_line_arr (&quick_sort_arr, num_of_buses);
  copy_array (bus_arr, &quick_sort_arr, num_of_buses);
  quick_sort (quick_sort_arr, quick_sort_arr+(num_of_buses));
  int check3 = is_sorted_by_duration(bus_arr,
                                     (bus_arr+(num_of_buses)));
  if (check3 == 1)
    {
      printf ("TEST 3 PASSED: The arr is indeed sorted by duration.\n");
    }
  else
    {
      printf ("TEST 3 FAILED: The arr is NOT sorted by duration.\n");

    }
  int check4 = is_equal (bus_arr,(bus_arr+
  (num_of_buses)), orig_arr, orig_arr+(num_of_buses));
  if (check4 == 1)
    {
      printf ("TEST 4 PASSED: The arrays have same elements.\n");
    }
  else
    {
      printf ("TEST 4 FAILED: The arrays DO NOT have same elements.\n");
    }
  free_bus_line_alloc(&quick_sort_arr);
}

/**
 * Insert the current Bus info to the BusLine array
 * @param arr_p the array
 * @param num_of_buses length of array
 */
void insert_line_input(BusLine** arr_p, int num_of_buses)
{
  int success = 1;
  for (int i = 0; i < num_of_buses; i++)
    {
      success = 1;
      while (success == 1)
        {
          success = get_bus_info (arr_p, i);
        }
    }
}

/**
 * Main Program - controls all functions.
 * @param argc number of arguments given by the user.
 * @param argv array of char arguments given bu the user.
 * @return Exit Success or Exit Failure, upon the program performance.
 */
int main (int argc, char *argv[])
{
  // Check arguments validity
  int action = arguments_validity (argc, *(argv+1));
  if (action == EXIT_FAILURE)
    {
      return EXIT_FAILURE;
    }
  // Get the amount of buses
  int num_of_buses = 0;
  while (num_of_buses <= 0)
    {
      get_num_of_buses (&num_of_buses);
    }
  // Makes a BusLine array of num_of_buses elements, stored in the Heap
  BusLine *bus_arr = {0};
  BusLine *orig_arr = {0};
  int success = alloc_bus_line_arr (&bus_arr, num_of_buses);
  if (success == 1)
    {
      return EXIT_FAILURE;
    }
  success = alloc_bus_line_arr (&orig_arr, num_of_buses);
  if (success == 1)
    {
      free (bus_arr);
      return EXIT_FAILURE;
    }
  // get inputs of each BusLine and store them in bus_arr (Heap)
  insert_line_input(&bus_arr, num_of_buses);
  // Copy array to Original array, so we save original at hand after changes
  copy_array (bus_arr, &orig_arr, num_of_buses);
  // Run the wanted action
  if (action == TEST)
    {
      test_function (bus_arr, orig_arr, num_of_buses);
      return EXIT_SUCCESS;
    }
  else if (action == BUBBLE)
    {
      bubble_sort (bus_arr,(bus_arr+(num_of_buses)));
      print_arr (bus_arr, num_of_buses);
    }
  else
    {
      quick_sort(bus_arr,(bus_arr+(num_of_buses)));
      print_arr (bus_arr, num_of_buses);
    }
  // free the Allocations
  free_bus_line_alloc(&bus_arr);
  free_bus_line_alloc(&orig_arr);
}
