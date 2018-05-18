/**
 * @author Michael Pacheco
 * @date 05/18/2018
 * @copyright TODO
 *
 * This file contains the definition of a Generic Linked List Abstract Data Type.
 * This ADT can storage <b>any</b> possible data type in C - <em>including user defined types</em>.
 * */

#ifndef GENERIC_LINKED_LIST_GCLL_H
#define GENERIC_LINKED_LIST_GCLL_H

#include <limits.h>

const int GCLL_HEAD  =  0;    ///< Flag used to insert/remove data from head (left)
const int GCLL_TAIL  = -1;   ///< Flag used to insert/remove data from tail (right)
const int GCLL_OK    =  1;
const int GCLL_ERROR = -1;

#include <stddef.h>

struct LinkedList;
struct Cell;
typedef struct LinkedList LinkedList;
typedef struct Cell Cell;

/**
 * This struct stores pointer for the head and the tail of the list, also it's size.
 * */
struct LinkedList {
    Cell *head;    ///< A pointer for the head cell.
    Cell *tail;    ///< A pointer for the tail cell.
    size_t tsize;  ///< The size in bytes of the data type that will be stored.
    size_t size;   ///< The current number of stored elements.
};

/**
 * This struct stores information about the data that will be stored into the list.
 * */
struct Cell {
    void *data;     ///< A pointer to the data.
    Cell *next;     ///< A pointer to the next cell.
    Cell *prev;     ///< A pointer to the previous cell.
};


/**
 * Create an empty list.
 * @param size the size in bytes of the data type to be stored. Use the sizeof operator.
 *        Example: LinkedList *list = GCLL_Create (sizeof(int)); This will create a list that stores integers.
 * @return A pointer to an empty list. If memory allocation fails it returns NULL.
 * */
LinkedList* GCLL_Create (size_t size);

/**
 * Clear the list and deallocate the memory. Set the pointer to NULL for security purpose.
 * @param list a address of a pointer to a list.
 * @param cleanup a pointer to a function that will be called for each data stored in the given list.
 * */
void GCLL_Destroy (LinkedList **list, void* (*cleanup) (void*));

/**
 * Insert a data into the given list.
 * @param list the list in which the data will be inserted.
 * @param pos the position in which the data will be inserted.
 *        Use the GCLL_HEAD to insert into the list head (left) and GCLL_TAIL to insert into the list tail (right).
 * @return GCLL_OK if success otherwise GCLL_ERROR.
 * */
int GCLL_Push (const LinkedList *list, int pos, const void* data);

/**
 * Remove a data into the given list.
 * @param list the list in which the data will be removed.
 * @param pos the position in which the data will be removed.
 *        Use the GCLL_HEAD to remove into the list head (left) and GCLL_TAIL to insert into the list tail (right).
 * @return A pointer to the data stored in the removed cell.
 * */
void* GCLL_Pop (const LinkedList *list, int pos);

#endif //GENERIC_LINKED_LIST_GCLL_H
