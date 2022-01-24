#include <stdio.h>
#include<stdlib.h>
#define EMPTY 0

// ����ü ����

typedef struct node {
	int data;
	struct node* link;
}Queue;

Queue* GetNode() {
	Queue* tmp;
	tmp = (Queue*)malloc(sizeof(Queue));
	tmp->link = EMPTY;
	return tmp;

}

void Enqueue(Queue** Front, Queue** Rear,int data ){

	if (*Front == EMPTY) { // ù ��° Enqueue()

		*Front = GetNode();
		*Rear = *Front;
	}

	else {

		(*Rear)->link = GetNode(); // *Rear = GetNode(); �� �� ��� ù��°�� ������ ������ ����ϰ�
								   // �߰� �������� �� �Ҿ������ �Ǵ� ���� �߻�.
		*Rear = (*Rear)->link;
	}
	(*Rear)->data = data; // �ߺ��Ǵ� �ڵ� �ٱ����� ���ֱ�

}

void Dequeue(Queue** Front) {


	Queue* tmp;

	if (*Front == 0) { // ����ó��
		printf("Queue is Empty!!\n");
		return;
	}

	tmp = *Front;
	printf("%d\n", (*Front)->data);
	*Front = (*Front)->link;
	free(tmp);
	
}


int main() {

	// Front, rear ����
	Queue* Front = EMPTY;
	Queue* Rear = EMPTY;

	Enqueue(&Front, &Rear, 10);
	Enqueue(&Front, &Rear, 20);
	Enqueue(&Front, &Rear, 30);

	Dequeue(&Front);
	Dequeue(&Front);
	Dequeue(&Front);
	Dequeue(&Front);


	return 0;

}