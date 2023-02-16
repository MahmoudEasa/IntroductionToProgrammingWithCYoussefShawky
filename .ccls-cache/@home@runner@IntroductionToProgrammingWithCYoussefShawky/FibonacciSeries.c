// #include <stdio.h>

// int readNumOfFibonacciSeries() {
//   int num;

//   printf("Please Enter The Number Of Fibonacci Series: ");
//   scanf("%d", &num);

//   return num;
// }

// void printFibonacciSeries(int numOfFibonacci, int *f1, int *f2) {
//   int f = *f1 + *f2;

//   if (numOfFibonacci > 0) {
//     printf("%d\n", f);

//     printFibonacciSeries(numOfFibonacci - 1, f2, &f);
//   }
// }

// int main() {
//   int f1 = -1, f2 = 1;
//   int numOfFibonacci = readNumOfFibonacciSeries();

//   printFibonacciSeries(numOfFibonacci, &f1, &f2);

//   // do {
//   //   f = f1 + f2;
//   //   f1 = f2;
//   //   f2 = f;
//   //   printf("%d\n", f);
//   //   num--;
//   // } while (num > 0);

//   // for (int i = 0; i < num; i++) {
//   //   f = f1 + f2;
//   //   printf("%d\n", f);

//   //   f1 = f2;
//   //   f2 = f;
//   // }

//   return 0;
// }
