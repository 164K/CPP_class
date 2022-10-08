#include "Mystack.hpp"
#include "Myqueue.hpp"
#include "iostream"
#include <algorithm>
#include <set>
#include <map>

using namespace std;

bool lsmatch(string s, string ls="([{", string rs=")]}")
{
	Mystack<char> ms(s.length());
	for (auto ch:s)
    {
        if(find(ls.begin(), ls.end(), ch)!=ls.end())
        	ms.push(ch);
        else if (find(rs.begin(), rs.end(), ch)!=rs.end())
        {
        	if (!ms.isEmpty())
            {
                char popchar = ms.pop();
                if(rs[ls.find(popchar)]!=ch)
                    return false;
            }else
            	return false;
        }
        ms.dispStack();
    }
    return ms.isEmpty();
}

void queueCall(unsigned int N)
{
    Myqueue<int> mq;
    for(int i=1;i<=N;i++)
        mq.enQueue(i);
    bool flag = true;
    while(!mq.isEmpty())
    {
        auto elem = mq.deQueue();

        if(flag)
            cout<<elem<<" -> ";
        else
            mq.enQueue(elem);
        
        flag = !flag;
    }
    cout<<"End"<<endl;
}


int main()
{
    string s = "", ls = "([{<", rs = ")]}>";
    cout << (lsmatch("(1+4/<{2+5}*45\"youjui\">)", ls, rs)?"True":"False")<<endl;
    // queueCall(100);
}