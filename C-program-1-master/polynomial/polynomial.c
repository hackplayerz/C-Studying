// 1233040 ������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct ListNode { // ���׽��� �� ���� ������ �����ϱ� ���� ��� ����ü
	int coef;
	int expon;
	struct ListNode *link;
} ListNode;

typedef struct ListHeader { // ��������� ������ �ϴ� ����ü
	int length;
	ListNode *head;
	ListNode *tail; // ���� ���� �ִ� ���׽��� ���� ������ �о�� �� �ִ�.
} ListHeader;

void init(ListHeader *plist); // ����Ʈ�� �ʱ�ȭ 
void error(char *message); // �����Ҵ� ���н� �����޽��� ���
void insert_node_last(ListHeader *plist, int coef, int expon); // ���ο� ��带 ����� ���� �Ҵ�

void poly_add(ListHeader *plist1, ListHeader *plist2, ListHeader *plist3); // ���Ḯ��Ʈ�� ������ ���׽��� ���� �Լ�
void poly_sub(ListHeader *plist1, ListHeader *plist2, ListHeader *plist3); // ���� �Լ�

void deletePoly(ListHeader *plist); // �����Ҵ�� ����Ʈ�� ��ȯ
void deleteWhiteSpace(char *poly1, char *poly2); // ����ڰ� �Է��� ���ڿ� �� ��ĭ�� �����ִ� �Լ�

void printUI(char *poly1, char *poly2); // �� ���� ���ڿ��� �� ���׽��� �Է� �޴� UI
int printInputUI(); // �Է� ���� ���׽��� �������� � ������ �� �� ��Ÿ���� UI

void changeStringToInteger(char *poly, ListHeader *list); // ����ڰ� �Է��� ���ڿ��� ���� ���·� ����� ������ ��ȯ
														  // ��ȯ�� ����� ���� ������ ����Ʈ�� ���ο� ��带 ����鼭 ���� (insert_node_last�� �Լ� ���� ����)

void poly_print(int nUser, ListHeader *plist); // �� ��쿡 ���� �´� ����ȭ�� ���׽� ���
											   // ����� 1�̰ų� ������ 1�̰ų� 0�� ���� ���� ��Ȳ���� �ΰ�ģȭ���� ǥ������ ���

void main() {
	char poly1[128];
	char poly2[128];
	int nUser;
	ListHeader list1, list2, list3; // list1, list2�� ����ڰ� �Է��� ���׽��� ���Ḯ��Ʈ�� ������ ����ü ����
									// list3�� �� ���׽��� ���� ����� �Էµ� ����ü ����

	printf("��������������������������������������������\n");
	printf("��   �й� : 1233040     �̸� : �� �� ��   ��\n");
	printf("��������������������������������������������\n");
	printf("��������������������������������������������\n");
	printf("��	  Start Polynomial Program 	 ��\n");
	printf("��������������������������������������������\n");

	do {
		init(&list1);	init(&list2);	init(&list3); // �� ����ü���� �ʱ�ȭ
		printUI(poly1, poly2); // ����ڷκ��� �Է� �޴� UI ���

		deleteWhiteSpace(poly1, poly2); // ����ڰ� �Է��� ���ڿ����� ������ ���� �Լ�

		changeStringToInteger(poly1, &list1); // ����ڰ� �Է��� ���׽� ���ڿ��� �������·� list1 ����ü ������ ����
		changeStringToInteger(poly2, &list2); // ����ڰ� �Է��� ���׽� ���ڿ��� �������·� list2 ����ü ������ ����

		nUser = 1; // �ʱ�ȭ�� ���� �ܼ� �� ���� ( + while���� ���Կ�)

		while ((nUser - '0') != 3) { // getch()�� �Է��� �ޱ� ������ �ƽ�Ű�ڵ尪���� ���
			nUser = printInputUI();
			switch (nUser - '0') { // �ƽ�Ű�ڵ尪���� ���, ����ڴ� �������̽� �󿡼� 1~4���� ������ �ȴ�
			case 1:
				poly_add(&list1, &list2, &list3);
				poly_print(nUser - '0', &list3);
				deletePoly(&list3); // ���� ������ ���� list3 ���� �޸� �ݳ� �� �ʱ�ȭ
				init(&list3);
				break;
			case 2:
				poly_sub(&list1, &list2, &list3);
				poly_print(nUser - '0', &list3);
				deletePoly(&list3); // ���� ������ ���� list3 ���� �޸� �ݳ� �� �ʱ�ȭ
				init(&list3);
				break;
			case 3: // ���α׷��� ������ϱ� �� �����Ҵ� ���� �޸𸮸� ���� �ݳ�
				deletePoly(&list1);	deletePoly(&list2);
				deletePoly(&list3);
				break;
			case 4: // ���α׷��� �����ϱ� �� �����Ҵ� ���� �޸𸮸� ���� �ݳ�
				deletePoly(&list1);	deletePoly(&list2);
				deletePoly(&list3);
				exit(1);
			}
		}
	} while ((nUser - '0') == 3);
}

