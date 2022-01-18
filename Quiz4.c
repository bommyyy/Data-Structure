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

	printf("�̸��� �Է��ϼ��� : ");
	scanf("%s",p->p->name);		//scanf()�� �̿��� name�� �̸��� �Է� ��������.

	printf("������ �Է��ϼ��� : ");
	scanf("%d", &(p->p->score));		//scanf()�� �̿��� score�� ������ �Է� ��������.

	printf("�̸� : %s\n", p->p->name); //�Է¹��� ���� ����ϼ���.
	printf("���� : %d\n", p->p->score);

	free(p->p->name);
	free(p->p);		//���� ���� �ڵ带 �߰��ϼ���.
	free(p);		//���� ���Ѽ� �����ϱ�!!

	return 0;
}