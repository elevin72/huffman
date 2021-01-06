#include "huffmanNode.h"

huffmanNode::huffmanNode(char _c, int _frequency) 
    : c(_c), frequency(_frequency) {
    right = left = NULL;
}

huffmanNode::~huffmanNode() {
    // the assumption here is that every node is some other node child except for root
    if (left) {
        delete left;
        left = NULL;
    }
    if (right) {
        delete right;
        right = NULL;
    }
}
