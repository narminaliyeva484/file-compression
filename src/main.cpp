
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include "HuffmanNode.h"

using namespace std;

int main() {

    // We'll test our Huffman components here.

    Node a('A', 8, nullptr, nullptr);
    Node b('B', 3, nullptr, nullptr);
    Node c('C', 2, nullptr, nullptr);

    priority_queue<Node*, vector<Node*>, Compare> pq;

    pq.push(&a);
    pq.push(&b);
    pq.push(&c);

    
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
    std::string input = "ABACAB";

    std::string result = encode(input, codes);

    std::cout << "Original: " << input << '\n';
    std::cout << "Encoded: " << result << '\n';

    return 0;
}
