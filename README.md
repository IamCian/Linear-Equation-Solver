# Lineq
Gets an equation from a linear sequence in the form Tn=a+(n-1)d.

# Usage
```console
$ lineq --help
Usage: lineq [-w show_workings] TERMS
Get equation from a linear sequence in the form Tn=a+(n-1)d
Example: lineq -w 13 9 5 1 -3 -7
$ lineq 13 9 5 1 -3 -7
Tn=-4n+17
$ lineq -w 13 9 5 1 -3 -7
Tn=a+(n-1)d
d=-4 (difference)
a=13 (starting term)
Tn=-4n+17
```
