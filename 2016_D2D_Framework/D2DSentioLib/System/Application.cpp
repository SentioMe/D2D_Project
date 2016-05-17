#include "SentioD2D.h"
#include "Application.h"

namespace DXLib
{
	int Application::Run(void)
	{
		
		LARGE_INTEGER last;
		LARGE_INTEGER now;

		QueryPerformanceCounter(&last);

		Director& director = Director::Instance();

		while (true)
		{
			QueryPerformanceCounter(&now);

			if (now.QuadPart - last.QuadPart > _renderingInterval.QuadPart)
			{
				last.QuadPart = now.QuadPart - (now.QuadPart % _renderingInterval.QuadPart);

				director.Run();
			}
			else
			{
				Sleep(1);
			}

		}

		director.Destroy();

		return 0;
	}

	void Application::SetRenderingFrameCount(int frameCount)
	{
		float interval = 1.0f / (float)frameCount;
		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency);
		_renderingInterval.QuadPart = (LONGLONG)(interval * frequency.QuadPart);
	}
}