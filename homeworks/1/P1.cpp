#include <iostream>
#include <cstdio>
using namespace std;

struct elem {
    int val;
    elem* next;
};

elem* add_last(elem* head, int x) {
    elem* p = new elem;
    (*p).next = NULL;
    (*p).val = x;
    if(head==NULL) {
       return p;
    }
    else {
        elem* q = head;
        while((*q).next) {
            q = (*q).next;
        }
        (*q).next = p;
    }
    return head;
}
elem* empty_list() {
	return NULL;
}

void print_list (elem* head) {
    elem* p = head;
    while(p !=NULL) {
        printf("%d ",(*p).val);
        p = (*p).next;
    }


}


int main()
{
    int n;
    cin>>n;
    elem* primeNumbers = empty_list();
    primeNumbers = add_last(primeNumbers,2);
    int count_primeNumbers = 1;
    int next_Number = 3;
    while(n>count_primeNumbers) {
        bool isPrime = true;
        elem* p = primeNumbers;
        while(isPrime&&(*p).val*(*p).val<=next_Number&&p) {
            if(next_Number%(*p).val==0) {
                isPrime = false;
            }
            p = (*p).next;
        }
        if(isPrime) {
            primeNumbers = add_last(primeNumbers,next_Number);
            count_primeNumbers++;
        }
        next_Number+=2;
    }
    print_list(primeNumbers);
    return 0;
}
