#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complex;

void readComplex(Complex *c) {
    printf("Enter the real part: ");
    scanf("%f", &c->real);
    printf("Enter the imaginary part: ");
    scanf("%f", &c->imag);
}

void writeComplex(Complex c) {
    printf("Complex number: %.2f + %.2fi\n", c.real, c.imag);
}

Complex addComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

Complex multiplyComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    return result;
}

int main() {
    Complex num1, num2, sum, product;

    printf("Enter the first complex number:\n");
    readComplex(&num1);

    printf("\nEnter the second complex number:\n");
    readComplex(&num2);

    printf("\n");
    writeComplex(num1);
    writeComplex(num2);

    // Addition of two complex numbers
    sum = addComplex(num1, num2);
    printf("\nSum of the complex numbers:\n");
    writeComplex(sum);

    // Multiplication of two complex numbers
    product = multiplyComplex(num1, num2);
    printf("\nProduct of the complex numbers:\n");
    writeComplex(product);

    return 0;
}
