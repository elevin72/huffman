#ifndef huffmanTree_H
#define huffmanTree_H

#include "huffmanNode.h"
#include <queue>
#include <map>

class huffmanTree {
    public:
        void encode(std::string str);
        void print();
        huffmanTree() {
            root = NULL;
        }
        ~huffmanTree() {
            if (root)
                delete root;
            root = NULL;
        }

    private: 
        void fillPQueue(std::string str);
        huffmanNode* constructCode(std::string str);
        void encodeText(std::string str);
        void print(huffmanNode *n);
        void encodeTree(huffmanNode* active);
        void createTable(std::string path, huffmanNode* cur);
        void encodeMessage(std::string str);

        std::priority_queue<huffmanNode*, 
            std::vector<huffmanNode*>, 
            huffmanNode::compareNode> pQueue;
        std::map<char, std::string> table;
        huffmanNode *root;
        std::string characters;
        std::string encodedMessage;
        std::string encodedTree;
        int nLetters; // size of alphabet
};

#endif
