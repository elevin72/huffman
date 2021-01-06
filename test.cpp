#include "huffmanTree.h"
using namespace std;

int main () {
    string str = "aaaacccbbd";
    huffmanTree h;
    h.encode(str);
    h.print();
    return 0;
}
