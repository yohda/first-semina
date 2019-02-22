#include<stdio.h>

/*
	- enum의 정의
	1. enum은 변수가 아니라 값의 정의이다.

	enum의 장점.
	1. 소스의 가독성을 높인다.
	
	-출처
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
	OR 연산들을 활용하여 여러개의 상태를 저장할 수 있다.
*/
typedef enum {
	BOLD = 1,
	ITALICS = 2,
	UNDERLINE = 4,
};

int main(int argc, char** argv)
{
	int _ts = BOLD | UNDERLINE;
	printf("0x%08X\n", _ts); // %08X는 앞의 빈 자리 8개를 0으로 채우고, 문자 출력시 대문자를 출력시킨다.

	return 0;
}