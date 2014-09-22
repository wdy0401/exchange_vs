#include"mainwindow.h"
#include<QApplication>
#include<map>
#include<list>
#include<string>
#include<fstream>
#include<iostream>

#include<stdio.h>
#include<stdlib.h> 
#include<Windows.h>

#include"./protobuf/stdafx.h"
#include"./protobuf/quote.pb.h"

#include"gpp_qt/cfg/cfg.h"
#include"gpp_qt/wtimer/wtimer.h"
#include"gpp_qt/log_info/log_info.h"
#include"gpp_qt/wfunction/wfunction.h"

#include"gpp_qt/bar/bar.h"
#include"gpp_qt/datafeed/datafeed.h"
#include"gpp_qt/fillpolicy/fillpolicy.h"
#include"gpp_qt/trans_event/trans_event.h"

#include"gpp_qt/match_engine/order.h"
#include"gpp_qt/match_engine/orderlist.h"
#include"gpp_qt/match_engine/orderbook.h"
#include"gpp_qt/match_engine/match_engine.h"

#include"test_function.h"

#include"tactic/tactic/tactic.h"

#pragma comment(lib,"libprotobuf.lib")
#pragma comment(lib,"libprotoc.lib")

using namespace std;
using namespace QUOTE;


cfg simucfg;
log_info loginfo;
match_engine me;
datafeed df;
trans_event te;
wtimer tm;
tactic * ptc;

MainWindow * mw;
QApplication * qa;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qa=&a;
    mw=&w;

    w.show();
	
	//20140922 猜测是用lib给定的信息在默认目录找的
	//string dllname;
	//#ifdef _DEBUG
	//dllname="C:/Users/xzqh/Desktop/exchange/exchange_vs/tactic/Debug/tactic.dll";
	//#else
	//dllname="C:/Users/xzqh/Desktop/exchange/exchange_vs/tactic/Release/tactic.dll";
	//#endif
	//HINSTANCE hdll=LoadLibrary(dllname.c_str());
		
	tactic tc;
	ptc=&tc;
	ptc->set_te(&te);
	//FreeLibrary(hdll);

	
    runtactic();
	//test_protobuf();
	//test_protobuf_order();
	//TestStream();	

    return a.exec();
}

//test git

//test 2
