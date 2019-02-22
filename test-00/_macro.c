#include<stdio.h>

/*
	- ��ũ���� ����
	
	- ��ũ���� ����
		1. �ܼ� ġȯ�̱� ������ �ӵ��� ������.
		2. ���������� �������� �����Ѵ�.

	- ��ũ���� ����
		1. Ÿ�� üũ�� ���� �ʱ� ������ ������ ������ ���ɼ��� ������.
		2. namespace�� �����Ѵ�(min/max�� �����ϸ� std::min/max�� �浹�Ѵ�).

	- ��ũ�� # ����
		- �Ű������� ����ȭ�Ѵ�.

	- ��ũ�� ## ����
		- ���ڿ� ��ū���� ���ս�Ų��.

	- ��ũ�ο��� do{}while(0)�� ���� ����
		1. ���������� �Ҵ��� �� �ִ� block�� ���� �� �ִ�.
		2. ���ǹ����� ������ ������ ����� �� �ִ�.

	- ��ũ�� ��Ÿ
		1. 

	- ��ó
	1. https://stackoverflow.com/questions/1772119/the-most-useful-user-made-c-macros-in-gcc-also-c99
	2. 
*/

#define PI 3.141592
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a)) // *a�� �迭 a�� ù��° ����� ���̴�.
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