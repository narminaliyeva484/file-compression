#include <iostream>
#include "HuffmanNode.h"

void generateCodes(
    Node* root,
    std::string code,
    std::unordered_map<unsigned char, std::string>& codes
){
    if (root==nullptr){
        return;
    }

    if (root->left==nullptr && root->right==nullptr){
        codes[root->character]=code;
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