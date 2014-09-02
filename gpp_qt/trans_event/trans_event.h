#ifndef TRANS_EVENT
#define TRANS_EVENT

#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include"../match_engine/match_engine.h"
#include"../match_engine/order.h"

//用来在ME与datafeed之间传递消息  2014-07-03
//定义在 match_engine.cpp中 2014-07-14
//更多应用方式与具体程序相关 不同release版本功能不保证一致or互相兼容 以免策略见互相暴露
//可用protobuffer 改写此程序 2014-08-06

class trans_event
{
public:
	trans_event();
	~trans_event();

	void setmessagefile(const std::string &);

	void datafeed_me(const std::string &);//简单消息
	void datafeed_me(const std::string & symbol, const std::string & ba, long level, double price, long size);//标准bid ask 消息
	void datafeed_me(const std::string &,const std::map<std::string,std::string> &);//非标准消息
	
    void tactic_me(const std::string & symbol,  const std::string & buysell, double price ,long size);//add order
	void fp_tactic(const std::string & message);
private:
	bool _recordmessage;
	std::ifstream * _pfile;
};

#endif

