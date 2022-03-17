---
layout: post
title: "C++ Printing Stars"
date: 2021-12-05 16:22:57 +0900
categories: C++
---

# Output Practices

## Right Triangle

```
*
**
***
****
```

### Rules

When row increases by one -> columns also increases by one

```c++
//i는 0~3까지 돌면 된다(row 증가)
for(int i = 0 ; i<4; i++){
     //j는 0부터 i까지 돌면 된다(row 의 수 만큼 별표 찍기)
    for(int j =0; j<=i;j++)
        cout<<"*";
    }
    cout<<endl;
}
```

## Reversed Right Triangle

```
n=5;

* * * * *
* * * *
* * *
* *
*
```

### Rules

When Row decreases by one -> columns also decreases by one

```c++
#include <iostream>
using namespace std;
int main(){
    //역삼각형
    int n;
    cin>>n;
    for(int i=n ; i>0 ;i--){// 열이 감소함에 따라
    for(int j=i;j>0;j--){
       //행도 열만큼 찍음
       cout<<"* " ;
    }
cout<<"\n";
    }
    return 0;
}
```

## Reversed Right Triangle(2)

```
n=2;
** **
*
n=3;
*** *** ***
** **
*
```

### Rules

1. Print n stars for n columns
2. col--, n--

```c++
for(int i = n ;i>0;i--){ //열이 감소함에 따라
    for(int k=i;k>0;k--){//행도 열만큼 길이
    for(int j= i; j>0;j--){
        cout<<"*";  //열만큼의 개수를 찍고
    }
    cout<<" ";//한칸 띄고
    }
 cout<<"\n";

}

}
```

## Horizontal Symmetry

```
***
**
*
**
***
```

### Rules

1. Upper Half
   - When Row increase, col decrease by one
2. Lower Half
   - When Row increase, col increase by one

int cnt ->

```
i   n=3
0   *** :n=3
-----------------
1   **  :dec
2   *   :dec
3   **  :inc
4   *** :inc
```

Pattern: when i<2 : dec, when i>2 : inc

```c++
int cnt=3;
for(int i=0; i<5; i++){ //cnt*2
    for(int j=0; j<cnt;j++){
        //FirstLine :*** -> after first line, check i(row) and see if its dec/inc
        cout<<"*";
    }
    cout<<endl;
    if(i<2){
        cnt--;
    }
    else{
        cnt++;
    }
}
```

## Right Diamond

```
n=5;
*
* *
* * *
* * * *
* * * * *
* * * *
* * *
* *
*
```

### Rules

1. Upper Half
   -when row increase, col increase
2. Lower Half
   -when row decrease, col decrease

### Pattern

```
i n=5
1   *
2   * *
3   * * *
4   * * * *
5   * * * * *
------------------
6   * * * *
7   * * *
8   * *
9   *
```

- n: for(int i=1;i<n\*2;i++)
- when i==n -> start to decrease

```c++
#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n * 2; i++) { //row
		if (i <= n) {//upper half
			for (int j = 1; j <= i; j++) { //as row increase, col inc
				cout << "* ";
			}
			cout << "\n";
		}
		else { //lower half
			for (int j = 2*n-i; j > 0; j--) { //as row inc, col dec
				cout << "* ";
			}
			cout << "\n";
		}
	}

	return 0;
}

```

## Triangles with whitespace

```
  *
 ***
*****
```

### Rules

```
n=3
i   prints   whitespaces    stars
0   ww*           2           1
1   w***          1           3
2   *****         0           5
```

1. Total stars: row\*2-1
2. whitespaces: n-1, n-2 , ...n -> As row inc, dec
3. stars: 1,n,2n-1

Patterns:

-> whitespaces : 2-i

-> stars : 2\*i +1

```c++
for(int i=0;i<3;i++){
    for(int j=0;j<2-i;j++)cout<<" ";//whitespaces
    for(int j=0;j<2*i+1;j++)cout<<"*";//stars
    cout<<"\n";
}

```

## Reversed Triangle

```
n=5
* * * * * * * * *
  * * * * * * *
    * * * * *
      * * *
        *
```

### Rules

1. first line : 2\*n-1
2. As row inc, i white space is added each end

Patterns:

```
n=5
i   stars
0   9       n*2-1
1   7       n*2-3
2   5       n*2-5
3   3       n*2-7
4   1       n*2-9
```

> stars:2n - 2i-1

```c++
	for (int i = 0; i < n; i++) {
		for (int j = i; j < 2*i; j++) {	//i white spaces are added  at front
			cout << "  ";
		}
		for (int k = 0; k < 2 * n - 2 * i - 1; k++) { //star formula above
			cout << "* ";
		}
		for (int j = i; j < 2 * i; j++) {	//i white spaces are added  at front
			cout << "  ";
		}
		cout << "\n";
	}
```

## Regular Triangle

```
n=3
    *
  * * *
* * * * *
```

### Rules

First, get rid of spaces that are added to stars

We can add whitespace at the very end.

