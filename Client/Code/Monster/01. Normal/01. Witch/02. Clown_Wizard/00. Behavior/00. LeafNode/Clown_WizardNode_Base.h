#pragma once

#include "Client_Defines.h"
#include "BTNode_Leaf.h"

#include "Clown.h"
#include "MonsterBt.h"

BEGIN(Client)

class CClown_WizardNode_Base abstract : public CBTNode_Leaf
{
public:
	CClown_WizardNode_Base();
	virtual ~CClown_WizardNode_Base() = default;

public:
	virtual HRESULT Initialize_Prototype(CMonsterBT::BT_MONSTERDESC* pDesc, CMonsterBT* pBT);
	virtual void	Start();
	virtual CBTNode::NODE_STATE	Tick(const _float& fTimeDelta);

	virtual CBTNode::NODE_STATE Atk_BehaviorTick(_float fDestWaitTime, const _float& fTimeDelta);

	virtual _bool Behavior_Wait(_float fDestWaitTime, const _float& fTimeDelta);

protected:
	_bool	m_bWait = false;
	CMonsterBT::BT_MONSTERDESC m_tBTMonsterDesc = {};

private:
	_float  m_fSourWaitTime = 0.f;

public:
	virtual void Free() override;
};

END

