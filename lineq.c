#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER 10

int is_int(char* str);

/* lineq: get equation from a linear sequence in the form Tn=a+(n-1)d */
int main (int argc, char* argv[]) {
  int i;              /* index variable */
  int terms[BUFFER];  /* list of terms */
  int n = 0;          /* number of terms */
  char workings = 0;  /* show workings */

  for (i=1; i<argc && n<=BUFFER-1; i++) {  /* check arguments */
    if (is_int(argv[i])) { /* add terms to list */
      terms[n] = atoi(argv[i]);
      n++; continue;
    }
    switch (argv[i][1]){  /* check flags */
      case 'w': workings=1;continue;
      default:
        if (strcmp(argv[i], "--help")==0){  /* help option */
          printf("Usage: lineq [-w show_workings] TERMS\nGet equation from a linear sequence in the form Tn=a+(n-1)d\nExample: lineq -w 13 9 5 1 -3 -7\n"); return 0;
        }
        else {printf("Usage: lineq [-w show_workings] TERMS\nTry 'lineq --help' for more information.\n"); return 1;} /* unknown argument */
    }
  }

  if (n < 2) {printf("error: less than two terms entered\n"); return 1;}  /* stops if less than two terms entered */

  int diff = terms[1] - terms[0]; /* difference between first two terms */
  for (i = 0; i < n-1; i++){
    if (terms[i+1] - terms[i] != diff) { /* checks difference is constant */
      printf("error: difference between terms not constant\n"); return 1;
    }
  }

  if (workings){printf("Tn=a+(n-1)d\nd=%i (difference)\na=%i (starting term)\n", diff, terms[0]);} /* prints workings */

  printf("Tn=%in", diff);
  if (terms[0]-diff != 0) {
    if (terms[0]-diff >= 0){putchar('+');}
    printf("%i", terms[0]-diff);
  }
  printf("\n");
  return 0;
}

/* is_int: checks if a string is an integer */
int is_int(char* str) {
  if (*str == '-' || *str == '+'){str++;}
  while(*str!='\0') {
    if (!isdigit(*str)){return 0;}  /* not an integer*/
    str++;
  }
  return 1; /* is an integer */
}
