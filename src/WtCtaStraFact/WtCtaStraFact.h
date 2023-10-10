#pragma once
#include "../Includes/CtaStrategyDefs.h"

USING_NS_WTP;

class WtStraFact : public ICtaStrategyFact
{
public:
	WtStraFact();
	virtual ~WtStraFact();

public:
	/*
	 *	��ȡ��������
	 */
	virtual const char* getName() override;

	/*
	 *	��������
	 *	@name	��������
	 *	@id		Ҫ�����Ĳ��Զ����ID
	 */
	virtual CtaStrategy* createStrategy(const char* name, const char* id) override;

	/*
	 *	ö�ٲ�������
	 *	@cb	ö�ٲ������ƵĻص�����
	 */
	virtual void enumStrategy(FuncEnumStrategyCallback cb) override;

	/*
	 *	ɾ������
	 *	@stra	���Զ���ָ��
	 */
	virtual bool deleteStrategy(CtaStrategy* stra) override;	
};

