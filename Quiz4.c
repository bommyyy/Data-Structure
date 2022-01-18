// ------ Quiz4 ------

#include<stdio.h>
#include<stdlib.h>


typedef struct
{
	char* name;
	int score;
}Element;

typedef struct
{
	int data1;
	int data2;
	Element* p;
}Data1;

int main()
{
	Data1* p = (Data1*)malloc(sizeof(Data1));
	p->p = (Element*)malloc(sizeof(Element));
	p->p->name = (char*)malloc(sizeof(char) * 20 );

	printf("이름을 입력하세요 : ");
	scanf("%s",p->p->name);		//scanf()를 이용해 name에 이름을 입력 받으세요.

	printf("점수를 입력하세요 : ");
	scanf("%d", &(p->p->score));		//scanf()를 이용해 score에 점수를 입력 받으세요.

	printf("이름 : %s\n", p->p->name); //입력받은 값을 출력하세요.
	printf("점수 : %d\n", p->p->score);

	free(p->p->name);
	free(p->p);		//동적 해제 코드를 추가하세요.
	free(p);		//순서 지켜서 해제하기!!

	return 0;
}