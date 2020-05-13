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
 * @file stats.c 
 * @brief Assignment1
 *
 * @author <Burak Orpak>
 * @date <03/02/2020 >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  print_array(test, SIZE);
  sort_array(test, SIZE);
  print_array(test, SIZE);
  print_statics(test);

}
void print_array(unsigned char * arr, unsigned int size) {
  int x = 0;
  printf("Printing array\n");
  for (int i=0; i<size; i++) {
	  x++;
	  printf("%d%s", arr[i], x==10? "\n": "\t");
	  if(x == 10) {
		  x = 0;
	  }
  }
	  printf("***\n");

}
void print_statics(unsigned char * arr) {
  printf("Minumum = %d\n", find_minumum(arr, SIZE));
  printf("Maximum = %d\n", find_maximum(arr, SIZE));
  printf("Mean Value = %d\n", find_mean(arr, SIZE));
  printf("Median Value = %d\n", find_median(arr, SIZE));	  
}
/*
void print_array(unsigned char * arr, unsigned int size) {
  for(unsigned int x; x < size; x++)
  {
    printf("%d\n", arr+x);
  }
}
*/
unsigned char find_median(unsigned char * arr, unsigned int size) {
  int midd = (size/2);
  float med = 0;
  if(size%2 == 0)
  {
    med = (arr[midd-1] + arr[midd])/2;
  } else {
    med = arr[midd];
  }
  return med; 
}
unsigned char find_mean(unsigned char * arr, unsigned int size) {
  float sum = 0;
  for(unsigned int x = 0; x < size; x++)
  {
    sum = sum + (*(arr+x));
  }
  return sum/size;
}
unsigned char find_maximum(unsigned char * arr, unsigned int size) {
  unsigned int max = *arr;
  for(int i = 0 ; i < size ; i++)
  {
    if ( max < *(arr+i))
    {
      max = *(arr+i);
    }
  }
  return max;
}
unsigned char find_minumum(unsigned char * arr, unsigned int size) {
  unsigned int min = *arr;
  for(int x = 0 ; x < size ; x++)
  {
    if ( min > *(arr+x))
    {
      min = *(arr+x);
    }
  }
  return min; 
}
void sort_array(unsigned char * arr, unsigned int size) {
  for(unsigned int a = 0; a < size-1; a++)
  {	
    for(unsigned int z = 0; z < size; z++)
    {
      if( (*(arr+z)) < (*(arr+z+1)))
        {	
	  unsigned int x = 0;
	  x = (*(arr+z));
	  (*(arr+z)) = (*(arr+z+1));
	  (*(arr+z+1)) = x;
	}
    }
  }  
}
