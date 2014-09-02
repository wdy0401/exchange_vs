#ifndef MATCH_ENGINE
#define MATCH_ENGINE

#include<string>
#include<map>
#include"orderbook.h"
#include"orderlist.h"
#include"order.h"
#include"../wtimer/wtimer.h"
#include"../fillpolicy/fillpolicy.h"
#include"../datafeed/datafeed.h"
//#include"../trans_event/trans_event.h"

//tactic
//���躯��
//0.��ʼ��
//1.�ջر�
//2.������
//3.���� �ĵ� ����


//��Ҫ����
//ģ�⽻�������д�Ͻ��ף����������ɴ����symbol�Ľ��ס�
//�����沢������ʵ��ʱ�䣬���ٶ�ȡ������Ϣ���ٶȡ����Ը���ĸ���ģ������
//�����������leg��Ϣ��������Ĵ���


//���ڶ���Ժϳɵĸ����ԣ���ME���������ԵĹ�ϵ�������������װ��ͬ���ӿ�

//ʱ���ϵΪ
//����orderbook(�������ã����ü��� ȡ��������Դ)
//�鿴fillpolicy��˳�����fill load��order ����ack or rej��
//����tactic����������orderlist��

//ME��datafeed����event_trans��ͨ��Ϣ ������Ϣ�� 


class match_engine
{
public:
	
	//friend class trans_event;

	bool loadtactic(std::string &);
	bool loadfillpolicy(std::string &);

	void rec_update(const std::string & symbol, const std::string & ba, long level, double price, long size);

	void setnowsymbol(const std::string & symbol);
	void updateorderbook(const std::string &,const std::string &,long,double,long);//IF1405 bid 1 2100.2 5
	void updatefp();//��дorderlist����order��״̬
	void updatetactic();//�����µ�orderbook���ж�ʱ����order
	void updatetacticbooks();//�ڲ�����Ҫ�����bookʱʹ�� ��δʵ��
		
	void add_order(const std::string & symbol,  const std::string & buysell, double price ,long size);
	void add_order(const std::string & msg);
private:
    std::map<std::string,orderbook> _orderbooks;
	fillpolicy _fp;
	orderlist _ol;
	std::string _nowsymbol;
};

/*
tactic ��η���_ol
ͨ��ME�� ֱ�ӳ�ΪME��Ա��

����Ҫ��tacticorder����һ���� ����tacticά����order���д���

fp��Ϣ��θ���tactic��

Ŀǰorder orderlist orderbook �ǽ���������tactic�� 

*/

/*
Ŀǰorder�����㽻������tactic��ͬ���������

*/

#endif

