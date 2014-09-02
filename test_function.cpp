#include"test_function.h"
#include <stdio.h>

using namespace std;
using namespace QUOTE;
//using namespace TRANS_ORDER;




extern cfg simucfg;
extern match_engine me;
extern datafeed df;



void runtactic()
{
    simucfg.loadfile();
    string quotefiles=	simucfg.getparam("datafeedfile");
    string fpname	=	simucfg.getparam("fillpolicy");

    me.loadfillpolicy(fpname);
    quotefiles="d:/data_trans_IF1401_100.csv";
    df.setfile(quotefiles);

    df.run();
}

int test_protobuf()
{
	qrs msgs;
	
	string outfile="d:/proto_buffer_vs_qt.log";
	fstream output(outfile.c_str(),ios::out | ios::trunc | ios::binary); 
	
	string plaintxt_filename="d:/data_trans_IF1401_100.csv";
	
	cout<<plaintxt_filename<<endl;

	fstream input(plaintxt_filename.c_str(), ios::in); 

	if(output.is_open() && input.is_open())
	{
		//正常情况
	}
	else
	{
		return 1;//有文件未打开 直接返回
	}
	string tmpstring;
	long lines=0;
	while(getline(input,tmpstring))
	{
			
		list<string> lists=splitstring(tmpstring,",");
		list<string>::iterator iter=lists.begin();

		long	nowtime=atol(iter->c_str());
		string	symbol=(++iter)->c_str();
		string	bidask=(++iter)->c_str();
		long	level=atol((++iter)->c_str());
		double	price=atof((++iter)->c_str());
		long	size=atol((++iter)->c_str());
		bool	tradeable=(atol((++iter)->c_str())==0);

		msgs.set_symbol(symbol);


		quote_record* msg=new quote_record;
		msg->set_tm(nowtime);
		msg->set_type(bidask);
		msg->set_price(price);
		msg->set_size(size);
		msg->set_level(level);
		msg->set_tradeable(tradeable);

		msgs.add_qr()->MergeFrom(*msg);
		lines++;
//		msgs.set_lines(lines);
	}
	if (!msgs.SerializeToOstream(&output))
	{ 
		cerr << "Failed to write msg." << endl; 
		return -1; 
	}
	output.close();
	input.close();

	//重新读入刚写入的file
	input.open(outfile.c_str(), ios::in | ios::binary); 
	//fstream input(outfile.c_str(), ios::in | ios::binary); 
	msgs.Clear();
	
	qrs msgss;
	
	msgss.ParseFromIstream(&input);

	int readlines=msgss.qr_size();
	for(int i=0;i<readlines;i++)
	{
		cout<<std::fixed<<msgss.mutable_qr()->Get(i).tm()<<endl;
		cout<<msgss.mutable_qr()->Get(i).size()<<endl;
	}
	return 0;
}


list<string> splitstring(std::string tp,std::string splitchar)
{
	list<string> ret;
	while(tp.size())
	{		
		static int index=0;
		index=tp.find_first_of(splitchar);

		string tmpstring=tp.substr(0,index);
		ret.push_back(tmpstring);

		if(index==-1)
		{
			break;
		}
		tp=tp.substr(index+1);
	}
	return ret;
}

int test_protobuf_order()
{
	
	TRANS_ORDER::orders ods;
	TRANS_ORDER::order od;
	
	string outfile="proto_buffer_vs_qt_ods.log";
	fstream output(outfile.c_str(),ios::out | ios::trunc | ios::binary); 
	
	if(output.is_open())
	{
		//正常情况
	}
	else
	{
		return 1;//有文件未打开 直接返回
	}
	od.set_symbol("IF1410");
	od.set_size(10);
	od.set_buysell(TRANS_ORDER::BUY);
//	od.set_buysell(0);
	ods.add_order_list()->MergeFrom(od);
	
	od.set_symbol("IF1411");
	od.set_size(20);
	od.set_buysell(TRANS_ORDER::SELL);
//	od.set_buysell(1);
	ods.add_order_list()->MergeFrom(od);
	if (!ods.SerializeToOstream(&output))
	{ 
		cerr << "Failed to write msg." << endl; 
		return -1; 
	}
	output.close();

	//重新读入刚写入的file
	fstream input;
	input.open(outfile.c_str(), ios::in | ios::binary); 
	//fstream input(outfile.c_str(), ios::in | ios::binary); 
	ods.Clear();
	
	
	ods.ParseFromIstream(&input);

	int readlines=ods.order_list_size();
	for(int i=0;i<readlines;i++)
	{
		cout<<std::fixed<<ods.mutable_order_list()->Get(i).symbol()<<endl;
		cout<<" "<<ods.mutable_order_list()->Get(i).size()<<endl;
		cout<<" "<<ods.mutable_order_list()->Get(i).buysell()<<endl;
		
	}
	return 0;
}
void TestStream()
{
	ifstream * ifs=new ifstream;
	ifs->open("d:/1.gz",ios_base::in|ios_base::binary);
	ofstream * ofs=new ofstream;
	ofs->open("d:/1.gz.txt",ios_base::out|ios_base::binary);
	wfunction::UnZipStream(*ifs,*ofs);
	ifs->close();
	ofs->close();

	ifs->open("d:/1.gz.txt",ios_base::out|ios_base::binary);
	ofs->open("d:/1.gz.txt.gz",ios_base::out|ios_base::binary);
	wfunction::ZipStream(*ifs,*ofs);
	ifs->close();
	ofs->close();
	
}
