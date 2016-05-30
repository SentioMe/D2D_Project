#pragma once

#ifndef __DXLIB_PATH_H__
#define __DXLIB_PATH_H__
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	/**
	@class Path
	@brief ファイルのパスなどの処理を支援する静的関数の集まり
	*/
	class Path
	{
	public:
		static std::string RunningPath(void);

		static std::string Parent(std::string path);
	};

}

#endif //!__DXLIB_PATH_H__