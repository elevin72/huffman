#include "huffmanTree.h"
using namespace std;

int main () {
    string str = "aaabbc";
    huffmanTree h;
    h.encode(str);
    h.print();
    h.decode();
    return 0;
}
