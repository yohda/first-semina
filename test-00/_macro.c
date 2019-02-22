#include<stdio.h>

/*
	- 매크로의 정의
	
	- 매크로의 장점
		1. 단순 치환이기 때문에 속도가 빠르다.
		2. 유지보수에 유연성을 제공한다.

	- 매크로의 단점
		1. 타입 체크를 하지 않기 때문에 잠재적 에러의 가능성을 가진다.
		2. namespace를 무시한다(min/max를 정의하면 std::min/max와 충돌한다).

	- 매크로 # 연산
		- 매개변수를 문자화한다.

	- 매크로 ## 연산
		- 문자열 토큰들을 결합시킨다.

	- 매크로에서 do{}while(0)을 쓰는 이유
		1. 지역변수를 할당할 수 있는 block을 만들 수 있다.
		2. 조건문에서 복잡한 문장을 사용할 수 있다.

	- 매크로 기타
		1. 

	- 출처
	1. https://stackoverflow.com/questions/1772119/the-most-useful-user-made-c-macros-in-gcc-also-c99
	2. 
*/

#define PI 3.141592
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a)) // *a는 배열 a의 첫번째 요소의 값이다.
#define MAX(a,b)   (((a) > (b)) ? (a) : (b))
#define MIN(a,b)   (((a) > (b)) ? (b) : (a))
#define ABS(a)	   (((a) > 0) ? (a) : -(a))
#define SQUARE(x)  (((x) * (x))) 
#define UPCASE(x)  (((x) >= 'a' && (x) <= 'z') ? ((x) - ('a' - 'A')) : (x))
#define LOWCASE(x) (((x) >= 'A' && (x) <= 'Z') ? ((x) + ('a' - 'A')) : (x))
#define STRING(s) #s
#define CONCAT(x,n) x##n

#define SWAP(a,b,T) do {T t = a, a = b, b = t} while(0)
#define COMPARE(a,b) ((a) > (b)) - ((a) < (b))
#define SIGN(a) COMPARE(a, 0)
#define SORT2(a, b, T) do { if ((a) > (b)) SWAP((a), (b), T); } while (0)

#define ZERO1(a) memset((a),0, sizeof(a))
#define SET(d, n, v) do{ size_t i_, n_; for (n_ = (n), i_ = 0; n_ > 0; --n_, ++i_) (d)[i_] = (v); } while(0)
#define ZERO2(d, n) SET(d, n, 0)

int main(int argc, char** argv)
{
	int arr[5] = { 1,2,3,4,5 };
	printf("%d\n", *arr);
	printf("array size: %d\n", ARRAY_SIZE(arr));
	printf("MAX(%d, %d): %d\n", 10, 3, MAX(10, 3));
	printf("MIN(%d, %d): %d\n", 10, 3, MIN(10, 3));
	printf("ABS(%d): %d\n", 3-44, ABS(3-44));
	printf("SQUARE(%d): %d\n", 10, SQUARE(10));
	printf("UPCASE(%c): %c\n", 'c', UPCASE('c'));
	printf("LOWCASE(%c): %c\n", 'C', LOWCASE('C'));
	puts(CONCAT(STRING(My name is), STRING(Yun,yohan)));

	return 0;
}