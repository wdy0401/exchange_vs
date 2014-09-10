// tactic.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "tactic.h"

using namespace std;

tactic::tactic()
{
	return;
}

void tactic::readquote()
{

}

void tactic::add_quote_symbol(const string & symbol)
{
	string s=symbol;
	_quote_symbols.push_front(s);
	_delete_same_symbol(&_quote_symbols);
	return;
}

void tactic::del_quote_symbol(const string & symbol)
{
	_delete_symbol(&_quote_symbols,symbol);
	return;
}

void tactic::add_order_symbol(const string & symbol)
{
	string s=symbol;
	_order_symbols.push_front(s);
	_delete_same_symbol(&_order_symbols);
	return;
}
void tactic::del_order_symbol(const string & symbol)
{
	_delete_symbol(&_quote_symbols,symbol);
	return;
}
void tactic::_delete_same_symbol(list<string> * dlist)
{
	if(dlist->size()==0 || dlist->size()==1)
	{
		return;
	}
	for(list<string>::iterator iter=dlist->begin();;)
	{
		iter++;
		if(iter==dlist->end())
		{
			return;
		}
		if(dlist->begin()->c_str()==iter->c_str())
		{
			dlist->pop_front();
			return;
		}
	}
}
void tactic::_delete_symbol(list<string> * dlist,const string & symbol)
{
	if(dlist->size()==0 || dlist->size()==1)
	{
		return;
	}
	for(list<string>::iterator iter=dlist->begin();iter!=dlist->end();)
	{
		if(iter->c_str()==symbol.c_str())
		{
			dlist->erase(iter++);
		}
		else
		{
			++iter;
		}
	}
}



