#ifndef TRANS_EVENT
#define TRANS_EVENT

#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include"../match_engine/match_engine.h"
#include"../match_engine/order.h"

//������ME��datafeed֮�䴫����Ϣ  2014-07-03
//������ match_engine.cpp�� 2014-07-14
//����Ӧ�÷�ʽ����������� ��ͬrelease�汾���ܲ���֤һ��or������� ������Լ����౩¶
//����protobuffer ��д�˳��� 2014-08-06

class trans_event
{
public:
	trans_event();
	~trans_event();

	void setmessagefile(const std::string &);

	void datafeed_me(const std::string &);//����Ϣ
	void datafeed_me(const std::string & symbol, const std::string & ba, long level, double price, long size);//��׼bid ask ��Ϣ
	void datafeed_me(const std::string &,const std::map<std::string,std::string> &);//�Ǳ�׼��Ϣ
	
    void tactic_me(const std::string & symbol,  const std::string & buysell, double price ,long size);//add order
	void fp_tactic(const std::string & message);
private:
	bool _recordmessage;
	std::ifstream * _pfile;
};

#endif

