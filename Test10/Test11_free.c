#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *question;
    struct node *no;
    struct node *yes;
} node ;

int yes_no(char *question){
    char answer[3];
    printf("%s? (y/n)", question);
    fgets(answer, 3, stdin);
    return answer[0] == 'y';
}

node* create(char *question){
    node *n = malloc(sizeof(node));
    n -> question = strdup(question);
    n -> no = NULL;
    n -> yes = NULL;
    return n;
}


void release(node *n) {
    if (n -> question) {
        free(n->question);
    }
    if (n -> no) {
        release(n->no);
    }
    if (n -> yes) {
        release(n->yes);
    }
    release(n);
}

int main()
{
    char question[80] ;
    char suspect[40] ;
    node *start_node = create("yes or no 1");
    start_node -> no = create("no answer 1");
    start_node -> yes = create("yes answer 1");

    node *current;
    do {
        current = start_node;
        while (1) {
            if (yes_no(current -> question)) {
                if (current -> yes) {
                    current = current -> yes;
                } else {
                    printf("피의자 확임됨 \n");
                    break;
                }
            } else if (current -> no){
                current = current ->no;
            } else {
                printf("new name? ");
                // fgets(suspect, 40, stdin);
                scanf("%79s", &suspect);
                node *yes_node = create(suspect);
                current -> yes = yes_node;

                node *no_node = create(current -> question);
                current -> no = no_node;

                printf("%s truequstion, %s falsequestion", suspect, current -> question) ;
                fgets(question, 80, stdin);
                current -> question = strdup(question);
                break;
            }
        };
    } while (yes_no("retry"));
    
    release(start_node);

    return 0;
}
