#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

typedef enum _Boolean {
	FALSE, TRUE
}Boolean;
/*
	- 쇼트 서킷 정의
		1. C의 논리 연산자는 속도 향상과 안전을 위해 불필요한 연산은 하지 않는다.

	- 쇼트 서킷 내용
		1. &&연산자의 경우 앞에 식이 거짓이라면, 뒤에 식은 실행되지 않는다.
		2. ||연산의 경우 앞에 식이 참이면, 뒤에 식은 검사도 안하고 참이 된다.
	
	- 쇼트 서킷 장점
		1. 실행 속도를 높일 수 있다.
		2. 코드의 안전성이 높아진다.
			- if(a != 0 && b/a == 3) a가 0이 아닐 경우에 뒤의 식을 실행한다.

	- 쇼트 서킷 단점
		1. 디버깅이 어려울 수 있다.
	
	- 쇼트 서킷 사용 사례
	
	- 출처
	1. 독하게 시작하는 c 프로그래밍/최호성
	2. https://m.blog.naver.com/PostView.nhn?blogId=ljc8808&logNo=220289656691&proxyReferer=https%3A%2F%2Fwww.google.com%2F
	3. https://softwareengineering.stackexchange.com/questions/201896/what-is-short-circuiting-in-c-like-languages
*/

__inline void _divide();
__inline Boolean is_file_exist();
__inline Boolean get_file_info();

int main(int argc, char** argv)
{
	_divide();
	return 0;
}


__inline void _divide()
{
	int a, b;
	char *str = NULL;
	scanf("%d %d", &a, &b);
	
	const char *ret1 = (a != 0 && (b % a == 2)) ? "a는 0아니다." : "a는 0이다.";
	const char *ret2 = (is_file_exist() && get_file_info()) ? puts("파일이 존재하고, 파일의 정보를 읽어왔습니다.") : puts("파일이 좋재하지 않거나, 파일은 있지만 정보를 읽어오지 못했습니다.");
	Boolean ret3 = (str == NULL || _strlen(str) == 0); // str이 NULL이면, 뒤에는 검사도 안한다.

	puts(ret1);
}

__inline Boolean is_file_exist()
{
	return TRUE;
}

__inline Boolean get_file_info()
{
	return TRUE;
}

__inline unsigned int _strlen(const char* _s)
{
	int i, len = 0;
	for (i = 0; _s[i]; i++)
		len++, puts("len");

	return len;
}
