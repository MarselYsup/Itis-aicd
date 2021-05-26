#include <iostream>
#include <vector>
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
    string str; //������,�� ������� ���� �����
    string pattern;//�����(���������)
    cin>>str>>pattern;
    int pattern_size = pattern.length();
    if(pattern_size>str.length()) {//���� ������ ��������� ������ ����� ������ ������� -1
        cout<<"-1"<<endl;
    }
    else {
        vector<int> pi = prefix_function(pattern+'@'+str);//��� ������� ������� ��������� str � pattern ��������,�� ������������ � ������� ������
        bool flag = true;//�������� �� ��,���� �� ����� � ������
        for(int i=0;i<str.length();i++) {
            if(pi[pattern_size+1+i]==pattern_size) {
                flag = false;
                cout<<"From "<<i-pattern_size+1<<" index to "<<i<<endl;
            }
        }
        if(flag) {//���� ������ ���,������� -1.
            cout<<"-1"<<endl;
        }
    }
    return 0;
}
