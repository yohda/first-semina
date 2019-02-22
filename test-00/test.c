#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define TRUE 1
#define FALSE 0

/*
	임베디드의 경우 메모리 접근에 포인터가 꼭 필요한 것은 아니다.
	임베디드 환경에서는 주로 포인터 없이 메모리에 직접 접근하는 경우를 볼 수가 있다.
*/

#define PA (*(volatile unsigned char*)0x30000000)
#define TEMP (*(volatile unsigned int*)0x001)

/*
	구조체를 1바이트 크기로 정렬하는 것은 구조체의 내용을 파일에 쓰거나 네트워크로 전송할 때 꼭 필요하다.
	윈도우의 경우 아래와 같이 #pramga를 지정해야 ARM의 __packed기능을 사용할 수 있다.
*/

typedef unsigned char _uChar;
typedef unsigned int _uInt;

#pragma pack(push, 1)
typedef struct _strtype{
	char name;
	int age;
	char addr;
	int num;
}strtype;
strtype han;
// name = 1bit, age = 4bit, addr= = 1bit, num = 4bit
// 합하면 총 10bit가 되야하지만, 실제로는 16bit다.
// 왜냐면, 구조체는 기본적으로 4바이트를 기준으로 데이터를 정렬하기 때문에,
// char 자료형 같은 경우 3bit의 패딩 비트를 추가한다.
#pragma pack(pop)

void checkEvenOrOdd();
int getMaxInt();
unsigned int getMaxUnsignedInt();

void clearABit(_uInt _n, const int _pos);
void clearBits(_uInt _n, const int _pos);
void setABit(_uInt _n, const int _pos);
void invertABit(_uInt _n, const int _pos);
int checkABit(_uInt _n, const int _pos);
int extractABit(_uInt _n, const int _pos);

void getNetworkAddress();
void getHostAddress();
void getBroadCastAddress();
_uInt inet_aton(const char* _s); // Dotted-Deimal Notation을 Big-Endian 32비트 값으로 변환.
char* inet_ntoa(_uInt _ip); // 네트워크 바이트 순서의 32비트 값을 Dotted-Decimal Notation으로 변환.

/*
	메모리의 주소는 1바이트 크기의 메모리 공간을 갖는다.
	예를 들어 크기가 4바이트인 메모리의 주소는 총 4개의 주소를 사용한다.
	
	컴퓨터 메모리는 숫자(2진수 형태)만을 저장할 수 있으므로, 문자는 컴퓨터 메모리에 직접 저장할 수 없다.
	그래서 문자를 컴퓨터 메모리에 저장하려면 각 문자에 해당하는 문자 코드(정수)를 사용한다.
	C언어의 경우 ASCII 코드를 사용한다. 한 마디로 C 언어 문법에서 65는 'A', 'A'는 65로 표현할 수 있다.

	0x12FF7C => 16진수는 숫자하나를 4비트로 표현하면 되고, 8진수라면 숫자하나를 3비트로 표현하면 된다.
	0001(1) 0010(2) 1111(F=15) 1111(F=15) 0111(7) 1100(12) => 1 2 F F 7 C	
*/

/*
	비트연산은 정수 계통 자료형에만 사용이 가능하다.
	더블형은 불가능하다.
*/
int main(int argc, char** argv)
{
	/*printf("%d\n", &(han.name));
	printf("%d\n", &(han.age));
	printf("%d\n", &(han.addr));
	printf("%d\n", &(han.num));*/

	// IP를 저장한다고 하면...?
	// 내 프로세서는 리틀 엔디안 설계인 것 같다.
	//const int n = 0x44434241; // 01000100(68) 01000011(67) 01000010(66) 01000001(65)

	//printf("n의 주소: %d\n", &n);
	//printf("n의 첫번째 주소: %d, %c\n", &((char)n) + 0, (char)n + 0); // A
	//printf("n의 두번째 주소: %d, %c\n", &((char)n) + 1, (char)n + 1); // B
	//printf("n의 세번째 주소: %d, %c\n", &((char)n) + 2, (char)n + 2); // C
	//printf("n의 네번째 주소: %d, %c\n", &((char)n) + 3, (char)n + 3); // D
	
	/*printf("max int: %d\n", getMaxInt());
	printf("unsigned int:%u\n", getMaxUnsignedInt());*/
	
	// 0001(1) 1100(C) 0010(2) 1111(F) 0011(3) 0010(2) 1010(A) 0011(3)  
	unsigned int n = 1;
	
	inputIPAddress();
	return 0;
}

