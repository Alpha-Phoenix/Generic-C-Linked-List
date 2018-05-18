#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "gcll.h"


void printElement(void *data);

int compare(const void *a, const void *b);

int main() {
    int ints[] = {1, 3, 2};
    for (int i = 0; i < 3; i++)
        printf("&ints[%d] = %p | ints[%d] = %d\n", i, &ints[i], i, ints[i]);
    puts("");

    void *array[] = {
            (void *) &ints[0],
            (void *) &ints[1],
            (void *) &ints[2]};

    for (int i = 0; i < 3; i++)
        printf("&array[%d] = %p | array[%d] = %p\n", i, &array[i], i, array[i]);

    puts("\nqsort()");
    qsort(array, 3, sizeof(void *), compare);


    puts("");
    return 0;

    unsigned size = sizeof(ints) / sizeof(int);

    LinkedList *list = GCLL_Create();

    for (unsigned i = 0; i < size; i++)
        GCLL_Push(list, i, &ints[i]);

    //GCLL_Sort(list, compare);


    //GCLL_ForEach(list, printElement);
    GCLL_Destroy(&list, NULL);
    assert(!list);
    return 0;
}

void printElement(void *data) {
    printf("%3d ", *(int *) data);
}

int compare(const void *a, const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;
    printf("%p %d | %p %d\n", x, *x, y, *y);
    return *x - *y;
}