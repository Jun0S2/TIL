---
layout: post
title: "C++ Basic Grammar (2)"
date: 2021-12-04 24:00 +0900
categories: C++
---

## cmath Library

```c++
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    cout<<(int)pow(a,b); //a^b
    return 0;
}
```

## continue

In `for` and `while` loop, you can use `continue` keyword to stop processing the current code and go back to next condition

```c++
for(int i =a; i<b; i++){
    code 1
    if(condition1){
        code2
        continue;
    }
    else if (condition2){
        code3
        continue;
    }
    code 4
}
```

In above sample, if the `condition1` was met : code1->code2
If the `condition1`was not met: code1-> check condition2 -> if met :code4 else back to for loop

## break

In `for` and `while` loop, `break` keyword is used to **completely escape from the nearest for loop**. In order to use `break`, you need to use it with condition

```c++
for(int i = a ; i<b ; i++){
    code 1
    if(condition1){
        code2
        break;
    }
    code3;
}
code4;
```

if condition1 was not met : code1 -> code3
if condition1 was met: code 1-> code2 ->`break` : escape nearest for loop -> **code4**
