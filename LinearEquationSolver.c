#include <stdio.h>

int main () {
  printf("Please type the linear sequence with a space in-between each term and then press enter\n");
  printf("Please enter at least two terms\n");
  printf("(The program will only use the first 10 terms!)\n\n");

  //Gets all terms in a list
  char c; //user input
  int term = 0; //current term
  int new = 0; //are they on a new number
  int len = 0; //length of the sequence
  int terms[9]; //terms of the sequence
  while (len < 9) {
    c = getchar();
    if (c>='0' && c<='9') { //if integer
      putchar(c);
      term = (term * 10) + (c - '0');
      new = 1;
    }
    if (c==' ' && new==1) { //if new number
      printf(", ");
      terms[len] = term;
      term = 0;
      new = 0;
      len++;
    }
    if (c=='\n') { //if enter pressed
      terms[len] = term;
      term = 0;
      new = 0;
      len++;
      break;
    }
  }

  //Stops if less than two terms are entered
  if (len <= 1) {
    printf("\nYou must enter at least TWO terms!\n");
    return 0;
  }

  //Gets difference
  int diff = terms[1] - terms[0]; //difference between terms

  //Stops if it's not linear
  int i;
  for (i = 0; i < len-1; i++){
    if (terms[i+1] - terms[i] != diff) {
      printf("\nThis is not a linear sequence as the first difference is NOT constant!\n");
      return 0;
    }
  }

  //Prints the variables
  printf("\nd = %i\n", diff); //prints value of D (difference)
  printf("a = %i\n", terms[0]); //prints value of A (starting term)

  //Gets the number to subtract N by
  int sub = diff - terms[0];

  //Prints the expression for the Nth term
  if (sub == 0) {
    printf("Tn = %in", diff);
  }
  if (sub < 0) {
    printf("Tn = %in+%i", diff, -1*sub);
  }
  if (sub > 0) {
    printf("Tn = %in-%i", diff, sub);
  }

  //Goes to a new line
  printf("\n");

  return 0;
}
