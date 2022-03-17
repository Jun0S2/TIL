---
layout: post
title: "C++ Basic Grammar(1)"
date: 2021-12-03 16:22:57 +0900
categories: C++
---

## Basic Format

```c++
#include <iostream>
using namespace std;
int main(){
    return 0;
}
```

- `#include <iostream>` : `#include <stdio.h>` in C

* `using namespace std`:
  To get input and print output, `std::` is needed as prefix
  ```c++
  std::cout<<"hello C++";
  ```
  However, by using `using namespace std` we can skip writing `std::` inside the code.
  Thus,
  ```c++
  cout<<"Good Bye std::";
  ```
  it gets much simpler.

- `;` is a must !
  Unlike python and js, semicolon is necessary and will yell at you if you don't include it.

## Variables

> int, longlong, double, char, **string**, bool

Unlike C, we can use string types by including `#include <string>` at the header.

```c++
#include <iostream>
#include <string>
int main(){
    ...
}
```

!!Note!! : Unlike Java, string is written int **small case !**

## Input and Output

### printf

```c
printf(%d %d);
```

is available-however- cin and cout is used in c++ to get input and print output

### cin & cout

```c++
int n;
cin>>n;
cout<<n;
```

In order to not confuse the arrow directions:

1. Input : you are **injecting input to n(variable)**
   Thus, the arrow is going **into** n(variable) `cin>>n`
2. Output : you are **injecting variable to output**
   Thus, the arrow is going **into** output `cout<<n`

### multiple input

Multiple input can be received :

```c++
int a,b,c;
cin>>a>>b>>c;
```

C++ reads input and **seperate with white space**
Therefore,
if the input is either

```
12 3 45
```

or

```
12
3
45
```

You can still use

```c++
cin>>a>>b>>c;
```

to receive all the input

### cin.get()

By using `cin.get()` , you can avoid saving unnecessary input to a variable.
So it's like using `br.readlin();` or `sc.next();` in Java for unwanted input

### multiple output using cout

```c++
cout<<"hello"<<" "<<100<<"\n";
cout<<a<<endl;
```

!!Note!! "\n" is much preferred than using endl in algorithm problems to shorten the runtime

## Precision

### %.nf

```c
double n = 0.5464849;
printf("%.3f",n); //0.546
```

In C++, above is available to print out precision of the double variables.
It is easy to remeber if you think of this way:
You are displaying 3 digits after `.` in float

However, C++ also allows you to use `precision(n)`

### precision(n)

```c++
double n = 0.4546523;
cout<<fixed;
cout.precision(3);
cout<<n; //0.455
```

I prefer the former format but I guess precision keyword is more strict forward to understand.
