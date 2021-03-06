#ifndef huffmanNode_H
#define huffmanNode_H

#include <string>

/* class compareNode; */ //is this necesary?
class huffmanNode {
    public: 
        huffmanNode();
        huffmanNode(char _c, int _frequency);
        ~huffmanNode();
    private:
        char c;
        int frequency;
        huffmanNode *right;
        huffmanNode *left;
        huffmanNode *parent;

        friend class compareNode;
        friend class huffmanTree;

        class compareNode {
            public: 
                bool operator()(huffmanNode* const & n1, huffmanNode* const & n2) {
                    return n1->frequency > n2->frequency;
                }
        };
    
};

#endif 
