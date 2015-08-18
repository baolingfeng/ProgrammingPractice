#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definition.h"

using namespace std;

void reverse_string(char* s, int n)
{
    for(int i=0; i<n/2; i++)
    {
        char temp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = temp;
    }
}

//translation_string: abcdefg -> cdefgab, k=2
// return (X^TY^T)^T
void translation_string(char* s, int n, int k)
{
    reverse_string(s, 2);
    reverse_string(s+2, n-2);
    reverse_string(s, n);
}

bool string_contain1(string &a, string &b)
{
    //26素数
    const int p[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,61, 67, 71, 73, 79, 83, 89, 97, 101};

    long res_a = 1;
    for(int i=0; i<a.length(); i++)
    {
        int temp = p[a[i] - 'A'];
        if(res_a % temp)
        {
            res_a *= temp;
        }
    }

    for(int i=0; i<b.length(); i++)
    {
        int temp = p[b[i] - 'A'];
        if(res_a % temp)
        {
            return false;
        }
    }
    return true;
}

//hash, bit operation
bool StringContain2(string &a,string &b)
{
    int hash = 0;
    for (int i = 0; i < a.length(); ++i)
    {
        hash |= (1 << (a[i] - 'A'));
    }

    for (int i = 0; i < b.length(); ++i)
    {
        if ((hash & (1 << (b[i] - 'A'))) == 0)
        {
            return false;
        }
    }
    return true;
}

//recursive
void string_all_permutation(char* s, int from, int to)
{
    if(to<=1)
    {
        return;
    }

    if(from == to)
    {
        for(int i=0; i<=to; i++)
        {
            cout<<s[i];
        }
        cout<<endl;
    }
    else
    {
        for(int i=from; i<=to; i++)
        {
            myswap(s[i], s[from]);
            string_all_permutation(s, from+1, to);
            myswap(s[i], s[from]);
        }
    }
}

//abc：abc -> acb -> bac -> bca -> cab -> cba
bool next_permutation(char* s, int n)
{   
    int i = n-2;
    while(i>=0 && s[i+1]<=s[i]) 
    {
        i--;
    }

    if(i<0) 
    {
        return false;
    }

    int j = n-1;
    while(j>i && s[j] <= s[i]) j--;

    myswap(s[i], s[j]);
    
    reverse_string(s+i+1, n-i-1);

    return true;
}


void string_all_permutation2(char* s, int n)
{
    cout<<s<<endl;

    while(next_permutation(s, n))
    {
        cout<<s<<endl;
    }
}

//ab: aa->ab->ba->bb
void perm(char* result, char *str, int size, int resPos)
{
  if(resPos == size)
    cout<<result<<endl;
  else
    {
      for(int i = 0; i < size; ++i)
        {
          result[resPos] = str[i];
          perm(result, str, size, resPos + 1);
        }
    }
}

void combination(char *s, int n)
{
    int k = 1<<n;
    for(int i=1; i<k; i++)
    {
       for(int j=0; j<n; j++)
       {
            if(i & (1<<j))
            {
                cout<<s[j];
            }
       }
       cout<<endl;
    }
}

int main()
{
    char s[] = "abd";
    int len = strlen(s);

    //translation_string(s, len, 2);
    //string_all_permutation2(s, len);
    //cout<<s<<endl;
    
    //char* result = new char[len];
    //perm(result, s, len, 0);
    //delete[] result;

    combination(s, len);

    return 0;
}