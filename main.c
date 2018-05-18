#include <stdio.h>
#include "gcll.h"

int main() {
    LinkedList *list = GCLL_Create(sizeof(long double));
    GCLL_Destroy(&list, NULL);
    return 0;
}