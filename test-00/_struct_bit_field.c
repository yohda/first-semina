#include<stdio.h>
/*
	- ����ü ��Ʈ �ʵ� ����
	
	- ����ü ��Ʈ �ʵ� ����
		1. ��Ʈ �ʵ忡 ������ ��Ʈ ����ŭ ����Ǹ� ������ ��Ʈ�� ��������.
		2. ����� Ÿ���� ��Ģ������ ������ �����ϸ�, ��ȣ�� ���ο� ���� unsigned or signed�� �����ϴ�.
		3. ��� Ÿ�Կ� ���� ��Ʈ �ʵ� ��ü�� ũ�Ⱑ �޶�����.
		4. double, array, pointer������ ��Ʈ �ʵ尡 �� �� ����.
		5. ����ü ��ü�� ũ��� ��� ��Ʈ ����� �� ��Ʈ���� ����.
		6. ��Ʈ �ʵ�� register ������ &�����ڸ� ����� �� ����.
		�ֳĸ�, &�� �ּҸ� �ǹ��ϴµ�, �ּҴ� ����Ʈ �����̱� �����̴�.
		7. ����ü ��� ���� �ٸ� �ڷ����� ����� ȥ���ϴ� ���� ������� �ʴ� ��Ʈ�� ���� �� �ִ�.

	- ����ü ��Ʈ �ʵ� ����
		1. �޸𸮸� ������ �� �ִ�.
		2. Ư�� ��Ʈ�� ���� �ֱ� ���ؼ��� ��Ʈ ����, ����Ʈ ������� �ؾ�������,
		����ü �ʵ带 �̿��� ��� ����ü ��� ������ �����ϴ� �͸����� ���� ��Ʈ�� �ٲ� �� �ִ�.

	- ����ü ��Ʈ �ʵ� ����
		
	- ����ü ��Ʈ �ʵ� ��� ���
		1. CPU�� ��Ÿ Ĩ�� �÷��׸� �ٷ�� �������� ���α׷����� �� ��,
		�⺻ �ڷ������� �� ���� ��Ʈ ������ ���� �������ų� �����ϴ� ��찡
		�����Ƿ� ����ü ��Ʈ �ʵ尡 �����ϰ� ���ȴ�.
	 
	- ��ó
	1. https://m.blog.naver.com/PostView.nhn?blogId=ahalinux&logNo=220782717045&proxyReferer=https%3A%2F%2Fwww.google.com%2F
	2. https://dojang.io/mod/page/view.php?id=472
	3. https://lab.cliel.com/entry/C-C-%EB%B9%84%ED%8A%B8%ED%95%84%EB%93%9CBit-Field
	4. http://soen.kr/lecture/ccpp/cpp1/13-4-1.htm
	5. https://goguri.tistory.com/entry/%EB%B9%84%ED%8A%B8-%ED%95%84%EB%93%9C-bit-field
*/

/*
	������ ���� ��Ʈ �ʵ��� �� ����� ������ ��Ʈ(LSB)���� ���ʴ�� ��ġ�ȴ�.
	-------    --------------------------------------------
	|     | ```|           c           |      b     |  a  |
	|     |    |       1111 1111       |     111    |  1  |
	-------    --------------------------------------------
	32    31   11                      4            1     0
	  MSB	                                          LSB	
*/
struct flags_t {
	unsigned int a : 1; // a�� 1��Ʈ ũ��
	unsigned int b : 3; // b�� 3��Ʈ ũ��
	unsigned int c : 7; // c�� 7��Ʈ ũ��
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

// �� 8bit�� ũ�⿡�� 9bit�� �Ҵ��ߴ�.
// unsigned char�� 8bit�̹Ƿ� f�� ������ �� ����.
// �׷��� ó������ a���� e������ 8bit�� ��� �� ���� f�� �ٽ� 8bit������
// Ȯ���� �� ó�� bit�κп� f�� ��� �Ǵ� ���Դϴ�(������ 7bit�� ����˴ϴ�).
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

	printf("a: %u\n", f.a); // 1, 1, ��Ʈ 1���� �����
	printf("b: %u\n", f.b); // 3, 011, ��Ʈ 2���� �����
	printf("c: %u\n", f.c); // 127, 111 1111, ��Ʈ 7���� �����
	
	bit_t b;
	b.a = 0; // 0000 0000 
	b.b = 3; // 0000 0011
	b.c = 2; // 0000 0010
	b.d = 8; // 0000 1000
	
	printf("bit_t = %d byte\n", sizeof(bit_t)); // 1byte
	
	printf("bb.a = %d\n", b.a); // 0, 0, ��Ʈ 1���� �����.
	printf("bb.b = %d\n", b.b); // -1, 1, ��Ʈ 1���� �����.
	printf("bb.c = %d\n", b.c); // 2, 10, ��Ʈ 2���� �����. 
	printf("bb.d = %d\n", b.d); // 0, 00, ��Ʈ 2���� �����.

	printf("bit2_t = %d byte\n", sizeof(bit2_t)); // 

	return 0;
}