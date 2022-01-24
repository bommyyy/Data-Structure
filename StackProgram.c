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

Stack* GetNode() { // Stack* �� tmp�� ��ȯ��
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

	printf("����\n");
	tmp = *top;
	*top = (*top)->link;
	free(tmp);

}

void Print(Stack** top) {

	//Stack* tmp;
	//Stack* a;
	//a = *top;
	//printf("�̸�\t\t����\t\t\n");

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

	printf("��ȣ\t�̸�\t����\n");

	while (tmp) { // tmp�� tmp�� 0�� �ƴ� �� �����϶�� �ǹ̿� ���ٰ� �� �� ����.
				  // ���� tmp!=EMPTY �� tmp�� ���� ����.

		printf("%3d\t%s\t%d\n", cnt, tmp->name, tmp->age); // 3�� ��ȣ�� ��� �� �� �ֵ��� �ϱ� ���� ����������
		tmp = tmp->link;
		cnt++;

	}

} 

int main()
{
	Stack* top = EMPTY;
	int sel; // 1. ���ǹ��� �����Ű�� ���� �ʱ�ȭ 
	Stack data;

	 do{ // 2. while���� do while������ ����
		printf("1. �Է�\n");
		printf("2. ����\n");
		printf("3. ���\n");
		printf("4. ����\n");
		printf("��ȣ �Է� >> ");
		scanf("%d", &sel);

		switch (sel) {
		case 1:
			printf("�̸� �Է� : ");
			scanf("%s",data.name); //�̸� �Է�
			printf("���� �Է� : "); 
			scanf("%d", &data.age); //���� �Է�
			//Push �Լ� ȣ��
			Push(&top, data);
			system("pause");
				break;
		case 2:
			//Pop �Լ� ȣ��
			Pop(&top);
			
			system("pause");
			break;
		case 3:
			//Print �Լ� ȣ��
			Print(&top);
			system("pause");
			break;
		case 4:
			//Pop �Լ� ȣ��
			while (top) { // top�� top!=EMPTY�� ���� �ǹ̸� ����.

				Pop(&top);
			}

			break;
		default:
			printf("1 ~ 4 �� �ϳ��� �Է����ּ���.\n");
			system("pause");
		}
		system("cls");

	 } while (sel != 4);

	return 0;
}