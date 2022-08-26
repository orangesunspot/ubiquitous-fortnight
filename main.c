#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Robin Muller"
#define YEAR 2022

/* NOTE: **************************************************************************************************************** 
It may be necessary to add "-lm" at the end of your compile statement. This will include the libraries in the compilation.
*************************************************************************************************************************/

void Dec2RadixI (int decValue, int radValue) {
    
    // boolean "symBool" indicates whether the specified number system has a symbol (eg. 0onumber for octal, or 0xnumber for hex)
    int symBool = 1, q = decValue, b = radValue;
    char sym;
    switch (b) {
        case 2:
        sym = 'b';
        break;

        case 8:
        sym = 'o';
        break;

        case 16:
        sym = 'x';
        break;

        default:
        symBool = 0;
    }

    //output format
    printf("The radix-%d value is ",b);
    symBool ? printf("0%c", sym) : (0);

    // for special case decValue = 0
    if (q == 0) printf("0");

    else {
        //size of return array
        int s = (int) ceil(log(decValue) / log(radValue) - 1); // using log(x)/log(y) = log base y of x

        char r[s];
        int temp = 0;
        //for (int i = 0; i <= s+1; i++) {
        int i = 0;
        while (q > 0) {
            temp = q % b;
            if (temp < 10) r[i] = temp + 48;
            else r[i] =  temp + 55;
            q = q / b;
            i++; 
        }

        for (int j = i - 1; j >= 0; j--) {
            printf("%c", r[j]);
        }
    }
    
    
    return;
}

int main() {
    //intro
    printf("*****************************\n %s\n Written by: %s\n Date: %d\n*****************************\n", TITLE, AUTHOR, YEAR);
    
    long n;
    int r;
    while(1) {
        //Gather input
        r = 1;
        printf("Enter a decimal number: ");
        scanf("%ld", &n);

        //exit condition:
        if (n == -1) {
            printf("EXIT\n");
            exit(0);
        }

        printf("The number you have entered is %ld\n", n);
        printf("Enter a radix for the converter between 2 and 16: ");
        scanf("%d", &r); 
        printf("The radix you have entered is %d\n", r);
        printf("The log2 of the number is %.2f\n", log2(n));
        printf("The integer result of the number divided by %d is %d\n", r, (int) n/r);
        printf("The remainder is %ld\n", n%r);

        Dec2RadixI(n, r);
        printf("\n\n");
    }

    return 0;

}

