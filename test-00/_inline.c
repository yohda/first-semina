///*
//	- 인라인 함수 정의
//
//	- 인라인 함수 장점
//		1. 함수 호출을 하지 않고 함수의 코드를 그 자리에서 그대로 실행하기 때문에 함수 실행시 오버헤드가 발생하지 않는다.
//		2. 속도가 빠르다.
//		3. 디버깅이 매크로 함수보다 편리하다.
//
//	- 인라인 함수 단점
//		1. 함수의 코드가 복제되므로, 함수를 많이 사용하면 실행 파일의 크기가 커진다.
//
//
//	- 인라인 함수 기타
//		1. C99부터 새로운 표준으로 등장.
//		2. 매크로 함수보다는 인라인 함수의 사용을 권장하고 있다(왜냐면, 인라인 함수는 인자의 타입 검사를 확인하기 때문이다).
//		3. 인라인 함수는 컴파일러가 처리하기 때문에 훨씬 똑똑하게 치환을 한다.
//
//	- 출처
//	1. https://modoocode.com/992
//	2. https://dojang.io/mod/page/view.php?id=748
//*/
//inline int square(const int a)
//{
//	return a * a;
//}
//
//inline int max(const int a, const int b)
//{
//	return a > b ? a : b;
//}
//
//inline int min(const int a, const int b)
//{
//	return a > b ? b : a;
//}
//
//inline int abs(const int a)
//{
//	return a > 0 ? a : -a;
//}
//
//inline int swap(int *a, int *b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//int main(int argc, char** argv)
//{
//	return 1;
//}