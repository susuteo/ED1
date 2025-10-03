#ifndef LISTA_H
#define LISTA_H

#define MAX_WORD 10

typedef struct Node {
    char word[MAX_WORD + 1];
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    Node *cursor;
    int size;
} TextEditor;

// Funções de manipulação do editor de texto
TextEditor* createEditor();
void insertAtStart(TextEditor *editor, const char *word);
void insertAtEnd(TextEditor *editor, const char *word);
void insertBeforeCursor(TextEditor *editor, const char *word);
void insertAfterCursor(TextEditor *editor, const char *word);
void moveCursorToStart(TextEditor *editor);
void moveCursorToEnd(TextEditor *editor);
void moveCursorToNext(TextEditor *editor);
void moveCursorToPrevious(TextEditor *editor);
void searchWord(TextEditor *editor, const char *word);
void removeCurrentWord(TextEditor *editor);
void listAll(TextEditor *editor);
void showCurrentWord(TextEditor *editor);
void showStatistics(TextEditor *editor);
void replaceCurrentWord(TextEditor *editor, const char *word);
void freeEditor(TextEditor *editor);

#endif
