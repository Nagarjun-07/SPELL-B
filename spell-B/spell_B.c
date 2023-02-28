#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    bool isEndOfWord;
    struct TrieNode* children[ALPHABET_SIZE];
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }

    return node;
}

void insert(TrieNode* root, char* word) {
    TrieNode* node = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = tolower(word[i]) - 'a';

        if (node->children[index] == NULL) {
            node->children[index] = createNode();
        }

        node = node->children[index];
    }

    node->isEndOfWord = true;
}

bool search(TrieNode* root, char* word) {
    TrieNode* node = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = tolower(word[i]) - 'a';

        if (node->children[index] == NULL) {
            return false;
        }

        node = node->children[index];
    }

    return node->isEndOfWord;
}

int main() {
    char dictionary[][10] = {"hello", "world", "how", "are", "you", "doing"};
    TrieNode* root = createNode();

    // Insert words into Trie
    for (int i = 0; i < sizeof(dictionary) / sizeof(dictionary[0]); i++) {
        insert(root, dictionary[i]);
    }

    // Check if a word is present in Trie
    char word[10];
    printf("Enter a word: ");
    scanf("%s", word);

    if (search(root, word)) {
        printf("%s is present in dictionary.\n", word);
    } else {
        printf("%s is not present in dictionary.\n", word);
    }

    return 0;
}