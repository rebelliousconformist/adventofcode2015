#include <stdio.h>


//
//void fundivya(int *ptr){
//	int temp1 = 17;
//	*ptr = temp1;
//}


void fundivya(int *ptr){
	int temp1 = 17;
	ptr = &temp1;
}


struct abc {
	double a,b,c;
};

int square(int value){

	return value*value;
}

int* squareplusone(int* finalvalue, int* inputvalue){
	static int storage = 0;
	storage = (*inputvalue)*(*inputvalue) +1;
	*finalvalue = storage;
	return &storage;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void addtofirst(int* first,int*second){
	int temp;

	temp = *first + *second;
	*first = temp;
}

void fun(int *p)
{
  static int q = 10;
//  p = &q;
  *p = q;
}

int main(){



	int a = 10;
	int b = 20;
	int c= 30;

//	int *ptr = &a;

	int *ptr  = NULL;
	ptr = &a;

	printf("ptr %p \n ", ptr);
	printf("*ptr %d \n",*ptr);

	ptr = &b;

	printf("ptr %p \n ", ptr);
	printf("b %p \n ", &b);
	printf("*ptr %d \n",*ptr);


	*ptr = c;

	printf("ptr %p \n ", ptr);
	printf("*ptr %d \n",*ptr);
	printf("b %d \n",b);


	fundivya(ptr);

	printf("ptr %p \n ", ptr);
	printf("*ptr %d \n",*ptr);

	printf("b %d \n",b);

	struct abc firststruct = {1,2,33};
	struct abc *ptrstruct = &firststruct;

	printf("struct pointer print %lf \n",*ptrstruct);
	printf("struct pointer print +1 %lf \n",*((double*)ptrstruct +2));


	printf("square of 2 is %d\n", square(2));

	int finval = 0;
	int* finalvalue = &finval;
	int value = 3;
	int * inputvalue = &value;
	int * getvalue = squareplusone(&finval, inputvalue);

	int a  = 20, b= 30;
	swap(&a,&b);
	printf("swap %d %d\n",a,b);

	addtofirst(&a, &b);

	printf("add to first %d \n",a);

	printf("sq + 1 of 7 is %d getvalue \n", *getvalue);
	printf("sq + 1 of 7 is %d finalvalue \n", finval);


	int storageval = 55;
	fun(&storageval);
	printf("the storage val is %d \n",storageval);

	return 0;
}
