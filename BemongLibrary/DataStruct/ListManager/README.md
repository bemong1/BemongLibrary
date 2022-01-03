# ListManager

* STL에서 Key, Value를 다루는(map, unorded_map 등) 클래스에 존재하지 않는 기능들을 추가한 클래스

  * Key값 기준의 정렬 지원

  * Multy Key( ex <int, int>, <int, string> 등 ) 지원
    * 특정 Key를 기준으로 정렬 가능
    * Key의 중복 유무 체크 가능
  * Multithread 환경에서 동시 접근 가능

## Environmemt
* C++14 이상

## Using
1. 선언
    ```c++
    #include "ListManager.h"
    
    bemong::vector::ListManager<int, int> foo; 
    ```
2. 상속
    ```c++
    #include "ListManager.h"
    
    class Foo : public ListManager<int, int>
    {
      Blah Blah...
    }
    ```
