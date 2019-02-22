#include<stdio.h>

/*
	- #pragma�� ����
	1. #pragma �����ڴ� �÷������� ������ ��ɿ� ���� ���� ������ �����Ϸ����� ���ϴ� ����̴�.
	'#'���ڷ� �����ϹǷ� ��ó�� ���ó�� �������� �����Ϸ� �������̴�. 
	pragma�� C����� �⺻ Ű������ ���ٴ�, �����Ϸ��� �������� Ű������ �ϴ°��� �½��ϴ�.
	�׷��� �����Ϸ��� �������� ��� ������ ������ �� ����.	

	- #pragma ����
	1. #pragma pack
		- pack �����ڴ� �ڵ� �󿡼� pack������ ���Ŀ�
		��ġ�� ����ü�� ���� ����� �����ϴ� �������̴�.

		- ���� �ҽ��� �ִ� �� ����ü�� ���� �ٸ� ������� ���� �� ���ִ�.
		- pack�� �Բ� ���Ǵ� Ű����� push�� pop�� �ִ�.
		- push�� ���� ���� �����ϸ鼭 ���� ���� �ٲٰ� ���� �� ����Ѵ�.
		- pop�� push�� ���� ����� ���� �ٽ� �ҷ����� ���� �� ����Ѵ�.
	2. #pragma once
		- �����Ϸ����� �ش� ��� ������ �ѹ��� ����ǵ��� �Ѵ�.
		�ش� ��������� ������ include �Ǵ� ���� �����ش�.
		�� �����ڿ� ������ ����� �����ϴ� ���Ǻ� �����ϵ� �ִ�.
		Microsoft Visual C++ �� GCC�� ������ �Ѵٴ� �� ����.
		�׷��� �̽ļ��� �����Ѵٸ� �� �����ڴ� ������� �ʴ� ���� ���ٰ� �Ѵ�(ǥ���� �ƴϱ� �����̴�).
		�����, ���Ǻ� �����Ϲ�ĺ��ٴ� #pragma once�� �ӵ� ���鿡�� �� ���ٰ� �Ѵ�.
		Ex)
		#ifndef _A_
		#define _A_
		...
		#endif _A_

	
	- ��ó
	 1.http://forum.falinux.com/zbxe/index.php?mid=lecture_tip&document_srl=783410
	 2. https://github.com/jwvg0425/ProjectArthas/wiki/%23pragma-pack-%EC%A0%95%EB%A6%AC
	 3. https://yesarang.tistory.com/67
*/

/*
	�Ʒ��� ���� �����ϸ� st1����ü�� 2����Ʈ ������ ���ĵǹǷ�, 6����Ʈ�� �ǰ�
	str2����ü�� 4����Ʈ ������ ���ĵǹǷ�, 8����Ʈ�� �ȴ�.
*/
typedef struct font {
	int size;
	int style;
	int position;
}Font_t;

typedef struct font {
	int size;
	int style;
	int position;
}Font_t;

#pragma pack(2)
struct st1 { short s; int i; };  // 2����Ʈ ����
#pragma pack(push, 4)			 // ������ ������ 2����Ʈ ������ Ǫ���ϸ鼭 4����Ʈ ���ķ� �ٲ�
struct st2 { short s; int i; };  // 4����Ʈ ����
#pragma pack(pop)				 // Ǫ���ߴ� 2����Ʈ ������ pop�ؼ� st3�� �����Ѵ�.
struct st3 { short s; int i; };  // 2����Ʈ ����
#pragma pack(4)					 // 4����Ʈ ���ķ� �ٲ�
struct Park { short s; int i; }; // 4����Ʈ ����

int main(int argc, char** argv)
{
	struct st1 C;
	struct st2 D;
	struct st3 E;
	struct Park B;
	Font_t f1 = { 1,2,3 };

	printf("C: %d\n", sizeof(C));
	printf("D: %d\n", sizeof(D));
	printf("E: %d\n", sizeof(E));
	printf("B: %d\n", sizeof(D));

	return 0;
}