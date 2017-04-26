#ifndef WORD_LIST_H
#define WORD_LIST_H

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200809L // POSIX.1-2008 Feature Test Macro
#endif

#include <stdbool.h> // true, false
#include <stdio.h>   // printf()
#include <stdlib.h>  // malloc()
#include <string.h>  // strncpy()

typedef struct _word_list {
    ssize_t index;
    char word[BUFSIZ];
    struct _word_list *prev;
    struct _word_list *next;
} WordList;

void word_list_ctor(WordList *list) {
    list->index = -1;
    list->prev = NULL;
    list->next = NULL;

    memset(list->word, '\0', BUFSIZ);
}

void word_list_append(WordList *list, char *word) {
    if (list->index == -1) {
        list->index += 1;

        strncpy(list->word, word, BUFSIZ);

        return;
    }

    WordList *current = list;
    WordList *new = (WordList*) malloc(sizeof(WordList));

    word_list_ctor(new);
    strncpy(new->word, word, BUFSIZ);

    while (current->next != NULL) {
        current = current->next;
    }

    new->prev = current;
    new->index = (current->index + 1);
    current->next = new;
}

void word_list_dtor(WordList **list) {
    WordList *current = *list;
    WordList *next;

    while (current != NULL) {
        next = current->next;

        free(current);

        current = next;
    }

    *list = NULL;
}

void word_list_print(WordList *list) {
    WordList *current = list;

    while (current != NULL) {
        printf("%s\n", current->word);

        current = current->next;
    }
}

void word_list_print_reversed(WordList *list) {
    WordList *current = list;

    while (current != NULL) {
        printf("%s\n", current->word);

        current = current->prev;
    }
}

WordList *word_list_get_last(WordList *list) {
    WordList *current = list;

    while (current->next != NULL) {
        current = current->next;
    }

    return current;
}

#endif // WORD_LIST_H
