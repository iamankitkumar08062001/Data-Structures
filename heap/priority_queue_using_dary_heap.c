#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
//================================================
//this is a implementation of a priority queue using
//d-ary max heap
//================================================
//==================DESCRIPTION===================
//================================================ 
//function definations
//================================================ 
//function for array/program
//in brackets () --> name of actual arguments(formal arguments names may be diffrent from actual arguments) passed in the program
//================================================
//Common Notations : -
//================================================
//1. d --> Number of Children, example --> 2 in case of binary heap
//2. n/heap_size --> Size
//3. array --> Address of first element of array
//4. i --> Current Node
//================================================
int menu(void);//Function to print menu()
void array_input(int *,int); //Arguments --> array, n/heap_size
void array_output(int *,int);//Arguments --> array, n/heap_size
//================================================
//function for max-heap
//================================================
int key_index(int,int,int,int);//
//                                         Arguments --> d,i
//                                         choice --> 1. 1 if child index is requested
//                                                    2. 0 if child index is requested,
//                                         child_no --> nth-child number
//                                         NOTE --> Don't care if parent is requested
void build_max_heap(int *,int,int);//
//                                   Arguments --> array, n/heap_size, d
void max_heapify(int *,int,int,int);//
//                                  Arguments --> array, n/heap_size, d, i
void swap(int *,int *);//Arguments --> Two pointers to numbers which need to be swapped
//================================================
//function for priority queue implementation
//================================================
int heap_maximum(int *);//
//Arguments --> array
int heap_extract_maximum(int *,int *,int);//
//
void heap_insert(int *,int *,int,int);//
//
void increase_key(int *,int,int);//This is a interface to heap_increase_key() function
//                             Arguments --> array,n/heap_size,d
void heap_increase_key(int *,int,int,int);//Arguments --> array,heap_size,key,d
//================================================ 
//================================================ 
//Driver Function
int main(void)
{
	printf("\n\nWELCOME...\n\n");
	int n,d,heap_size;
	printf("\nPlease enter the number of children that each node will have : ");
	scanf(" %d",&d);
	printf("Please enter the size of the array : ");
	scanf(" %d",&n);
	heap_size=n;
	int *array=(int *)malloc(sizeof(int)*heap_size);
	array_input(array,n);
	build_max_heap(array,n,d);
	while(1)
	{
		switch(menu())
		{
			case 1: printf("\nThe key %d has been succesfully extracted...\n\n",heap_extract_maximum(array,&heap_size,d));
					break;
			case 2: heap_insert(array,&heap_size,n,d);
					break;
			case 3: increase_key(array,heap_size,d);
					break;
			case 4: printf("The maximum key is %d\n\n",heap_maximum(array));
					break;
			case 5: printf("The heap is : ");
					array_output(array,heap_size);
					break;
			case 6: printf("The array is : ");
					array_output(array,n);
					break;
			case 7: free(array);
					printf("Thank you for using my program...\n\n");
					exit(0);
		}
	}
	return 0;
}

//Functions which accepts current node index
//and returns children/parent based on choice/child_no
int key_index(int d,int i,int choice,int child_no)
{
	//if choice is 1 then child is requested
	//if child is requested then child_no corresponds to the child
	//
	//if choice is 0 then parent is requested
	//child_no is a don't care if parent is requested
	if(choice==1)
	{
		//children index
		int child_index,j;
		i+=1;
		if(d%2==0)
		{
			child_index=(d*i)-(d/2);
			for(j=0;j<d;j++)
			{
				child_index+=j;
				if(j+1==child_no)
				{
					return (child_index-1);
				}
			}
		}
		else
		{
			child_index=(d*i)-((d-1)/2);
			for(j=0;j<d;j++)
			{
				child_index+=i;
				if(j+1==child_no)
				{
					return (child_index-1);
				}
			}
		}
	}
	else
	{
		//parent index
		return ((int)(i/d)-1);
	}
}

int heap_maximum(int *array)
{
	return *(array+0);
}

int heap_extract_maximum(int *array,int *n,int d)
{
	swap(array+0,array+(*n)-1);
	(*n)-=1;
	max_heapify(array,(*n),d,0);
	return *(array+(*n));
}

void increase_key(int *array,int n,int d)
{
	int key,key_index;
	printf("\nEnter the value of key which you want to change : ");
	scanf(" %d",&key);
	int i;
	for(i=0;i<n;i++)
	{
		if(*(array+i)==key)
		{
			key_index=i; 
			break;
		}
	}
	int new_key;
	printf("Enter the new key : ");
	scanf(" %d",&new_key);
	heap_increase_key(array,key_index,new_key,d);
	return;
}

void heap_insert(int *array,int *heap_size,int n,int d)
{
	if((*heap_size)==n)
	{
		printf("\nHEAP OVERFLOW...\n");
	}
	else
	{
		(*heap_size)+=1;
		int key;
		printf("\nEnter the new key : ");
		scanf(" %d",&key);
		*(array+(*heap_size)-1)=INT_MIN;
		heap_increase_key(array,*(heap_size)-1,key,d);
	}
	return;
}

void heap_increase_key(int *array,int i,int key,int d)
{
	if(key<*(array+i))
	{
		printf("\nNew key is smaller than current key...\n");
	}
	else
	{
		*(array+i)=key;
		int parent_index=key_index(d,i,0,0);
		while(i>0 && *(array+parent_index)<*(array+i))
		{
			swap(array+parent_index,array+i);
			i=parent_index;
		}
	}
	return;
}

void build_max_heap(int *array,int n,int d)
{
	int i;
	for(i=(int)((((n-1)*(d-1))+1)/d);i>0;i--)
	{
		max_heapify(array,n,d,i-1);
	}
	return;
}

void max_heapify(int *array,int n,int d,int i)
{
	int *children_index=(int *)malloc(sizeof(int)*d);
	int j;
	for(j=0;j<d;j++)
	{
		*(children_index+j)=key_index(d,i,1,j+1);
	}
	int largest=i,pres_index;
	for(j=0;j<d;j++)
	{
		pres_index=*(children_index+j);
		if(pres_index<n && *(array+pres_index)>*(array+largest))
		{
			largest=pres_index;
		}
	}
	if(largest!=i)
	{
		swap(array+largest,array+i);
		max_heapify(array,n,d,largest);
	}
	free(children_index);
	return;
}

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return;
}

int menu(void)
{
	printf("============MENU============\n\n");
	int choice;
	printf("1. Press 1 to extract maximum element...\n");
	printf("2. Press 2 to insert into the heap ...\n");
	printf("3. Press 3 to increase a key ...\n");
	printf("4. Press 4 to display maximum key ...\n");
	printf("5. Press 5 to display heap...\n");
	printf("6. Press 6 to display array...\n");
	printf("7. Press 7 to exit the program...\n\n");
	printf("Your Choice : ");
	scanf(" %d",&choice);
	printf("\n\n");
	return choice;
}

void array_input(int *array,int n)
{
	int i;
	printf("\n\nThe program will now ask for array elements...\n");
	for(i=0;i<n;i++)
	{
		printf("Enter the %d element : ",i+1);
		scanf(" %d",array+i);
	}
	printf("\n\n");
	return;
}

void array_output(int *array,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",*(array+i));
	}
	printf("\n\n");
	return;
}