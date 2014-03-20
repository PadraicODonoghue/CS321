#include <stdio.h>

// Define a structure representing a complex number
typedef struct comp 
{ 
	float real; 
	float imag; 
} complex; 

// Function that multiplies two complex numbers and returns the answer (a complex number, too)
complex mult(complex a,complex b) 
{ 
	complex c; 
	c.real=a.real*b.real - a.imag*b.imag; 
	c.imag=a.real*b.imag + a.imag*b.real; 
	return c; 
} 

int main() 
{ 
	float real, imaginary;
	complex a, b;
	
	// Get two complex numbers as inputs
	printf("Please enter the first complex number (real imaginary): ");
	scanf("%f%f", &real, &imaginary);
	a.real = real; a.imag = imaginary;
	
	printf("Please enter the second complex number (real imaginary): ");
	scanf("%f%f", &real, &imaginary); 
	b.real = real; b.imag = imaginary;
	
	// Multiply them and print output
	a = mult(a,b); 
	printf("Their product is %f + %fi \n", a.real, a.imag);
	return 0; 
}