#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EMPTY 0

typedef struct node {
	char name[20];
	int age;
	struct node* link;
}Stack;

//void Push(Stack** top,char name[], int age ) {
//
//	Stack* tmp;
//	tmp = (Stack*)malloc(sizeof(Stack));
//	strcpy(tmp->name, name);
//	tmp->age = age;
//	tmp->link = (*top);
//	*top = tmp;
//
//}

Stack* GetNode() { // Stack* 은 tmp의 반환형
	Stack* tmp;
	tmp = (Stack*)malloc(sizeof(Stack)); 
	tmp->link = EMPTY;
	return tmp;

}

void Push(Stack** top, Stack data) {

	Stack* tmp;
	tmp = *top;
	*top = GetNode();
	strcpy((*top)->name, data.name); 
	(*top)->age = data.age;
	(*top)->link = tmp;
	
}


void Pop(Stack** top) {

	Stack* tmp;

	if (*top== EMPTY) {
		printf("Stack is Empty!!\n");
		return;

	}

	printf("삭제\n");
	tmp = *top;
	*top = (*top)->link;
	free(tmp);

}

void Print(Stack** top) {

	//Stack* tmp;
	//Stack* a;
	//a = *top;
	//printf("이름\t\t나이\t\t\n");

	//while (1) {

	//	if ((*top)->link == 0) {
	//		printf("%s\t\t", (*top)->name);
	//		printf("%d\t\t", (*top)->age);

	//		break;
	//	}
	//
	//	printf("%s\t\t", (*top)->name);
	//	printf("%d\t\t", (*top)->age);
	//	printf("\n");

	//	tmp = (*top)->link;
	//	*top = tmp;

	//}
	//*top = a;

	Stack* tmp;
	int cnt = 1;

	tmp = *top;

	printf("번호\t이름\t나이\n");

	while (tmp) { // tmp는 tmp가 0이 아닐 때 실행하라는 의미와 같다고 볼 수 있음.
				  // 따라서 tmp!=EMPTY 를 tmp로 변경 가능.

		printf("%3d\t%s\t%d\n", cnt, tmp->name, tmp->age); // 3은 번호가 가운데 올 수 있도록 하기 위한 서식지정자
		tmp = tmp->link;
		cnt++;

	}

} 

int main()
{
	Stack* top = EMPTY;
	int sel; // 1. 조건문을 실행시키기 위해 초기화 
	Stack data;

	 do{ // 2. while문을 do while문으로 변경
		printf("1. 입력\n");
		printf("2. 삭제\n");
		printf("3. 출력\n");
		printf("4. 종료\n");
		printf("번호 입력 >> ");
		scanf("%d", &sel);

		switch (sel) {
		case 1:
			printf("이름 입력 : ");
			scanf("%s",data.name); //이름 입력
			printf("나이 입력 : "); 
			scanf("%d", &data.age); //나이 입력
			//Push 함수 호출
			Push(&top, data);
			system("pause");
				break;
		case 2:
			//Pop 함수 호출
			Pop(&top);
			
			system("pause");
			break;
		case 3:
			//Print 함수 호출
			Print(&top);
			system("pause");
			break;
		case 4:
			//Pop 함수 호출
			while (top) { // top은 top!=EMPTY와 같은 의미를 가짐.

				Pop(&top);
			}

			break;
		default:
			printf("1 ~ 4 중 하나를 입력해주세요.\n");
			system("pause");
		}
		system("cls");

	 } while (sel != 4);

	return 0;
}