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

    {if (pos < nrOfTokens) 
        {Root->elem = operations[pos];

        if (operations[pos] == "+" || operations[pos] == "-" || operations[pos] == "*" || operations[pos] == "/")
            
            {pos++;
            Root->left = new tree;
            construct(Root->left);

            pos++;
            Root->right = new tree;
            construct(Root->right);}

        else 

            {Root->left = NIL;
            Root->right = NIL;}
        
        }
    }

double evaluate(tree* pos)
    {if (pos->elem == "+")
        return evaluate(pos->left) + evaluate(pos->right);
    
    if (pos->elem == "-")
        return evaluate(pos->left) - evaluate(pos->right);
    
    if (pos->elem == "*")
        return evaluate(pos->left) * evaluate(pos->right);

    if (pos->elem == "/")
        return (evaluate(pos->left)) / evaluate(pos->right);

    return stod(pos->elem);}


int main()
    {ifstream inputFile("input.txt");
    string input;

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
    cout << evaluate(root);

    inputFile.close();}

