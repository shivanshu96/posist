#include<bits/stdc++.h>//header file to include all library function
using namespace std;

struct data{
string ownerId;
float value;
string ownerName;
string hash;
};
int ct=0;//keep the count of number of node
struct node{
string nodeId;
struct data*link;
int nodeNumber;
struct node* referenceNodeId;
struct node* left;
struct node* right;
struct node* genesisReferenceNodeId;
string HashValue;

};

struct node* Genesis=NULL;//root node GENESIS
struct node* createNewNode(string Id,int num)//Method to create new node
{
    struct node* root=new node();
    root->nodeId=Id;
    root->nodeNumber=num;
    root->left=NULL;
    root->right=NULL;
    return root;
};
int i=0;
struct node* createNode(string id,int num,struct node*root)//Method to look for Child node with null value
{
    if(root==NULL)
    {
        createNewNode(id,num);
    }else if(root->left==NULL)
    {
        root->left=createNewNode(id,num);
    }else if(root->right==NULL)
    {
        root->right=createNewNode(id,num);
    }else if(ct%2==0)
    {
        createNode(id,num,root->left);
    }
    else
    {
        createNode(id,num,root->right);
    }

}
struct node*printNode(struct node*root)//print all the node in tree
{
    if(root==NULL)
        return 0;
    cout<<root->nodeId<<"-"<<root->nodeNumber<<endl;
    printNode(root->left);
    printNode(root->right);
}
int longestChainRoot(struct node* root)//return the max height of that tree
{
    if(root==NULL)
        return 0;
    else
        return max(1+longestChainRoot(root->left),1+longestChainRoot(root->right));
}int h=0;
searchNode(struct node*root,string k)//return height of any node
{
    if(root!=NULL)
    {


    if(k==root->nodeId)
         h=longestChainRoot(root);
    searchNode(root->left,k);
    searchNode(root->right,k);
    }
}
int main()
{
    Genesis=new node();
    int flag=1;
    while(flag==1)//take input from user till user wants to enter
    {
        int num;string id;
        printf("Enter node ID\n");
        cin>>id;
        printf("Enter node num\n");
        cin>>num;
        ct++;
        createNode(id,num,Genesis);
        cout<<"TO Enter new node enter 1\n";
        cin>>flag;
    }
    cout<<"Entered data"<<endl;
    printNode(Genesis);
    cout<<"Longest Chain in tree"<<endl;
    cout<<longestChainRoot(Genesis)<<endl;
    cout<<"enter a node whose length you want to find"<<endl;
    string id;
    cin>>id;
    searchNode(Genesis,id);
    cout<<h<<endl;

}
