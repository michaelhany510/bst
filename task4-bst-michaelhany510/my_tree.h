#ifndef MY_TREE_H
#define MY_TREE_H

#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

template <class T>
struct Node{
    T key;
    Node *left;
    Node *right;
    Node(T k,Node *l,Node *r):key(k),left(l),right(r){}
};

template <class T>
class MyTree{

private:
    Node<T> *root;
    int sz;

    Node<T> *insert(int key,Node<T> *nd)
    {
        if(nd == NULL) nd = new Node<T>(key,NULL,NULL);
        else if(key < nd->key) nd->left = insert(key,nd->left);
        else nd->right = insert(key,nd->right);
        return nd;
    }
    void insertInterval(vector<T> &vec,int l,int r)
    {
        if(l > r || l < 0 || r >= vec.size()) return;
        int mid = (l+r)/2;
        insert(vec[mid]);
        insertInterval(vec,l,mid-1);
        insertInterval(vec,mid+1,r);
    }
    bool search(T key,Node<T> *nd) const
    {
        if(nd == NULL) return false;
        if(key == nd->key) return true;

        else if(key < nd->key) return search(key,nd->left);
        else return search(key,nd->right);
    }
    void inorder_rec(Node<T> *nd) const
    {
        if(nd == NULL) return;
        inorder_rec(nd->left);
        cout<<nd->key<<' ';
        inorder_rec(nd->right);
    }
    void preorder_rec(Node<T> *nd) const
    {
        if(nd == NULL) return;
        cout<<nd->key<<' ';
        preorder_rec(nd->left);
        preorder_rec(nd->right);
    }
    void postorder_rec(Node<T> *nd) const
    {
        if(nd == NULL) return;
        postorder_rec(nd->left);
        postorder_rec(nd->right);
        cout<<nd->key<<' ';
    }
    Node<T> *findMin(Node<T> *nd)
    {
        if(nd == NULL) return NULL;
        else if(nd->left == NULL) return nd;
        else return findMin(nd->left);
    }
    Node<T> *remove(int key,Node<T> *nd)
    {
        if(nd == NULL) return NULL;
        if(key < nd->key) return nd->left = remove(key,nd->left);
        else if(key > nd->key) return nd->right = remove(key,nd->right);
        else
        {
            //the node to be returned
            Node<T> *ret = NULL;

            //if the node has two children
            if(nd->left && nd->right)
            {
                //the minimun node to the right of the node to be removed takes
                //the place of the node to be removed. then we remove it, so that it does not occur twice.
                Node<T> *mn = findMin(nd->right);
                ret->key = mn->key;
                ret->left = nd->left;
                ret->right = remove(mn->key,nd->right);

            }

                //if the node has just one smaller child
            else if(nd->left)
            {
                ret = nd->left;
            }
                //if the node has just one bigger child
            else if(nd->right)
            {
                ret = nd->right;
            }
            delete nd;
            return ret;
        }
    }

public:
    MyTree()
    {
        root = NULL;
        sz = 0;
    }

    MyTree(vector<T> elements)
    {
        root = NULL;
        sz = 0;
        sort(elements.begin(),elements.end());
        insertInterval(elements,0,elements.size()-1);
    }

    bool search(T key) const
    {
        return search(key,root);
    }

    void insert(T key)
    {

        root = insert(key,root);
        sz++;
    }

    void inorder_rec() const
    {
        inorder_rec(root);
        cout<<endl;
    }

    void preorder_rec() const
    {
        preorder_rec(root);
        cout<<endl;
    }

    void postorder_rec() const
    {
        postorder_rec(root);
        cout<<endl;
    }

    void inorder_it() const
    {
        Node<T> *current = root;
        stack<Node<T> *> nodeStack;

        while(!nodeStack.empty() || current != NULL)
        {
            while(current != NULL)
            {
                nodeStack.push(current);
                current = current->left;
            }
            current = nodeStack.top();
            nodeStack.pop();

            cout<<current->key<<' ';

            current = current->right;
        }
        cout<<endl;
    }

    void preorder_it() const
    {
        stack<Node<T>*> nodeStack;
        nodeStack.push(root);

        //my implementation
//            while(!nodeStack.empty())
//            {
//                Node<T> *current = nodeStack.top();
//                nodeStack.pop();
//                while(current != NULL)
//                {
//                    cout<<current->key<<' ';
////                    cout<< (current->right == NULL) << ' ';
//                    if(current->right != NULL)
//                        nodeStack.push(current->right);
//                    current = current->left;
//                }
//
//            }
        //geeks for geeks implementation.
        while (nodeStack.empty() == false) {
            // Pop the top item from stack and print it
            Node<T>* node = nodeStack.top();
            cout<<node->key<<' ';
            nodeStack.pop();

            // Push right and left children of the popped node to stack
            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }
        cout<<endl;
    }

    void postorder_it() const
    {
        stack<Node<T>*>parentStack;
        stack<Node<T>*>childrenStack;
        childrenStack.push(root);
        while(!childrenStack.empty())
        {
            Node<T> *current = childrenStack.top();
            childrenStack.pop();
            parentStack.push(current);

            if(current->left)  childrenStack.push(current->left);
            if(current->right) childrenStack.push(current->right);

        }
        while(!parentStack.empty())
        {
            cout<<parentStack.top()->key<<' ';
            parentStack.pop();
        }
        cout<<endl;
    }

    void breadth_traversal() const
    {
        queue<Node<T> *> q;
        q.push(root);
        while(!q.empty())
        {
            Node<T> * parent = q.front();
            q.pop();
            cout<< parent->key<< ' ';
            if(parent->left) q.push(parent->left);
            if(parent->right) q.push(parent->right);
        }
        cout<<endl;
    }
    void remove(int key)
    {
        remove(key,root);
    }

    int size()
    {
        return sz;
    }
};

#endif