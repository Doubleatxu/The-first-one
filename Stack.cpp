#include<iostream>
#include<stdlib.h>
#define STACK_INIT_SIZE 100;
#define STACKINCREMENT 10;
using namespace std;

typedef struct {//定义栈  
	int *base;
	int *top;
	int stacksize;

}SqStack;
/*-------------函数声明--------------*/ 
void InitStack(SqStack &S);

void DestoryStack(SqStack &S);

void ClearStack(SqStack &S);

bool StackEmpty(SqStack S);

int StackLength(SqStack S);

void GetTop(SqStack S, int e);

void Push(SqStack &S, int e);

void Pop(SqStack &S, int &e);

void StackTraverse(SqStack S, int(*visit()));

void conversion(SqStack &S,int &e);

/*-------------函数实现-----------*/ 
void InitStack(SqStack &S) {
	S.base = (int*)malloc(100* sizeof(int));
	if (!S.base)
		;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}

void DestoryStack(SqStack &S) {
	delete S.base;
	delete S.top;
}

void ClearStack(SqStack &S) {
	S.base = S.top = 0;
}

bool StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return true;
	return false;
}



int StackLength(SqStack S) {
	return S.top - S.base;
}

void GetTop(SqStack S, int e)
{
}



void Push(SqStack &S, int e) {
	if (S.top - S.base >= S.stacksize) {
		S.base = (int *)realloc(S.base, (S.stacksize + 10) * sizeof(int));
		if (!S.base)
			;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
}

void Pop(SqStack &S,int &e) {
	if (S.top == S.base)
		;
	e = *--S.top;
}

void StackTraverse(SqStack S, int(*visit()))
{
}

void conversion(SqStack &S,int &e) {
	InitStack(S);
	int N;
	//scanf("%d", N);
	cin >> N;
	while (N) {
		Push(S, N % 8);
		N = N / 8;
	}
	while (!StackEmpty(S)) {
		Pop(S, e);
		printf("%d", e);
	}
}
/*-------------main函数 --------*/
int main() {

	SqStack S;
	int e;
	conversion(S, e);
	return 0;

}
