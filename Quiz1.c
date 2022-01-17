// ------ Quiz1 ------

#include <stdio.h>
#include<stdlib.h>

typedef struct
{
	int data1;
	int data2;

}Data1;

//Func1()�Լ��� ���� Func1()�ȿ��� data1�� 100�� ��������.
void Func1(Data1** p) {
	(**p).data1 = 100;
	//(*p)->data1 = 100;
}

//Func2()�Լ��� ���� Func2()�ȿ��� data2�� 200�� ��������.	
void Func2(Data1* p) {
	(*p).data2 = 200;
	//p->data2 = 200;
}

int main()
{

	Data1* p = (Data1*)malloc(sizeof(Data1));

	Func1(&p);
	Func2(p);

	printf("��� : %d\n",p->data1);		//data1�� data2�� ����ϼ���. 
	printf("��� : %d\n",p->data2);

	free(p);	// �������� �ڵ带 �߰��ϼ���.

	return 0;
}
