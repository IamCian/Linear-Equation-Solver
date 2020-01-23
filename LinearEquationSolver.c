#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
  //Stops if less than two terms are entered
  if (argc < 3) {
    printf("You must enter at least TWO terms!\n");
    return 0;
  }

  //Gets all terms in a list
  short int term = 0; //current term
  short int i; //index variable for loop
  int terms[argc-1]; //terms of the sequence
  for (i = 1; i < argc; i++) {
    term = atoi(argv[i]); //gets value as integer
    printf("%d ", term); //print integer
    terms[i-1] = term; //add to list
  }

  //Gets difference
  int diff = terms[1] - terms[0]; //difference between terms

  //Stops if difference isn't constant
  for (i = 0; i < argc-2; i++){
    if (terms[i+1] - terms[i] != diff) {
      printf("\nThis is not a linear sequence as the first difference is NOT constant!\n");
      return 0;
    }
  }

  //Prints the variables
  printf("\nd = %i (difference)\n", diff); //prints value of D (difference)
  printf("a = %i (starting term)\n", terms[0]); //prints value of A (starting term)

  //Prints the equation
  printf("Tn=%in", diff); //Prints N
  if (terms[0]-diff != 0) {
    if (terms[0]-diff >= 0){printf("+");}
    printf("%i", terms[0]-diff); //prints difference minus the first term
  }

  //Goes to a new line
  printf("\n");

  return 0;
}
