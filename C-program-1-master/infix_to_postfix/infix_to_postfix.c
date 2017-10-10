#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int element;
char evalchar[128]; // �������� ����� �� ����� ��������

typedef struct StackNode {
	element item;
	struct StackNode *link;
} StackNode;

typedef struct {
	StackNode *top;
	int count; // ������ ���� ������ ��Ÿ���ִ� ����
} LinkedStackType;

void init(LinkedStackType *s) {
	s->top = NULL;
	s->count = 0;
}

int is_empty(LinkedStackType *s) {
	return (s->top == NULL || s->count == 0);
}

int printUI();
void push(LinkedStackType*, element);
element pop(LinkedStackType*);
element peek(LinkedStackType*);
void deleteWhiteSpace(char *); // ����ڰ� �Է��� ���ڿ��� ������ ����
void make_stack_node(char *, LinkedStackType*); // �Է��� ���ڿ��� ����� ���� ������ ��ȯ
int prec(char);
void infix_to_postfix(LinkedStackType*); // �������� ���������� ��ȯ���
int eval(char*); // ���� ǥ�� ���� ����Լ�

void main() {
	char poly[128];
	int i;
	do {
		for (i = 0; i < 128; i++)
			evalchar[i] = NULL; // �������� �ʱ�ȭ
		LinkedStackType *s = (LinkedStackType *)malloc(sizeof(LinkedStackType));
		printf("���������� ���ڿ��� �Է��ϼ���.\n");
		gets(poly);
		printf("����ڰ� �Է��� ������: %s\n", poly);
		deleteWhiteSpace(poly); // ����ڰ� �Է��� �������� ���鹮�ڸ� ����
		make_stack_node(poly, s); // ����ڰ� �Է��� ���׽��� ����� ���� ������ ��ȯ
		printf("���������� ��ȯ �� ���: ");
		infix_to_postfix(s); // ���������� ��ȯ �� ���
		printf("�������� ����� ��: %d\n", eval(evalchar));
		free(s);
	} while (printUI() - '0' == 1);
	exit(1);
}

int printUI() {
	putchar('\n');
	printf("��� �Ͻðڽ��ϱ�?\n");
	printf("1 : �ٽ� ó������ \t 2 : ���α׷� ����\n");
	return getch();
}

void push(LinkedStackType *s, element item) {
	StackNode *temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL)
		fprintf(stderr, "�޸� �Ҵ翡��\n");
	else {
		temp->item = item;
		temp->link = s->top;
		s->top = temp;
		(s->count)++;
	}
}

element pop(LinkedStackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		StackNode *temp = s->top;
		element item = temp->item;
		s->top = s->top->link;
		free(temp);
		(s->count)--;
		return item;
	}
}

element peek(LinkedStackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		return s->top->item;
	}
}

void deleteWhiteSpace(char *poly) {
	char *tmp;
	tmp = poly;
	while (strchr(poly, ' ') != '\0') { // poly1�� ���� ���ڰ� ���� ��
		tmp = strchr(poly, ' '); // ���鹮�ڰ� ��ġ�� ���� ���� ����
		*tmp = '\0';
		strcat(tmp, tmp + 1); // 
	}
}

void make_stack_node(char *poly, LinkedStackType *s) {
	int i, len;
	len = strlen(poly);
	init(s);
	for (i = 0; i < len; i++) {
		push(s, poly[i]);
	}
}

int prec(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

void infix_to_postfix(LinkedStackType* s) {
	int i = 0;
	char ch, top_op;
	char evalch;
	int eval_result;
	LinkedStackType p; // ������ ����� ����� ���ó�� s�� ����� ������ �Ųٷ� ������ ���� ���� p
	LinkedStackType *temp = (LinkedStackType *)malloc(sizeof(LinkedStackType));
	// ���� ��ȯ�� ������ ������ ����� ����Ÿ���� ������
	init(&p);
	while (!is_empty(s)) { // ������ ����� ���ó�� s�� ���ְ� �� ������ �ٲ� �״�� p�� �ű��.
		push(&p, pop(s));
	}
	init(temp); 
	while(!is_empty(&p)) {
		ch = pop(&p);
		switch (ch) {
		case '+': case '-': case '*': case '/': // ������
			while (!is_empty(temp) && (prec(ch) <= prec(peek(temp)))) {
				evalch = pop(temp);
				printf("%c", evalch);
				evalchar[i++] = evalch;
			}
			push(temp, ch);
			break;
		case '(':
			push(temp, ch);
			break;
		case ')':
			top_op = pop(temp);
			while (top_op != '(') {
				printf("%c", top_op);
				evalchar[i++] = top_op;
				top_op = pop(temp);
			}
			break;
		default:
			printf("%c", ch);
			evalchar[i++] = ch;
			break;
		}
	}

	while (!is_empty(temp)) { // ���ÿ� ����� �����ڵ� ���
		evalch = pop(temp);
		printf("%c", evalch);
		evalchar[i++] = evalch;
	}
	putchar('\n');
	evalchar[i] = '\0';
	free(temp);
}

int eval(char *evalch) {
	int op1, op2, value, i = 0;
	int len = strlen(evalch);
	char ch;
	LinkedStackType temp;
	init(&temp);
	for(i=0; i<len; i++) {
		ch = evalch[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			// �Է��� �ǿ������� ���
			value = ch - '0';
			push(&temp, value);
		}
		else {
			op2 = pop(&temp); // ������ ����
			op1 = pop(&temp); // ������ ���� 
			switch (ch) {
			case '+': push(&temp, op1 + op2); break;
			case '-': push(&temp, op1 - op2); break;
			case '*': push(&temp, op1 * op2); break;
			case '/': push(&temp, op1 / op2); break;
			}
		}
	}
	return pop(&temp);
}