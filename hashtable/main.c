#include <stdio.h>
#include <malloc.h>
#include <time.h>
#define M_S 100

typedef struct node{
    int key;
    int val;

    struct node *head;
    struct node *next;
    struct node *link;
}node;

node *lnode[M_S];

void printA()
{
    int i;
    for(i=0;i<M_S;i++){
        node *tmp = lnode[i];
        if(tmp!=NULL)puts("");
        while(tmp!=NULL){
           printf("[%d,%d,%d] ",i,tmp->key,tmp->val);
           tmp = tmp->link;
        }

    }
}

void insert(int id,int val)
{
    //hash f
    int hval = (id*13)%M_S;

    node *tmp = (node *)malloc(sizeof(node));
    tmp->key = id;
    tmp->val = val;
    tmp->link =NULL;
    tmp->head=NULL;
    tmp->next=NULL;

    if(lnode[hval]==NULL){
        lnode[hval] = tmp;
    }else{
        tmp->link = lnode[hval];
        lnode[hval]=tmp;
    }
}

node *getN(int id)
{
    int val = (id*13)%M_S;

    node *tmp = lnode[val];
    while(tmp!=NULL){
        if(tmp->key==id){
            return tmp;
        }else{
            tmp = tmp->link;
        }
    }

    return NULL;
}

int main()
{
    printf("this is hash table(separate chaining hash)\n");

    time_t t = clock();
    /*
    insert(100101,111);
    insert(10011,222);
    insert(105101,333);
    insert(100601,444);
    insert(1001221,555);
    insert(100111,444);
    insert(100188,333);
    insert(14,333);
    insert(15,333);
    insert(6,333);
    insert(7878,33);
    insert(99888,33);
*/
    int i;
    for(i=1;i<1000;i++){

        insert(i,i+3);
    }


    printA();

    node * tmp = getN(111);
    printf("key:%d,val:%d\n",tmp->key,tmp->val);
    tmp = getN(12);
    printf("key:%d,val:%d\n",tmp->key,tmp->val);

    t=clock()- t;
    printf("time:%f",t/1000.);
    return 0;
}
