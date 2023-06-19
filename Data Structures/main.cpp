#include <iostream>
#include <string>
#include "testDoubleNode.h"
#include "linkedList-doc.h"

// Create a debugging checkpoint
void checkpoint(int p) {
    std::cout << "Checkpoint " << p << " reached!\n";
}

// Display node data
template <class L>
void displayNode(L const nd) {
    std::cout << "Current Node Data: " << nd.get_data() << "\n"; 
    return;
}

// Display the whole list along with the indexes of the list (not that you can access them lmao)
template <class C, typename T>
void displayList(linked_list<C, T>* const list) {
    C* currNode = list->get_head();
    unsigned int idx = 0;
    while (currNode != nullptr && idx < 100) {
        std::cout << "At index(" << idx << "): ";
        displayNode(*currNode);
        currNode = currNode->get_next();
        ++idx;
    }
    return;
}

#define intNode Node<int>, int

#define dND DoubleNode
#define str std::string
#define strDNode DoubleNode<std::string>, std::string

int main() {
    
    linked_list<strDNode>* dList = new linked_list<strDNode>();
    dND<str>* dNode1 = new dND<str>("1st");
    dND<str>* dNode2 = new dND<str>("2nd");
    auto dNode3 = new dND<str>("3rd");
    auto dNode4 = dND<str>("1st");

    auto insertNode = new dND<str>("Inserted!");

    dList->push_back(dNode1);
    dList->push_front(dNode2);
    dList->push_front(dNode3);
    dList->push_front(&dNode4);
    dList->insert_node(insertNode, 3);
    std::cout << "Test list with inserting regular pre-made nodes:\n";
    displayList(dList);

    



    return 0;
}