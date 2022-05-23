#include <iostream>
#include <string>
#include "Node.h"
#include "LinkedList.h"
using namespace std;
int makenum(string a,int start,int end,int num)
{
    if(start > end)
    return num;
    return makenum(a,start+1,end,num*10+int(a[start]-'0'));
}
int main()
{
    int a[100];
    string input;
    string f ;
    getline(cin,input);
    int start = 0;
    int count = 0;
    
    for (int i = 0;i<input.length();i++)
    {
        if(input[i]==' ')
        {
            a[count] = makenum(input,start,i-1,0);
            count++;
            start = i+1;
        }
        else if (input[i]>= 'A' && input[i]<='Z')
        {
            if(input[i]=='S')
            {
            f[0] = 'S';
            i++;
            start = i+1;
            }
            else
            {
            f=input.substr(i,2);
            i+=2;
            start = i+1;
            }
        }
        if (i==input.length()-1)
        {
            a[count] = makenum(input,start,i,0);
            count++;
        }
    }
    LinkedList* L = new LinkedList(a,count-2);
   
      if(f == "AF") L->addFront(a[count-2]); 
    else if(f == "AE") L->addEnd(a[count-2]); 
    else if(f == "AP") L->addAtPosition(a[count-2],a[count-1]); 
    else if(f== "S") L->search(a[count-2]); 
    else if(f == "DF") L->deleteFront(); 
    else if(f == "DE") L->deleteEnd(); 
    else if(f == "DP") L->deletePosition(a[count-2]);
    else if(f == "GI") L->getItem(a[count-2]); 
    L->printItems(); 

}