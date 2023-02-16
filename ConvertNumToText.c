#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Write a program to get an integer number and convert to amount text between
// 0..999999 => Nine hundred ninety-nine thousand nine hundred ninety-nine

// I will Create strcat() from Scratch

/*
Read Number From User

============================================================================
Create Function for one(num);
  Create Array1 From 0 To 19
    [
      zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine,
      Ten, Eleven, Twelve, Thirteen, Fourteen, Fifteen, Sixteen,
      Seventeen, Eighteen, Nineteen
    ]

  if(num >= 0 && < 20)
    return array[num];
  else
    return "Wrong Number";

============================================================================
Create Function for ten(num);
  Create Array2 From 20, 30, 40...To 90
    [
      Twenty, Thirty, Fourty, Fifty, Sixty, Seventy, Eightty, Ninety
    ]
  if(num >= 2 && < 10)
    return array[num - 2];
  else
    return "Wrong Number";

============================================================================
Create Function for hundred(num);
  Create Array3 From 100, 200, 300...To 900
      [
        One Hundred, Two Hundred, Three Hundred, Four Hundred, Five Hundred,
        Six Hundred, Seven Hundred, Eight Hundred, Nine Hundred
      ]

    if(num >= 0 && < 20)
      return array[num];
    else
      return "Wrong Number";

============================================================================
Create Function for thousand(string);
  return sring + Thousand

============================================================================
Create Function for handleOneNumbers(num)
  printf("%s", one(num));

============================================================================
Create Function for handleTenNumbers(num)
  one = number / 10;
  ten = number % 10;

  if one > 0
    printf("%s %s", ten(ten), one(one));
  else
    printf("%s", ten(ten));

============================================================================
Create Function for handleHundredNumbers(num)
  one = number / 100;
  ten = number % 100;

  if ten > 0
    printf("%s %s", hundred(one), handleTenNumbers(ten));
  else
    printf("%s", hundred(one));

============================================================================
Create Function for handleThousandNumbers(num)
  one = number / 1000;
  hundred = number % 1000;

  if hundred > 0
    printf("%s %s", thousand(printHundred(one)), handleHundredNumbers(hundred));
  else
    printf("%s", thousand(printHundred(one)));

============================================================================
Create Function for printResult(num)
  if num > -1 && < 20 handleOneNumbers(num)
  else if num < 100 handleTenNumbers(num)
  else if num < 1000 handleHundredNumbers(num)
  else if num < 1000000 handleThousandNumbers(num)
  else printf("The number is Greater Than Or Equal Million");
*/

int readNumber() {
  int num;

  printf("Please Enter a Number: ");
  scanf("%d", &num);

  return num;
}

char *one(int num) {

  char *array[] = {"zero",    "One",     "Two",       "Three",    "Four",
                   "Five",    "Six",     "Seven",     "Eight",    "Nine",
                   "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
                   "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

  if (num >= 0 && num < 20)
    return array[num];
  else
    return "Wrong Number";
}

char *ten(int num) {

  char *array[] = {
      "Twenty", "Thirty",  "Fourty",  "Fifty",
      "Sixty",  "Seventy", "Eightty", "Ninety",
  };

  if (num >= 2 && num < 10)
    return array[num - 2];
  else
    return "Wrong Number";
}

char *hundred(int num) {

  char *array[] = {"One Hundred",   "Two Hundred",   "Three Hundred",
                   "Four Hundred",  "Five Hundred",  "Six Hundred",
                   "Seven Hundred", "Eight Hundred", "Nine Hundred"};

  if (num > 0 && num < 20)
    return array[num - 1];
  else
    return "Wrong Number";
}

char *thousand(char *string) {
  // char thousanWord[] = string;
  char *res;
  res = malloc(strlen(string) + strlen(" Thousand") + 1);

  if (!res) {
    fprintf(stderr, "malloc() failed: insufficient memory!\n");
    return 0;
  }

  strcpy(res, string);
  strcat(res, " Thousand");

  // strcat("string", );
  // printf("%s", res);

  return res;
}

void handleOneNumbers(int num) { printf("%s", one(num)); }

void handleTenNumbers(int num) {
  int oneN = num / 10;
  int tenN = num % 10;

  if (tenN > 0)
    printf("%s %s", ten(oneN), one(tenN));
  else
    printf("%s", ten(oneN));
}

void handleHundredNumbers(int num) {
  int one = num / 100;
  int ten = num % 100;

  if (ten > 0) {
    printf("%s ", hundred(one));
    handleTenNumbers(ten);
  } else
    printf("%s", hundred(one));
}

void handleThousandNumbers(int num) {
  int oneN = num / 1000;
  int hundredN = num % 1000;

  if (hundredN > 0) {
    printf("%s ", thousand(one(oneN)));
    handleHundredNumbers(hundredN);
  } else
    printf("%s", thousand(one(oneN)));
}

void printResult(int num) {
  if (num > -1 && num < 20)
    handleOneNumbers(num);
  else if (num < 100)
    handleTenNumbers(num);
  else if (num < 1000)
    handleHundredNumbers(num);
  else if (num < 1000000)
    handleThousandNumbers(num);
  else
    printf("The number is Greater Than Or Equal Million");
}

int main() {
  printResult(readNumber());
  // thousand("str");

  return 0;
}