#include "huffmanTree.h"
#include "huffmanNode.h"
#include <vector>
#include <iostream>


void huffmanTree::encode(std::string str) {
    fillPQueue(str);
    root = constructCode(str);
    encodedTree = ""; // critical to the correctness of the following line
    encodeTree(root); // if 'encodedTree' isn't empty then this won't work
    createTable("", root);
    encodeMessage(str);
}

void huffmanTree::print() {
    std::cout << nLetters << '\n';
    print(root);
    std::cout << '\n' << encodedTree << '\n';
    std::cout << encodedMessage << '\n';
}

void huffmanTree::print(huffmanNode *n) {
    if (n != NULL) {
        print(n->left);
        if ( n->c )
            std::cout << n->c;
        print(n->right);
    }
}

void huffmanTree::fillPQueue(std::string str) {
    int length, frequency;
    huffmanNode *newNode;
    nLetters = 0;
    while (!str.empty()) {
        length = str.length();
        char c = str.at(0); // front?
        for (int i = 0; i < str.length(); ++i) {
            if (str.at(i) == c) {
                str.erase(i, 1);
                --i;
                ++frequency;
            }
        }
        frequency = length - str.length();
        newNode = new huffmanNode(c, frequency);
        pQueue.push(newNode);
        ++nLetters;
    }
}

huffmanNode* huffmanTree::constructCode(std::string str) {
    huffmanNode *newNode, *rootNode;
    for (int i = 0; i < nLetters-1; ++i) {
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

void huffmanTree::encodeTree(huffmanNode* active) {
    if(active->left) {
        encodedTree.push_back('0');
        encodeTree(active->left);
        encodeTree(active->right);
    }
    else {
        encodedTree.push_back('1');
    }
}

void huffmanTree::createTable(std::string path, huffmanNode* cur) {
    if (cur != NULL) {
        createTable(path+"0", cur->left);
        if ( cur->c )
            table[cur->c] = path; 
        createTable(path+"1", cur->right);
    }
}

void huffmanTree::encodeMessage(std::string str) {
    std::string letter;
    encodedMessage = "";
    for (int i = 0; i < str.length(); ++i) {
        encodedMessage += table[str.at(i)];
    }
}

