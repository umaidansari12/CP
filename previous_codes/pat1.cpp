#include <bits/stdc++.h>

using namespace std;
/*string temp=n;
    for(int i=0;i<k-1;i++)
    {
        n+=temp;
    }
    if(n.length()==1)
    {
        int x =stoi(n);
        return x;
    }
    stringstream geek(n);
    int x=0;
    geek >> x;
    stringstream ss;
    ss << x;
    string str = ss.str();
    return x%10 + superDigit(str,1);*/

int pat(int n)
{
    if(n==0)
    {
        return 1;
    }
    pat(n-1);
    for(int i=0;i<n;i++)
    {
        cout << "*";
    }
    cout <<endl;

}
int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    return n * fact(n-1);
}
int fibo(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    return fibo(n-1)+fibo(n-2);
}
int binarysearch(int arr[],int l,int h,int search)
{
    if(h >= l)
    {
        int mid=(l+h)/2;
    if(arr[mid]==search)
        return mid;
    else if(search < arr[mid])
        binarysearch(arr,l,mid-1,search);
    else if(search > arr[mid])
        binarysearch(arr,mid+1,h,search);
    }

    return -1;
}
int sorted(int arr[],int n)
{
    if(n==1)
    {
        return 1;
    }
    if(arr[n-1]<arr[n-2])
    {
        return 0;
    }
    else
    {
        sorted(arr,n-1);
    }

}
int recursive_sum(long long int n)
{
    if(n==0)
        return 0;
    return n%10 + recursive_sum(n/10);
}
int superDigit(string n, int k) {
    int x=stoi(n);
    int sum=recursive_sum(x);
    sum*=k;
    string str = to_string(sum);
    if(n.length()==1)
    {

        int a= atoi(n.c_str());
        return a;
    }
    return superDigit(str,1);
}

int main()
{
    /*for(int i=0 ; i <= 15 ;i++)
    {
        cout << fibo(i)<<"\t";
    }
    cout <<endl;*/
    /*int arr[10];
    for(int i=0;i< 10;i++)
    {
        cin >> arr[i];
    }
    int x = sorted(arr,10);
    cout <<  x;*/
    /*int a = 10;
    stringstream ss;
    ss << a;
    string str = ss.str();
    cout << str;*/
    string str="88";
    int k=2;
    int x = superDigit(str,k);
    cout << x;

    
}
