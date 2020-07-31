#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct max_subArray_info{
	int start;
	int end;
	int sum;
};

typedef struct max_subArray_info tuple;

void array_input(int *,int);
void find_Maximum_Subarray(int *,int,tuple *,int,int);
void find_Maximum_Crossing_Subarray(int *,int,tuple *,int,int,int);

int main()
{
	int n;
	printf("\nENTER THE SIZE OF THE ARRAY : ");
	scanf(" %d",&n);
	int *array=(int *)malloc(sizeof(int)*n);
	tuple max_SubArray;          //tuple --> start,end,sum
	array_input(array,n);
	find_Maximum_Subarray(array,n,&max_SubArray,0,n-1);
	printf("\nMAXIMUM SUB-ARRAY IS : ");
	int i;
	for(i=max_SubArray.start;i<=max_SubArray.end;i++)
	{
		printf("%d ",*(array+i));
	}
	printf("\nMAXIMUM SUB-ARRAY SUM IS %d",max_SubArray.sum);
	printf("\n");
	free(array);
	return 0;
}

void find_Maximum_Subarray(int *array,int n,tuple *max_SubArray,int start,int end)
{
	if(start==end)
	{
		max_SubArray->start=start;
		max_SubArray->end=start;
		max_SubArray->sum=*(array+start);
		return;
	}
	int mid=(start+end)/2;
	tuple left_max_SubArray,right_max_SubArray,cross_max_SubArray;
	find_Maximum_Subarray(array,n,&left_max_SubArray,start,mid);
	find_Maximum_Subarray(array,n,&right_max_SubArray,mid+1,end);
	find_Maximum_Crossing_Subarray(array,n,&cross_max_SubArray,start,mid,end);
	if((left_max_SubArray.sum)>(right_max_SubArray.sum) && (left_max_SubArray.sum)>(cross_max_SubArray.sum))
	{
		max_SubArray->start=left_max_SubArray.start;
		max_SubArray->end=left_max_SubArray.end;
		max_SubArray->sum=left_max_SubArray.sum;
	}
	else if((right_max_SubArray.sum)>(left_max_SubArray.sum) && (right_max_SubArray.sum)>(cross_max_SubArray.sum))
	{
		max_SubArray->start=right_max_SubArray.start;
		max_SubArray->end=right_max_SubArray.end;
		max_SubArray->sum=right_max_SubArray.sum;
	}
	else if((cross_max_SubArray.sum)>(left_max_SubArray.sum) && (cross_max_SubArray.sum)>(right_max_SubArray.sum))
	{
		max_SubArray->start=cross_max_SubArray.start;
		max_SubArray->end=cross_max_SubArray.end;
		max_SubArray->sum=cross_max_SubArray.sum;
	}
	return;
}

void find_Maximum_Crossing_Subarray(int *array,int n,tuple *cross_max_SubArray,int start,int mid,int end)
{
	int i;
	int sum=0,left_max=INT_MIN,right_max=INT_MIN;
	int left_start,right_end;
	for(i=mid;i>=start;i--)
	{
		sum+=*(array+i);
		if(sum>left_max)
		{
			left_max=sum;
			left_start=i;
		}
	}
	sum=0;
	for(i=mid+1;i<=end;i++)
	{
		sum+=*(array+i);
		if(sum>right_max)
		{
			right_max=sum;
			right_end=i;
		}
	}
	cross_max_SubArray->start=left_start;
	cross_max_SubArray->end=right_end;
	cross_max_SubArray->sum=left_max+right_max;
	return;
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

