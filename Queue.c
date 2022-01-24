#include <stdio.h>
#include<stdlib.h>
#define EMPTY 0

// 구조체 정의

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

	if (*Front == EMPTY) { // 첫 번째 Enqueue()

		*Front = GetNode();
		*Rear = *Front;
	}

	else {

		(*Rear)->link = GetNode(); // *Rear = GetNode(); 로 할 경우 첫번째와 마지막 공간만 기억하고
								   // 중간 공간들은 다 잃어버리게 되는 문제 발생.
		*Rear = (*Rear)->link;
	}
	(*Rear)->data = data; // 중복되는 코드 바깥으로 빼주기

}

void Dequeue(Queue** Front) {


	Queue* tmp;

	if (*Front == 0) { // 예외처리
		printf("Queue is Empty!!\n");
		return;
	}

	tmp = *Front;
	printf("%d\n", (*Front)->data);
	*Front = (*Front)->link;
	free(tmp);
	
}


int main() {

	// Front, rear 선언
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