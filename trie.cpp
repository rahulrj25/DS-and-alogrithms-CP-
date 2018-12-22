//Trie for strings with lower-case characters
struct node{
        node *children[26];
        bool isLeaf;
       int count;
};
    
node *getNode(void) {
    node *pNode = NULL;
    pNode = (node *)malloc(sizeof(node));
    if (pNode) {
        pNode->isLeaf = false;
        for (int i = 0; i < 26; i++)
            pNode->children[i] = NULL;
            pNode->count=0;
    }
    return pNode;
}

void insert(node *root, string key) {
    
    node *temp = root;
    for (int i = 0; i < key.length(); i++) {
        
        int index = key[i] - 'a';
        if (!temp->children[index]) temp->children[index] = getNode();
        temp->children[index]->count++;
        temp = temp->children[index];
    
    }
    temp->isLeaf = true;
}

// Returns number of strings which have "key" as prefix

int search(node *root, string key) {

    node *temp = root;
    for (int i = 0; i < key.length(); i++) {

        int index = key[i] - 'a';
        if(temp->children[index]) temp = temp->children[index];
        else return 0;
        
    }
    
    return (temp->count);
}