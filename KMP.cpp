#include <iostream>
#include <vector>

using namespace std;

void printArray(int a[], int size){
    for(int i=0; i<size; i++)
        cout<<a[i]<<",";
    cout<<""<<endl;
}
void printVector(const vector<int> &vv){
    for(auto itr=vv.begin(); itr!=vv.end(); itr++)cout<<*itr<<",";
    cout<<""<<endl;
}

void getNext(char pattern[], vector<int> &next){
    next[0]=0;
    for(int i=1, j=0; i<strlen(pattern);)// 自己既是模式串又是数据串，比KMP多了给next赋值的操作
        if(pattern[i]==pattern[j])next[i++] = ++j;
        else if(j-1>=0)j = next[j-1];
        else next[i++]=0;
}

int KMP(char data[], int dlow, int dhig, char pattern[], const vector<int> &next){// 最差情况复杂度上界是 2m-n
    int i,j;
    for(j=0, i=dlow; i<=dhig && j<strlen(pattern);)
        if(pattern[j]==data[i])j++,i++;
        else if(j-1>=0)j = next[j-1];
        else i++;
    if(j!=strlen(pattern))return -1;
    else return i-strlen(pattern);
}

int main(){
    char pattern[] = "ababaca";
    char data[] = "bacbababadababacambabacaddababacasdsd";
    vector<int> next(strlen(pattern), 0);
    getNext(pattern, next);
    printVector(next);
    cout<<KMP(data, 20, 36, pattern, next)<<endl;

    return 0;
}
