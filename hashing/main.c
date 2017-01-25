#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_NUM 9000000

struct schema {
	char name[100];
	int hash;
};
struct schema db[MAX_NUM + 1];

int strcpy(char *a, char *b)
{
	int i = 0;
	int hash = 0;
	while (a[i] != '\0') {
		b[i] = a[i];

		//해쉬만들어보기
		hash += (int)a[i] * (i+1)*10;

		i++;
		
	}
	b[i] = a[i];

	return hash;
}
int strlen(char *a) {
	int i = 0;
	while (a[i] != '\0') {
		i++;
	}
	return i;
}

int strcmp(char *a, char *b) {
	int i = 0;
	int len = strlen(a);
	/*
	while (a[i] != '\0') {
		if (a[i] != b[i])
			return 0;
		i++;
	}

	if (b[i] == '\0')
		return 1;
	else return 0;
	*/

	for (i = 0; i <= len; i++) {
		if (a[i] != b[i])
			return 0;
	}
		return 1;
}


void print()
{
	int i, max = 20;
	for (i = 0; i < max; i++) {
		printf("\n%s", db[i].name);
	}
}

int hash(char *a)
{
	int hash = 0,i=0;
	while (a[i] != '\0') {
		hash += (int)a[i] * (i + 1)*10;
		i++;
	}
	return hash;
}

void main()
{
	
	int i;
		
	clock_t t;

	t = clock();
	int a = 'a';
	//make datas
	for (i = 0; i < MAX_NUM; i++) {
		char tmp[] = "abcdefghijklmnopqrstuvwxyz";
		tmp[0] = rand() % 26 + 97;
		tmp[10] = rand() % 26 + 97;
		tmp[20] = rand() % 26 + 97;
		

		db[i].hash = strcpy(tmp,db[i].name);
	}
	
	print();

	t = clock()-t;
	printf("\n넣는데 소요시간:%f", (float)t / CLOCKS_PER_SEC);

	//search부분
	
	char target[] = "abcdefghijhlmnopqrstqvwxyz";
//	int t_hash = hash(target);
	int count = 0;


	//1.그냥
	t = clock();
	count = 0;
	for (i = 0; i < MAX_NUM; i++) {
		//if (t_hash == db[i].hash) {
		if (strcmp(target, db[i].name)) {
			//printf(",%d", i);
			count++;
		}
		//	}
	}
	printf("\n검색대상수 : %d", count);
	t = clock() - t;
	printf("\n그냥 찾기검색소요시간:%f", (float)t / 1000);

	//2.해싱
	t = clock();
	int t_hash = hash(target);
	count = 0;

	for (i = 0; i < MAX_NUM; i++) {
		if (t_hash == db[i].hash) {
			if (strcmp(target, db[i].name)) {
				//printf(",%d", i);
				count++;
			}
		}
	}
	printf("\n검색대상수 : %d", count);
	t = clock() - t;
	printf("\n해슁검색소요시간:%f", (float)t / 1000);

	
		
	
}