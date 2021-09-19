#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

struct TrieNode{
    string word;
    unordered_map<char,TrieNode*> children;
    TrieNode(){
        word = "";
    }
};
// 通过insertTrie注意到，每个TrieNode有个map和word， 而map里又有一个TrieNode， 只有成功遍历了字典树的所有字符，才能得到最终的word
void insertTrie(TrieNode *root,string word ){
    TrieNode* node = root;
    for(auto &ch:word){
        if(!node->children.count(ch)){
            node->children[ch] = new TrieNode();
        }
        node = node->children[ch];
    }
    node->word = word;
}

class Solution {
public:
    bool dfs(vector<vector<char>>& board, int x, int y, set<string>& res, TrieNode* root){
        char ch = board[x][y];
        if(!root->children.count(ch)){
            return false;
        }
        root = root->children[ch];
        if(root->word.size() > 0){
            res.insert(root->word);
        }

        board[x][y] = '#';
        for(int i=0;i<4;++i){
            int nx = x + dirs[i][0];
            int ny = y = dirs[i][1];
            if(nx >= 0 && nx < board.size() && ny >=0 && ny<board[0].size()){
                if(board[nx][ny] != '#'){
                    dfs(board, nx, ny, res, root);
                }
            }
        }
        board[x][y] = ch;
        return true;

    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(auto& word:words){
            insertTrie(root, word);
        }

        for(int i=0;i<board.size();++i){
            for(int j =0;j<board[0].size();++j){
                dfs(board, i, j, res, root);
            }
        }

        for(auto& word:res){
            ans.push_back(word);
        }

        return ans;
    }
private:
    set<string> res;
    vector<string> ans;

    int dirs[4][2] = {{1,0}, {-1,0},{0,1},{0,-1}};


};

// 同一单元内的字母不允许使用， 需要个used数组来记忆, 直接修改为#

//  做一个字典树

int main(){
    Solution sl;
    vector<vector<char>> stringvec = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> svec = {"oath","pea","eat","rain"};
    sl.findWords(stringvec, svec);
}