#include"../match_engine/orderbook.h"
#include"../match_engine/orderlist.h"
#include"../wtimer/wtimer.h"

#ifndef FILLPOLICY
#define FILLPOLICY

//���۳ɽ���fp
//

//fp��Ҫά��һ��snapshot��Ϣ �Ա����֮ǰ��snapshot���˽��������
//���ڴ�fp�ǹ��۳ɽ����ʲ���Ҫǰһ��snapshot
class fillpolicy
{
public:
	void updateorderlist(orderlist & ,orderbook & );
private:
	
};

#endif
