#include <stdio.h>
#include <string.h>
#include "lista.h"

int main() {
    TextEditor *editor = createEditor();
    char command;
    char word[MAX_WORD + 1];

    while (1) {
        scanf(" %c %s", &command, word);

        if (command == 'X' && strcmp(word, "editor") == 0) {
            break;
        }

        switch (command) {
            case 'I': insertAtStart(editor, word); break;
            case 'F': insertAtEnd(editor, word); break;
            case 'A': insertBeforeCursor(editor, word); break;
            case 'D': insertAfterCursor(editor, word); break;
            case 'P': searchWord(editor, word); break;
            case 'R': removeCurrentWord(editor); break;
            case 'G':
                if (strcmp(word, "inicio") == 0) moveCursorToStart(editor);
                else if (strcmp(word, "fim") == 0) moveCursorToEnd(editor);
                else if (strcmp(word, "prox") == 0) moveCursorToNext(editor);
                else if (strcmp(word, "ant") == 0) moveCursorToPrevious(editor);
                break;
            case 'L':
                if (strcmp(word, "texto") == 0) listAll(editor);
                else if (strcmp(word, "palavra") == 0) showCurrentWord(editor);
                break;
            case 'S': showStatistics(editor); break;
            default: break;  // Opcional, mas recomendado para lidar com comandos inválidos
        }
    }

    // Libera memória e finaliza o editor
    freeEditor(editor);
    return 0;
}
