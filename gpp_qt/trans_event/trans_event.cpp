#include"trans_event.h"
#include"../wfunction/wfunction.h"
#include"../match_engine/match_engine.h"
#include"../log_info/log_info.h"
#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include"mainwindow.h"

extern match_engine me;
extern datafeed df;
extern MainWindow * mw;
extern log_info loginfo;
using namespace std;

trans_event::trans_event()
{
	_recordmessage=false;
}
trans_event::~trans_event()
{
	if(_pfile)
	{
		delete _pfile;
		_pfile=NULL;
	}
}
void trans_event::setmessagefile(const string & filename)
{
	_pfile=new ifstream;
	_pfile->open(filename.c_str());
	if(! _pfile->is_open()) //检测文件存在性
	{
		delete _pfile;
		_pfile=NULL;
		
		cerr << "Cannot open trans_event file " << filename.c_str() << endl;
		cerr << "Press any key to continue"<<endl;
		getchar();
		return;
	}
	else
	{
		this->_recordmessage=true;
	}
}
void trans_event::datafeed_me(const std::string & simple_message)
{
    loginfo.writeinfo(simple_message);
    return;//目前不处理简单message
}
void trans_event::datafeed_me(const std::string & symbol, const std::string & ba, long level, double price, long size)//IF1405 bid 1 2100.2 5
{
    string ts;
    ts+=symbol;
    ts+=" "+ba;
    ts+=" "+wfunction::itos(level);
    ts+=" "+wfunction::ftos(price);
    ts+=" "+wfunction::itos(size);
    mw->set_text(ts);
    me.rec_update(symbol,ba,level,price,size);
}
void trans_event::tactic_me(const std::string & symbol,  const std::string & buysell, double price ,long size)
{
    me.add_order(symbol,buysell,price,size);
}
void trans_event::datafeed_me(const std::string & message_type,const std::map<std::string,std::string> & map_message)
{
    loginfo.writeinfo(message_type);
    loginfo.writeinfo(wfunction::itos(map_message.size()));
    return;//目前不处理复杂消息
}
