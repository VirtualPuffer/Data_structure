#include <iostream>
#include<string>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* lef;
    Node* rig;
    ~Node() {};
    Node() {};
};

class Tree {
public:
    int* value;
    Node* head;
    Node* creatTree(int index,int leng) {

        if (!(index < (leng+1))) {
            return NULL;
        }
        int get = value[index - 1];
        if(get == 0) {
            return NULL;
        }

        Node* node = new Node();
        node->data = get;
        node->lef = creatTree(index*2,leng);
        node->rig = creatTree(index*2+1,leng);

        return node;
    };
    Tree() {
    };
    void pre(Node* node) {
        cout << node->data << " ";
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
        int num;
        cin >> num;

        int* in = new int[num];
        for (int i = 0; i < num; i++) {
            int r;
            cin >> r;
            in[i] = r;
        }

        Tree tree;
        tree.value = in;
        tree.head = tree.creatTree(1,num);
        tree.pre(tree.head);
        cout << endl;
    }
    return 0;
}