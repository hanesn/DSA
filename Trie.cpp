#include <bits/stdc++.h>
#define ll long long int
using namespace std;
struct TrieNode{
    TrieNode *links[26];
    bool flag=false;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,TrieNode *node){
        links[ch-'a']=node;
    }
    TrieNode* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag==true;
    }
};

class Trie{
    private:
    TrieNode *root;

    public:
    Trie(){
        root=new TrieNode();
    }
    void insert(string word){
        TrieNode *node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
            }else{
                node->put(word[i],new TrieNode());
                node=node->get(word[i]);
            }
        }
        node->setEnd();
    }
    bool search(string word){
        TrieNode *node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
            }else{
                return false;
            }
        }
        return node->isEnd();
    }
    bool startsWith(string word){
        TrieNode *node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
            }else{
                return false;
            }
        }
        return true;
    }
};
int main(){

}