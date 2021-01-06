#ifndef huffmanTree_H
#define huffmanTree_H

#include "huffmanNode.h"
#include <queue>
#include <map>

class huffmanTree {
    public:
        void encode(std::string str);
        void decode();
        void print();
        huffmanTree() {
            root = NULL;
        }
        ~huffmanTree() {
            if (root)
                delete root;
            root = NULL;
        }
        struct Code {
            int n;
            std::string characters;
            std::string tree;
            std::string text;
        } code;

    private: 
        //encoding functions
        void populateQueue(std::string str);
        huffmanNode* makeTreeFromText(std::string str);
        void encodeText(std::string str);
        void encodeTree(huffmanNode* active);
        void createTable(std::string path, huffmanNode* cur);
        void encodeMessage(std::string str);
        void getCharacters(huffmanNode *n);

        //decoding functions
        void getDecodingData();
        void makeTreeFromCode();
        void addCharactersToTree(huffmanNode *cur);
        void decodeMessage();


        std::priority_queue<huffmanNode*, 
            std::vector<huffmanNode*>, 
            huffmanNode::compareNode> pQueue;
        std::map<char, std::string> table;
        huffmanNode *root;
        int charCounter;

       /* int nLetters; // size of alphabet */
        /* std::string characters; */
        /* std::string encodedTree; */
        /* std::string encodedMessage; */
};

#endif
