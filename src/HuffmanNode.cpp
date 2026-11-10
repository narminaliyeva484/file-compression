#include <iostream>
#include "HuffmanNode.h"

void generateCodes(Node* root,std::string code){
    if (root==nullptr){
        return;
    }

    if (root->left==nullptr && root->right==nullptr){
        std::cout <<root->character<< ": "<<code<< '\n';
        return;
    }

    generateCodes(root->left,code + "0");
    generateCodes(root->right,code + "1");
    
}