void printUI(char *poly1, char *poly2) {
	printf("����������������������������������������������������������\n");
	printf("��    Input Two Polynomial That You Want To Calculate   ��\n");
	printf("����������������������������������������������������������\n");
	printf("		(1) : ");	gets(poly1);
	printf("		(2) : ");	gets(poly2);
}

int printInputUI() {
	printf("��������������������������������������������������������������������������������������������������������\n");
	printf("��       1. Poly Add		2. Poly Sub		3. Roll Back		4.Exit Program       ��\n");
	printf("��������������������������������������������������������������������������������������������������������\n");
	return (int)getch();
}

void init(ListHeader *plist) {
	plist->length = 0;
	plist->head = plist->tail = NULL;
}

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void insert_node_last(ListHeader *plist, int coef, int expon) {
	ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL)	error("�޸� �Ҵ� ����");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->length++;
}

void poly_add(ListHeader *plist1, ListHeader *plist2, ListHeader *plist3) {
	ListNode *a = plist1->head;
	ListNode *b = plist2->head;
	int sum;

	while (a != NULL && b != NULL) {
		if (a->expon == b->expon) {
			sum = a->coef + b->coef;
			if (sum != 0)	insert_node_last(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon > b->expon) {
			insert_node_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {
			insert_node_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}

	if (a != NULL) {
		for (; a != NULL; a = a->link) {
			insert_node_last(plist3, a->coef, a->expon);
		}
	}
	if (b != NULL) {
		for (; b != NULL; b = b->link) {
			insert_node_last(plist3, b->coef, b->expon);
		}
	}
}

void poly_sub(ListHeader *plist1, ListHeader *plist2, ListHeader *plist3) {
	ListNode *a = plist1->head;
	ListNode *b = plist2->head;
	int sum;

	while (a != NULL && b != NULL) {
		if (a->expon == b->expon) {
			sum = a->coef - b->coef;
			if (sum != 0)	insert_node_last(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon > b->expon) {
			insert_node_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {
			insert_node_last(plist3, (-1) * b->coef, b->expon);
			b = b->link;
		}
	}

	if (a != NULL) {
		for (; a != NULL; a = a->link) {
			insert_node_last(plist3, a->coef, a->expon);
		}
	}
	if (b != NULL) {
		for (; b != NULL; b = b->link) {
			insert_node_last(plist3, (-1) * b->coef, b->expon);
		}
	}
}

void deletePoly(ListHeader *plist) { // �����Ҵ� ���� ���׽��� �ݳ��ϴ� �Լ�
	ListNode *phead = plist->head;
	if (phead) {
		ListNode *p = phead;
		while (p != NULL) {
			phead = phead->link;
			free(p);
			p = phead;
		}
	}
}

void poly_print(int nUser, ListHeader *plist) { // ��¿� ���� ���� ����
	ListNode *p = plist->head;
	int nNode = plist->length;
	int cnt = 0;
	putchar('\n');
	switch (nUser) {
	case 1:
		printf("\tPoly Add\t���׽� ��� ���: ");
		break;
	case 2:
		printf("\tPoly Sub\t���׽� ��� ���: ");
		break;
	}

	for (; p; p = p->link) {
		cnt++;
		if (cnt == 1) { // ���׽� ù ��° ���� ����ó��
			if (p->coef < 0) { // ù ��° ���� ����� 0���� ���� ��
				if (p->coef == -1) { // ù ��° ���� ����� -1�� ��
					if (p->expon == 1) { // �ش� ������ 1�� ���� ��� ���� -x�� ���
						printf("\t\t-x ");
					}
					else if (p->expon == 0) { // �ش� ������ 0�� ���� ����� ���
						printf("\t\t%d ", p->coef);
					}
					else {
						printf("\t\t-x^%d ", p->expon); // ������ 1���� ũ�� ���� ���
					}
				}
				else { // ù ��° ���� ����� -2 ~ -9�� ��
					if (p->expon == 1) { // �ش� ������ 1�� ���� ��� (����) �� �Բ� x ���
						printf("\t\t%dx ", (p->coef));
					}
					else if (p->expon == 0) { // �ش� ������ 0�� ���� ��� (����) �� ���
						printf("\t\t%d ", p->coef);
					}
					else {
						printf("\t\t%dx^%d ", p->coef, p->expon); // ������ 1���� ũ�� ��� (����) �� �Բ� ���� ���
					}
				}
			}
			else if (p->coef > 0) { // ù ��° ���� ����� 0���� Ŭ ��
				if (p->coef == 1) { // ù ��° ���� ����� 1�� ��
					if (p->expon == 1) { // �ش� ������ 1�� ���� ��� ���� x�� ���
						printf("\t\tx ");
					}
					else if (p->expon == 0) { // �ش� ������ 0�� ���� ����� ���
						printf("\t\t%d ", p->coef);
					}
					else {
						printf("\t\tx^%d ", p->expon); // ������ 1���� ũ�� ���� ���
					}
				}
				else { // ����� 1���� Ŭ ��
					if (p->expon == 1) { // �ش� ������ 1�� ���� ����� x�� ���
						printf("\t\t%dx ", p->coef);
					}
					else if (p->expon == 0) { // �ش� ������ 0�� ���� ����� ���
						printf("\t\t%d ", p->coef);
					}
					else {
						printf("\t\t%dx^%d ", p->coef, p->expon);
					}
				}
			}
		}
		else {
			if (p->coef < 0) { // ���׽� ù ��° �� ������ ���� ���
				printf("- "); // ����� ������ ���� ������ = '-'
				if (p->coef == -1) { // ����� -1�� ��
					if (p->expon == 0) { // ������ 0�� ���� ����� ���
						printf("%d ", (-1) * (p->coef));
					}
					else if (p->expon == 1) { // ������ 1�� ���� x�� ��� (�տ� '-'�����ڰ� �ֱ� ������ x�� ���)
						printf("x ");
					}
					else { // ������ 1���� Ŭ �� �ش� ����� �������� ���
						printf("%dx^%d ", (-1) * (p->coef), p->expon);
					}
				}
				else { // ����� -2 ~ -9 �� ��
					if (p->expon == 0) { // ������ 0�� �� �ش� ����� ��� (-1�� ���ϴ� ������ �տ� '-'�����ڰ� �ֱ� ����)
						printf("%d ", (-1) * (p->coef));
					}
					else if (p->expon == 1) { // ������ 1�� �� �ش� ����� x�� ��� (�տ� '-'�����ڰ� �ֱ� ������ x�� ���)
						printf("%dx ", (-1) * (p->coef));
					}
					else {
						printf("%dx^%d ", (-1) * (p->coef), p->expon); // ������ 1���� Ŭ �� �ش� ����� �������� ���
					}
				}
			}
			else { // ����� ����� ��
				printf("+ ");
				if (p->coef == 1) { // ����� 1�� ��
					if (p->expon == 0) { // ������ 0�� ���� ����� ���
						printf("%d ", (p->coef));
					}
					else if (p->expon == 1) { // ������ 1�� ���� x�� ���
						printf("x ");
					}
					else { // ������ 1���� Ŭ ���� x�� ������ ���
						printf("x^%d ", p->expon);
					}
				}
				else { // ����� 1���� Ŭ ��
					if (p->expon == 0) { // ������ 0�� �� �ش� ����� ���
						printf("%d ", (p->coef));
					}
					else if (p->expon == 1) { // ������ 1�� �� �ش� ����� x�� ���
						printf("%dx ", (p->coef));
					}
					else {
						printf("%dx^%d ", (p->coef), p->expon);
					}
				}
			}
		}
	}
	printf("\n\n");
}

void deleteWhiteSpace(char *poly1, char *poly2) {
	char *tmp1, *tmp2;
	tmp1 = poly1;	tmp2 = poly2;
	while (strchr(poly1, ' ') != '\0') { // poly1�� ���� ���ڰ� ���� ��
		tmp1 = strchr(poly1, ' '); // ���鹮�ڰ� ��ġ�� ���� ���� ����
		*tmp1 = '\0';
		strcat(tmp1, tmp1 + 1); // 
	}
	while (strchr(poly2, ' ') != '\0') {
		tmp2 = strchr(poly2, ' ');
		*tmp2 = '\0';
		strcat(tmp2, tmp2 + 1);
	}
}

void changeStringToInteger(char *poly, ListHeader *list) {
	int coef;
	int expon;
	char chInt[128];
	int cnt = 0; // ����ڰ� �Է��� ����� �ڸ����� �ִ� 128�ڸ����� �ޱ� ���� �ʿ��� ī���ú���
	char *tmp = poly;
	while (*tmp != '\0') {
		if (*tmp == '-') { // �Էµ� ���� '-' �� ��� (���� ó�� ��ƾ)
			tmp++;
			if (*tmp >= 48 && *tmp <= 57) { // ����� ������ �� (0~9)
				if (*(tmp + 1) >= 48 && *(tmp + 1) <= 57) { // ���ӵ� ����� ������ ��
					cnt = 0; // �ʱ�ȭ�� �ȵǾ� ���� ���ɼ� ����
					while (*tmp != '\0' && *tmp != 'x' && *tmp != 'X' && *tmp != '+' && *tmp != '-') { // �� �ڸ� ������� Ȯ���ϴ� ��ƾ
						chInt[cnt++] = *(tmp++); // ĳ���� �迭�� ���ʴ�� ���� �� ������ �̵�
					}
					chInt[cnt] = '\0';
					coef = (-1) * atoi(chInt); // ���� ��� ����
					cnt = 0; // ī���� ���� �ʱ�ȭ
				}
				else { // ���ӵ� ����� �������� ���� ��, �� ����� �� �ڸ� �� �� ��
					coef = *(tmp++) - '0'; // ���� ����� ��������� ��, ������ �� ĭ �̵�
					coef *= (-1); // �����̱� ������ ���� ó���� ���ش�.
				}
				if (*tmp == 'x' || *tmp == 'X') { // �̵��� ��ġ�� ������ ���� ���
					if (*(tmp + 1) == '^') { // ������ 1�̻��� ���
						expon = (*(tmp + 2)) - '0';
						insert_node_last(list, coef, expon);
						tmp = tmp + 3;
					}
					else { // ������ 1�� ���
						expon = 1;
						insert_node_last(list, coef, expon);
						tmp++;
					}
				}
				else { // ������ ���� ������� ���
					expon = 0;
					insert_node_last(list, coef, expon);
				}
			}
			else if (*tmp == 'x' || *tmp == 'X') { // ����� -1, ������ ������ ��
				coef = -1;
				if (*(tmp + 1) == '^') { // ������ 1�̻��� ���
					expon = (*(tmp + 1)) - '0';
					insert_node_last(list, coef, expon);
					tmp = tmp + 3;
				}
				else { // ������ 1�� ���
					expon = 1;
					insert_node_last(list, coef, expon);
					tmp++;
				}
			}
		}
		else { // �Էµ� ���� '-'�� �ƴ� ��� (��� ó�� ��ƾ)
			if (*tmp == '+') {
				tmp++;
			}
			if (*tmp >= 48 && *tmp <= 57) { // ����� �������� �� (0~9)
				if (*(tmp + 1) >= 48 && *(tmp + 1) <= 57) { // ���ӵ� ����� ������ ��
					cnt = 0; // �ʱ�ȭ�� �ȵǾ� ���� �� ���� ���ɼ� ����
					while (*tmp != '\0' && *tmp != 'x' && *tmp != 'X' && *tmp != '+' && *tmp != '-') { // �� �ڸ� ������� Ȯ���ϴ� ��ƾ
						chInt[cnt++] = *(tmp++); // ĳ���� �迭�� ���ʴ�� ���� �� ������ �̵�
					}
					chInt[cnt] = '\0';
					coef = atoi(chInt); // ��� ����
					cnt = 0;
				}
				else { // ���ӵ� ����� �������� ���� ��, �� ����� �� �ڸ� �� �� ��
					coef = *(tmp++) - '0'; // ���� ����� ��������� ��, ������ �� ĭ �̵�
				}
				if (*tmp == 'x' || *tmp == 'X') { // �̵��� ��ġ�� ������ ���� ���
					if (*(tmp + 1) == '^') { // ������ 1�̻��� ���
						expon = (*(tmp + 2)) - '0'; // ĳ���ͷ� �ԷµǾ� �ִ� �����̱� ������ �ƽ�Ű �� 48�� �ش��ϴ� '0'�� ���ش�.
						insert_node_last(list, coef, expon);
						tmp = tmp + 3;
					}
					else { // ������ 1�� ���
						expon = 1;
						insert_node_last(list, coef, expon);
						tmp++;
					}
				}
				else { // ������ ���� ����� ���
					expon = 0;
					insert_node_last(list, coef, expon);
				}
			}
			else if (*tmp == 'x' || *tmp == 'X') { // ����� 1, ������ ������ ��
				coef = 1;
				if (*(tmp + 1) == '^') { // ������ 1�̻��� ���
					expon = (*(tmp + 1)) - '0';
					insert_node_last(list, coef, expon);
					tmp = tmp + 3;
				}
				else { // ������ 1�� ���
					expon = 1;
					insert_node_last(list, coef, expon);
					tmp++;
				}
			}
		}
	}
}