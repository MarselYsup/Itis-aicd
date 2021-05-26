#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
vector<int> prefix_function(string s) {
    vector<int> pi(s.length(),0);//������� ������ ������� �������,��������� ������
    int j = 0;//������ ���������� �� ������� ������
    int i = 1;//������ ���������� �� ������� ������
    while(i!=s.length()) {//���� ������ i �� ����� �� ����� ������
        if(s[i]==s[j]) {//���� ������� �� ������� �������� ��������� � ���������,�� ��������� 1 � ������ �� i �����
            pi[i] = j+1;//��� ��� ��������� ��������� �������� ������� ����� �������� �� 1
            i++;
            j++;
        }
        else if(j==0) {//���� �� �� ���������,�� ��������� ����� �� ������ �������� �� ��������� �������
            pi[i]=0;//���� ��,�� ������ 0 � ������ , �� ���� ������� � ������� �� ���������
            i++;
        }
        else {//���� �� ������ ����� �� �� ��������� �����,������� ��� ������������ ������� pi
            j=pi[j-1];
        }
    }
    return pi;


}

int main()
{
    string str=""; //������,�� ������� ���� �����
    string pattern="";//�����(���������)
    int size;
    cin>>size;//����������� �������� � ������
    for (int i =0;i<size;i++) {
            char c = ((rand() % ( 'z'-'a' +1)) +'a');
            str +=c;
    }
    int size2 = rand()%(size-1)+1;//����������� �������� � ������
    for (int i =0;i<size;i++) {
            char c = ((rand() % ( 'z'-'a' +1)) +'a');
            pattern +=c;
    }
    unsigned int start_time2 =  clock();//������ �������
    vector<int> pi = prefix_function(pattern+'@'+str);
    unsigned int end_time2 = clock();
    unsigned int search_time2 = end_time2 - start_time2;//����� �������
    cout<<"Time:"<<search_time2<<" Size for Str-"<<size<<" Size for pattern-"<<size2<<endl;
    return 0;
}

