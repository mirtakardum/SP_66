#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

struct list;
typedef struct list* Pozicija;
typedef struct list {
	int br;
	Pozicija next;
}_list;

void push(Pozicija, int);
void pop(Pozicija);
void print(Pozicija);
int createRandom();


int main() {
	_list head;
	_list stogHead;
	head.next = NULL;
	stogHead.next = NULL;
	Pozicija last = &head;
	char a = ' ';
	char b, pom;
	int broj = 0;

	srand(time(0));

	while (a != '\n') {
		printf("Zelite li urediti stog(S) ili red(R)?\nZa izlaz pritisnite enter\n");
		a = getchar();
		pom = getchar();

		switch (toupper(a)) {
		case 'S':
			printf("Zelite li dodati(D) ili skinuti(S) element?\n");
			scanf(" %c", &b);
			switch (toupper(b)) {
			case 'D':
				broj = createRandom();
				push(&stogHead, broj);
				break;

			case 'S':
				pop(&stogHead);
				break;

			default:
				printf("Pogresan unos, unesite D ili S!");
				break;


			}
			break;

		case 'R':
			printf("Zelite li dodati(D) ili skinuti(S) element?\n");
			scanf(" %c", &b);
			switch (toupper(b)) {
			case 'D':
				broj = createRandom();
				push(last, broj);
				last = last->next;

				break;

			case 'S':
				pop(&head);
				break;

			default:
				printf("Pogresan unos, unesite D ili S!");
				break;

			}
			break;

		case '\n':
			break;

		default:
			printf("Pogresan unos!");
			break;
		}
		printf("Stog: ");
		print(&stogHead);
		printf("\nRed: ");
		print(&head);
		printf("\n");
		pom = getchar();
	}
}

void push(Pozicija p, int n) {
	Pozicija q = NULL;
	q = (Pozicija)malloc(sizeof(Pozicija));

	if (q == NULL) {
		printf("Greska pri alokaciji!");
		return -1;
	}

	q->br = n;

	q->next = p->next;
	p->next = q;
}

void pop(Pozicija p) {
	if (p->next == NULL) {
		printf("Lista je vec prazna.");
		return;
	}
	Pozicija temp = p->next;

	p->next = temp->next;
	free(temp);
}

int createRandom() {
	int a = rand() % 91 + 10;

	return a;
}

void print(Pozicija p) {
	p = p->next;

	while (p != NULL) {
		printf("%d ", p->br);
		p = p->next;
	}
}