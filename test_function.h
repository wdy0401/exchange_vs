#include"protobuf/stdafx.h"
#include"protobuf/quote.pb.h"
#include"protobuf/order.pb.h"

#include"gpp_qt/wfunction/wfunction.h"

#include"gpp_qt/datafeed/datafeed.h"
#include"gpp_qt/match_engine/match_engine.h"
#include"gpp_qt/cfg/cfg.h"

#include<Windows.h>
#include<string>
#include<list>
#include<stdio.h>

void runtactic();
int test_protobuf();
std::list<std::string> splitstring(std::string,std::string splitchar);
int test_protobuf_order();
void TestStream();
