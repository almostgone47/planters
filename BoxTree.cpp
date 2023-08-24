//
// Created by Jeremiah Barro on 22/8/2023.
//

#include "BoxTree.h"
#include "BoxList.h"

//Name:   BoxList
//Desc:   Constructor for BoxList class.
//input:  none
//output: none
//return: none
BoxTree::BoxTree() {
    root = nullptr;
    totalLeaves = 0;
}

//Name:   ~BoxList
//Desc:   Destructor for BoxList class. The delete keyword deallocates memory and the pointers are
//        set to null so as not to leave dangling pointers.
//input:  none.
//output: none
//return: none
BoxTree::~BoxTree() {
    deleteTree(root);
};

void BoxTree::deleteTree(Node *&node) {
    if (node) {
        deleteTree(node->leftNode);
        deleteTree(node->rightNode);
        delete node->data;
        delete node;
        node = nullptr;
    }
}

//Name:   BoxTree
//Desc:   Copy constructor for BoxTree class.
//input:  none.
//output: none
//return: none
BoxTree::BoxTree(const BoxTree &tree) {
    root = nullptr;
    totalLeaves = 0;
    copyTree(root, tree.root);
}

void BoxTree::copyTree(Node *&newTree, Node *oldTree) {
    if (!oldTree) {
        newTree = nullptr;
        return;
    }

    newTree = new Node(oldTree->data);
    copyTree(newTree->leftNode, oldTree->leftNode);
    copyTree(newTree->rightNode, oldTree->rightNode);
}

//Name:   operator=
//Desc:   Redefines = to perform deep copy.
//input:  Reference to the linked list to copy from.
//output: none
//return: A reference to the linked list that used the method to copy.
const BoxTree & BoxTree::operator= (const BoxTree &tree) {
    if (this != &tree) {
        deleteTree(root);

        copyTree(root, tree.root);
        totalLeaves = tree.totalLeaves;
    }

    return *this;
}

void BoxTree::insert(Box *box) {
    if (!root) {
        root = new Node(box);
        totalLeaves = 1;
    } else {
        insert(root, box);
    }
}

void BoxTree::insert(Node *node, Box *box) {
    if (box->getNum() < node->data->getNum() && node->leftNode != nullptr) {
        insert(node->leftNode, box);
    } else if (box->getNum() < node->data->getNum()) {
        if (box->getNum() == 46765) {
            cout << "";
        }
        node->leftNode = new Node(box);
        totalLeaves++;
    } else if (box->getNum() > node->data->getNum() && node->rightNode != nullptr) {
        insert(node->rightNode, box);
    } else if (box->getNum() > node->data->getNum()) {
        if (box->getNum() == 46765) {
            cout << "";
        }
        node->rightNode = new Node(box);
        totalLeaves++;
    }
}

void BoxTree::remove(int boxNum)  {
    remove(root, boxNum);
}

void BoxTree::remove(Node *node, int boxNum)  {
    if (!node) {
        return;
    } else if (node->leftNode && boxNum == node->leftNode->data->getNum() || node->rightNode && boxNum == node->rightNode->data->getNum()) {
        deleteNode(node, boxNum);
    } else if (boxNum < node->data->getNum()) {
        remove(node->leftNode, boxNum);
    } else {
        remove(node->rightNode, boxNum);
    }
}

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

void BoxTree::restructureTree(Node *node) {
    if (!node)
        return;

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
        insert(root, tempLeftNode->data);
        restructureTree(tempLeftNode);
    }

    if (tempRightNode != nullptr) {
        insert(root, tempRightNode->data);
        restructureTree(tempRightNode);
    }

    delete node;
    totalLeaves--;
}


BoxList BoxTree::getRange(const int start, const int end) {
    BoxList list;
    getRangeRecursive(root, start, end, &list);
    return list;
}

void BoxTree::getRangeRecursive(Node *node, const int start, const int end, BoxList *list) {
    if (node == nullptr) {
        return;
    }

    int currNum = node->data->getNum();

    if (currNum == 45691) {
        cout << "";
    }

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

void BoxTree::printLeaves() {
    cout << totalLeaves << endl;
}

void BoxTree::inorder() {
    cout << "____________________________________________________" << endl << endl;
    printTree(root, 0);
    cout << "____________________________________________________" << endl << endl;
}

void BoxTree::printTree(Node *node, int level) {
    if (node == nullptr) {
        return;
    }

    printTree(node->rightNode, level + 1);

    for (int i = 0; i < level; ++i) {
        cout << "    ";
    }

    if (node->data) {
        cout << "+-- " << node->data->getNum() << endl;
    } else {
        cout << "+-- null" << endl;
    }

    printTree(node->leftNode, level + 1);
}