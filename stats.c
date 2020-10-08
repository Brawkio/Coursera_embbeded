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
 * @file <stats.c> 
 * @brief <statistics computing of an array of data>
 *
 * <From a 40 elements array of unsigned char, the maximum, minimum, mean and median
 *  are computed using functions defined in the header file. Finally, a report is
 *  created and displayed "nicely" using the printf function.>
 *
 * @author <Braulio Peraza>
 * @date <06/10/2020> (dd/mm/yyyy)
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() 
{

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
	     
unsigned char *eq;
eq=&test[0];
print_array(eq,SIZE);
eq=sort_array(eq, SIZE);
print_array(eq,SIZE);
float med, mean;
med=find_median(eq,SIZE);
printf("\nThe median is %3.2f\n",med);
mean=find_mean(eq,SIZE);
printf("The mean is: %3.2f",mean);
}
 



  /* Statistics and Printing Functions Go Here */
void print_statistics(unsigned char *array, unsigned int n_elements)
{
}

void print_array(unsigned char *array, unsigned int n_elements)
{
printf("\n\t|The array of %d elements is:|\n",n_elements);
for(int i=0; i<n_elements; i++)
{
 printf("__");
}
printf("\n");
for(int i=0; i<n_elements; i++)
{
 printf("| %d ", *array);
 array++;
if(i==(.3*n_elements))
{
printf("|\n");
}
else if(i==.6*n_elements)
{
printf("|\n");
}
else if(i==n_elements-1)
{
printf("|\n");
}
}

for(int i=0; i<n_elements; i++)
{
 printf("__");
}
printf("\n\n");
}

float find_median(unsigned char *array, unsigned int n_elements)
{
int i_aux;
float f_aux;
float median;
i_aux=n_elements/2;
f_aux=n_elements/2.0;
if(f_aux-i_aux==0.0)
{
/*Even number of elements*/
median=(*(array+i_aux-1)+*(array+i_aux))/2.0;
}
else
{
/*Odd number of elements*/
median=*(array+i_aux);
}
return median;
}
float find_mean(unsigned char *array, unsigned int n_elements)
{
float total, mean;
for(int i=0;i<n_elements;i++)
{
total=total+*array;
array++;
}
mean=total/n_elements;
return(mean);
}
unsigned char find_maximum(unsigned char *array, unsigned int n_elements)
{
}
unsigned char find_minimum(unsigned char *array, unsigned int n_elements)
{
}

unsigned char *sort_array(unsigned char *array, unsigned int n_elements)
{
unsigned char mem_aux;
int i, j;
for(i=0; i<n_elements; i++)
{
 for(j=i+1; j<n_elements; j++)
 {
	if(*(array+j)>*(array+i))
	{
	mem_aux=*(array+i);
	*(array+i)=*(array+j);
	*(array+j)=mem_aux;
	}
 }
}
return array;
}

/* Add other Implementation File Code Here */


