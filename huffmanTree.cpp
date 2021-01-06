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
    code.tree = ""; // critical to the correctness of the following line
    encodeTree(root);  
    getCharacters(root);
    // by now all the data is packaged in struct code, don't need nodes anymore
    delete root; 
}

void huffmanTree::print() {
    std::cout << code.n << '\n';
    std::cout << code.characters << '\n';
    std::cout << code.tree << '\n';
    std::cout << code.text << '\n';
}

void huffmanTree::getCharacters(huffmanNode *cur) {
    if (cur != NULL) {
        getCharacters(cur->left);
        if ( cur->c )
            code.characters += cur->c;
        getCharacters(cur->right);
    }
}

void huffmanTree::populateQueue(std::string str) {
    int length, frequency;
    huffmanNode *newNode;
    code.n = 0;
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
        ++code.n;
    }
}

huffmanNode* huffmanTree::makeTreeFromText(std::string str) {
    huffmanNode *newNode, *rootNode;
    for (int i = 0; i < code.n -1; ++i) {
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
    /* while (!pQueue.empty()) */
    /*     pQueue.pop(); */
    return rootNode;
}

void huffmanTree::encodeTree(huffmanNode* active) {
    if(active->left) {
        code.tree.push_back('0');
        encodeTree(active->left);
        encodeTree(active->right);
    }
    else {
        code.tree.push_back('1');
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
    code.text = "";
    for (int i = 0; i < str.length(); ++i) {
        code.text += table[str.at(i)];
    }
}


void huffmanTree::decode() {
    getDecodingData();
    makeTreeFromCode();
    charCounter = 0;
    addCharactersToTree(root);
    decodeMessage();
    std::cout << '\n';
}

void huffmanTree::getDecodingData() {
    std::cout << "enter n";
    std::cin >> code.n;
    std::cout << "enter the letters";
    do {
        std::cin >> code.characters;
        if (code.characters.length() != code.n)
            std::cout << "Size of alphabet must match number of characters!\n";
        else
            break;
    } while (true);
    std::cout << "enter the encoded structure";
    do {
        std::cin >> code.tree;
        if (code.tree.length() != (2*code.n)-1)
            std::cout << "size of tree must be 2n-1 !\n";
        else 
            break;
    } while (true);
    std::cout << "enter the encoded text";
    std::cin >> code.text;
}

void huffmanTree::makeTreeFromCode() {
    root = new huffmanNode('\0', 0);
    huffmanNode *active = root, *temp;
    for (int i = 0; i < code.tree.length(); ++i) {
        if (code.tree.at(i) == '0') {
            // create 2 new nodes
            active->left = new huffmanNode;
            active->right = new huffmanNode;
            active->left->parent = active;
            active->right->parent = active;
            active = active->left;
        }
        else {
            do {
                temp = active;
                active = active->parent;
            } while ( active && temp == active->right) ;
            if (!active)
                continue;
            active = active->right;
        }
    }
}


void huffmanTree::addCharactersToTree(huffmanNode *cur) {
    if (cur != NULL) {
        addCharactersToTree(cur->left);
        if (!cur->left)
            cur->c = code.characters.at(charCounter++);
        addCharactersToTree(cur->right);
    }
}

void huffmanTree::decodeMessage() {
    huffmanNode *cur;
    int i = 0;
    while (i < code.text.length()){
        cur = root;
        while (cur->left) {
            if (code.text.at(i) == '0')
                cur = cur->left;
            else
                cur = cur->right;
            ++i;
        }
        std::cout << cur->c;
    }
}
