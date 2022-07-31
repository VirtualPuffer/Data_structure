#include <iostream>
#include<string>
#include<queue>
using namespace std;

class Node {
public:

    Node* fathers;
    char data;
    Node* par;
    Node* lef;
    Node* rig;
    ~Node() {};
    Node() {};
};

class Tree {
public:
    int high;
    queue<Node*> son;
    int num;
    string value;
    int index;
    Node* head;
    Node* creatTree(int i) {

        char get = value[index++];
        if (get == '0') {
            return NULL;
        }
        i++;
        if (i > high) {
            high = i;
        }
        Node* node = new Node();
        node->data = get;

        node->lef = creatTree(i);

        node->rig = creatTree(i);

        return node;
    };
    Tree() {
    };
    void pre(Node* node) {
        cout << node->data;
        if (node->lef != NULL) {
            pre(node->lef);
        }
        if (node->rig != NULL) {
            pre(node->rig);
        }
    };
};

int main() {
    int count;
    cin >> count;
    while (count--) {
        string in;
        cin >> in;
        Tree tree;
        tree.high = 0;
        tree.num = 0;
        tree.index = 0;
        tree.value = in;
        tree.head = tree.creatTree(0);
        cout << tree.high << endl;
    }
    return 0;
}