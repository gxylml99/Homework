

////分别用栈和数组实现十进制转换成十六和二进制
////栈实现
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
	int items[MAX_SIZE];
	int top;
} Stack;

void init(Stack* s) {
	s->top = -1; // 初始化栈顶指针为-1，表示栈为空
}

int isFull(Stack* s) {
	return s->top == MAX_SIZE - 1; // 判断栈是否已满
}

int isEmpty(Stack* s) {
	return s->top == -1; // 判断栈是否为空
}

void push(Stack* s, int value) {
	if (isFull(s)) {
		printf("Stack is full\n");
	}
	else {
		s->items[++(s->top)] = value; // 将元素压入栈顶
	}
}

int pop(Stack* s) {
	if (isEmpty(s)) {
		printf("Stack is empty\n");
		return -1;
	}
	else {
		return s->items[(s->top)--]; // 弹出栈顶元素
	}
}

void decimalToBinary(int x) {
	Stack s;
	init(&s);
	int y;

	while (x != 0) {
		y = x % 2;  // 取余数，得到二进制位
		push(&s, y); // 将二进制位压入栈
		x = x / 2;  // 更新商继续循环
	}

	printf("Binary二进制: ");
	while (!isEmpty(&s)) {
		printf("%d", pop(&s)); // 弹出栈顶元素并打印，实现二进制数的输出
	}
	printf("\n");
}

void decimalToHexadecimal(int x) {
	char hex[50]; // 用来存储十六进制数
	int i = 0;

	while (x != 0) {
		int remainder = x % 16; // 计算余数，即十六进制位
		if (remainder < 10) {
			hex[i] = remainder + 48; // 将余数转换为字符形式存入数组
		}
		else {
			hex[i] = remainder + 55; // 将余数转换为字母形式存入数组
		}
		x = x / 16; // 更新商继续循环
		i++;
	}

	printf("Hexadecimal十六进制: ");
	for (int j = i - 1; j >= 0; j--) {
		printf("%c", hex[j]); // 倒序打印数组中的字符，得到十六进制数
	}
	printf("\n");
}

int main() {
	int decimalNumber = 11; // 待转换的十进制数
	decimalToBinary(decimalNumber); // 转换为二进制并输出
	decimalToHexadecimal(decimalNumber); // 转换为十六进制并输出

	return 0;
}

//数组实现
//#include <stdio.h>
//
//void decimalToBinary(int x) {
//    int binary[32]; // 用来存储二进制位
//    int i = 0;
//
//    while (x > 0) {
//        binary[i] = x % 2; // 取余数，得到二进制位
//        x = x / 2; // 更新商继续循环
//        i++;
//    }
//
//    printf("Binary: ");
//    for (int j = i - 1; j >= 0; j--) {
//        printf("%d", binary[j]); // 倒序打印数组中的二进制位
//    }
//    printf("\n");
//}
//
//void decimalToHexadecimal(int x) {
//    char hex[50]; // 用来存储十六进制数
//    int i = 0;
//
//    while (x != 0) {
//        int remainder = x % 16; // 计算余数，即十六进制位
//        if (remainder < 10) {
//            hex[i] = remainder + 48; // 将余数转换为字符形式存入数组
//        }
//        else {
//            hex[i] = remainder + 55; // 将余数转换为字母形式存入数组
//        }
//        x = x / 16; // 更新商继续循环
//        i++;
//    }
//
//    printf("Hexadecimal: ");
//    for (int j = i - 1; j >= 0; j--) {
//        printf("%c", hex[j]); // 倒序打印数组中的字符，得到十六进制数
//    }
//    printf("\n");
//}
//
//int main() {
//    int decimalNumber = 25; // 待转换的十进制数
//    decimalToBinary(decimalNumber); // 转换为二进制并输出
//    decimalToHexadecimal(decimalNumber); // 转换为十六进制并输出
//
//    return 0;
//}
