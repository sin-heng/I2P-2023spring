#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    char ch;
    struct Node* next,* prev;
} Node;
int main(void){

    Node dummy_head, rear;
    Node* cursor,* tmp;
    int T,N;
    char ctmp;

    scanf("%d",&T);
    while(T--){
        dummy_head.prev = NULL;
        dummy_head.next = &rear;
        rear.prev = &dummy_head;
        rear.next = NULL;
        cursor = &dummy_head;
        scanf("%d",&N);
        getchar();
        while(N--){
            scanf("%c",&ctmp);
            if(ctmp=='R'){
                if(cursor->next!=NULL)
                    cursor = cursor->next;
            }
            else if(ctmp=='L'){
                if(cursor->prev!=NULL)
                    cursor = cursor->prev;
            }
            else if(ctmp=='B'){
                cursor->next->prev = cursor->prev;
                cursor->prev->next = cursor->next;
                tmp = cursor;
                cursor = cursor->prev;
                free(tmp);
            }
            else{
                tmp = (Node*)malloc(sizeof(Node));
                cursor->next->prev = tmp;
                tmp->next = cursor->next;
                cursor->next = tmp;
                tmp->prev = cursor;
                cursor = cursor->next;
                cursor->ch = ctmp;
            }
        }
        cursor = dummy_head.next;
        while(cursor!=&rear){
            printf("%c",cursor->ch);
            cursor = cursor->next;
            free(cursor->prev);
        }
        printf("\n");
    }

    return 0;
}