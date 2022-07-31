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

class Tree{
public:
    queue<Node*> son;
    int num;
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

        if (node->lef != NULL) {
            node->lef->fathers = node;
        }

        node->rig = creatTree();

        if (node->rig != NULL) {
            node->rig->fathers = node;
        }

        if (node->lef == NULL && node->rig == NULL) {
            son.push(node);
        }

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
        tree.num = 0;
        tree.index = 0;
        tree.value = in;
        tree.head = tree.creatTree();

        queue<Node*> fath;
        while (!tree.son.empty()) {
            Node* nod = tree.son.front();
            tree.son.pop();
            fath.push(nod);
            cout << nod->data << " ";
        }
        cout << endl;

        while (!fath.empty()) {
            Node* nod = fath.front();
            fath.pop();
            cout << nod->fathers->data << " ";
        }
        cout << endl;
        //tree.pre(tree.head);
        //cout << endl;
        //cout << endl;
        //tree.mid(tree.head);
        //cout << endl;
        //tree.back(tree.head);
        //cout << endl;
    }
    return 0;
}