// ----- Stack -----

#include <stdio.h>
#include <stdlib.h>
#define EMPTY 0

typedef struct node {
	int data;
	struct node* link; // 구조체 포인터 변수 struct node = Stack
}Stack;

Stack* GetNode()
{
	Stack* tmp;
	tmp = (Stack*)malloc(sizeof(Stack));
	tmp->link = EMPTY;
	return tmp; // 반환 후 함수 종료
}

void Push(Stack** top, int data)
{
	Stack* tmp;
	tmp = *top;
	*top = GetNode(); // main의 top에 반환값 저장
	(*top)->data = data;
	(*top)->link = tmp;
}

void Pop(Stack** top) {

	Stack* tmp;

	// Pop이 Push보다 많이 실행되는 것을 막기 위해
	// 예외처리 진행
	if (*top == EMPTY) { // 할당된 공간이 없을 때
		printf("Stack is Emplty!!\n");
		return; // 함수 종료
	}

	printf("%d\n", (*top)->data);
	tmp = *top;
	*top = (*top)->link;
	free(tmp);

}
 
int main()
{
	Stack* top = EMPTY;

	Push(&top, 10);
	Push(&top, 20); 
	Push(&top, 30);

	Pop(&top);
	Pop(&top);
	Pop(&top);
	Pop(&top); // Push보다 Pop이 더 많이 진행된다면 프로그램 비정상 종료
			   // 예외처리를 통해 Pop이 더 많이 진행되더라도 정상종료되도록 함.

	return 0;
}