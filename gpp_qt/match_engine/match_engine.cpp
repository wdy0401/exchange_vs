#include<map>
#include"match_engine.h"
#include"../wtimer/wtimer.h"
#include"../log_info/log_info.h"
#include"../fillpolicy/fillpolicy.h"
#include"protobuf/stdafx.h"
#include"protobuf/quote.pb.h"

using namespace std;
using namespace QUOTE;

extern log_info loginfo;

match_engine::match_engine()
{
	_fp.pme=this;
}
bool match_engine::loadtactic(std::string & tacticname)
{
    loginfo.writeinfo(tacticname);
    return 0;
}
bool match_engine::loadfillpolicy(std::string & fpname)
{
    loginfo.writeinfo(fpname);
    return 0;
}
void match_engine::setnowsymbol(const std::string & symbol)
{
	_nowsymbol=symbol;
}
void match_engine::rec_update(const std::string & symbol, const std::string & ba, long level, double price, long size)
{
	setnowsymbol(symbol);
	updateorderbook(symbol,ba,level,price,size);
	updatefp();
	updatetactic();
	updatetacticbooks();
}
void match_engine::updateorderbook(const std::string & symbol, const std::string & ba, long level, double price, long size)//IF1405 bid 1 2100.2 5
{
	//auto it=_orderbooks.find(symbol);
	std::map<std::string,orderbook>::iterator iter=_orderbooks.find(symbol);
	if(iter==_orderbooks.end())//尚未添加此symbol之book
	{
		orderbook tmpob;
		tmpob.setsymbol(symbol);
		tmpob.updateorderbook(ba,level,price,size);
		_orderbooks[symbol]=tmpob;		
	}
	else
	{
		iter->second.updateorderbook(ba,level,price,size);
	}
	
}

void match_engine::updatefp()//改写orderlist各个order的状态
{
	_fp.updateorderlist(_ol,_orderbooks.find(_nowsymbol)->second);
}

void match_engine::updatetactic()//根据新的orderbook来判断时候发送order
{
    //const orderlist & ol,const orderbook & ob
}
void match_engine::updatetacticbooks()//根据新的orderbooks来判断时候发送order
{
	//const orderlist & ol,const orderbook & ob
}
void match_engine::add_order(const std::string & symbol,const std::string & buysell, double price ,long size)
{
    std::cout<<symbol<<" "<<buysell<<" "<<price<<" "<<size<<std::endl;
	this->_ol.neworder(symbol,buysell,price,size);
}
void match_engine::add_order(const string & orderstr)
{
	_order_message.ParseFromString(orderstr);
	string buysell=_order_message.buysell()==0?"buy":"sell";
	add_order(_order_message.symbol(),buysell,_order_message.price(),_order_message.size());
}

void match_engine::fp_te_tactic_order_send_ack(const std::string & orderid)
{
	return;
}

void match_engine::fp_te_tactic_order_change_size_ack(const std::string & orderid, long size)
{
	return;
}
void match_engine::fp_te_tactic_order_change_price_ack(const std::string & orderid, double price)
{
	return;
}

void match_engine::fp_te_tactic_order_fill(const std::string & orderid,long fillsize)
{
	return;
}

void match_engine::fp_te_tactic_order_change_size_rej(const std::string & orderid, long size)
{
	return;
}

void match_engine::fp_te_tactic_order_change_price_rej(const std::string & orderid, double price)
{
	return;
}

void match_engine::fp_te_tactic_order_change_size_done(const std::string & orderid, long size)
{
	return;
}
void match_engine::fp_te_tactic_order_change_price_done(const std::string & orderid, double price)
{
	return;
}
