#include<stdio.h>

/*
	- #pragma의 정의
	1. #pragma 지시자는 플랫폼별로 고유한 기능에 대한 지시 사항을 컴파일러에게 전하는 방법이다.
	'#'문자로 시작하므로 전처리 명령처럼 보이지만 컴파일러 지시자이다. 
	pragma는 C언어의 기본 키워드라기 보다는, 컴파일러에 종속적인 키워드라고 하는것이 맞습니다.
	그래서 컴파일러를 변경했을 경우 실행을 보장할 수 없다.	

	- #pragma 종류
	1. #pragma pack
		- pack 지시자는 코드 상에서 pack지시자 이후에
		위치한 구조체의 정렬 방식을 지정하는 지시자이다.

		- 같은 소스에 있는 두 구조체를 서로 다른 방식으로 정렬 할 수있다.
		- pack가 함께 사용되는 키워드로 push와 pop이 있다.
		- push는 현재 값을 저장하면서 정렬 값을 바꾸고 싶을 때 사용한다.
		- pop은 push에 의해 저장된 값을 다시 불러오고 싶을 때 사용한다.
	2. #pragma once
		- 컴파일러에게 해당 헤더 파일이 한번만 빌드되도록 한다.
		해당 헤더파일이 여러번 include 되는 것을 막아준다.
		이 지사자와 동일한 기능을 수행하는 조건부 컴파일도 있다.
		Microsoft Visual C++ 과 GCC는 지원을 한다는 것 같다.
		그러나 이식성을 생각한다면 이 지시자는 사용하지 않는 것이 좋다고 한다(표준이 아니기 때문이다).
		참고로, 조건부 컴파일방식보다는 #pragma once가 속도 측면에서 더 좋다고 한다.
		Ex)
		#ifndef _A_
		#define _A_
		...
		#endif _A_

	
	- 출처
	 1.http://forum.falinux.com/zbxe/index.php?mid=lecture_tip&document_srl=783410
	 2. https://github.com/jwvg0425/ProjectArthas/wiki/%23pragma-pack-%EC%A0%95%EB%A6%AC
	 3. https://yesarang.tistory.com/67
*/

/*
	아래와 같이 선언하면 st1구조체는 2바이트 단위로 정렬되므로, 6바이트가 되고
	str2구조체는 4바이트 단위로 정렬되므로, 8바이트가 된다.
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
struct st1 { short s; int i; };  // 2바이트 정렬
#pragma pack(push, 4)			 // 이전에 수행한 2바이트 정렬을 푸시하면서 4바이트 정렬로 바꿈
struct st2 { short s; int i; };  // 4바이트 정렬
#pragma pack(pop)				 // 푸쉬했던 2바이트 정렬을 pop해서 st3를 정렬한다.
struct st3 { short s; int i; };  // 2바이트 정렬
#pragma pack(4)					 // 4바이트 정렬로 바꿈
struct Park { short s; int i; }; // 4바이트 정렬

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