#include<stdio.h>

/*
	- 쉬프트 연산 정의
	- 쉬프트 연산 내용
		1. 부호가 없는 unsigned의 경우 빈자리는 모두 0으로 채워진다.
		그리고 숫자가 넘어가더라도 0으로 채워진다.
		
		2. 부호가 있고 오른쪽 시프트인 경우, 부호 비트를 따라 채워진다.
		그리고 부호가 있고 왼쪽 시프트인 경우는 음수가 양수도 될 수 있고, 양수가 음수도 될 수 있다. 
	
	- 쉬프트 연산 장점
		1. 빠르다.

	- 쉬프트 연산 단점
		1. 

	- 쉬프트 연산 사용 사례
		1. Crypto API
		2. Network API

	- 출처
	1. https://dojang.io/mod/page/view.php?id=174
	2. https://dojang.io/mod/page/view.php?id=183
*/

inline void test1();
inline void test2();
inline void test3();
inline void test4();

int main(int argc, char** argv)
{
	test1();
	test2();
	test3();
	test4();
	
	return 0;
}

inline void test1()
{
	unsigned char n1 = 3;  // 0000 0011 
	unsigned char n2 = 24; // 0001 1000

	printf("n1: %u\n", n1 << 3); // 24, 0001 1000(3 * 2의 3승)
	printf("n2: %u\n", n2 >> 2); // 6, 0000 0110(24 / 2의 2승) 
}

inline void test2()
{
	unsigned char n1 = 240; // 240, 1111 0000
	unsigned char n2 = 15;  // 15, 0000 1111

	printf("n1: %u\n", n1 << 2); // 192, 1100 0000
	printf("n2: %u\n", n2 >> 2); // 3, 0000 0011
}

inline void test3()
{
	unsigned char n1 = 131; // 131, 1000 0011
	char n2 = -125;			// -125, 1000 0011

	printf("n1: %u\n", n1 >> 5); // 4, 0000 0100
	printf("n2: %d\n", n2 >> 5); // -4, 1111 1100, 모자라는 공간은 부호 비트의 값인 1로 채워지므로 1111 1100이 됨.
}

inline void test4()
{
	char n1 = 113; // 113, 0111 0001
	char n2 = -15; // -15, 1111 0001
	char n3, n4, n5, n6;

	n3 = n1 << 2;
	n4 = n2 << 2;
	
	n5 = n1 << 4;
	n6 = n2 << 4;

	printf("n3: %d\n", n3); // -60, 1100 0100, 부호 비트를 덮어쓰게 되므로 양수에서 음수가 된다.
	printf("n4: %d\n", n4); // -60, 1100 0100 
	printf("n5: %d\n", n5); // 16, 0001 0000
	printf("n6: %d\n", n6); // 16, 0001 0000, 부호 비트를 덮어쓰게 되므로 음수에서 양수가 된다.
}