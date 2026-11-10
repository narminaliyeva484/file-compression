#include <string>

#pragma once


struct Node {
    unsigned char character;
    int frequency;

    Node* left;
    Node* right;

    Node(unsigned char ch, int freq,
         Node* l, Node* r) {
        character = ch;
        frequency = freq;
        left = l;
        right = r;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency;
    }
};

void generateCodes(Node* root, std::string code);