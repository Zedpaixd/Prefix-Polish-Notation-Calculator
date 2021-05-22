#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>

#define NIL NULL

using namespace std;

int nrOfTokens;
int pos = 0;
vector<string> operations;

class tree
    {
    public:
        tree();
        tree* left;
        tree* right;
        string elem;
    };

tree::tree()
   {/*What do programmers and
    * the British have in common?
    * they both like to innit()
    * 
    * idk why i wrote that
    * but not having a constructor
    * for some reason ruins the
    * code completely and i
    * won't attempt to debug it
    * so i just added a joke
    * and a small wall of text
    * instead of actual code
    */}

tree* root;

void construct(tree* Root) 

    {if (pos < nrOfTokens) // so that we do not create unnecessarily many nodes that will have to be removed later
        {Root->elem = operations[pos];

        if (operations[pos] == "+" || operations[pos] == "-" || operations[pos] == "*" || operations[pos] == "/") // If current node is an operation, create 2 children
            
            {pos++;
            Root->left = new tree;  //done via recursion, adding all operations to the leftmost until ran out of, then adding numbers and backtracking to add to the right child too 
            construct(Root->left);

            pos++;
            Root->right = new tree;
            construct(Root->right);}

        else 

            {Root->left = NIL;
            Root->right = NIL;}
        
        }
    }

double calc(tree* pos)     //self explanatory, does the calculation of each called position
    {if (pos->elem == "+")
        return calc(pos->left) + calc(pos->right);
    
    if (pos->elem == "-")
        return calc(pos->left) - calc(pos->right);
    
    if (pos->elem == "*")
        return calc(pos->left) * calc(pos->right);

    if (pos->elem == "/")
        return (calc(pos->left)) / calc(pos->right);

    return stod(pos->elem);}


int main()
    {ifstream inputFile("input.txt");
    string input;

    /* The splitting is done based on spaces and a queue is made with all the operations and numbers*/

    inputFile.seekg(0, ios::end);
    input.reserve(inputFile.tellg());
    inputFile.seekg(0, ios::beg);
    input.assign((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    istringstream doesthiswork(input);

    string elements;

    while (getline(doesthiswork, elements, ' '))
        {operations.push_back(elements);
        nrOfTokens++;}

    root = new tree;

    construct(root);
    cout << calc(root);

    inputFile.close();}

