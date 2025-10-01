#include <iostream>
#include "BSTree.h"

using namespace std;


int main () {
    cout << "Hiya" << endl;
    BSTree<T>* L = new BSTree<T>();
    cout << L->locateNewLeaf(L->root, 5) << endl;
    return 0;
}