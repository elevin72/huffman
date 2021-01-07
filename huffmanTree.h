#ifndef huffmanTree_H
#define huffmanTree_H

#include "huffmanNode.h"
#include <queue>
#include <map>

class huffmanTree {
    public:
        huffmanTree(){}
        ~huffmanTree();
        void encode(std::string str);
        void decode();

    private: 
        //encoding functions
        void clear();
        void populateQueue(std::string str);
        huffmanNode* makeTreeFromText(std::string str);
        void encodeTree(huffmanNode* active);
        void createTable(std::string path, huffmanNode* cur);
        void encodeText(std::string str);
        void getCharacters(huffmanNode *n);

        //decoding functions
        void getDecodingData();
        void makeTreeFromCode();
        void addCharactersToTree(huffmanNode *cur);
        void decodeText();

        void print();

        std::priority_queue<huffmanNode*, 
            std::vector<huffmanNode*>, 
            huffmanNode::compareNode> pQueue;
        std::map<char, std::string> table;
        huffmanNode *root;
        int charCounter;

        struct Code {
            int n;
            std::string characters;
            std::string tree;
            std::string text;
        } code;
};

#endif
