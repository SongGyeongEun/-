//1. 매개변수가 없는 경우
#include<stdio.h>

void aa()
{
	int a, b;
	printf("1값 입력 : ");
	scanf_s("%d", &a);
	printf("2값 입력 : ");
	scanf_s("%d", &b);
	printf("1값 + 2값 = %d 입니다.", a + b);
}

int main()
{

	aa();
}

//2. 매개변수가 int 인 경우
#include<stdio.h>

int ab(int a, int b)
{
	return a + b;
}

int main()
{
	int a, b;
	printf("1값 입력 : ");
	scanf_s("%d", &a);
	printf("2값 입력 : ");
	scanf_s("%d", &b);
	printf("1값 + b값 = %d 입니다.", ab(a, b));
}
//3. 매개변수가 포인터(int 형)인 경우
#include<stdio.h>

void swap(int* aa, int* bb)
{
	int te;

	te = *aa;
	*aa = *bb;
	*bb = te;
}
int main()
{
	printf("a값과 b값을 바꿀것입니다. \n");
	int a, b;
	printf("a값 입력 : ");
	scanf_s("%d", &a);
	printf("b값 입력 : ");
	scanf_s("%d", &b);
	swap(&a, &b);
	printf("a값 : %d / b값 : %d", a, b);
}
//4. 매개변수가 일차원 배열인 경우
#include<stdio.h>

int swap(int a[])
{
	int sum = 0;

	for (int i = 0; i < 10; i++)
	{
		sum += a[i];
	}
	return sum;
}
int main()
{
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = i;
	}
	printf("0~9까지의 합 : %d", swap(a));
}

//5. 매개변수가 이차원 배열인 경우
#include <stdio.h>

#define a 3
#define b 4

void PrintArray(int(*arr)[b], int row, int col);

int main(int argc, char* argv[]) {
	int arr[a][b] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	};
	PrintArray(arr, a, b);
	return 0;
}
void PrintArray(int(*arr)[b], int row, int col) {
	int i;
	int j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
//6. 매개변수가 삼차원 배열인 경우
#include <stdio.h>

int main(void) {
	int score[3][3][2] = { 0 };
	int total[2] = { 0 };
	int a, b, c, d, e;

	for (c = 0; c < 3; c++) {
		for (b = 0; b < 3; b++) { //점수 입력받음
			printf("%d반 %d번 학생의 국어, 수학점수: ", c + 1, b + 1);
			scanf_s("%d %d", &score[c][b][0], &score[c][b][1]);
		}
	}
	printf("\n\n전체반 9명의 국어 총점:%d", sk(&score));
	printf("\n전체반 9명의 수학 총점:%d", summath(&score));

	return 0;
}
int sk(int aa[3][3][2])
{
	int re = 0;
	int a, b, c, dd, e;
	for (e = 0; e < 3; e++) {
		for (dd = 0; dd < 3; dd++) {
			re += aa[e][dd][0];

		}
	}
	return re;

}
int summath(int aa[3][3][2])
{
	int re = 0;
	int a, b, c, d, e;

	for (e = 0; e < 3; e++)
	{
		for (d = 0; d < 3; d++)
		{
			re += aa[e][d][1];
		}
	}
	return re;
}
//7. 매개변수가 구조체인 경우
#include<stdio.h> 
#include <math.h>

typedef struct {
	int x, y;
}POINTER;

double distance(POINTER p1, POINTER p2);

int main()
{
	POINTER p1, p2;
	double dist;
	printf("please enter x & y coordinate : ");
	scanf_s("%d %d", &p1.x, &p1.y);
	printf("please enter x' & y' coordinate : ");
	scanf_s("%d %d", &p2.x, &p2.y);

	dist = distance(p1, p2);    //구조체 변수를 인수로 전달
	printf("distance : %6.3f\n", dist);

	return 0;
}
double distance(POINTER p1, POINTER p2)
{
	int square1, square2;

	square1 = (p2.x - p1.x) * (p2.x - p1.x);
	square2 = (p2.y - p1.y) * (p2.y - p1.y);
	return (sqrt(square1 + square2));
}
//8. 매개변수가 구조체 배열인 경우
#include <stdio.h>

struct Point2D {
	int x;
	int y;
};

int main()
{
	// 구조체 배열을 선언하면서 초기화
	struct Point2D p1[3] = { {.x = 10, .y = 20 }, {.x = 30, .y = 40 }, {.x = 50, .y = 60 } };

	printf("%d %d\n", p1[0].x, p1[0].y);    // 10 20
	printf("%d %d\n", p1[1].x, p1[1].y);    // 30 40
	printf("%d %d\n", p1[2].x, p1[2].y);    // 50 60

	// 구조체 배열을 선언하면서 초기화
	struct Point2D p2[3] = { { 10, 20 }, { 30, 40 }, { 50, 60 } };

	printf("%d %d\n", p2[0].x, p2[0].y);    // 10 20
	printf("%d %d\n", p2[1].x, p2[1].y);    // 30 40
	printf("%d %d\n", p2[2].x, p2[2].y);    // 50 60

	return 0;
}
//9. 매개변수가 함수 포인터인 경우
#define _CRT_SECURE_NO_WARNINGS    // strcpy 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <string.h>    // strcpy 함수가 선언된 헤더 파일

struct Person {
	char name[20];
	int age;
	char address[100];
}
void setPerson(struct Person* p)
{
	strcpy(p->name, "부산 경상 대학교");
	p->age = 201506010;
	strcpy(p->address, "부산 광역시");
}
int main()
{
	struct Person p1;

	strcpy(p1.name, "홍길동");
	p1.age = 30;
	strcpy(p1.address, "서울시 용산구 한남동");

	setPerson(&p1);

	printf("학교: %s\n", p1.name);
	printf("학번: %d\n", p1.age);
	printf("주소: %s\n", p1.address);

	return 0;
}
