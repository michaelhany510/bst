#include <iostream>
#include "my_tree.h"

using namespace std;

int main(int argc, char** argv){

//    freopen("input.in","rt",stdin);
//    MyTree<int> bst;
    int elementsNum,opNum;
    cin >> elementsNum >> opNum;

    vector<int> elements;

    for (int i = 0; i < elementsNum; ++i) {
        int x;
        cin>>x;
        elements.push_back(x);
    }
    MyTree<int> bst(elements);

//    bst.inorder_rec();

    while(opNum--)
    {
        int opType;
        cin>>opType;
        if(opType == 1)
        {
            int element;
            cin>>element;
            bst.insert(element);
        }
        else if(opType == 2)
        {
            int element;
            cin>>element;
            cout << (bst.search(element)?"1 ":"0")<<endl;
        }
        else if(opType == 3)
        {
            int secondOperation;
            cin>>secondOperation;
            if(secondOperation == 1) bst.inorder_rec();
            else bst.inorder_it();
        }
        else if(opType == 4)
        {
            int secondOperation;
            cin>>secondOperation;
            if(secondOperation == 1) bst.preorder_rec();
            else bst.preorder_it();
        }
        else if(opType == 5)
        {
            int secondOperation;
            cin>>secondOperation;
            if(secondOperation == 1) bst.postorder_rec();
            else bst.postorder_it();
        }
        else if (opType == 6)
        {
            bst.breadth_traversal();
        }
        else
        {
            cout<<bst.size()<<' '<<'\n';
        }
    }


//input example
//3 3
//1 2 3
//7
//1 5
//3 1


//test
//3 8
//8 6 1
//1 0
//1 7
//1 3
//1 9
//3 2
//5 2
//2 8
//2 11

//


//7 8
//6 7 3 4 2 1 5
//3 1
//3 2
//4 1
//4 1
//5 1
//5 3
//6
//7

//3 3
//2 3 1
//1 4
//7
//3 1

}