//
// Created by michael on 5/18/18.
//

#include <stdlib.h>
#include "gcll.h"

LinkedList *GCLL_Create(size_t size) {
    LinkedList *list;
    if ((list = (LinkedList*) malloc(sizeof(LinkedList))) == NULL)
        return NULL;
    list->size = 0;
    list->tsize = size;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void GCLL_Destroy(LinkedList **list, void* (*cleanup) (void*)) {
    // TODO clear list passing each element to be removed to the cleanup function.
    free(*list);
    *list = NULL;
}

int GCLL_Push(const LinkedList *list, const int pos, const void *data) {
    return 0;
}

void *GCLL_Pop(const LinkedList *list, int pos) {
    return NULL;
}


