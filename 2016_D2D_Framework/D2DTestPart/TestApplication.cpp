#include "stdafx.h"
#include "TestApplication.h"


TestApplication::TestApplication(void)
{
}


TestApplication::~TestApplication(void)
{
}

bool TestApplication::_OnInitialize(void)
{

	SetRenderingFrame(60.0f);

	return true;
}