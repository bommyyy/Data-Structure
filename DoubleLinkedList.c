#include<stdio.h>
#include<stdlib.h>
#define EMPTY 0

typedef struct node {

	int data;
	struct node* Llink;
	struct node* Rlink;

}DLinkedList;

DLinkedList* GetNode() {

	DLinkedList* tmp;
	tmp = (DLinkedList*)malloc(sizeof(DLinkedList));
	tmp->Llink = EMPTY;
	tmp->Rlink = EMPTY;
	return tmp;
}

void Insert(DLinkedList** Head, int data) {

	if (*Head == EMPTY) { // ù ��° Insert 

		*Head = GetNode();
		(*Head)->data = data;

	}
	else {

		Insert(&(*Head)->Rlink, data); 
		(*Head)->Rlink->Llink = (*Head); // �ι�° Insert�� ���� �� �� �ٷ� ����


	}
}

void Output(DLinkedList** Head) {

	if (*Head) { // *Head �� *Head != EMPTY �� ���� �ǹ�.
		printf("%d\n", (*Head)->data);
		Output(&(*Head)->Rlink);
	}

}


void Add(DLinkedList** Head, int data1, int data2) {

	DLinkedList* newNode = EMPTY;

	if (*Head == EMPTY) {

		printf("%d not exist!!\n", data1);

	}

	else if ((*Head)->data == data1) {

		Insert(&newNode, data2);
		newNode->Rlink = (*Head)->Rlink;
		newNode->Llink = (*Head);
		(*Head)->Rlink->Llink = newNode;
		(*Head)->Rlink = newNode;

	}

	else {
		Add(&(*Head)->Rlink, data1, data2);
	}
}

//void Delete(DLinkedList** Head, int data) {
//
//	DLinkedList* tmp;
//
//	if (*Head == EMPTY) {
//
//		printf("%d not exist!!\n", data);
//
//	}
//	else if ((*Head)->data == data) {
//
//		if ((*Head)->Llink == EMPTY) {
//
//			tmp = *Head;
//			*Head = (*Head)->Rlink;
//			(*Head)->Llink = EMPTY;
//			free(tmp);
//		}
//
//		else if ((*Head)->Rlink == EMPTY) {
//
//			tmp = *Head;
//			*Head = (*Head)->Rlink;
//			free(tmp);
//		}
//
//		else {
//			tmp = *Head;
//			*Head = (*Head)->Rlink;
//			(*Head)->Llink = tmp->Llink;
//			free(tmp);
//		}
//
//	}
//
//	else {
//		Delete(&(*Head)->Rlink, data);
//	}
//
//}

void Delete(DLinkedList** Head, int data) {

	DLinkedList* tmp;

	if (*Head == EMPTY) {

		printf("%d not exist!!\n", data);

	}
	else if ((*Head)->data == data) {

		tmp = *Head;
		*Head = (*Head)->Rlink;

		if (*Head != EMPTY) {
			(*Head)->Llink = (*Head)->Llink->Llink; // ������ ��带 �����ϴ� ���������� ������ �ʿ� ����!!!!
		}

		free(tmp);

	}

	else {
		Delete(&(*Head)->Rlink, data);
	}

}

int main() {

	//head ����
	DLinkedList* Head = EMPTY;
	Insert(&Head, 10);
	Insert(&Head, 20);
	Insert(&Head, 30);

	//Output(&Head);

	//Add(&Head, 20, 25);
	//Add(&Head, 40, 45);

	//Delete(&Head, 20);
	//Delete(&Head, 10);
	Delete(&Head, 30);
    Delete(&Head, 40);

	Output(&Head);

	return 0;
}