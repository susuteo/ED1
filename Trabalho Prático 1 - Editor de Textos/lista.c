#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

// Função para criar o editor de texto
TextEditor* createEditor() {
    TextEditor *editor = (TextEditor *) malloc(sizeof(TextEditor));
    editor->head = editor->tail = editor->cursor = NULL;
    editor->size = 0;
    return editor;
}

// Função para inserir no início
void insertAtStart(TextEditor *editor, const char *word) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    strncpy(newNode->word, word, MAX_WORD);
    newNode->word[MAX_WORD] = '\0';  // Garantir o término da string
    newNode->prev = NULL;
    newNode->next = editor->head;

    if (editor->head) {
        editor->head->prev = newNode;
    } else {
        editor->tail = newNode;  // Se for o primeiro nó, é também o último
    }
    
    editor->head = newNode;
    editor->cursor = newNode;
    editor->size++;
}

// Função para inserir no final
void insertAtEnd(TextEditor *editor, const char *word) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    strncpy(newNode->word, word, MAX_WORD);
    newNode->word[MAX_WORD] = '\0';
    newNode->next = NULL;
    newNode->prev = editor->tail;

    if (editor->tail) {
        editor->tail->next = newNode;
    } else {
        editor->head = newNode;  // Se for o primeiro nó, é também o primeiro
    }
    
    editor->tail = newNode;
    editor->cursor = newNode;
    editor->size++;
}

// Função para inserir antes do cursor
void insertBeforeCursor(TextEditor *editor, const char *word) {
    if (!editor->cursor) {
        insertAtStart(editor, word);
        return;
    }
    
    Node *newNode = (Node *) malloc(sizeof(Node));
    strncpy(newNode->word, word, MAX_WORD);
    newNode->word[MAX_WORD] = '\0';
    newNode->next = editor->cursor;
    newNode->prev = editor->cursor->prev;

    if (editor->cursor->prev) {
        editor->cursor->prev->next = newNode;
    } else {
        editor->head = newNode;
    }

    editor->cursor->prev = newNode;
    editor->cursor = newNode;
    editor->size++;
}

// Função para inserir depois do cursor
void insertAfterCursor(TextEditor *editor, const char *word) {
    if (!editor->cursor) {
        insertAtEnd(editor, word);
        return;
    }

    Node *newNode = (Node *) malloc(sizeof(Node));
    strncpy(newNode->word, word, MAX_WORD);
    newNode->word[MAX_WORD] = '\0';
    newNode->prev = editor->cursor;
    newNode->next = editor->cursor->next;

    if (editor->cursor->next) {
        editor->cursor->next->prev = newNode;
    } else {
        editor->tail = newNode;
    }

    editor->cursor->next = newNode;
    editor->cursor = newNode;
    editor->size++;
}

// Funções de movimentação do cursor e manipulação do editor
void moveCursorToStart(TextEditor *editor) { editor->cursor = editor->head; }
void moveCursorToEnd(TextEditor *editor) { editor->cursor = editor->tail; }
void moveCursorToNext(TextEditor *editor) { if (editor->cursor && editor->cursor->next) editor->cursor = editor->cursor->next; }
void moveCursorToPrevious(TextEditor *editor) { if (editor->cursor && editor->cursor->prev) editor->cursor = editor->cursor->prev; }

// Função para buscar uma palavra
void searchWord(TextEditor *editor, const char *word) {
    Node *current = editor->cursor;
    while (current) {
        if (strncmp(current->word, word, MAX_WORD) == 0) {
            editor->cursor = current;
            return;
        }
        current = current->next;
    }
}

// Função para remover a palavra atual
void removeCurrentWord(TextEditor *editor) {
    if (!editor->cursor) return;

    Node *toRemove = editor->cursor;

    if (toRemove->prev) {
        toRemove->prev->next = toRemove->next;
    } else {
        editor->head = toRemove->next;
    }

    if (toRemove->next) {
        toRemove->next->prev = toRemove->prev;
    } else {
        editor->tail = toRemove->prev;
    }

    editor->cursor = toRemove->prev;
    free(toRemove);
    editor->size--;
}

// Funções para listar e mostrar estatísticas
void listAll(TextEditor *editor) {
    Node *current = editor->head;
    while (current) {
        printf("%s ", current->word);
        current = current->next;
    }
    printf("\n");
}

void showCurrentWord(TextEditor *editor) {
    if (editor->cursor) {
        printf("%s\n", editor->cursor->word);
    }
}

void showStatistics(TextEditor *editor) {
    printf("%d\n", editor->size);
}

void replaceCurrentWord(TextEditor *editor, const char *word) {
    if (editor->cursor) {
        strncpy(editor->cursor->word, word, MAX_WORD);
        editor->cursor->word[MAX_WORD] = '\0';
    }
}

// Função para liberar a memória alocada pelo editor
void freeEditor(TextEditor *editor) {
    Node *current = editor->head;
    while (current) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    free(editor);
}
