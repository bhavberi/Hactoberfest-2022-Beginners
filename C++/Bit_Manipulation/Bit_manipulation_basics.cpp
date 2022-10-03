// Author: Priya Kumari
// Date: 3-10-2022


// Topics
//a) Programme to count total number of bits in a number
//b)Programme to Check whether the number is power of two or not
//c)Programme to count total number of set bits
//d)programme to check ith bit is set or not
//e)Programme to generate all subset using bits
//f)Programme to get most significant bit

#include <iostream>

#include <algorithm>
using namespace std;
//*---------------------------------------------------------------*/
#define ll long long int

//*---------------------------------------------------------------*/

//counting total no. of bits
 ll countBits(ll n)
{
   ll count = 0; //initialize the count with zero
   while (n) // run the while loop till n>0
   {
        count++;
        n >>= 1; // right shift by 1 for ex if n=1011 after shifting it will be 0101
    }
    return count;
}

// checking power of two
bool check(ll x)
{
    if (x == 0)
    {
        return false;
    }
    return (x && !(x & x - 1));// if x=100 then x-1=011 =>!(x&x-1)=1 
}

// counting no. of set bits (or one);

int countone(ll x)
{
    if (x == 0)
    {

        return 0;
    }
    int count = 0;
    while (x)//as all the bits after right most bit in x is flipped in x-1
//for ex=if x=101100 then x-1=101011; or x=1010 x-1=1001;

    {
        x = x & x - 1;
        count++;
    }
    return count;
}

//checking i th bit is set or not;

bool check(ll n, ll i)
{
    if (n & 1 << i)
    {
        return true;
    }
    return false;
}
// 1<<i=2^i;
//if i =2 and n=101   then(1<<2==4==100)  this implies
// 101 & 100=100(true);

// printing subset using bits;
// let the set have n element
//=> it have 2^n subsets

void subset(ll a[], ll n)
{
    ll q = 1 << n;

    for (ll i = 0; i < q; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (i & 1 << j) //it gives wether the jth bit
            //is set or not
            {
                cout << a[j];
            }
        }
    }
}
//{a,b,c}
// 0 = (000)2 = {}
// 1 = (001)2 = {c}
// 2 = (010)2 = {b}
// 3 = (011)2 = {b, c}
// 4 = (100)2 = {a}
// 5 = (101)2 = {a, c}
// 6 = (110)2 = {a, b}
// 7 = (111)2 = {a, b, c}

//most significant setbit

long setbit(long n)
{  
    //changing all right side bits to 1.
    n = n | (n >> 1);
    n = n | (n >> 2);
    n = n | (n >> 4);
    n = n | (n >> 8);

     //as now the number is 2*x-1,
     // where x is required answer, so adding 1 and dividing it by

    return (n + 1) >> 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
