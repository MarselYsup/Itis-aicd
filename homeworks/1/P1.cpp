#include <iostream>

using namespace std;

struct elem {
    int val;
    elem* next;
};

elem* add(elem* head,int x) { //добавление элемента в лист
    elem* p = new elem;
    (*p).val = x;
    p->next = head;
    return p;
}

elem* empty_list() { //пустой лист
return NULL;
}

elem* reverse_list(elem* head) { //переворачивает лист 
    elem* p = head;
    elem* newList = empty_list();
    while(p) {
        newList = add(newList,(*p).val);
        p = (*p).next;
    }
    return newList;
}

void print_list (elem* head) { //вывод листа
    elem* p = head;
    while(p !=NULL) {
        cout<<(*p).val<<" ";
        p = (*p).next;
    }
    cout<<endl;

}
int main()
{
    int n;
    cin>>n;
    elem* primeNumbers = empty_list();
    primeNumbers = add(primeNumbers,2); //так как 1<=n
    int count_primeNumbers = 1; //счетчик кол-во простых чисел
    int next_Number = 3; // следующее введенное число
    while(n>count_primeNumbers) {
        bool isPrime = true;
        elem* p = primeNumbers;
        while(p&&isPrime) {
            if(next_Number%(*p).val==0) {
                isPrime = false;
            }
            p = (*p).next;
        }
        if(isPrime) {
            primeNumbers = add(primeNumbers,next_Number);
            count_primeNumbers++;
        }
        next_Number+=2;
    }
    primeNumbers = reverse_list(primeNumbers); //переворачиваем лист в правильном порядке
    print_list(primeNumbers);
    return 0;
}
