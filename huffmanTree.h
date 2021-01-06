#ifndef huffmanTree_H
#define huffmanTree_H

#include "huffmanNode.h"
#include <queue>

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
        void encodeTree(std::string str);

        std::priority_queue<huffmanNode*, 
            std::vector<huffmanNode*>, 
            huffmanNode::compareNode > pQueue;
        huffmanNode *root;
        std::string characters;
        int nLetters; // size of alphabet
};

#endif
