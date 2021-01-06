#include "huffmanNode.h"

huffmanNode::huffmanNode() {
    c = '\0';
    frequency = 0;
    right = left = parent = NULL;
}

// not sure why constructor overloading wasn't working
huffmanNode::huffmanNode(char _c, int _frequency) 
    : c(_c), frequency(_frequency) {
    right = left = parent = NULL;
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
