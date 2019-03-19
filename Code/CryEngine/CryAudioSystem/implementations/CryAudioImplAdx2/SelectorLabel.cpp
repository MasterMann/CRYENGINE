// Copyright 2001-2018 Crytek GmbH / Crytek Group. All rights reserved.

#include "stdafx.h"
#include "SelectorLabel.h"
#include "BaseObject.h"

#include <cri_atom_ex.h>

namespace CryAudio
{
namespace Impl
{
namespace Adx2
{
//////////////////////////////////////////////////////////////////////////
void CSelectorLabel::Set(IObject* const pIObject)
{
	auto const pBaseObject = static_cast<CBaseObject const*>(pIObject);

	CriAtomExPlayerHn const pPlayer = pBaseObject->GetPlayer();
	criAtomExPlayer_SetSelectorLabel(pPlayer, static_cast<CriChar8 const*>(m_selectorName), static_cast<CriChar8 const*>(m_selectorLabelName));
	criAtomExPlayer_UpdateAll(pPlayer);
}

//////////////////////////////////////////////////////////////////////////
void CSelectorLabel::SetGlobally()
{
	auto const szSelectorName = static_cast<CriChar8 const*>(m_selectorName);
	auto const szSelectorLabelName = static_cast<CriChar8 const*>(m_selectorLabelName);

	for (auto const pBaseObject : g_constructedObjects)
	{
		CriAtomExPlayerHn const pPlayer = pBaseObject->GetPlayer();
		criAtomExPlayer_SetSelectorLabel(pPlayer, szSelectorName, szSelectorLabelName);
		criAtomExPlayer_UpdateAll(pPlayer);
	}
}
} // namespace Adx2
} // namespace Impl
} // namespace CryAudio
