#include "Mystack.hpp"
#include "iostream"
#include <set>
#include <map>

using namespace std;

bool lsmatch(string s)
{
	Mystack<char> ms(s.length());
    
    map<char, char> msmap{
        {'(',')'},
        {'[',']'},
        {'{','}'}
    };
    set<char> lset{'(','[','{'},rset{')',']','}'};

	for (auto ch:s)
    {
        if(lset.find(ch)!=lset.end())
        	ms.push(ch);
        else if (rset.find(ch)!=rset.end())
        {
        	if (ms.isEmpty())
            	return false; 
        	else if(msmap[ms.pop()]!=ch)
            	return false;
        }
        ms.dispStack();
        // cout<<1;
    }
    return ms.isEmpty();
}

int main()
{
    cout << lsmatch("(1+2/(3)[{}]")<<endl;
}