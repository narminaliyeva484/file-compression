#include <iostream>
#include "HuffmanNode.h"
#include <stdexcept>

void generateCodes(
    Node* root,
    std::string code,
    std::unordered_map<unsigned char, std::string>& codes
){
    if (root==nullptr){
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        codes[root->character] = code.empty() ? "0" : code;
        return;
    }

    generateCodes(root->left,code + "0",codes);
    generateCodes(root->right,code + "1",codes);
    
}

std::string encode(
    const std::string& input,
    const std::unordered_map<unsigned char, std::string>& codes
){
    std::string encoded="";
    for (char ch: input){
        encoded += codes.at(static_cast<unsigned char>(ch));
    }
    return encoded;
}

std::string decode(const std::string& encoded, Node* root) {
    std::string decoded = "";

    if (root == nullptr) {
        return decoded;
    }

    if (root->left == nullptr && root->right == nullptr) {
        for (char ch : encoded) {
            if (ch != '0') {
                throw std::invalid_argument("Invalid encoded bit");
            }

            decoded += root->character;
        }

        return decoded;
    }

    Node* current = root;

    for (char ch : encoded) {

        if (ch == '0') {
            current = current->left;
        }
        else if (ch == '1') {
            current = current->right;
        }
        else {
            throw std::invalid_argument("Invalid encoded bit");
        }

        if (current == nullptr) {
            throw std::invalid_argument("Invalid encoded sequence");
        }

        if (current->left == nullptr && current->right == nullptr) {
            decoded += current->character;
            current = root;
        }
    }

    if (current != root) {
        throw std::invalid_argument("Incomplete encoded sequence");
    }

    return decoded;
}