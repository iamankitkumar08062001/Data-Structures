#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

//INT_MAX is used as tombstone(marker) when the keys are deleted
//INT_MIN is used to indicate empty position

//linear probe functions
void linear_probe(int **,int);
int linear_search(int **,int);
void delete_key_linear(int **,int);
//quadratic probe functions
void quadratic_probe(int **,int,int,int);
int quadratic_search(int **,int,int,int);
void delete_key_quadratic(int **,int,int,int);
//common functions
int hash_function(int,int);
void menu(int *);
void probe_menu(int *);
void init_hash_table(int **,int);
void print_keys(int **hash_table,int m);

int main()
{
	int choice=0,probe_method_choice,m,*hash_table;
	printf("\n\nEnter the approximate size of the hash table : ");
	scanf(" %d",&m);
	init_hash_table(&hash_table,m);
	probe_menu(&probe_method_choice);
	int c1,c2;
	if(probe_method_choice==2)
	{
		printf("Enter the required values...\n");
		printf("Function is of the form - c1*(x^2) + c2*x\n");
		printf("Enter the value of c1 : ");
		scanf(" %d",&c1);
		printf("Enter the value of c2 : ");
		scanf(" %d",&c2);
		printf("\n");
	}
	while(choice!=5)
	{
		menu(&choice);
		switch(choice)
		{
			case 1: if(probe_method_choice==1)
					{
						linear_probe(&hash_table,m);
					}
					else
					{
						quadratic_probe(&hash_table,m,c1,c2);
					}
					break;
			case 2: if(probe_method_choice==1)
					{
						linear_search(&hash_table,m);
					}
					else
					{
						quadratic_search(&hash_table,m,c1,c2);
					}
					break;
			case 3: if(probe_method_choice==1)
					{
						delete_key_linear(&hash_table,m);
					}
					else
					{
						delete_key_quadratic(&hash_table,m,c1,c2);
					}
					break;
			case 4: print_keys(&hash_table,m);
					break;
			case 5: printf("THANK YOU FOR USING MY PROGRAM...\n\n");
					break;
			default:printf("\nINVALID CHOICE!!!");
					break;
		}
	}
	free(hash_table);
	return 0;
}

void menu(int *choice)
{
	printf("\n\n******************** MENU ********************\n");
	printf("The Serial number corresponds to the option\n\n");
	printf("1. Do you want to insert any key ?\n");
	printf("2. Do you want to search any key ?\n");
	printf("3. Do you want to delete any key ?\n");
	printf("4. Do you want to print all keys ?\n");
	printf("5. Do you want to exit the program ?\n\n");
	printf("Your Choice : ");
	scanf(" %d",choice);
	printf("\n");
	return;
}

void probe_menu(int *choice)
{
	printf("\n\n******************** PROBE METHOD MENU ********************\n");
	printf("Which probe method do you want to use ? \n");
	printf("The Serial number corresponds to the option\n\n");
	printf("1. Linear Probing\n");
	printf("2. Quadratic Probing\n\n");
	printf("Your Choice : ");
	scanf(" %d",choice);
	printf("\n");
	return;
}

//linear probe function definations

void linear_probe(int **hash_table,int m)
{
	int key;
	printf("INSERTING KEY...\n\n");
	printf("Enter the key(data) : ");
	scanf(" %d",&key);
	int i=0,init_pos,offset;
	init_pos=hash_function(key,m);
	offset=(init_pos+i)%m;
	while(*((*hash_table)+offset)!=INT_MIN && *((*hash_table)+offset)!=INT_MAX && i<m)
	{
		i++;
		offset=(init_pos+i)%m;
	}
	if(i!=m)
	{
		*((*hash_table)+offset)=key;
		printf("\nKEY INSERTED SUCCESSFULLY...\n\n");
	}
	else
	{
		printf("HASH TABLE OVERFLOW!!!");
	}
	return;
}

