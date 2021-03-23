/*
Author : Nguyen Le Minh
Group : N3251 
Date : 23/3/2021
Problem : find the minimal positive integer number Q so that the product of digits of Q is exactly equal to N. (1014's problem)
*/
#include <iostream>
using namespace std;
int n;
int main(){
    int num;
    cin>>num;
    while(num--)
    {
        int n;
        cin>>n;
        if(n==0||n==1)
        {
            cout<<n<<endl;
            continue;
        }
        string str="";
        for(int i=9;i>=2;i--)
        {
            while(n%i==0)
            {
                char ch=('0'+i);
                str=str+ch;
                n=n/i;
            }
        }
        if(n!=1) cout<<"-1"<<endl;
        else
        {
            for(int i=str.size()-1;i>=0;i--)
                cout<<str[i];
            cout<<endl;
        }
    }
    return 0;
}
