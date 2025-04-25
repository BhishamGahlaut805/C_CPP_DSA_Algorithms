#include<iostream>
using namespace std;
//Implementation of Priority Queues Using Binary Search Tree

struct Node
{
    int key;
    Node *left;
    Node *right;

    Node(int val){
        key = val;
        left = right = NULL;
    }
};

class Priority_Queue{
    private:
        Node *root;

        //1.Insert into a BST
        Node*insert(Node*root,int key){
            if(root==NULL){
                return new Node(key);
            }
            if(key<=root->key){
                root->left = insert(root->left, key);
            }
            else{
                root->right = insert(root->right, key);
            }
            return root;
        }

        //2.Find the Maximum node(rightmost Node)
        Node*findMax(Node*root){
            while(root && root->right){
                root = root->right;
            }
            return root;
        }

        //3.Delete Maximum Element(rightmost Node)
        Node*deleteMax(Node*root){
            if(!root){
                return root;
            }
            if(!root->right){
                Node *temp = root->left;
                delete root;
                return temp;
            }
            root->right = deleteMax(root->right);
            return root;
        }

        //Inorder Traversal
        void inorder(Node*root){
            if(root==NULL){
                return;
            }
            else{
                inorder(root->left);
                cout << root->key << " ";
                inorder(root->right);
            }
        }

    public:
    Priority_Queue(){
        root = NULL;
    }

    //1.Insertion
    void push(int key){
        root = insert(root, key);
    }
    // 2.Deletion
    void pop(){
        if(!root){
            cout << "Priority Queue is Empty\n";
            return;
        }
        root = deleteMax(root);
    }

    //3.Get Highest Element
    int top(){
        Node *maxNode = findMax(root);
        if(maxNode){
            return maxNode->key;
        }
        cout << "Priority Queue is Empty\n";
        return -1;
    }

    //4.Display Elements
    void display(){
        cout << "Inorder Traversal of Priority Queue : ";
        inorder(root);
        cout << endl;
    }
};

int main(){
    Priority_Queue p;
    p.push(10);
    p.push(30);
    p.push(5);
    p.push(31);
    p.push(20);

    p.display();
    cout << "Highest Priority Element: " << p.top() << endl;
    p.pop();
    p.display();

    cout << "Highest Priority Element: " << p.top() << endl;
}