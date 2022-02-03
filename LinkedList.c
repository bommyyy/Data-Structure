#include<stdio.h>
#include<stdlib.h>
#define EMPTY 0

// 구조체 정의

typedef struct node {
	int data;
	struct node* link;
}LinkedList;


LinkedList* GetNode() {

	LinkedList* tmp;
	tmp = (LinkedList*)malloc(sizeof(LinkedList));
	tmp->link = EMPTY;
	return tmp;
}


void Insert(LinkedList** Head, int data) {


	if (*Head == EMPTY) { // 첫 번째 Insert 

		*Head = GetNode();
		(*Head)->data = data;
		 
	}
	else {

		Insert(&(*Head)->link,data);
		
	}
}

void Output(LinkedList** Head) {

	//if (*Head == EMPTY) {
	//	return;
	//}
	//else {   

	//	printf("%d\n", (*Head)->data);
	//	Output(&(*Head)->link);
	//}

	if (*Head) { // *Head 는 *Head != EMPTY 와 값은 의미.
		printf("%d\n", (*Head)->data);
		Output(&(*Head)->link);
	}
}

void Search(LinkedList** Head, int data) {

	//if (*Head) {

	//	if ((*Head)->data == data) {
	//		printf("%d Search!!\n", data);
	//		return;
	//	}

//	if ((*Head)->link == 0) {
//		printf("%d not exist!!\n", data);
//		return;
//	}

//	Search(&(*Head)->link, data);
//}

if (*Head == EMPTY) {

	printf("%d not exist!!\n", data);

}
else if ((*Head)->data == data)
{
	printf("%d Search!!\n", data);

}
else {
	Search(&(*Head)->link, data);
}

}

//void Add(LinkedList** Head, int data1, int data2) {
//	 
//	LinkedList* tmp;
//
//	if (*Head == EMPTY) {
//
//		printf("%d not exist!!\n", data1);
//
//	}
//
//	else if ((*Head)->data == data1) 
//	{
//
//		tmp = (*Head)->link;
//		(*Head)->link = GetNode();
//		(*Head)->link->data = data2;
//		(*Head)->link->link = tmp;
//
//	}
//
//	else {
//		Add(&(*Head)->link, data1, data2);
//	}
//}

void Add(LinkedList** Head, int data1, int data2) {

	LinkedList* newNode = EMPTY;

	if (*Head == EMPTY) {

		printf("%d not exist!!\n", data1);

	}

	else if ((*Head)->data == data1) {

		Insert(&newNode, data2);
		newNode->link = (*Head)->link;
		(*Head)->link = newNode;

	}

	else {
		Add(&(*Head)->link, data1, data2);
	}
}

void Delete(LinkedList** Head, int data) {

	LinkedList* tmp;

	if (*Head == EMPTY) {

		printf("%d not exist!!\n", data);

	}
	else if ((*Head)->data == data) {

		tmp = *Head;
		*Head = (*Head)->link;
		free(tmp);

	}

	else {
		Delete(&(*Head)->link, data);
	}

}

void sort(LinkedList** Head) {

	// 재귀와 반복문을 같이 사용한다.

	LinkedList* tmp;
	int tmp_int;

	//if (*Head == EMPTY) {
	//	return;
	//}
	//else {

	//	tmp = (*Head)->link;

	//	while (tmp) // tmp는 tmp!=EMPTY와 같은 의미
	//	{

	//		if ((*Head)->data < tmp->data) {

	//			tmp_int = (*Head)->data;
	//			(*Head)->data = tmp->data;
	//			tmp->data = tmp_int;

	//		}

	//		tmp = tmp->link;
	//	}
	//	sort(&(*Head)->link);
	//}

	if (*Head) {
		
		tmp = (*Head)->link;

		while (tmp) // tmp는 tmp!=EMPTY와 같은 의미
		{

			if ((*Head)->data < tmp->data) {

				tmp_int = (*Head)->data;
				(*Head)->data = tmp->data;
				tmp->data = tmp_int;

			}

			tmp = tmp->link;
		}
		sort(&(*Head)->link);
	}

}



int main() {


	LinkedList* Head = EMPTY;
	Insert(&Head, 20);
	Insert(&Head, 10);
	Insert(&Head, 30);

	//Output(&Head);

	//Search(&Head, 20);
	//Search(&Head, 40);

	//Add(&Head, 20, 25);
	//Add(&Head, 40, 45);

	//Delete(&Head, 20);
	//Delete(&Head, 40);

	sort(&Head);

	Output(&Head);

	return 0;
}