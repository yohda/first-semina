#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*
	typedef�� 2���� ����.
	1. �ڷ����� ���� Ŀ���͸���¡ �� �� �ִ�.
	2. ���������� �������� �����Ѵ�.

	- ��ó
	1. https://modoocode.com/103
	2. https://www2.dmst.aueb.gr/dds/ismr/psu/indexw.htm
*/

// 1. �ڷ����� ���̸� Ŀ���� ����¡ �� �� �ִ�.
struct _Human {
	int age;
	int weight;
	int height;
	char name[20];
};

typedef struct _Human Human;
// ���� typedef�� ���ؼ� struct _Human�� Human���� �ٿ��� �� �� �ִ�.

enum _CT {
	ADD = 1,
	SUBSTRACT ,
	EXIT
};

// 2. ���������� �������� �����Ѵ�.
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
// ���� ���� CAL_TYPE�� int���� short �ٲ���� scanf�� ���� �����ڸ� �ٲ��شٸ� �̻��� ����.

int main(int argc, char** argv)
{
	CAL_TYPE input;
	CAL_TYPE a, b;

	while (1) {
		printf("--- ���� ---\n1. ����\n2. ����\n3. ����\n");
	
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			printf("�� ��: ");
			scanf("%d %d", &a, &b);
			printf("%d �� %d�� ��: %d\n", a, b, a + b);
			break;
		case SUBSTRACT:
			printf("�� ��: ");
			scanf("%d %d", &a, &b);
			printf("%d �� %d�� ��: %d\n", a, b, a - b);
			break;
		case EXIT:
			printf("���α׷��� �����մϴ�.\n");

			return 1;
		default:
			printf("�������� �ʴ� �����Դϴ�. �ٽ� �� �� Ȯ�ιٶ��ϴ�.\n");
			continue;
			break;
		}
	}

	return 0;
}