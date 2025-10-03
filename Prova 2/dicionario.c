        //Suellen Teodorico dos Santos Silva
        //       15489275

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char english[46];
    char portuguese[46];
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char* english, char* portuguese) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->english, english);
    strcpy(newNode->portuguese, portuguese);
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertEnglishTree(Node* root, char* english, char* portuguese) {
    if (root == NULL) {
        return createNode(english, portuguese);
    }

    if (strcasecmp(english, root->english) < 0) {
        root->left = insertEnglishTree(root->left, english, portuguese);
    } else {
        root->right = insertEnglishTree(root->right, english, portuguese);
    }

    return root;
}

Node* insertPortugueseTree(Node* root, char* english, char* portuguese) {
    if (root == NULL) {
        return createNode(english, portuguese);
    }

    if (strcasecmp(portuguese, root->portuguese) < 0) {
        root->left = insertPortugueseTree(root->left, english, portuguese);
    } else {
        root->right = insertPortugueseTree(root->right, english, portuguese);
    }

    return root;
}

char* searchEnglishTree(Node* root, char* english) {
    while (root != NULL) {
        int cmp = strcasecmp(english, root->english);

        if (cmp == 0) {
            return root->portuguese;
        }

        if (cmp < 0) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NULL;
}

char* searchPortugueseTree(Node* root, char* portuguese) {
    while (root != NULL) {
        int cmp = strcasecmp(portuguese, root->portuguese);

        if (cmp == 0) {
            return root->english;
        }

        if (cmp < 0) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NULL;
}

void loadDictionary(char* filename, Node** englishTree, Node** portugueseTree) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char line[101], english[46], portuguese[46];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';

        if (line[0] == '#' || strlen(line) == 0) continue;

        if (sscanf(line, "%45[^,],%45[^,],#", english, portuguese) == 2) {
            *englishTree = insertEnglishTree(*englishTree, english, portuguese);
            *portugueseTree = insertPortugueseTree(*portugueseTree, english, portuguese);
        }
    }
    fclose(file);
}

void translateUSPT(Node* englishTree) {
    char word[46];
    while (1) {
        if (scanf(" %45[^,\n]", word) == EOF) break;

        if (strcmp(word, "#") == 0) {
            printf("#\n");
            break;
        }

        char* translation = searchEnglishTree(englishTree, word);
        if (translation) {
            printf("%s\n", translation);
        } else {
            printf("%s\n", word);
        }

        char delim;
        if (scanf("%c", &delim) == EOF) break;
        if (delim == '\n') break;
    }
}

void translatePTUS(Node* portugueseTree) {
    char word[46];
    while (1) {
        if (scanf(" %45[^,\n]", word) == EOF) break;

        if (strcmp(word, "#") == 0) {
            printf("#\n");
            break;
        }

        char* translation = searchPortugueseTree(portugueseTree, word);
        if (translation) {
            printf("%s\n", translation);
        } else {
            printf("%s\n", word);
        }

        char delim;
        if (scanf("%c", &delim) == EOF) break;
        if (delim == '\n') break;
    }
}

int main() {
    Node* englishTree = NULL;
    Node* portugueseTree = NULL;

    loadDictionary("dict.txt", &englishTree, &portugueseTree);

    char mode[6];
    if (scanf("%5[^,],", mode) == EOF) {
        printf("Erro na entrada.\n");
        return 1;
    }

    if (strcasecmp(mode, "USPT") == 0) {
        translateUSPT(englishTree);
    } else if (strcasecmp(mode, "PTUS") == 0) {
        translatePTUS(portugueseTree);
    } else {
        printf("Modo de tradução inválido.\n");
    }

    return 0;
}
