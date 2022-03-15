---
marp: true
theme: gaia
_class: lead
paginate: true
backgroundColor: #fff
backgroundImage: url('https://marp.app/assets/hero-background.svg')

---

![bg left:40% 80%](https://www.pngkit.com/png/full/101-1010012_c-programming-icon-c-programming-language-logo.png)

# **Linking in C**
## Add external functionality

https://talks.obedmr.com/


---

## Let's start with a simple one


[lib.c](./src/03/lib.c)
```
int add(int a, int b) {
    return a + b;
}
```

[static-linking.c](./src/03/static-linking.c)
```
int add(int, int);
int main() {
  printf("2+3=%d\n", add(2,3));
  return 0;
}
```

---

# Ok, but how to `link` it?

```
gcc -c static-linking.c -o static-linking.o
gcc -c lib.c -o lib.o
gcc static-linking.o lib.o -o linked
```

It Works!
```
./linked
2+3=5
```

---

# Let's analyze the linking symbols

`nm linked`
```
                  U _add
0000000000000000 T _main
                  U _printf
```
`nm lib.o`
```
0000000000000000 T _add
```

Compile, link and run [static-linking2.c](src/03/static-linking2.c), what happened?

---

# Shared or Dynamic Linking

`ldd $(which emacs)`
```
 linux-vdso.so.1 (0x00007fff725cf000)
 libtiff.so.5 => /usr/lib/libtiff.so.5 (0x00007f46288be000)
 libjpeg.so.8 => /usr/lib/libjpeg.so.8 (0x00007f4628829000)
 libpng16.so.16 => /usr/lib/libpng16.so.16 (0x00007f46287f1000)
 libgif.so.7 => /usr/lib/libgif.so.7 (0x00007f46287e6000)
 libXpm.so.4 => /usr/lib/libXpm.so.4 (0x00007f46287d2000)
 .
 .
 .
```
_Take a look on [ldconfig](http://man7.org/linux/man-pages/man8/ldconfig.8.html][ldconfig) tool and common shared library_


---

# C Standard Library
- Input and output: `<stdio.h>`
- Character Class Tests: `<ctype.h>`
- String Functions: `<string.h>`
- Mathematical Functions: `<math.h>`
- Utility functions: `<stdlib.h>`
- Diagnostics: `<assert.h>`
- Variable argument lists: `<stdarg.h>`
- Non-local jumps: `<setjmp.h>`
- Signals: `<signal.h>`
- Date and Time functions: `<time.h>`
- Implementation-defined limits: `<limits.h>` and `<float.h>`

<style scoped>
ul { columns: 2; }
</style>
---

# Let's code: Strings Manipulation library

- Follow instructions from:

[[http://classify.obedmr.com/get-lab/ap-labs/str-lib]]


---

# Resources and Credits
This material is genereated thanks to some extracts from following resources:

- The C Programming Language - _Brian_ _W._ _Kernighan_
- [What is static linking in C?](https://jameshfisher.com/2017/08/26/static-linking.html) - _James_ _H._ _Fisher_


---

# Thanks

- **Obed N Muñoz Reynoso**
	- Cloud Software Engineer
	- obed.n.munoz@``gmail | tec | intel``.com
