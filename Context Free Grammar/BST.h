#ifndef BST_H
#define BST_H

#pragma once

#include <iostream>
using namespace std;

class Student_Node{
public:
    string Student_Name;
    int Student_Age;
    string Student_ID;
    string Student_Email;
    string Student_Password;
    Student_Node* leftchild;
    Student_Node* rightchild;

    Student_Node();
    Student_Node(string, int, string, string, string);
    Student_Node& operator=(Student_Node &);
};


class BinarySearchTree{
private:
    Student_Node* root;
public:
    BinarySearchTree();
    void AddNewRecord(string, int, string, string, string);
    void InOrderTraversalWrapper();
    void InOrderTraversal(Student_Node*);
    void PreOrderTraversalWrapper();
    void PreOrderTraversal(Student_Node*);
    int HeightWrapper();
    int Height(Student_Node*);
    void Display(Student_Node* ptr);
    Student_Node* Search(string);
    Student_Node* DeleteWrapper(string);
    Student_Node* DeleteNode(Student_Node*, string);
    Student_Node* InorderPredecessor(Student_Node*);
    Student_Node* InorderSuccessor(Student_Node*);

    string* ParseWords(string);

    void writeToFile(Student_Node*);
    bool Login();
    void SignUp();
};

#endif