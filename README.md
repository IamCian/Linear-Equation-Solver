# Lineq (Linear Sequence)
Gets the Nth term for a linear sequence.

# License
Licensed under the [MIT License](https://github.com/IamCian/lineq/blob/master/LICENSE).
See [https://choosealicense.com/licenses/mit/](https://choosealicense.com/licenses/mit/)

# Usage
```console
$ lineq --help
Usage: lineq [-w show_workings] TERMS
Get the Nth term for a linear sequence
Example: lineq -w 13 9 5 1 -3 -7
$ lineq 13 9 5 1 -3 -7
Tn=-4n+17
$ lineq -w 13 9 5 1 -3 -7
Tn=a+(n-1)d
d=-4 (difference)
a=13 (starting term)
Tn=-4n+17
```

# Installation
Installs to __/usr/local/bin/lineq__ by default
```console
$ git clone https://github.com/IamCian/lineq.git lineq
$ cd lineq
$ make
$ sudo make install
```
**Removal**
```console
sudo make uninstall
```
or
```console
sudo rm /usr/local/bin/lineq
```
