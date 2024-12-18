#include <stdio.h>
// Recursive function to calculate factorial
int factorial(int n) {
    printf("Entering factorial(%d)\n", n); // Show the current function call (state of the stack)
    // Base case: if n is 0, return 1
    if (n == 0) {
        printf("Returning 1 from factorial(0)\n"); // Base case return
        return 1;
    }
    // Recursive case: n * factorial(n-1)
    int result = n * factorial(n - 1);
    // After recursion, show the return state
    printf("Returning %d from factorial(%d)\n", result, n);
    return result;
   }int main() {
 int num;
// Input: number to calculate factorial
    printf("Enter a number: ");
    scanf("%d", &num);
   // Call the factorial function and display the result
    int result = factorial(num);
    printf("The factorial of %d is %d\n", num, result);
   return 0;}
