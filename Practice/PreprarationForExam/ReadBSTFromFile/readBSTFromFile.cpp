#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <queue>
#include <string>

using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::nothrow;
using std::queue;
using std::string;
using std::vector;

const int INF = std::numeric_limits<int>::max();
const int STAR = std::numeric_limits<int>::min();
const int MINUS_INF = std::numeric_limits<int>::min();

struct Node
{
    int data;
    Node *leftChild;
    Node *rightChild;
    Node(int _data, Node *_leftChild = nullptr, Node *_rightChild = nullptr)
        : data(_data), leftChild(_leftChild), rightChild(_rightChild) {}
};

void freeTree(Node *&root)
{
    if (!root)
    {
        return;
    }

    freeTree(root->leftChild);
    freeTree(root->rightChild);

    delete root;
    root = nullptr;
}

void printTreeRec(string prefix, const Node *root, bool isLeft = false)
{
    if (root)
    {

        cout << prefix;
        cout << (isLeft ? "|--" : "`--");
        cout << root->data << endl;

        printTreeRec(prefix + (isLeft ? "|   " : "    "), root->leftChild, true);
        printTreeRec(prefix + (isLeft ? "|   " : "    "), root->rightChild, false);
    }
}

void printTree(const Node *root)
{
    printTreeRec("", root, false);
}

bool isBST(const Node *root)
{
    if (!root)
    {
        return true;
    }

    if (root->leftChild)
    {
        if (root->data < root->leftChild->data)
            return false;
    }

    if (root->rightChild)
    {
        if (root->data > root->rightChild->data)
            return false;
    }

    return isBST(root->leftChild) && isBST(root->rightChild);
}

bool areTreesEqual(const Node *first, const Node *second)
{
    if (!first && !second)
    {
        return true;
    }

    if (first->data != second->data)
    {
        return false;
    }

    if (first->leftChild && !second->leftChild)
        return false;
    else if (!first->leftChild && second->leftChild)
        return false;
    else if (first->rightChild && !second->rightChild)
        return false;
    else if (!first->rightChild && second->rightChild)
        return false;

    return areTreesEqual(first->leftChild, second->leftChild) &&
           areTreesEqual(first->rightChild, second->rightChild);
}

bool readNode(ifstream &in, Node *root, queue<Node *> &wave, Node *&outNode)
{
    string buffer;
    if (!(in >> buffer))
    {
        return true;
    }

    int element = STAR;

    if (buffer != "*")
    {
        element = std::stoi(buffer);
    }
    else
    {
        return true;
    }

    outNode = new (nothrow) Node(element);

    if (!outNode)
    {
        freeTree(root);
        return false;
    }

    wave.push(outNode);
    return true;
}

Node *createTree(const string &path)
{
    ifstream in(path);
    if (!in)
    {
        std::cerr << "Error: Couldn't open " << path << " for reading.\n";
        return nullptr;
    }

    int numberOfVertices = 0;
    int heightOfTree = 0;

    in >> numberOfVertices;
    in >> heightOfTree;

    if (numberOfVertices == 0)
    {
        return nullptr;
    }

    int element = 0;
    in >> element;
    Node *root = new (nothrow) Node(element);

    if (!root)
    {
        delete root;
        return nullptr;
    }

    std::queue<Node *> wave;
    wave.push(root);

    Node *curr = nullptr;

    while (!wave.empty())
    {
        curr = wave.front();
        wave.pop();

        if (!readNode(in, root, wave, curr->leftChild))
        {
            return nullptr;
        }

        if (!readNode(in, root, wave, curr->rightChild))
        {
            return nullptr;
        }
    }

    in.close();
    return root;
}

inline bool isValidNode(const Node *node) { return node && node->data != STAR; }

bool kthSmallestRec(const Node *root, size_t &kth, int &outSmallest)
{
    if (!isValidNode(root))
        return false;

    if (kthSmallestRec(root->leftChild, kth, outSmallest))
        return true;

    if (kth == 0)
    {
        outSmallest = root->data;
        return true;
    }

    --kth;

    if (kthSmallestRec(root->rightChild, kth, outSmallest))
        return true;

    return false;
}

int kthSmallest(const Node *root, size_t kth)
{
    int res = 0;
    kthSmallestRec(root, kth, res);
    return res;
}

int main()
{

    Node *tree = createTree("InputGraph1.txt");
    // if (isBST(tree))
    //{
    printTree(tree);
    //}

    int kThSmallest = 3;
    int kThSmallest1 = 6;
    // cout << kthSmallest(tree, kThSmallest);
    cout << kthSmallest(tree, kThSmallest1);

    freeTree(tree);

    return 0;
}