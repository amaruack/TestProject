#include <stdlib.h>

typedef struct island {
    char *name;
    char *open;
    char *close;
    struct island *next;
} island ;

island* create(char *name){
    island *p = malloc(sizeof(island));
    p -> name = strdup(name);
    p -> open = "09:00";
    p -> close = "17:00";
    p -> next = NULL;
    return p;
}

void display(island *il) {
    printf("island name = %s", il -> name);
}

void release(island *start) {
    island *i = start;
    island *next  = NULL;
    for (; i!=NULL ; i = next) {
        next = i->next;
        free(i->name);
        free(i);
    }
}
int main(int argc, char const *argv[])
{
    
    island *son = create("son island");
    island *son2 = create("son2 island");

    son -> next = son2;

    

    return 0;
}
