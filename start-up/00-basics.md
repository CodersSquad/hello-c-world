---
marp: true
theme: gaia
_class: lead
paginate: true
backgroundColor: #fff
backgroundImage: url('https://marp.app/assets/hero-background.svg')
---

![bg left:40% 80%](https://www.pngkit.com/png/full/101-1010012_c-programming-icon-c-programming-language-logo.png)

# **C Basics**
## This is just the beginning

https://talks.obedmr.com/

---

# `hello.c`

```
 #include <stdio.h>

 main()
 {
 	printf("Hello world \n");
 }
```

---

# GCC, the GNU Compiler Collection

The GNU Compiler Collection includes front ends for C, C++,
Objective-C, Fortran, Ada, Go, and D, as well as libraries for these
languages (libstdc++,...). GCC was originally written as the compiler
for the GNU operating system.

https://gcc.gnu.org/

### Compiling your first program:

```
  cc hello.c -o hello
```

---

# `hello2.c`

```
 #include <stdio.h>

 int main(int argc, char **argv)
 {
 	printf("Hello  %s\n", argv[1]);
 }

```

### Let's run it:

```
 cc hello2.c -o hello2
 ./hello2 Obed
 Hello Obed
```

---

# What if ``./hello2 Obed N Munoz``?


```
 ./hello2 Obed N Munoz
 Hello Obed
```

### Let's fix it on `hello3.c`

---

# Check out  the [``fahrenheit_celsius.c``](src/00/fahrenheit_celsius.c)

```
#include <stdio.h>

#define   LOWER  0       /* lower limit of table */
#define   UPPER  300     /* upper limit */
#define   STEP   20      /* step size */

int main()
{
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
	printf("Fahrenheit: %3d, Celcius: %6.1f\n", fahr, (5.0/9.0)*(fahr-32));

    return 0;
}
```

---

#  Let's Code: `fahrenheit_celsius2.c`

Add support for single and ranged values. Below both cases.

```bash
./fahrenheit_celsius 32
Fahrenheit: 32, Celsius: 0
```

```bash
./fahrenheit_celsius 0 200 10
Fahrenheit:  0, Celsius: -17.77
Fahrenheit: 10, Celsius: -12.22
Fahrenheit: 20, Celsius: -6.66
Fahrenheit: 30, Celsius: -1.11
...
```

---

# Simple Input and Output

Link to source code: [`word_counter.c`](src/00/word_counter.c)

```
#include <stdio.h>

#define IN   1   /* inside a word */
#define OUT  0   /* outside a word */

int main()

{
    int c, nl, nw, nc, state;
    state = OUT;

    nl = nw = nc = 0;
```

---

```
while ((c = getchar()) != EOF) {
	++nc;
	if (c == '\n')
	    ++nl;

	if (c == ' ' || c == '\n' || c == '\t')
	    state = OUT;
	else if (state == OUT) {
	    state = IN;
	    ++nw;
	}
    }

    printf("Lines: %d,  Words: %d, Chars: %d\n", nl, nw, nc);
    return 0;
}
```
---

# Arrays - fixed size - [reverse.c](src/00/reverse.c)

```
 #define ARRAY_LENGHT 10

 int main() {
     int i, tmp, arr[ARRAY_LENGHT];
     srand(time(NULL));

     for (i = 0;  i < ARRAY_LENGHT; i++) {
         arr[i] = rand() % 100;
     }

     for (i = 0;  i < ARRAY_LENGHT/2; i++) {
         tmp = arr[i];
         arr[i] = arr[ARRAY_LENGHT - i - 1];
         arr[ARRAY_LENGHT - i - 1] = tmp;
     }
 }
```

---

# Arrays - as argument - [reverse2.c](src/00/reverse2.c)

```
 void reverse(int arr[ARRAY_LENGHT]) {
     int i, tmp;

     for (i = 0;  i < ARRAY_LENGHT/2; i++) {
         tmp = arr[i];
         arr[i] = arr[ARRAY_LENGHT - i - 1];
         arr[ARRAY_LENGHT - i - 1] = tmp;
     }
 }

 int main() {
     // initialization
     reverse(arr);
     // print results
 }
```

---

# Arrays - as argument - Question

- Why there is not return statement in the `reverse` function?

---

# Arrays - dynamic size - [reverse3.c](src/00/reverse3.c)

```
 void reverse(int lenght, int arr[]) {
     int i, tmp;

     for (i = 0;  i < lenght/2; i++) {
         tmp = arr[i];
         arr[i] = arr[lenght - i - 1];
         arr[lenght - i - 1] = tmp;
     }
 }

 int main(int argc, char **argv) {
     int i, lenght, *arr;
     arr = malloc(sizeof(int) * lenght);
     // initialization
     reverse(lenght, arr);
     // print results
 }


```
---

#  Let's Code: Word Reverser

Follow instructions from:

https://github.com/CodersSquad/c-word-reverser

---

#  Resources
This material was base in some extracts of the following book:

- **The C Programming Language** (chs. 1,2,3,4) - _by_ _Brian_ _W._ _Kernighan_

---

# Thanks

- **Obed N Muñoz Reynoso**
	- Cloud Software Engineer
	- obed.n.munoz@``gmail | tec | intel``.com
