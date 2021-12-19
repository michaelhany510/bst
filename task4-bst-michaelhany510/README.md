[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=6588556&assignment_repo_type=AssignmentRepo)
# SBE307_Task 5 --> **B**inary **S**earch **T**ree

## Fill these info

### Name: ....

### Sec: ....

### B.N.: ....

### Did you implement remove function (YES|NO)? ...

### Did you implement a self balancing tree (YES|NO)? ...

## Task Explanation

- In this task you are required to build all the functions in my_tree.h
- There is my_tree_original.h file in case you need messed up my_tree.h, **don't edit my_tree_original.h**
- The functions are "constructors, search, insert, all depth_first traversal recursively and iteratively, breadth, size"
- search returns true if eement is found, else returns false
- size return the number of elements found in the tree
- all traversal functions should print the tree to the standard output.
- in my_tree.cpp, you will get the input from the user
- The input format will be as follows
  - first line: two numbers, **tree_size** **number_of_operations**
  - second line: **tree_size** elemnets, the initial elements to be inserted in the tree
  - **number_of_operations** lines: operations to be done on the tree, operations can be one of the following
    - 1 element --> insert element in the tree
    - 2 element --> search for element
    - 3 1 --> in_order_rec    ||  3 2 --> in_order_it
    - 4 1 --> pre_order_rec   ||  4 2 --> pre_order_it
    - 5 1 --> post_order_rec   ||  5 3 --> post_order_it
    - 6 --> breadth
    - 7 --> size

## Bonus

- implement remove function, you should keep the BST structure, left < node < right
- implement all the above functions for any kind of self balancing trees **AVL or RB Tree** in a new file called sbt.h 

## input example

- 3 3 // the initial tree size is 3, you are expecting 3 operations
- 1 2 3 // the elements to be inserted in the tree
- 7 // first operation, print the size should print 3
- 1 5 // second operation, insert 5 to the tree
- 3 1 // print the tree in_order recursively, should print 1 2 3 5

### General Notes

- This is an individual based assignment.
- The due date for the submission of this phase is Sunday, 20/12/2021 at 11:59 pm.
- Each hour delay will lead to one-point reduction in the homework’s grade.
- Your code should be clear, understandable, and documented (comments). Follow a consistent naming convention for variables and functions.
- You are permitted to discuss the following problems with others in the class. However, you must write up your own solutions to these problems. Any indication to the contrary will be considered an act of academic dishonesty.
