#ifndef huffmanNode_H
#define huffmanNode_H

#include <string>

/* class compareNode; */ //is this necesary?
class huffmanNode {
    public: 
        huffmanNode(char _c, int _frequency) {
            c = _c;
            frequency = _frequency;
            right = left = NULL;
        }
        ~huffmanNode() {
            if (left) {
                delete left;
                left = NULL;
            }
            if (right) {
                delete right;
                right = NULL;
            }
        }
    private:
    char c;
    int frequency;
    huffmanNode *right;
    huffmanNode *left;

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
