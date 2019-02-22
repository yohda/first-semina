#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*
	typedef의 2가지 이점.
	1. 자료형의 길이 커스터마이징 할 수 있다.
	2. 유지보수의 유연성을 제공한다.

	- 출처
	1. https://modoocode.com/103
	2. https://www2.dmst.aueb.gr/dds/ismr/psu/indexw.htm
*/

// 1. 자료형의 길이를 커스터 마이징 할 수 있다.
struct _Human {
	int age;
	int weight;
	int height;
	char name[20];
};

typedef struct _Human Human;
// 위의 typedef를 통해서 struct _Human을 Human으로 줄여서 쓸 수 있다.

enum _CT {
	ADD = 1,
	SUBSTRACT ,
	EXIT
};

// 2. 유지보수의 유연성을 제공한다.
typedef enum CT CAL_CONSTANT;
typedef int CAL_TYPE;
typedef int(*Padd)(int, int); // int (*ptr)(int, int) = add => Padd ptr = add
typedef int Arrays[10];		  // int arr[10] => Arrays arr

typedef signed char int8_t;
typedef unsigned char u_int8_t;
typedef short int16_t;
typedef unsigned short u_int16_t;
typedef int int32_t;
typedef unsigned u_int32_t;
typedef long int64_t;
typedef unsigned long u_int64_t;

typedef u_int32_t in_addr_t;
typedef u_int16_t in_port_t;
// 위의 만약 CAL_TYPE이 int에서 short 바뀌더라도 scanf의 서식 지정자만 바꿔준다면 이상이 없다.

int main(int argc, char** argv)
{
	CAL_TYPE input;
	CAL_TYPE a, b;

	while (1) {
		printf("--- 계산기 ---\n1. 덧셈\n2. 뺄셈\n3. 종료\n");
	
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			printf("두 수: ");
			scanf("%d %d", &a, &b);
			printf("%d 와 %d의 합: %d\n", a, b, a + b);
			break;
		case SUBSTRACT:
			printf("두 수: ");
			scanf("%d %d", &a, &b);
			printf("%d 와 %d의 차: %d\n", a, b, a - b);
			break;
		case EXIT:
			printf("프로그램을 종료합니다.\n");

			return 1;
		default:
			printf("존재하지 않는 연산입니다. 다시 한 번 확인바랍니다.\n");
			continue;
			break;
		}
	}

	return 0;
}