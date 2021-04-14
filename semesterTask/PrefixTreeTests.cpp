#include <iostream>
#include <ctime>
using namespace std;

const int alphabet = 26;

struct PrefixTree {

    PrefixTree *next[alphabet] = {0};
    bool is_terminal = false;
};
void add(string  s,PrefixTree* root) {
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
bool contains(string  s,PrefixTree* root) {
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
void remove(string  s,PrefixTree* root) {
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
{

int size;
cin>>size;//вводим колчество вводимых элементов
int length;
cin>>length;//вводим длинну вводимых слов
for(int i=0;i<50;i++) { // проверяет 50 наборов
string s [size];
PrefixTree *root = new PrefixTree();
for(int j = 0;j<size;j++) { //создаем наборы данных
        for (int i =0;i<length;i++) {
            char c = ((rand() % ( 'z'-'a' +1)) +'a');
            s[j] +=c;
        }
}
unsigned int start_time =  clock();//считаем время через функцию clock()

    for (int i =0;i<size;i++) {
        add(s[i],root);
    }

    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout<<"Adding time:"<<search_time<<endl;


    unsigned int start_time2 =  clock();

    for (int i =0;i<size;i++) {
        contains(s[i],root);
    }

    unsigned int end_time2 = clock();
    unsigned int search_time2 = end_time2 - start_time2;
    cout<<"Containing time:"<<search_time2<<endl;


    unsigned int start_time3 =  clock();

    for (int i =0;i<size;i++) {
        remove(s[i],root);
    }

    unsigned int end_time3 = clock();
    unsigned int search_time3 = end_time3 - start_time3;
    cout<<"Removing time:"<<search_time3<<endl;

}



    return 0;
}
