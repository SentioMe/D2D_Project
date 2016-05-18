#pragma once

#ifndef __LIB_CONFIG_H__
#define __LIB_CONFIG_H__

/**
@brief　プリプロセッサを使ってライブラリーの設定を定義する。
*/

#pragma region Enable warning message
#ifndef SL_ENABLE_WARNING
#define SL_ENABLE_WARNING 0
#endif

#if (SL_ENABLE_WARNING == 0)
#pragma warning (disable: 4005)		//4005 意味 : マクロの再定義に対しての警告
#pragma warning (disable: 4244)		//4244 意味 : キャスチングの中で起きる値の損失に対しての警告
#pragma warning (disable: 4018)		//4018 意味 : 符号付きの値と無い値のマッチングに対しての警告
#pragma warning (disable: 4311)		//4311 意味 : DWORD刑みたいな64Bitの値の移植性に対しての警告
#pragma warning (disable: 4312)		//4312 意味 : DWORD刑みたいな64Bitの値の移植性に対しての警告
#pragma warning (disable: 4002)		//4002 意味 : assertのマクロのパラメータが多過ぎな事に対しての警告
#pragma warning (disable: 4172)		//4172 意味 : ローカルのアドレスを返されした事に対しての警告
#endif
#pragma endregion

#pragma region Enable constructor call
#ifndef SL_ENABLE_NEW_OPERATOR
#define SL_ENABLE_NEW_OPERATOR 1
#endif

#ifndef SL_CONSTRUCTOR_ACCESS_LEVEL
	#if (SL_ENABLE_NEW_OPERATOR != 0)
		#define SL_CONSTRUCTOR_ACCESS_LEVEL public
	#else
		#define SL_CONSTRUCTOR_ACCESS_LEVEL protected
	#endif
#endif

#pragma endregion

#endif //!__LIB_CONFIG_H__