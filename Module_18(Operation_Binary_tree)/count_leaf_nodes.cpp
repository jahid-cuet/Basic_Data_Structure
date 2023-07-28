#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
       int value;
       Node* left;
       Node* right;
    Node(int value){
        this->value=value;
        this->left=NULL;
        this->right=NULL;
    }

};
 Node* input_tree(){
int value;
cin>>value;
Node* root;
if(value==-1) root=NULL;
else root=new Node(value);
queue<Node*>q;
if(root) q.push(root);
while(!q.empty()){
    //1.node ber kore ano
     Node* p=q.front();
    q.pop();
    //2. Jabotiyo kaj kora
    int l,r;
    cin>>l>>r;
    Node* myleft;
    Node* myright;
    if(l==-1) myleft=NULL;
    else myleft=new Node(l);
     if(r==-1) myright=NULL;
    else myright=new Node(r);
    p->left = myleft;
        p->right = myright;

        // 3. children gulo ke push koro
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}
int count_leaf(Node* root){

    if(root==NULL)return 0;
    if(root->left==NULL && root->right==NULL) return 1;
    else{

        int l=count_leaf(root->left);
        int r=count_leaf(root->right);
        return l+r;
    }
}


int main()
{
   Node* root=input_tree();
   cout<<count_leaf(root)<<" ";
     
    
    return 0;
}