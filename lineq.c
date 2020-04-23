#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER 10

int is_int(char* str);

/* lineq: get equation from a linear sequence in the form Tn=a+(n-1)d */
int main (int argc, char* argv[]) {
  int i;              /* index variable */
  int terms[BUFFER];  /* list of terms*/
  int n = 0;          /* number of terms */
  char workings = 0;  /* show workings */

  for (i=1; i<argc && n<=BUFFER-1; i++) {  /* check arguments */
    if (is_int(argv[i])) { /* add terms to list */
      terms[n] = atoi(argv[i]);
      n++;
    }
    else if (argv[i][0] != '-'){ /* non-integers and non-flags*/
      printf("Usage: %s [-w show_workings] TERMS\nTry '%s --help' for more information.\n", argv[0], argv[0]);
      return 1;
    }
    else { /* check flags */
      if (argv[i][1] == 'w'){
        workings = 1;
      }
      if (strcmp(argv[i], "--help")==0){  /* help option */
        printf("Usage: %s [-w show_workings] TERMS\nGet equation from a linear sequence in the form Tn=a+(n-1)d\nExample: %s -w 13 9 5 1 -3 -7\n", argv[0], argv[0]);
        return 0;
      }
    }
  }

  if (n < 2) { /* stop if less than two terms entered */
    printf("error: less than two terms entered\n");
    return 1;
  }

  int diff = terms[1] - terms[0]; /* difference between first two terms */
  for (i = 0; i < n-1; i++){
    if (terms[i+1] - terms[i] != diff) {
      printf("error: difference between terms not constant\n");
      return 1;
    }
  }

  if (workings){  /* prints workings */
    printf("Tn=a+(n-1)d\nd=%i (difference)\na=%i (starting term)\n", diff, terms[0]);
  }

  printf("Tn=%in", diff);
  if (terms[0]-diff != 0) {
    if (terms[0]-diff >= 0){printf("+");}
    printf("%i", terms[0]-diff);
  }
  printf("\n");

  return 0;
}

/* is_int: checks if a string is an integer */
int is_int(char* str) {
  while(*str!='\0') {
    if (!isdigit(*str) && *str!='-' && *str!='+'){
      return 0; /* not an integer*/
    }
    str++;
  }
  return 1; /* is an integer */
}
