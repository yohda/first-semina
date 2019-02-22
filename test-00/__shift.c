#include<stdio.h>

/*
	- ����Ʈ ���� ����
	- ����Ʈ ���� ����
		1. ��ȣ�� ���� unsigned�� ��� ���ڸ��� ��� 0���� ä������.
		�׸��� ���ڰ� �Ѿ���� 0���� ä������.
		
		2. ��ȣ�� �ְ� ������ ����Ʈ�� ���, ��ȣ ��Ʈ�� ���� ä������.
		�׸��� ��ȣ�� �ְ� ���� ����Ʈ�� ���� ������ ����� �� �� �ְ�, ����� ������ �� �� �ִ�. 
	
	- ����Ʈ ���� ����
		1. ������.

	- ����Ʈ ���� ����
		1. 

	- ����Ʈ ���� ��� ���
		1. Crypto API
		2. Network API

	- ��ó
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

	printf("n1: %u\n", n1 << 3); // 24, 0001 1000(3 * 2�� 3��)
	printf("n2: %u\n", n2 >> 2); // 6, 0000 0110(24 / 2�� 2��) 
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
	printf("n2: %d\n", n2 >> 5); // -4, 1111 1100, ���ڶ�� ������ ��ȣ ��Ʈ�� ���� 1�� ä�����Ƿ� 1111 1100�� ��.
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

	printf("n3: %d\n", n3); // -60, 1100 0100, ��ȣ ��Ʈ�� ����� �ǹǷ� ������� ������ �ȴ�.
	printf("n4: %d\n", n4); // -60, 1100 0100 
	printf("n5: %d\n", n5); // 16, 0001 0000
	printf("n6: %d\n", n6); // 16, 0001 0000, ��ȣ ��Ʈ�� ����� �ǹǷ� �������� ����� �ȴ�.
}