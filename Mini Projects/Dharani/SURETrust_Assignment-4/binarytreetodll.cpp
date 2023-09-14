#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(){
	    left = right = NULL;
	}
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
   
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
  
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    Node* root = newNode(stoi(ip[0]));
        
   
    queue<Node*> queue;
    queue.push(root);
        
   
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
      
        Node* currNode = queue.front();
        queue.pop();
            
        
        string currVal = ip[i];
            
      
        if(currVal != "N") {
                
           
            currNode->left = newNode(stoi(currVal));
                
          
            queue.push(currNode->left);
        }
            
    
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
       
        if(currVal != "N") {
                
          
            currNode->right = newNode(stoi(currVal));
                
           
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

class Solution
{
    public: 
    void help(Node*root,Node**head){
        if(root==NULL){
            return;
        }
        help(root->right,head);
        
        root->right= *head;
        
        if(*head!=NULL){
            (*head)->left=root;
        }
        *head = root;
        
        help(root->left,head);
        
    }
   
    Node * bToDLL(Node *root)
    {
        Node*ans=NULL;
        help(root,&ans);
        return ans;
        // your code here
    }
};


void printList(Node *node)
{
    Node *prev = NULL;
    while (node!=NULL)
    {
        cout << node->data << " ";
        prev = node;
        node = node->right;
    }
    cout << endl;
    while (prev!=NULL)
    {
        cout << prev->data << " ";
        prev = prev->left;
    }
    cout << endl;
}

void inorder(Node *root)
{
   if (root != NULL)
   {
       inorder(root->left);
       cout << root->data;
       inorder(root->right);
   }
}


int main()
{
  int t;
  cin >> t;
  getchar();
  
  while (t--)
  {
     string inp;
     getline(cin, inp);
     Node *root = buildTree(inp);
     
     Solution ob; 
     Node *head = ob.bToDLL(root);
     printList(head);

  }
  return 0;
}
