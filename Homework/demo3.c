

////�ֱ���ջ������ʵ��ʮ����ת����ʮ���Ͷ�����
////ջʵ��
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
	int items[MAX_SIZE];
	int top;
} Stack;

void init(Stack* s) {
	s->top = -1; // ��ʼ��ջ��ָ��Ϊ-1����ʾջΪ��
}

int isFull(Stack* s) {
	return s->top == MAX_SIZE - 1; // �ж�ջ�Ƿ�����
}

int isEmpty(Stack* s) {
	return s->top == -1; // �ж�ջ�Ƿ�Ϊ��
}

void push(Stack* s, int value) {
	if (isFull(s)) {
		printf("Stack is full\n");
	}
	else {
		s->items[++(s->top)] = value; // ��Ԫ��ѹ��ջ��
	}
}

int pop(Stack* s) {
	if (isEmpty(s)) {
		printf("Stack is empty\n");
		return -1;
	}
	else {
		return s->items[(s->top)--]; // ����ջ��Ԫ��
	}
}

void decimalToBinary(int x) {
	Stack s;
	init(&s);
	int y;

	while (x != 0) {
		y = x % 2;  // ȡ�������õ�������λ
		push(&s, y); // ��������λѹ��ջ
		x = x / 2;  // �����̼���ѭ��
	}

	printf("Binary������: ");
	while (!isEmpty(&s)) {
		printf("%d", pop(&s)); // ����ջ��Ԫ�ز���ӡ��ʵ�ֶ������������
	}
	printf("\n");
}

void decimalToHexadecimal(int x) {
	char hex[50]; // �����洢ʮ��������
	int i = 0;

	while (x != 0) {
		int remainder = x % 16; // ������������ʮ������λ
		if (remainder < 10) {
			hex[i] = remainder + 48; // ������ת��Ϊ�ַ���ʽ��������
		}
		else {
			hex[i] = remainder + 55; // ������ת��Ϊ��ĸ��ʽ��������
		}
		x = x / 16; // �����̼���ѭ��
		i++;
	}

	printf("Hexadecimalʮ������: ");
	for (int j = i - 1; j >= 0; j--) {
		printf("%c", hex[j]); // �����ӡ�����е��ַ����õ�ʮ��������
	}
	printf("\n");
}

int main() {
	int decimalNumber = 11; // ��ת����ʮ������
	decimalToBinary(decimalNumber); // ת��Ϊ�����Ʋ����
	decimalToHexadecimal(decimalNumber); // ת��Ϊʮ�����Ʋ����

	return 0;
}

//����ʵ��
//#include <stdio.h>
//
//void decimalToBinary(int x) {
//    int binary[32]; // �����洢������λ
//    int i = 0;
//
//    while (x > 0) {
//        binary[i] = x % 2; // ȡ�������õ�������λ
//        x = x / 2; // �����̼���ѭ��
//        i++;
//    }
//
//    printf("Binary: ");
//    for (int j = i - 1; j >= 0; j--) {
//        printf("%d", binary[j]); // �����ӡ�����еĶ�����λ
//    }
//    printf("\n");
//}
//
//void decimalToHexadecimal(int x) {
//    char hex[50]; // �����洢ʮ��������
//    int i = 0;
//
//    while (x != 0) {
//        int remainder = x % 16; // ������������ʮ������λ
//        if (remainder < 10) {
//            hex[i] = remainder + 48; // ������ת��Ϊ�ַ���ʽ��������
//        }
//        else {
//            hex[i] = remainder + 55; // ������ת��Ϊ��ĸ��ʽ��������
//        }
//        x = x / 16; // �����̼���ѭ��
//        i++;
//    }
//
//    printf("Hexadecimal: ");
//    for (int j = i - 1; j >= 0; j--) {
//        printf("%c", hex[j]); // �����ӡ�����е��ַ����õ�ʮ��������
//    }
//    printf("\n");
//}
//
//int main() {
//    int decimalNumber = 25; // ��ת����ʮ������
//    decimalToBinary(decimalNumber); // ת��Ϊ�����Ʋ����
//    decimalToHexadecimal(decimalNumber); // ת��Ϊʮ�����Ʋ����
//
//    return 0;
//}
