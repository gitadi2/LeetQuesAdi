// Trie fn Implementation(insert,Search,Starts with)

struct Node{
    Node*links[26];      // Reference Links
    bool flag=false;     // Set up the flag by default as false
    // Setting up all the Links to NULL initially 
    Node(){
        for(int i=0;i<26;i++){
            links[i]=NULL;
        }
    }
    bool cointainsKey(char ch){
        return(links[ch-'a']!=NULL);     // if this holds i.e char does exist
    }
    void put(char ch,Node*node){
        links[ch-'a']=node;
    }
    Node*get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie{
    private:Node*root;       // Define the Root of the Trie
public:
    Trie(){
        root=new Node();
    }

    // Inserts a word into the Trie
    void insert(string word){
        Node*node=root;          // Start from the Root
        for(int i=0;i<word.size();i++){
            if(!node->cointainsKey(word[i])){
                // If doesn't contain the char
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);     // Move to the New Reference Trie
        }
        node->setEnd();            // Make the last Trie flag as true
    }

    // Search for the word in the Trie
    bool search(string word){
        Node*node=root;          // Starts from the Root
        for(int i=0;i<word.size();i++){
            if(!node->cointainsKey(word[i])){
                // If doesn't contain the Char
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd();    // Returns the flag
    }

    // Returns if there is any word in the trie that starts with this
    bool startsWith(string prefix){
        Node*node=root;           // Start with the Root
        for(int i=0;i<prefix.size();i++){
            if(!node->cointainsKey(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj=new Trie();
 * obj->insert(word);
 * bool param_2=obj->search(word);
 * bool param_3=obj->startsWith(prefix);
 */