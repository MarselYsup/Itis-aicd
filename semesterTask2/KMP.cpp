#include <iostream>
#include <vector>
using namespace std;
vector<int> prefix_function(string s) {
    vector<int> pi(s.length(),0);//создаем массив префикс функции,заполняем нулями
    int j = 0;//индекс отвечающий за префикс строки
    int i = 1;//индекс отвечающий за суффикс строки
    while(i!=s.length()) {//пока индекс i не дошел до конца строки
        if(s[i]==s[j]) {//если символы на индексе префикса совпадают с суффиксом,то добавляем 1 в массив на i место
            pi[i] = j+1;//так как увеличтся следующие значение массива может максимум на 1
            i++;
            j++;
        }
        else if(j==0) {//если же не совпадают,то проверяем стоит ли индекс префикса на начальной позиции
            pi[i]=0;//если да,то ставим 0 в массив , то есть префикс и суффикс не совпадают
            i++;
        }
        else {//если же индекс стоит не на начальном месте,смещаем его относительно массива pi
            j=pi[j-1];
        }
    }
    return pi;


}

int main()
{
    string str; //строка,по которой ищем образ
    string pattern;//образ(подстрока)
    cin>>str>>pattern;
    int pattern_size = pattern.length();
    if(pattern_size>str.length()) {//если размер подстроки больше самой строки выводим -1
        cout<<"-1"<<endl;
    }
    else {
        vector<int> pi = prefix_function(pattern+'@'+str);//для префикс функции склеиваем str и pattern символом,не используемый в входных данных
        bool flag = true;//проверка на то,есть ли образ в строке
        for(int i=0;i<str.length();i++) {
            if(pi[pattern_size+1+i]==pattern_size) {
                flag = false;
                cout<<"From "<<i-pattern_size+1<<" index to "<<i<<endl;
            }
        }
        if(flag) {//если образа нет,выводим -1.
            cout<<"-1"<<endl;
        }
    }
    return 0;
}
