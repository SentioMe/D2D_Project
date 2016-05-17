#pragma once


/**
@brief　Direct2Dの開発環境を提供する静的ライブラリーのファイル
*/

#include "LibConfig.h"
#include "UsingLibrary.h"

//###################################################################
#pragma region Share
#include "Share\tinyxml2.h"
#pragma endregion
//###################################################################

//###################################################################
#pragma region Utility
#include "Utility\Abstract\Singleton.h"
#include "Utility\Abstract\IUpdatable.h"
#include "Utility\Abstract\IXMLSerializable.h"

#include "Utility\Extend\ExtendMath.h"
#include "Utility\Extend\ExtendString.h"
#include "Utility\Extend\ExtendCollection.h"

#include "Utility\Macro.h"
#include "Utility\Random.h"
#include "Utility\XMLSerializer.h"
#pragma endregion
//###################################################################

//###################################################################
#pragma region System
#include "System\Director.h"
#include "System\Application.h"
#include "System\BagicNode.h"

#include "System\Sprite\Texture.h"
#include "System\Sprite\TextureCashe.h"
#include "System\Sprite\Sprite.h"

#include "System\Label\Label.h"

#include "System\Scene\Scene.h"
#include "System\Scene\SceneLoader.h"

#pragma endregion
//####################################################################

//###################################################################
#pragma region Extension
#pragma endregion
//###################################################################
