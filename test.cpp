#include "huffmanTree.h"
using namespace std;

int main () {
    string str = "Hi my name is Nechama and I like to eat shit!";
    huffmanTree *h  = new huffmanTree;
    h->encode(str);
    h->print();
    delete h;
    return 0;
}
