#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*
ORIGINAL ALGORITHM ASSUMES THAT THERE IS AT-LEAST ONE POSITIVE NUMBER..
Code - 
int find_Maximum_subArray(int *array,int n)
{
	int i;
	int curr_sum=0,max_sum=INT_MIN;
	for(i=0;i<n;i++)
	{
		curr_sum+=*(array+i);
		if(curr_sum>max_sum)
		{
			max_sum=curr_sum;
		}
		if(curr_sum>=0)
		{
			continue;
		}
		else
		{
			curr_sum=0;
		}
	}
	return max_sum;
}

SMALL MODIFICATION TO RETURN SMALLEST NEGATIVE NUMBER 
WHEN ALL OF THE NUMBERS ARE NEGATIVE

*/

void array_input(int *,int);
int find_Maximum_subArray(int *,int);

int main()
{
	int n;
	printf("\nENTER THE SIZE OF THE ARRAY : ");
	scanf(" %d",&n);
	int *array=(int *)malloc(sizeof(int)*n);
	array_input(array,n);
	printf("\nMAXIMUM SUBARRAY SUM IS %d\n",find_Maximum_subArray(array,n));
	printf("\n");
	free(array);
	return 0;
}

int find_Maximum_subArray(int *array,int n)
{
	int i;
	int curr_sum=0,max_sum=INT_MIN;
	for(i=0;i<n;i++)
	{
		curr_sum+=*(array+i);
		if(curr_sum>max_sum)
		{
			max_sum=curr_sum;
		}
		if(curr_sum>=0)
		{
			continue;
		}
		else
		{
			curr_sum=0;
		}
	}
	return max_sum;
}

void array_input(int *array,int n)
{
	printf("\n\nPLEASE INPUT ARRAY ELEMENTS...\n\n");
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nINPUT THE %d ELEMENT : ",i+1);
		scanf(" %d",array+i);
	}
	return;
}
