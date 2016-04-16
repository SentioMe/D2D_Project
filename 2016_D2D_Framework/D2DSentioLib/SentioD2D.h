#pragma once


/**
@brief　Direct2Dの開発環境を提供する静的ライブラリーのファイル
*/

#include "LibConfig.h"
#include "UsingLibrary.h"

//###################################################################
#pragma region Utility
#include "Utility\Abstraction\Singleton.h"
#include "Utility\Abstraction\IUpdatable.h"
#include "Utility\Macro.h"
#include "Utility\Random.h"
#include "Utility\MathUtil.h"
#include "Utility\StringUtil.h"
#include "Utility\GenericUtil.h"
#pragma endregion
//###################################################################

//###################################################################
#pragma region System

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
