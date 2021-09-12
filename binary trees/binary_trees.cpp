#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int v;
        Node *left, *right;
        Node(int v){
            this->v = v;
            left = right = nullptr;
        }
};

Node* ConstructFromVals(vector<int>data, int i, Node *root){
    if (i < data.size())
    {
        Node* temp = data[i] == -1 ? nullptr : new Node(data[i]);
        root = temp;
 
        // insert left child
        root->left = ConstructFromVals(data, 2 * i + 1, root->left);
 
        // insert right child
        root->right = ConstructFromVals(data, 2 * i + 2, root->right);
    }
    return root;

}

Node* ConstructTree(){
    Node *root = nullptr;
    int x;
    
    cout<<"Enter data (-1 denotes for null node) : ";
    cin>>x;
    if(x==-1) return nullptr;
    root = new Node(x);
    
    cout<<"Enter left value for "<<x<<":-\n";
    root->left = ConstructTree();
    cout<<"Enter right value for "<<x<<":-\n";
    root->right = ConstructTree();

    return root;
}

void InorderTraversal(Node *root){
    if(!root) return;

    InorderTraversal(root->left);
    cout<<root->v<<" ";
    InorderTraversal(root->right);
    cout<<endl;
}

void PreorderTraversal(Node *root){
    if(!root) return;

    cout<<root->v<<" ";
    InorderTraversal(root->left);
    InorderTraversal(root->right);
    cout<<endl;
}

void PostorderTraversal(Node *root){
    if(!root) return;

    InorderTraversal(root->left);
    InorderTraversal(root->right);
    cout<<root->v<<" ";
    cout<<endl;
}

vector<vector<int>> levelorderTraversal(Node *root){
    vector<vector<int>> ans;
    
    if(!root) return ans; 

    queue<Node *>Q;
    Q.emplace(root);

    while(!Q.empty()){
        int size = Q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            Node *t = Q.front();
            Q.pop();
            if(t->left) Q.push(t->left);
            if(t->right) Q.push(t->right);
            level.push_back(t->v);
        }
        ans.push_back(level);
    }
    return ans;
}

void orderPrint(vector<vector<int>> data){
    for(auto it:data){
        for(auto k:it){
            cout<<k<<" ";
        }
        cout<<endl;
    }
}

int main() {

    vector<int> values {69,6,9,-1,2,4,-1};
    Node *root = nullptr;
    // root = ConstructFromVals(values,0,root);    
    root = ConstructTree();
    // InorderTraversal(root);
    // vector<vector<int>> ans = levelorderTraversal(root);
    // orderPrint(ans);

    return 0;
}