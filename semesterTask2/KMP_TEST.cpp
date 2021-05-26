#include <iostream>
#include <vector>
#include <ctime>
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
    string str=""; //строка,по которой ищем образ
    string pattern="";//образ(подстрока)
    int size;
    cin>>size;//колличество символов в строке
    for (int i =0;i<size;i++) {
            char c = ((rand() % ( 'z'-'a' +1)) +'a');
            str +=c;
    }
    int size2 = rand()%(size-1)+1;//колличество символов в образе
    for (int i =0;i<size;i++) {
            char c = ((rand() % ( 'z'-'a' +1)) +'a');
            pattern +=c;
    }
    unsigned int start_time2 =  clock();//начало времени
    vector<int> pi = prefix_function(pattern+'@'+str);
    unsigned int end_time2 = clock();
    unsigned int search_time2 = end_time2 - start_time2;//конец времени
    cout<<"Time:"<<search_time2<<" Size for Str-"<<size<<" Size for pattern-"<<size2<<endl;
    return 0;
}

