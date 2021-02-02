#include <iostream>
#include "tree.h"

int main()
{
    Tree<int> arbol;
    
    arbol.push(15);
    arbol.push(2);
    arbol.push(4);  
    arbol.push(6);
    arbol.push(1);
    arbol.push(16);
    arbol.push(3);

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
