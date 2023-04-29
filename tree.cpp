#include <iostream>
#include <list>
#include <queue>

using namespace std;




struct Node
{
    int data;
    Node* left;
    Node* right;
};


struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    
    return node;
}


void insert(Node* &root, int data)
{
    if(root == NULL)
    {
        root = newNode(data);
        return;
    }

    if(data < root->data)
    {
        insert(root->left, data);
    }

    else
    {
        insert(root->right, data);
    }
}


void search(Node* root, int data)
{
    if(root == NULL)
    {
        cout<<"Nu exista nodul cautat!"<<endl;
        return;
    }

    if(root->data == data)
    {
        cout<<"Nodul a fost gasit!"<<endl;
        return;
    }

    if(data < root->data)
    {
        search(root->left, data);
    }

    else
    {
        search(root->right, data);
    }
}


void deleteNode(Node* &root, int data)
{
    if(root == NULL)
    {
        return;
    }

    if(data < root->data)
    {
        deleteNode(root->left, data);
    }

    else if(data > root->data)
    {
        deleteNode(root->right, data);
    }

    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }

        else if(root->left == NULL)
        {
            Node* temp = root;
            root = root->right;
            delete temp;
        }

        else if(root->right == NULL)
        {
            Node* temp = root;
            root = root->left;
            delete temp;
        }

        else
        {
            Node* temp = root->right;

            while(temp->left != NULL)
            {
                temp = temp->left;
            }

            root->data = temp->data;
            deleteNode(root->right, temp->data);
        }
    }
}


void search_min(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    if(root->left == NULL)
    {
        cout<<"Nodul minim este: "<<root->data<<endl;
        return;
    }

    search_min(root->left);
}


void search_max(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    if(root->right == NULL)
    {
        cout<<"Nodul maxim este: "<<root->data<<endl;
        return;
    }

    search_max(root->right);
}


int find_highest_lower(Node* root, int data, int& max_val)
{
    if(root == NULL)
    {
        return max_val;
    }

    if(root->data < data)
    {
        max_val = max(max_val, root->data);
        return find_highest_lower(root->right, data, max_val);
    }
    else
    {
        return find_highest_lower(root->left, data, max_val);
    }
}


int find_lowest_higher(Node* root, int data, int& min_val)
{
    if(root == NULL)
    {
        return min_val;
    }

    if(root->data > data)
    {
        min_val = min(min_val, root->data);
        return find_lowest_higher(root->left, data, min_val);
    }
    else
    {
        return find_lowest_higher(root->right, data, min_val);
    }
}


void sort_interval(Node* root, int a, int b)
{
    if(root == NULL)
    {
        return;
    }

    sort_interval(root->left, a, b);

    if(root->data >= a && root->data <= b)
    {
        cout<<root->data<<" ";
    }

    sort_interval(root->right, a, b);
}



void print(Node* root)
{

    if(root == NULL)
    {
        return;
    }

    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}





int main()
{
    cout<<"Creeaza un arbore binar de cautare!"<<endl;


    cout<<"Introdu numarul de noduri: "<<endl;
    
    int n;
    cin>>n;
    
    cout<<"Introduceti radacina: "<<endl;

    int data;
    cin>>data;
    Node* root = newNode(data);
    

    /*
    queue<Node*> q;

    int data;
    cin >> data;
    root = newNode(data);
    q.push(root);


    while (!q.empty()) 
    {
        Node* currNode = q.front();
        q.pop();

        cout<<"Introduceti nodul stanga si dreapta pentru nodul cu valoarea "<<currNode->data<<endl;

       

        int leftData, rightData;
        cin >> leftData >> rightData;

        if (leftData == -1 && rightData == -1) {
            currNode->left = NULL;
            currNode->right = NULL;
            continue;
        }

        if (leftData != -1) { 
            currNode->left = newNode(leftData);
            q.push(currNode->left);
        }

        if (rightData != -1) { 
            currNode->right = newNode(rightData);
            q.push(currNode->right);
        }

    }

*/
    insert(root, 5);
    insert(root, 20);
    insert(root, 3);
    insert(root, 7);
    insert(root, 15);
    insert(root, 25);

    print(root);


    
    return 0;
}


/*

          6
          /\
          4   8
          /\   /\
          1 9   5 10
*/
