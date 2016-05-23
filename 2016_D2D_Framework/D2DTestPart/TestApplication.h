#pragma once


class TestApplication : public DXLib::Application
{
public:
	TestApplication(void);
	virtual~TestApplication(void) override;

protected:
	virtual bool _OnInitialize(void) override;
};

