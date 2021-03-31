#include <iostream>
using namespace std;

const int alphabet = 26;

struct PrefixTree {

    PrefixTree *next[alphabet] = {0};
    bool is_terminal = false;
};
PrefixTree *root = new PrefixTree();
void add(string  s) {
    PrefixTree *head = root;
    for(int i = 0;i<s.length();i++) {
        char c = s[i];
        if(head->next[c-'a']==nullptr) {
            head->next[c-'a'] = new PrefixTree;
        }
        head = head->next[c-'a'];

    }
    head->is_terminal = true;
}
bool contains(string  s) {
    PrefixTree *head = root;
    bool flag = true;
    for(int i = 0;i<s.length();i++) {
        char c = s[i];
        if(head->next[c-'a']==nullptr) {
            flag = false;
            return flag;
        }
        head = head->next[c-'a'];

    }
    flag &= head->is_terminal;
    return flag;
}
void remove(string  s) {
    PrefixTree *head = root;
    for(int i=0;i<s.length();i++) {
        char c = s[i];
        if(head->next[c-'a']==nullptr) {
            break;
        }
        head = head->next[c-'a'];
    }
    head->is_terminal = false;
}

int main()
{   //Задание:найти лексикографически самое маленькое слово
    int n;
    cin>>n;
    for(int i = 0;i<n;i++) {
        string s;
        cin>>s;
        add(s);
    }
    PrefixTree *head = root;
    string lexic_smallest_word = "";
    while(!head->is_terminal) {
        bool isNewNode = false;
        for(int i=0;i<alphabet&&!isNewNode;i++) {
            if (head->next[i]!=nullptr){
                lexic_smallest_word +=(char)(i+'a');
                head = head->next[i];
                isNewNode = true;
            }
        }
    }
    cout<<"Lexicographically smallest word is "+lexic_smallest_word<<endl;


    return 0;
}