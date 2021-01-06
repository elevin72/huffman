#include "huffmanTree.h"
#include "huffmanNode.h"
#include <vector>
#include <iostream>


void huffmanTree::encode(std::string str) {
    fillPQueue(str);
    root = constructCode(str);
}

void huffmanTree::print() {
    std::cout << "printing\n";
    print(pQueue.top());
}

void huffmanTree::print(huffmanNode *n) {
    if (n != NULL) {
        print(n->left);
        if ( n->c )
            std::cout << n->c << ": " << n->frequency << '\n';
        else 
            std::cout << "Empty node\n";
        print(n->right);
    }
}

void huffmanTree::fillPQueue(std::string str) {
    int length, frequency;
    huffmanNode *newNode;
    nLetters = 0;
    while (!str.empty()) {
        length = str.length();
        std::cout << "length:" << length << '\n';
        char c = str.at(0); // front?
        for (int i = 0; i < str.length(); ++i) {
            if (str.at(i) == c) {
                std::cout << "i:" << i << " char:" << c << '\n';
                std::cout << str << '\n';
                str.erase(i, 1);
                --i;
                ++frequency;
            }
        }
        std::cout << '\n';
        frequency = length - str.length();
        newNode = new huffmanNode(c, frequency);
        pQueue.push(newNode);
        ++nLetters;
    }
    std::cout << "nLetters:" << nLetters << '\n';
}

huffmanNode* huffmanTree::constructCode(std::string str) {
    huffmanNode *newNode, *rootNode;
    for (int i = 0; i < nLetters; ++i) {
        newNode = new huffmanNode('\0', 0);
        newNode->left = pQueue.top();
        pQueue.pop();
        newNode->right = pQueue.top();
        pQueue.pop();
        newNode->frequency = newNode->left->frequency + newNode->right->frequency;
        newNode->c = '\0';
        pQueue.push(newNode);
    }
    rootNode = pQueue.top();
    while (!pQueue.empty())
        pQueue.pop();
    return rootNode;
}

