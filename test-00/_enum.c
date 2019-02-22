#include<stdio.h>

/*
	- enum�� ����
	1. enum�� ������ �ƴ϶� ���� �����̴�.

	enum�� ����.
	1. �ҽ��� �������� ���δ�.
	
	-��ó
	1. https://cpattern.tistory.com/12?category=566640
	2. https://www.programiz.com/c-programming/c-enumeration
*/

typedef enum {
	FALSE = 0,
	TRUE
}Bool;

enum _power { OFF = 0, ON };

typedef enum _power Power;

typedef enum {
	LOW = 0,
	HIGH,
}Switch;

/*
	OR ������� Ȱ���Ͽ� �������� ���¸� ������ �� �ִ�.
*/
typedef enum {
	BOLD = 1,
	ITALICS = 2,
	UNDERLINE = 4,
};

int main(int argc, char** argv)
{
	int _ts = BOLD | UNDERLINE;
	printf("0x%08X\n", _ts); // %08X�� ���� �� �ڸ� 8���� 0���� ä���, ���� ��½� �빮�ڸ� ��½�Ų��.

	return 0;
}