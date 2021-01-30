#include <iostream>
#include "tree.h"

int main()
{
    Tree<int> arbol;
    
    arbol.recursivePush(15);
    arbol.recursivePush(2);
    arbol.recursivePush(4);  
    arbol.recursivePush(6);
    arbol.recursivePush(1);
    arbol.recursivePush(16);
    arbol.recursivePush(3);

    arbol.recursiveInOrder();

    std::cout << 2 <<  " " << arbol.recursiveExists(2) << std::endl
              << 200 << " " << arbol.recursiveExists(200) << std::endl
              << 15 << " " << arbol.recursiveExists(15) << std::endl << std::endl; 
    arbol.recursiveRemove(1);
    arbol.recursiveInOrder();
    arbol.recursiveRemove(15);
    arbol.recursiveInOrder();
    std::cout << "SDFALÑKFJÑFKLJ" << std::endl;
    arbol.recursiveRemove(200);
    //arbol.recursiveRemove(1);
    //arbol.recursiveRemove(10);
    //arbol.recursiveRemove(15);
    arbol.recursiveInOrder();
    return 0;
}
