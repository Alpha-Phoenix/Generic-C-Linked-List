#include <stdio.h>
#include <math.h>
#include "gcll.h"


void squareAndPrint(void *data);
void squareAndPrint(void *data) {
    *(int*)data = (int) pow(*(int*)data, 2);
    printf("%d ", *(int*)data);
}

int main() {
    LinkedList *list = GCLL_Create();
    int ints[] = {0, 1, 2, 3, 4};
    for (int i = 0; i < 5; ++i)
        GCLL_Push(list, GCLL_TAIL, &ints[i]);
    GCLL_ForEach(list, squareAndPrint);

    puts("");

    for (int i = 0; i < 5; ++i)
        printf("%d ", ints[i]);

    GCLL_Destroy(&list, NULL);
    return 0;
}