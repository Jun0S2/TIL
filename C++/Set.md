# SET

set 을 사용하기 위해서는  헤더 파일에 

```
#include <set>

set<int>s;

```
을 포함시켜 줘야 한다.

# Insert

set에서 값을 추가하기 위해서는 `s.insert(값)` 을 사용한다.

# Find

find 함수를 사용하기 위해 한참을 해맸다. s.find(값) 과 같은 형식이지만 이터레이터를 사용해야한다.

```cpp
set<int>::iterator iter; //iterator 선언
iter = s.find(값);
if(iter != s.end())
{
  cout<<"found\n";//iterator 위치가 끝까지 돌지 않았다면 찾았다는 뜻이다.
}
else cout<<"not found\n"; //iterator가 끝까지 넘어감 == 없다.
```