/*
	짝수 * 짝수 = 짝수
	짝수 + 짝수 = 짝수
	짝수 + 홀수 = 홀수
	짝수 * 홀수 = 짝수
	홀수 + 홀수 = 짝수
*/
void checkEvenOrOdd()
{
	int n[5] = { 2, 7, 12, 3, 5 }, i;
	for (i = 0; i < 5; i = i + 1)
		(n[i] & 1) ? printf("n[%d]는 홀수\n", i) : printf("n[%d]는 짝수\n", i);
}

/*
	int의 경우 MSB를 사용하기 때문에, MSB를 제외한 나머지 비트를 모두 1로하면 최대값을 구할 수 있다.
*/
int getMaxInt()
{
	return ~(1 << 31); 
}

/*
	unsigned int의 경우 MSB를 사용하지 않기 때문에 0을 전부 반전하면 최대값을 구할 수 있다.
*/
_uInt getMaxUnsignedInt()
{
	return ~((_uInt)0);
}

/*
	클리어의 의미는 해당 비트를 0으로 만든다는 의미이다.
	_n &= (0x0 << (_pos));
	위와 같이 하면 안될까? 당연하다!
	왜냐면, _n이 10110111일 경우, 0x0은 전부 0이기 때문에
	_pos를 오른쪽으로 쉬프트한 결과와 상관없이, _n은 모두 0이 되버린다.
	임의의 비트와 1을 AND연산할 경우 값이 그대로 나온다.
*/
void clearABit(_uInt _n, const int _pos)
{
	_n &= ~(0x1 << (_pos)); // _n = _n & (0x1 << (_pos));
}

/*
	set이라는 말은 해당 비트를 1로 설정한다는 의미이다.

		0001 1100 0010 1111 0011 0010 1010 0011
	|   0000 0000 0000 0000 0000 0000 1000 0000
	-------------------------------------------
	    0000 0000 0000 0000 0000 0000 1000 0000
*/
void setABit(_uInt _n, const int _pos)
{
	_n |= (0x1 << (_pos));
}

/*
	invert는 반전을 의미하고, 반전은 0을 1로, 1을 0으로 만든다는 의미이다.
	
		1001 1110
	^	0011 0110
	--------------
		1010 1000

		1001 1110
	^	1111 1111
	--------------
		0110 0001
*/
void invertABit(_uInt _n, const int _pos)
{
	_n ^= (0x1 << (_pos));
}

/*
	원리
		0001 1100 0010 1111 0011 0010 1010 0011
	&   0000 0000 0000 0000 0000 0000 1000 0000
	-------------------------------------------
	    0000 0000 0000 0000 0000 0000 1000 0000

	@ 참고로 아래 값이 반환하는 값은 &연산의 결과가 되기 때문에
	@ 1 또는 0 형식으로 반환되지 않는다. 그렇기 때문에 아래와 같이 0을 기준으로 판단해야 한다.
*/
int checkABit(_uInt _n, const int _pos)
{
	return (_n & (0x1 << (_pos))) > 0 ? TRUE : FALSE;
}

/*
	- 정리
		1. AND에서 0은 모든 결과를 0으로 출력. 1은 원래 값을 출력.
		2. OR에서 0은 원래 값을 출력. 1은 모든 결과를 1로 출력
		3. XOR에서 0은 원래 값을 출력. 1은 모든 결과를 NOT값으로 출력.
*/

/*
	호스트 부분이 0이면 네트워크 주소 => 즉, 0
	호스트 부분이 1이면 브로드캐스트 주소 => 즉, 255
	그래서 총 사용할 수 있는 호스트 부분은 일반적으로 254개이다.
	서브넷을 나누게 되면, 다른 서브넷끼리 통신하기 위해서는 라우터를 이용해야 한다.
*/

