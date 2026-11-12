
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include "HuffmanNode.h"

using namespace std;

int main() {

    // We'll test our Huffman components here.

    Node a('A', 6, nullptr, nullptr);

    priority_queue<Node*, vector<Node*>, Compare> pq;

    pq.push(&a);
    

    
    while (pq.size() > 1){
        Node* first = pq.top();
        pq.pop();

        Node* second = pq.top();
        pq.pop();

        Node* parent = new Node('\0',first->frequency + second->frequency,first,second);
        pq.push(parent);

    }

    Node* root = pq.top();
    std::unordered_map<unsigned char, std::string> codes;
    generateCodes(root, "",codes);
    std::string input = "AAAAAA";

    std::string encoded = encode(input, codes);
    std::string decoded = decode(encoded, root);

    std::cout << encoded << '\n';
    std::cout << decoded << '\n';

    return 0;
}
