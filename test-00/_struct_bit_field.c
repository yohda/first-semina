#include<stdio.h>
/*
	- 구조체 비트 필드 정의
	
	- 구조체 비트 필드 내용
		1. 비트 필드에 지정한 비트 수만큼 저장되며 나머지 비트는 버려진다.
		2. 멤버의 타입은 원칙적으로 정수만 가능하며, 부호의 여부에 따라 unsigned or signed가 가능하다.
		3. 멤버 타입에 따라 비트 필드 전체의 크기가 달라진다.
		4. double, array, pointer따위는 비트 필드가 될 수 없다.
		5. 구조체 자체의 크기는 모든 비트 멤버의 총 비트수와 같다.
		6. 비트 필드와 register 변수는 &연산자를 사용할 수 없다.
		왜냐면, &는 주소를 의미하는데, 주소는 바이트 단위이기 때문이다.
		7. 구조체 멤버 내에 다른 자료형의 멤버가 혼재하는 경우는 사용하지 않는 비트가 생길 수 있다.

	- 구조체 비트 필드 장점
		1. 메모리를 절약할 수 있다.
		2. 특정 비트에 값을 넣기 위해서는 비트 연산, 쉬프트 연산등을 해야하지만,
		구조체 필드를 이용할 경우 구조체 멤버 변수에 접근하는 것만으로 쉽게 비트를 바꿀 수 있다.

	- 구조체 비트 필드 단점
		
	- 구조체 비트 필드 사용 사례
		1. CPU나 기타 칩의 플래그를 다루는 저수준의 프로그래밍을 할 때,
		기본 자료형보다 더 작은 비트 단위로 값을 가져오거나 저장하는 경우가
		많으므로 구조체 비트 필드가 유용하게 사용된다.
	 
	- 출처
	1. https://m.blog.naver.com/PostView.nhn?blogId=ahalinux&logNo=220782717045&proxyReferer=https%3A%2F%2Fwww.google.com%2F
	2. https://dojang.io/mod/page/view.php?id=472
	3. https://lab.cliel.com/entry/C-C-%EB%B9%84%ED%8A%B8%ED%95%84%EB%93%9CBit-Field
	4. http://soen.kr/lecture/ccpp/cpp1/13-4-1.htm
	5. https://goguri.tistory.com/entry/%EB%B9%84%ED%8A%B8-%ED%95%84%EB%93%9C-bit-field
*/

/*
	다음과 같이 비트 필드의 각 멤버는 최하위 비트(LSB)부터 차례대로 배치된다.
	-------    --------------------------------------------
	|     | ```|           c           |      b     |  a  |
	|     |    |       1111 1111       |     111    |  1  |
	-------    --------------------------------------------
	32    31   11                      4            1     0
	  MSB	                                          LSB	
*/
struct flags_t {
	unsigned int a : 1; // a는 1비트 크기
	unsigned int b : 3; // b는 3비트 크기
	unsigned int c : 7; // c는 7비트 크기
};

typedef struct _bit_t {
	unsigned char a : 1; // 0(0), 1(1)
	signed char b : 1;   // -1(1), 0(0) 
	unsigned char c : 2; // 0(00), 1(01), 2(10), 3(11)
	signed char d : 2;   // -2(10), -1(11), 0(00), 1(01)
}bit_t;

typedef struct _bit2_t {
	unsigned int a : 2;
	unsigned int c : 8;
}bit2_t;

// 총 8bit인 크기에서 9bit를 할당했다.
// unsigned char는 8bit이므로 f를 수용할 수 없다.
// 그러나 처음부터 a부터 e까지는 8bit에 담고 그 다음 f를 다시 8bit영역을
// 확보한 후 처음 bit부분에 f를 담게 되는 것입니다(나머지 7bit는 낭비됩니다).
typedef struct _bit3_t {
	unsigned char a : 2;
	unsigned char b : 3;
	unsigned char c : 1;
	unsigned char d : 1;
	unsigned char e : 1;
	unsigned char f : 1;
}bit3_t;

int main(int argc, char** args)
{
	struct flags_t f;

	f.a = 1;   // 0000 0001
	f.b = 11;  // 0000 1011
	f.c = 255; // 1111 1111

	printf("a: %u\n", f.a); // 1, 1, 비트 1개만 저장됨
	printf("b: %u\n", f.b); // 3, 011, 비트 2개만 저장됨
	printf("c: %u\n", f.c); // 127, 111 1111, 비트 7개만 저장됨
	
	bit_t b;
	b.a = 0; // 0000 0000 
	b.b = 3; // 0000 0011
	b.c = 2; // 0000 0010
	b.d = 8; // 0000 1000
	
	printf("bit_t = %d byte\n", sizeof(bit_t)); // 1byte
	
	printf("bb.a = %d\n", b.a); // 0, 0, 비트 1개만 저장됨.
	printf("bb.b = %d\n", b.b); // -1, 1, 비트 1개만 저장됨.
	printf("bb.c = %d\n", b.c); // 2, 10, 비트 2개만 저장됨. 
	printf("bb.d = %d\n", b.d); // 0, 00, 비트 2개만 저장됨.

	printf("bit2_t = %d byte\n", sizeof(bit2_t)); // 

	return 0;
}