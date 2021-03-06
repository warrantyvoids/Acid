﻿#pragma once

#include "Fonts/Text.hpp"
#include "Guis/Gui.hpp"

namespace acid
{
class ACID_EXPORT UiStartLogo :
	public UiObject
{
public:
	explicit UiStartLogo(UiObject *parent);

	void UpdateObject() override;

	bool IsFinished() const { return m_finished; }

	Delegate<void()> &OnFinished() { return m_onFinished; }

private:
	Gui m_guiBackground;
	Gui m_guiLogoAcid;
	Text m_textCopyright;

	Timer m_delayTimer;
	bool m_fadeout;
	bool m_finished;

	Delegate<void()> m_onFinished;
};
}
