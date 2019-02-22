#include<stdio.h>
#include<stdlib.h>

/*
	- 메인 함수의 리턴값의 의미
		1. 메인 함수가 리턴값을 가지는 이유는 프로그램을 호출 한 측에서 그 리턴값을 참조 할 수 있도록 하기 위해서이다.

		2. 메인 함수의 리턴값은 특별한 의미를 지닌다.
			- return 0: 프로그램이 정상적으로 종료되었음을 알린다.
			- return x(x != 0): 프로그램이 비정상적으로 종료됨을 알린다.
			- 여기서 O/S나 호출 프로그램은 x값을 반환받음으로서 호출된 프로그램이 어떻게 종료되었는지 알 수 있다.

		3. 메인 함수의 반환형을 void로 선언할 수 있다
		반환형을 void로 쓸 경우 exit code를 부모 프로세스나 운영체제에 리턴할 수 없을뿐이다.

		4. 반환형이 void일 때 exit code를 알리고 싶다면, exit()를 이용하자.
		
	- 메인 함수의 리턴값 기타 내용
		1. Visual C++ 7.0이나 gcc로

	- 출처
	1. http://thenine.egloos.com/v/430823
	2. 
*/
int main(int argc, char** argv)
{
	
	return 1; // exit(1);
}