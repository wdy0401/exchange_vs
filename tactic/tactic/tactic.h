// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� TACTIC_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// TACTIC_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef TACTIC_EXPORTS
#define TACTIC_API __declspec(dllexport)
#else
#define TACTIC_API __declspec(dllimport)
#endif


#include<list>
#include<string>

// �����Ǵ� tactic.dll ������
class TACTIC_API tactic {
public:
	tactic(void);
	// TODO: �ڴ��������ķ�����	
	void init();

	//quote���
	void add_quote_symbol(const std::string &);
	//��������Щsymbol��quote ����quote����
	void del_quote_symbol(const std::string &);
	//������Щsymbol��quote
	void readquote();
	
	//order���
	void add_order_symbol(const std::string &);
	void del_order_symbol(const std::string &);
	
private:
	//����
	void _delete_same_symbol(std::list<std::string> *);
	void _delete_symbol(std::list<std::string> *,const std::string & );

	
	std::list<std::string> _quote_symbols;
	std::list<std::string> _order_symbols;

};