int linear_search(int **hash_table,int m)
{
	int key;
	printf("\nEnter the key which you want to search/delete : ");
	scanf(" %d",&key);
	printf("\nSEARCHING KEY...\n\n");
	int offset,init_pos,i=0;
	init_pos=hash_function(key,m);
	offset=(init_pos+i)%m;
	while(*((*hash_table)+offset)!=INT_MIN && i<m)
	{
		if(*((*hash_table)+offset)==key)
		{
			printf("The given key exists!!!");
			printf("\n\nKEY SEARCHED SUCCESSFULLY...");
			return offset;
		}
		i++;
		offset=(init_pos+i)%m;
	}
	printf("The given key does not exist!!!");
	return INT_MIN;
}

void delete_key_linear(int **hash_table,int m)
{
	int offset;
	offset=linear_search(hash_table,m);
	if(offset==INT_MIN)
	{
		printf("\nERROR!!!");
	}
	else
	{
		printf("\nDELETING KEY...\n");
		*((*hash_table)+offset)=INT_MAX;
		printf("\nKEY DELETED SUCCESSFULLY...\n");
	}
	return;
}

//quadratic probe function definations

void quadratic_probe(int **hash_table,int m,int c1,int c2)
{
	int key;
	printf("INSERTING KEY...\n\n");
	printf("Enter the key(data) : ");
	scanf(" %d",&key);
	int i=0,init_pos,offset;
	init_pos=hash_function(key,m);
	offset=(init_pos+(c1*(int)pow(i,2))+(c2*i))%m;
	while(*((*hash_table)+offset)==INT_MIN && *((*hash_table)+offset)!=INT_MAX && i<m)
	{
		i++;
		offset=(init_pos+(c1*(int)pow(i,2))+(c2*i))%m;
	}
	if(i!=m)
	{
		*((*hash_table)+offset)=key;
		printf("\nKEY INSERTED SUCCESSFULLY...\n\n");
	}
	else
	{
		printf("HASH TABLE OVERFLOW!!!");
	}
	return;
}

int quadratic_search(int **hash_table,int m,int c1,int c2)
{
	int key;
	printf("\nEnter the key which you want to search/delete : ");
	scanf(" %d",&key);
	printf("\nSEARCHING KEY...\n\n");
	int offset,init_pos,i=0;
	init_pos=hash_function(key,m);
	offset=(init_pos+(c1*(int)pow(i,2))+(c2*i))%m;
	while(*((*hash_table)+offset)!=INT_MIN && i<m)
	{
		if(*((*hash_table)+offset)==key)
		{
			printf("The given key exists!!!");
			printf("\n\nKEY SEARCHED SUCCESSFULLY...");
			return offset;
		}
		i++;
		offset=(init_pos+(c1*(int)pow(i,2))+(c2*i))%m;
	}
	printf("The given key does not exists!!!");
	return INT_MIN;
}

void delete_key_quadratic(int **hash_table,int m,int c1,int c2)
{
	int offset;
	offset=quadratic_search(hash_table,m,c1,c2);
	if(offset==INT_MIN)
	{
		printf("\nERROR!!!");
	}
	else
	{
		printf("\nDELETING KEY...\n");
		*((*hash_table)+offset)=INT_MAX;
		printf("\nKEY DELETED SUCCESSFULLY...\n");
	}
	return;
}

void init_hash_table(int **hash_table,int m)
{
	(*hash_table)=(int *)malloc(sizeof(int)*m);
	int i;
	for(i=0;i<m;i++)
	{
		*((*hash_table)+i)=INT_MIN;
	}
	return;
}

int hash_function(int key,int m)
{
	return key%m;
}

void print_keys(int **hash_table,int m)
{
	int i;
	printf("PRINTING KEYS...\n\n");
	for(i=0;i<m;i++)
	{
		if(*((*hash_table)+i)==INT_MIN || *((*hash_table)+i)==INT_MAX)
		{
			continue;
		}
		else
		{
			printf("%d ",*((*hash_table)+i));
		}
	}
	printf("\n\nKEYS PRINTED SUCCESSFULLY...");
	return;
}














