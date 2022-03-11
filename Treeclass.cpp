
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

template<typename T>
class TreeNode
{
    public:
    T data;
    vector<TreeNode<T>*>children;

    TreeNode(T data)
    {
        this->data=data;
    }
};

TreeNode<int>* TakeInputLevel()
{
    int rootData;
    cout<<"enter the root data"<<endl;
    cin>>rootData;

    TreeNode<int>*root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    
    while(!pendingNodes.empty())
    {
        TreeNode<int>*Front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"enter the numChild of"<<Front->data<<endl;
        cin>>numChild;

        for(int i=0;i<numChild;i++)
        {
            int childData;
            cout<<"enter the "<<i<<"th child data"<<endl;
            cin>>childData;

            TreeNode<int>*child = new TreeNode<int>(childData);
            Front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
   return root;
}

void print(TreeNode<int>*root)
{
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++)
    {
        cout<<(root)->children[i]->data<<",";
    }
    cout<<endl;
    
    for(int i=0;i<root->children.size();i++)
    {
        print(root->children[i]);
    }
}

int main()
{
       TreeNode<int>* root = TakeInputLevel();
        print(root);
}
