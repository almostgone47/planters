//
// Created by Jeremiah Barro on 22/8/2023.
//

#include "BoxTree.h"
#include "BoxList.h"

// Name:   BoxTree
// Desc:   Default Constructor
// input:  none
// output: none
// return: none
BoxTree::BoxTree() {
    root = nullptr;
    totalLeaves = 0;
}

// Name:   ~BoxList
// Desc:   Destructor
// input:  none
// output: none
// return: none
BoxTree::~BoxTree() {
    deleteTree(root);
};

// Name:   deleteTree
// Desc:   Recursively deletes the nodes in the tree rooted at the specified node, including the data contained in each node.
// Input:  A reference to a pointer pointing to the root node of the tree.
// Output: none
// Return: none
void BoxTree::deleteTree(Node *&node) {
    if (node) {
        deleteTree(node->leftNode);
        deleteTree(node->rightNode);
        delete node->data;
        delete node;
        node = nullptr;
    }
}

// Name:   BoxTree
// Desc:   Copy Constructor
// input:  none
// output: none
// return: none
BoxTree::BoxTree(const BoxTree &tree) {
    root = nullptr;
    totalLeaves = 0;
    copyTree(root, tree.root);
}

// Name:   copyTree
// Desc:   Recursively copies from the existing tree (oldTree) to create a new tree rooted at newTree.
// Input:  Reference to a pointer pointing to the root node of the new tree to be created and a Pointer to the
//         root node of the old tree to be copied.
// Output: none
// Return: none
void BoxTree::copyTree(Node *&newTree, Node *oldTree) {
    if (!oldTree) {
        newTree = nullptr;
        return;
    }

    newTree = new Node(oldTree->data);
    copyTree(newTree->leftNode, oldTree->leftNode);
    copyTree(newTree->rightNode, oldTree->rightNode);
}

// Name:   =
// Desc:   Assignment Operator
// input:  Reference to a BoxTree to copy from.
// output: none
// return: A reference to the BoxTree that used the method to copy.
const BoxTree & BoxTree::operator= (const BoxTree &tree) {
    if (this != &tree) {
        deleteTree(root);

        copyTree(root, tree.root);
        totalLeaves = tree.totalLeaves;
    }

    return *this;
}

// Name:   insert
// Desc:   Inserts a new Box into the BoxTree.
// input:  A pointer to the Box to be inserted.
// Output: none
// Return: none
void BoxTree::insert(Box *box) {
    if (!root) {
        root = new Node(box);
        totalLeaves = 1;
    } else {
        insertRecursive(root, box);
    }
}

// Name:   insertRecursive
// Desc:   Recursively inserts a new Box into the BoxTree rooted at the given node.
// input:  A pointer to the node where the insertion should start and a pointer to the Box to be inserted.
// output: none
// return: none
void BoxTree::insertRecursive(Node *node, Box *box) {
    int nodeBoxNum = node->data->getNum();
    int newBoxNum = box->getNum();

    if (newBoxNum < nodeBoxNum && node->leftNode != nullptr) {
        insertRecursive(node->leftNode, box);
    } else if (newBoxNum < nodeBoxNum) {
        node->leftNode = new Node(box);
        totalLeaves++;
    } else if (newBoxNum > nodeBoxNum && node->rightNode != nullptr) {
        insertRecursive(node->rightNode, box);
    } else if (newBoxNum > nodeBoxNum) {
        node->rightNode = new Node(box);
        totalLeaves++;
    }
}

// Name:   remove
// Desc:   Initiates the removal of a Box with the given box number from the BoxTree.
// input:  Box number to be removed.
// output: none
// return: none
void BoxTree::remove(int boxNum)  {
    removeRecursive(root, boxNum);
}

// Name:   removeRecursive
// Desc:   Recursively removes a Box with the given box number from the BoxTree rooted at the given node.
// input:  Pointer to the node where the removal should start and an integer representing the Box number to be removed.
// output: none
// return: none
void BoxTree::removeRecursive(Node *node, int boxNum)  {
    if (!node) {
        return;
    } else if ((node->leftNode && boxNum == node->leftNode->data->getNum()) || (node->rightNode && boxNum == node->rightNode->data->getNum())) {
        deleteNode(node, boxNum);
    } else if (boxNum < node->data->getNum()) {
        removeRecursive(node->leftNode, boxNum);
    } else {
        removeRecursive(node->rightNode, boxNum);
    }
}

// Name:   deleteNode
// Desc:   Deletes a node with the given box number from the BoxTree.
// input:  Pointer to the node where the deletion should occur and an integer representing the  box number to be deleted.
// output: none
// return: none
void BoxTree::deleteNode(Node *node, int boxNum) {
    if (!node)
        return;

    if (node->leftNode && node->leftNode->data->getNum() == boxNum) {
        Node *tempLeftNode = node->leftNode;
        delete node->leftNode->data;
        node->leftNode->data = nullptr;
        node->leftNode = nullptr;

        restructureTree(tempLeftNode);
    } else if (node->rightNode && node->rightNode->data->getNum() == boxNum) {
        Node *tempRightNode = node->rightNode;
        delete node->rightNode->data;
        node->rightNode->data = nullptr;
        node->rightNode = nullptr;

        restructureTree(tempRightNode);
    }
}

// Name:   restructureTree
// Desc:   Re-inserts nodes that were attached to removed node in order to restore the structure of the BoxTree.
// input:  Pointer to the node that was deleted.
// output: none
// return: none
void BoxTree::restructureTree(Node *node) {
    if (!node) {
        return;
    }

    Node *tempLeftNode = nullptr;
    Node *tempRightNode = nullptr;

    if (node->leftNode != nullptr) {
        tempLeftNode = node->leftNode;
        node->leftNode = nullptr;
    }

    if (node->rightNode != nullptr) {
        tempRightNode = node->rightNode;
        node->rightNode = nullptr;
    }

    if (tempLeftNode != nullptr) {
        insertRecursive(root, tempLeftNode->data);
        restructureTree(tempLeftNode);
    }

    if (tempRightNode != nullptr) {
        insertRecursive(root, tempRightNode->data);
        restructureTree(tempRightNode);
    }

    delete node;
    totalLeaves--;
}

// Name:   getRange
// Desc:   Retrieves a BoxList containing all boxes within the specified range of box numbers.
// input:  An integer representing the starting box number of the range and an integer representing the
//         ending box number of the range.
// output: none
// return: A BoxList containing boxes within the specified range.
BoxList BoxTree::getRange(const int start, const int end) {
    BoxList list;
    getRangeRecursive(root, start, end, &list);
    return list;
}

// Name:   getRangeRecursive
// Desc:   Recursively populates a BoxList with boxes from the BoxTree that fall within the specified range.
// input:  A pointer to the current node being examined.
//         An integer for the starting box number of the range.
//         An integer for the ending box number of the range.
//         A pointer to the BoxList to populate.
// output: none
// return: none
void BoxTree::getRangeRecursive(Node *node, const int start, const int end, BoxList *list) {
    if (node == nullptr) {
        return;
    }

    int currNum = node->data->getNum();

    if (currNum >= start) {
        getRangeRecursive(node->leftNode, start, end, list);
    }

    if (currNum >= start && currNum <= end) {
        list->insertAtTail(node->data);
    }

    if (currNum <= end) {
        getRangeRecursive(node->rightNode, start, end, list);
    }
}