```
i                   whitespace  stars   whitespaces
1    *                  2        1          2
2   ***                 1        3          1
3  *****                0        5          0
```

Formulas:

1. for n times
2. whitespace at front
   - n-- whitespaces
3. stars
   - 2i-1
4. whitespace at end
   - same as #2

```c++
for (int i = 1; i <= n; i++) {
		//whitespace at front
		for (int j= cnt; j > 1; j--) {
			cout << "  ";
		}
		//stars
		for (int k = 0; k < 2 * i - 1; k++) {
			cout << "* ";
		}
		//whitespace at end : cnt-- after when its done
		for (int j = cnt; j > 1; j--) {
			cout << "  ";
		}
			cnt--;
		cout << "\n";
	}
```

## Hourglass

```
n=3
* * * * *
  * * *
    *
  * * *
* * * * *

```

### Rules

1. Remove whitespaces added to stars

```
*****
 ***
  *
 ***
*****
```

Pattern:

```
i whitespace stars
0   0         5         2*n-1
1   1         3         2*n-2
2   2         1         2*n-3
------------------------------------
3   1         3         2*n-2
4   0         5         2*n-1
```

> cnt = 1;

> stars : 2\*n - cnt

1. if(i<=n)
   - stars : cnt--
2. if(i>n)
   -stars : cnt++

```c++
   #include <iostream>
    using namespace std;
    int main() {
	    int n,cnt,wcnt;
        cin >> n;
        cnt = 0;
        wcnt = 0;
        for (int i = 0; i < 2*n-1; i++) {
            if (i <n) {
                cnt++;
            }
            else {
                cnt--;
            }
            //cout << "When i is : " << i << "cnt is : " << cnt<<"\n";
            //whitepsaces: cnt-1 수만큼 찍음
            for (int j = 0; j < cnt - 1; j++) {
                cout << "  ";
            }
            //stars
            for (int j = 0; j <=2 * (n - cnt); j++) {
                cout << "* ";
            }

            cout << "\n";
        }
        system("pause");
        return 0;
}

```

## Diamond

```
n = 2
 *
***
 *

n = 3
  *
 ***
*****
 ***
  *
```

### Rules

1. Remove spaces

```
n=2
i       space   stars
1         1       1
2         0       3
--------------------
1         1       1


n=3
i       space   stars
1         2       1
2         1       3
3         0       5
------------------------
1         1       3
2         2       1
```

1. Upper Half
   - spaces: n-i
   - stars : 2\*i-1
2. Lower Half
   - spaces : i
   - stars : 2\*n-2\*i-1

```c++
#include <iostream>
using namespace std;
int main() {
	int n,cnt,scnt;
	cin >> n;
	cnt = 0;
	scnt = 0;
	//upper
	for (int i = 1; i <= n; i++) {
		cnt = n - i;
		scnt = 2 * i - 1;
		//whitespaces
		for (int j = 0; j < cnt; j++) {
			cout << " ";
		}
		//stars
		for (int j = 0; j < scnt; j++) {
			cout << "*";
		}
		cout << "\n";
	}

	//lower
	for (int i = 1; i < n; i++) {
		cnt = i;
		scnt = 2 * n-2*i-1;
		//whitespaces
		for (int j = 0; j <cnt; j++) {
			cout << " ";
		}
		//stars
		for (int j = 0; j < scnt; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	system("pause");
	return 0;
}


```

## Printing Boxes

```
n=5
i\j  0 1 2 3 4

0    * * * * *
1    *       *
2    *       *
3    *       *
4    * * * * *

for column 0 and 4 -> print stars for n times
for row 0 and row 4 -> print stars for n times
else : print space
```

```c++
for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
        if(i==0 || i==4) cout<<"*";
        if(j==0 || j==4) cout<<"*";
    }
    else cout<<" ";//else blank
    cout<<"\n";
}
```

## Printing Boxes (2)

```
n=1
* * *
*   *
* * *
n=2
* * * * *
*   *   *
* * * * *
*   *   *
* * * * *
```

### Analyze

```
i/j  0 1 2 3 4
 0   * * * * *
 1   *   *   *
 2   * * * * *
 3   *   *   *
 4   * * * * *

 for i=0,2,4 : print * for n times
 for j=0,2,4: print * for n times
 else whitespaces

i/j  0 1 2 3 4 5 6
0    * * * * * * *
1    *   *   *   *
2    * * * * * * *
3    *   *   *   *
4    * * * * * * *
5    *   *   *   *
6    * * * * * * *

for i=0,2,4,6 : print * for n times
for j=0,2,4,6 : print * for n times
else blankspace
```

### Pattern

-> Instead of starting with index0, start with 1 ~ 2*n+1
in odd rows & cols : print * for n times
in even rows & cols : print " "

```c++
    for(int i=1;i<=2*n+1;i++){      //row
        for(int j=1;j<=2*n+1;j++){  //col
            if(i%2==1 || j%2==1){   //odd : print *
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
            cout<<"\n";
    }

```
