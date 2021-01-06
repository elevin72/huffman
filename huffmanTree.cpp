#include "huffmanTree.h"
#include "huffmanNode.h"
#include <vector>
#include <iostream>

void huffmanTree::encode(std::string str) {
    //each line in this function does/creates something necessary for the next line
    populateQueue(str);
    root = makeTreeFromText(str); // based on queue
    createTable("", root);  // based on tree
    encodeMessage(str);     // based on table
    encodedTree = ""; // critical to the correctness of the following line
    encodeTree(root);  
    // delete tree
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

void huffmanTree::populateQueue(std::string str) {
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

huffmanNode* huffmanTree::makeTreeFromText(std::string str) {
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


void huffmanTree::decode() {
    getDecodingData();
    makeTreeFromCode();
    decodeMessage();
}

void huffmanTree::getDecodingData() {
    std::cout << "enter n";
    std::cin >> nLetters;
    std::cout << "enter the letters";
    do {
        std::cin >> characters;
        if (characters.length() != nLetters)
            std::cout << "Size of alphabet must match number of characters!\n";
        else
            break;
    } while (true);
    std::cout << "enter the encoded structure";
    do {
        std::cin >> encodedTree;
        if (encodedTree.length() != (2*nLetters)-1)
            std::cout << "size of tree must be 2n-1 !\n";
        else 
            break;
    } while (true);
    std::cout << "enter the encoded text";
    std::cin >> encodedMessage;
}

void huffmanTree::makeTreeFromCode() {
    huffmanNode *newNode = new huffmanNode('\0', 0);
    huffmanNode *active;
    buildTree(root, 0);


}

void huffmanTree::buildTree(huffmanNode *active, huffmanNode *prev, int i) {
    if (active->left) {

    }
    if (!encodedTree.at(i)) {
        // construct 2 nodes, insert them and make active = left one
        
    }
    else {
        // get first right child of ancestor

    }
}

void huffmanTree::decodeMessage() {
    huffmanNode *cur = root;
    for (int i = 0; i < encodedMessage.length(); ++i) {

    }

}
