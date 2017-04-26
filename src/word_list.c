#include <stdlib.h> // EXIT_SUCCESS, malloc()
#include "word_list.h"

int main(void) {
    WordList *list = (WordList*) malloc(sizeof(WordList));

    word_list_ctor(list);
    word_list_append(list, "One");
    word_list_append(list, "Two");
    word_list_append(list, "Three");
    word_list_append(list, "Four");
    word_list_append(list, "Five");
    word_list_print(list);

    WordList *last = word_list_get_last(list);

    word_list_print_reversed(last);
    word_list_dtor(&list);

    return EXIT_SUCCESS;
}
