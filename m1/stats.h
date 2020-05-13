/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h 
 * @brief Assignment1
 *
 * @author <Burak Orpak>
 * @date <20/01/2020>
 *
 */

#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief A function that prints the statics of an array including minimum, maximum,mean and median.
 * 
 * @param 8-bit char pointer of n-element data array
 * @return not to return value 
 */
void print_statics(unsigned char * arr);

/**
 * @brief Given an array of data and a length, prints the array to the screen.
 *
 * @param 8-bit char pointer of n-element data array and size of array
 * @return not to return value
 */
void print_array(unsigned char * arr, unsigned int size);

/**
 * @brief Given an array of data and a length, returns the median value
 * 
 * @param 8-bit char pointer of n-element data array and size of array
 * @return 8-bit unsigned char median value of array
 */
unsigned char find_median(unsigned char * arr, unsigned int size);

/**
 * @brief Given an array of data and a length, returns the mean value.
 * 
 * @param 8-bit char pointer of n-element data array and size of array
 * @return 8-bit unsigned char mean value of array
 */
unsigned char find_mean(unsigned char * arr, unsigned int size);

/**
 * @brief Given an array of data and a length, returns the maximum.
 *  
 * @param 8-bit char pointer of n-element data array and size of array
 * @return 8-bit unsigned char maximum value of array
 */
unsigned char find_maximum(unsigned char * arr, unsigned int size);

/**
 * @brief Given an array of data and a length, returns the minumum.
 * 
 * @param 8-bit char pointer of n-element data array and size of array
 * @return 8-bit unsigned char minumum value of array
 */
unsigned char find_minumum(unsigned char * arr, unsigned int size);

/**
 * @brief Given an array of data and a length, sorts the array from largest to smallest. 
 * (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )
 * @param 8-bit char pointer of n-element data array
 * @return not to return value
 */
void sort_array(unsigned char * arr, unsigned int size);


#endif /* __STATS_H__ */
