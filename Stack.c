// ----- Stack -----

#include <stdio.h>
#include <stdlib.h>
#define EMPTY 0

typedef struct node {
	int data;
	struct node* link; // ����ü ������ ���� struct node = Stack
}Stack;

Stack* GetNode()
{
	Stack* tmp;
	tmp = (Stack*)malloc(sizeof(Stack));
	tmp->link = EMPTY;
	return tmp; // ��ȯ �� �Լ� ����
}

void Push(Stack** top, int data)
{
	Stack* tmp;
	tmp = *top;
	*top = GetNode(); // main�� top�� ��ȯ�� ����
	(*top)->data = data;
	(*top)->link = tmp;
}

void Pop(Stack** top) {

	Stack* tmp;

	// Pop�� Push���� ���� ����Ǵ� ���� ���� ����
	// ����ó�� ����
	if (*top == EMPTY) { // �Ҵ�� ������ ���� ��
		printf("Stack is Emplty!!\n");
		return; // �Լ� ����
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
	Pop(&top); // Push���� Pop�� �� ���� ����ȴٸ� ���α׷� ������ ����
			   // ����ó���� ���� Pop�� �� ���� ����Ǵ��� ��������ǵ��� ��.

	return 0;
}