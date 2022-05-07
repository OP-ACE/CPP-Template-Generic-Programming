// // C program to illustrate the concept of
// // returning pointer from a function
// #include <stdio.h>

// // Function returning pointer
// int* fun()
// {
// 	int A = 10;
// 	return (&A);
// }

// // Driver Code
// int main()
// {
// 	// Declare a pointer
// 	int* p;

// 	// Function call
// 	p = fun();

// 	printf("%p\n", p);
// 	printf("%d\n", *p);
// 	return 0;
// }

//!------------------------------------------------------------------

// C program to illustrate the concept of
// returning pointer from a function

#include <stdio.h>

// Function that returns pointer
int* fun()
{
	// Declare a static integer
	static int A = 10;
	return (&A);
}

// Driver Code
int main()
{
	// Declare a pointer
	int* p;

	// Function call
	p = fun();

	// Print Address
	printf("%p\n", p);

	// Print value at the above address
	printf("%d\n", *p);
	return 0;
}