/*
	%hhu가 unsigned char의 서식 지정자인거 같다.
	근데, 재미있는 건 정수로 받아지는 듯 하다.
	생각을 좀 해보았는데, 당연한듯 하다.
	%c는 아스키 코드에 맞춰져있다. 즉, 128이상의 값들은 받지 못한다.
	그래서 %hhu는 128이상부터 255이하까지 받을 수 있으므로, 문자 표현보다는
	정수로 아예받아지는 것 같다.
*/
_uInt inet_aton(const char* _s)
{
	_uInt ip;
	_uChar c_ip[4];
	
	scanf("%hhu.%hhu.%hhu.%hhu", c_ip + 0, c_ip + 1, c_ip + 2, c_ip + 3);
	ip = ( c_ip[0] << 24 | c_ip[1] << 16 | c_ip[2] << 8 | c_ip[3] );
	
	return ip;
}

// "255.255.255.255"
char* inet_ntoa(_uInt _ip)
{
	static char b[16];
	// sprintf(b, sizeof(b), "", );

	return b;
}

void getNetworkAddress()
{

}

void getHostAddress()
{

}

void getBroadCastAddress()
{

}

/*
	루프를 종료시키기 위한 검사는 항상 count-down-to-zero를 사용하도록 한다.
	즉, 루프를 점점 감소시키면서 검사하는 것이다.
	
	조건 검사의 경우 0인지 아닌지를 비교하는데 더 작은 시간이 소비된다.
*/
void fastFor() 
{
	int i;
	for(i = 10; i--;){} // for(i = 0 ; i < 10 ; i = i+1){}
}

/*
	가급적 루프에서 함수를 호출하지 마라.
	왜냐면, 함수 호출은 오버헤드가 크기 때문이다.
	실행해야될 함수가 있는 포인터만 변경하는게 아닌, 값들을 stack에 push하는 것과
	새로운 변수의 할당과 같은 작업이 수행되기 때문이다.
	차라리 함수에서 루프를 호출하거나 함수를 제거한다.
	짧은 루프문의 경우 그냥 돌려라. 가능하면 루프를 줄이는게 더 효율적이다.
*/

/*
	가능한 인자의 수를 줄여라.
	@ 함수가 호출되면 register에 함수의 인자를 넘기게 된다.
	@ 그러나 이들 인자는 실제 4개만을 전달할 수 있다는 한계를 가진다.
	@ 이 이상으로 인자가 넘어가게 되면, stack을 이용해서 함수의 인자를 넘기게 된다.
	
	함수 설계 원칙
	@ 4개 이하의 인자를 가지도록 함수를 설계하자. 4개가 넘아가면 스택을 통해서 인자를 넘기게 된다.
	@ 만약 함수가 4개의 이상의 인자가 사용되면, 스택을 통해서 인자를 넘기게 되고 스택의 크기만큼 메모리 접근이 발생하게 된다.
	@ 이럴 경우 구조체를 선언하고, 구조체에 대한 포인터를 넘기는 방식으로 사용하도록 한다.
	@ 가변인자를 사용하지 말라. 가변인자를 사용하게 되면, 인자가 stack으로 넘어가게 된다.
*/

/*
	전역 변수는 절대 레지스터에 할당할 수 없다.
	따라서 컴파일러는 전역변수의 값을 레지스터에 올려서 캐쉬할 수 없게 되고 때문에
	전역 변수를 이용할 때마다 다시 읽어들이는 오버로드가 생기게 된다.
	그러므로, 글로벌 변수를 직접 호출하는 대신에, 로컬변수를 이용해서 필요한 연산을 한 후
	그 결과를 글로벌 변수에 할당하는 방법을 사용하자.
*/

/*
	나눗셈 연산은 가급적이면 곱셈연산으로 대체해야 한다.
	대신 이럴 경우, 정수가 아닌 실수를 사용해야 될 수도 있다...
	- (a/b) > c == a > (b*c)
	- a = a / 2; == a = a * 0.5;
*/
void printSum(int n)
{
	int a = n * (n + 1) / 2;
	int b = n * (n + 1) * 0.5;

	int v1 = a / 2;
	int v2 = a * 0.5;
}

/*
	이중 포인터시 주의할 점
	포인터 변수가 주소를 가지고 있다고, 그냥 전달하면 CallbyValue가 된다.
	그러므로, 포인터 변수의 값을 변경시키기 위해서는 2중 포인터를 사용해야 한다.
*/
void swap(char **_tag)
{
	(*_tag) = (char*)malloc(sizeof(char) * 30);
	strncpy(*_tag, "pointer tag\n", sizeof(char) * 30);
}

void process()
{	
	char *tag;
	swap(&tag);
	free(tag);
}