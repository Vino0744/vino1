/*************************************************************************
	> File Name: tree.h
	> Author: 
	> Mail: 
	> Created Time: Thu 23 May 2024 08:09:45 PM CST
 ************************************************************************/

#ifndef _TREE_H
#define _TREE_H

#include <vector>
#include "pai.h"

class Node {
public:
    Node();
    Node(PAI *, int);
    int win;
    PAI *p;
    vector<Node *> child;
};

bool checkEmpty(int *);
void getTree(Node *, int *, int *);

#endif
