//
// Created by Di Yang on 2022/4/24.
//

#ifndef _TREE_H
#define _TREE_H

#include <iostream>
#include <string>

using namespace std;
typedef struct TreeNode {
    char Data;
    struct TreeNode *lc, *rc;
} TreeNode, *BT;

    void CreatedTree(BT &tree) {
        char ch;
        cin >> ch;
        if (ch == '#')tree = NULL;
        else {
            tree = new TreeNode;
            tree->Data = ch;
            CreatedTree(tree->lc);
            CreatedTree(tree->rc);
        }
    }

    void FindTreeF(BT tree) {
        if (tree) {
            cout << tree->Data;
            FindTreeF(tree->lc);
            FindTreeF(tree->rc);
        }
    }

    void FindTreeZ(BT tree) {
        if (tree) {
            FindTreeZ(tree->lc);
            cout << tree->Data;
            FindTreeZ(tree->rc);
        }
    }

    void FindTreeH(BT tree) {
        if (tree) {
            FindTreeH(tree->lc);
            FindTreeH(tree->rc);
            cout << tree->Data;
        }
    }

    int Depth(BT &tree) {
        if (tree == NULL) return 0;
        else {
            int m = Depth(tree->lc);
            int n = Depth(tree->rc);
            if (m > n)return (m + 1);
            else return (n + 1);
        }
    }

    int NodeTree(BT &tree) {
        if (tree == NULL)return 0;
        else return (NodeTree(tree->rc) + NodeTree(tree->lc) + 1);
    }

    void DeleteTree(BT &tree) {
        if (tree) {
            DeleteTree(tree->lc);
            DeleteTree(tree->rc);
            cout << "1";
            delete tree;
            cout << "0";
        }
    }

#endif //_TREE_H