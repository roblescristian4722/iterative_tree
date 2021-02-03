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
    
    std::cout << "Enorden: " << std::endl;
    arbol.inOrder();
    std::cout << "Preorden: " << std::endl;
    arbol.preOrder();
    std::cout << "Postorden: " << std::endl;
    arbol.postOrder();

    std::cout << "existe 2: " << arbol.recursiveExists(2) << std::endl
              << "existe 200: " << arbol.recursiveExists(200) << std::endl
              << "existe 15: " << arbol.recursiveExists(15) << std::endl << std::endl; 
    
    std::cout << "existe 2: " << arbol.exists(2) << std::endl
              << "existe 200: " << arbol.exists(200) << std::endl
              << "existe 15: " << arbol.exists(15) << std::endl;

    arbol.remove(1);
    arbol.recursiveInOrder();
    arbol.remove(15);
    arbol.recursiveInOrder();
    std::cout << "SDFALÑKFJÑFKLJ" << std::endl;
    arbol.recursiveRemove(200);
    //arbol.recursiveRemove(1);
    //arbol.recursiveRemove(10);
    //arbol.recursiveRemove(15);
    arbol.recursiveInOrder();
    return 0;
}
