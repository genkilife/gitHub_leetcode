class Trie {
public:
    set<string> strset;
    /** Initialize your data structure here. */
    Trie() {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {

        strset.insert(word);
        return;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return strset.find(word) != strset.end();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        for(set<string>::iterator iter = strset.begin(); iter != strset.end(); iter++){
            string teststr = *iter;
            if(teststr.find(prefix, 0) == 0){
                //cout<<"prefix: "<<prefix<<endl;
                //cout<<"fullstr: "<<teststr<<endl;
                return true;
            }
            
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
