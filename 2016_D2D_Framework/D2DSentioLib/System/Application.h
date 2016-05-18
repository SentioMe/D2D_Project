#pragma once


#ifndef __DXLIB_APPLICATION_H__
#define __DXLIB_APPLICATION_H__
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	struct ApplicationData
	{
		HINSTANCE	instanceHandle;
		HWND		windowHandle;
	};

	class Application sealed :
		public Singleton<Application>
	{
	SL_CONSTRUCTOR_ACCESS_LEVEL:
		Application(void)
		{
		}
		virtual~Application(void) override
		{
		}

	public:
		int Run(void);

		void SetRenderingFrameCount(int frameCount);
	protected:
		LARGE_INTEGER _renderingInterval;

		PropertyReadonly(ApplicationData, _appData, AppData);
		Property(std::string, _resourceRootPath, ResourceRootPath);
		
	};

}

#endif //!__DXLIB_APPLICATION_H__