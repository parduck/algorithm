#include <stdio.h>

typedef struct BTN {
	int v; int cnt;
}Button;

struct BTN Q[400];
int sptr=0,eptr=0;

void push(Button t)
{
	Q[eptr] = t;
	eptr++;
}

struct BTN pop()
{
	sptr++;
	return Q[sptr-1];
}

void main()
{
	int a, b, i;
	struct BTN temp;

	scanf("%d %d", &a, &b);

	//bfs
	//push
	push((struct BTN){a,0});
	while (sptr<eptr) {
		temp = pop();
		if (temp.v == b)
			break;
		if (temp.v < b) {
			push((Button) { temp.v + 10, temp.cnt + 1 });
			push((Button) { temp.v + 5, temp.cnt + 1 });
			push((Button) { temp.v + 1, temp.cnt + 1 });
		}
		else {
			push((Button) { temp.v - 10, temp.cnt + 1 });
			push((Button) { temp.v - 5, temp.cnt + 1 });
			push((Button) { temp.v - 1, temp.cnt + 1 });
		}
	}
	printf("%d", temp.cnt);
	//printf("%d,%d", a, b);
}