#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

typedef enum _Boolean {
	FALSE, TRUE
}Boolean;
/*
	- ��Ʈ ��Ŷ ����
		1. C�� �� �����ڴ� �ӵ� ���� ������ ���� ���ʿ��� ������ ���� �ʴ´�.

	- ��Ʈ ��Ŷ ����
		1. &&�������� ��� �տ� ���� �����̶��, �ڿ� ���� ������� �ʴ´�.
		2. ||������ ��� �տ� ���� ���̸�, �ڿ� ���� �˻絵 ���ϰ� ���� �ȴ�.
	
	- ��Ʈ ��Ŷ ����
		1. ���� �ӵ��� ���� �� �ִ�.
		2. �ڵ��� �������� ��������.
			- if(a != 0 && b/a == 3) a�� 0�� �ƴ� ��쿡 ���� ���� �����Ѵ�.

	- ��Ʈ ��Ŷ ����
		1. ������� ����� �� �ִ�.
	
	- ��Ʈ ��Ŷ ��� ���
	
	- ��ó
	1. ���ϰ� �����ϴ� c ���α׷���/��ȣ��
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
	
	const char *ret1 = (a != 0 && (b % a == 2)) ? "a�� 0�ƴϴ�." : "a�� 0�̴�.";
	const char *ret2 = (is_file_exist() && get_file_info()) ? puts("������ �����ϰ�, ������ ������ �о�Խ��ϴ�.") : puts("������ �������� �ʰų�, ������ ������ ������ �о���� ���߽��ϴ�.");
	Boolean ret3 = (str == NULL || _strlen(str) == 0); // str�� NULL�̸�, �ڿ��� �˻絵 ���Ѵ�.

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
