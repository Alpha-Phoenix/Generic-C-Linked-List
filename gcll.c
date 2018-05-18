//
// Created by michael on 5/18/18.
//

#include <stdlib.h>
#include <assert.h>
#include "gcll.h"

const int GCLL_HEAD  =  0;
const int GCLL_TAIL  = -1;
const int GCLL_OK    =  1;
const int GCLL_ERROR = -1;

// +++++++++++++++++++++++++++++++++ Begin private declarations +++++++++++++++++++++++++++++++++
Cell* allocateCell (Cell *prev, Cell *next, void *data);
int insertFirstElement (LinkedList *list, void *data);
// ++++++++++++++++++++++++++++++++++ End private declarations ++++++++++++++++++++++++++++++++++


// ++++++++++++++++++++++++++++++++++ Begin global definitions ++++++++++++++++++++++++++++++++++
LinkedList *GCLL_Create() {
    LinkedList *list;
    if ((list = (LinkedList*) malloc(sizeof(LinkedList))) == NULL)
        return NULL;
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void GCLL_Destroy(LinkedList** const pplist, void (*const cleanup)(void *)) {
    LinkedList *list = *pplist;
    if (!GCLL_IsEmpty(list)) {
        // TODO best way
        for (Cell *cell = list->head;;) {
            Cell *next = cell->next;
            if (cleanup) cleanup(cell->data);
            free(cell);
            if (!next)
                break;
            cell = next;
        }
    }

    free(list);
    *pplist = NULL;
}

int GCLL_Push(LinkedList* const list, const int pos, void* const data) {
    if ((pos != GCLL_HEAD && pos != GCLL_TAIL) && (pos < 0 || pos > GCLL_GetSize(list)))
        return GCLL_ERROR;

    if (GCLL_IsEmpty(list))
        return insertFirstElement(list, data);

    Cell *newCell = allocateCell(NULL, NULL, data);
    if (!newCell)
        return GCLL_ERROR;

    switch (pos) {
        case GCLL_HEAD:
            newCell->next = list->head;
            list->head->prev = newCell;
            list->head = newCell;
            break;
        case GCLL_TAIL:
            newCell->prev = list->tail;
            list->tail->next = newCell;
            list->tail = newCell;
            break;
        default:
            // TODO insert in arbitrary position
            break;
    }

    list->size++;
    return GCLL_OK;
}

void* GCLL_Pop(const LinkedList *list, const int pos) {
    return NULL;
}

inline size_t GCLL_GetSize(const LinkedList *list) {
    return list->size;
}

inline bool GCLL_IsEmpty(const LinkedList *list) {
#ifdef GCLL_DEBUG
    if (list->size == 0)
        assert((size_t)(list->head == list->tail) &
               (size_t)(list->head == NULL));
#endif
    return list->size == 0;
}

void GCLL_ForEach(const LinkedList *list, void (*const f)(void *)) {
    for (Cell *cell = list->head; cell != NULL; cell = cell->next)
        f(cell->data);
}

// ++++++++++++++++++++++++++++++++++ End global definitions ++++++++++++++++++++++++++++++++++


// Private definitions
Cell* allocateCell (Cell* const prev, Cell* const next, void* const data) {
    Cell *newCell = (Cell*) malloc(sizeof(Cell));
    if (!newCell)
        return NULL;
    newCell->prev = prev;
    newCell->next = next;
    newCell->data = data;
    return newCell;
}

int insertFirstElement (LinkedList* const list, void* const data) {
    Cell *newCell = allocateCell(NULL, NULL, data);
    if (!newCell) return GCLL_ERROR;
    list->head = list->tail = newCell;
    list->size = 1;
    return GCLL_OK;
}
// End Private definitions
