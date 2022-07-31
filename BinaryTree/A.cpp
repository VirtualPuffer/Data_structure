#include <iostream>
#include<string>
#include<queue>
using namespace std;

class Node {
public:
    char data;
    Node* lef;
    Node* rig;
    ~Node() {};
    Node() {};
};

class Tree{
public:
    string value;
    int index;
    Node* head;
    Node* creatTree(){
        char get = value[index++];
        if (get =='0') {
            return NULL;
        }
        Node* node = new Node();
        node->data = get;

        node->lef = creatTree();
        node->rig = creatTree();

        return node;
    };
    Tree() {
        index = 0;
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
    void mid(Node* node) {

        if (node->lef != NULL) {
            mid(node->lef);
        }
        cout << node->data;
        if (node->rig != NULL) {
            mid(node->rig);
        }
    };
    void back(Node* node) {
        if (node->lef != NULL) {
            back(node->lef);
        }
        if (node->rig != NULL) {
            back(node->rig);
        }
        cout << node->data;
    };
};

int main() {

    int count;
    cin >> count;
    while (count--) {
        string in;
        cin >> in;
        Tree tree;
        tree.index = 0;
        tree.value = in;
        tree.head = tree.creatTree();
        tree.pre(tree.head);
        cout << endl;
        //cout << endl;
        tree.mid(tree.head);
        cout << endl;
        tree.back(tree.head);
        cout << endl;
    }
    return 0;
}