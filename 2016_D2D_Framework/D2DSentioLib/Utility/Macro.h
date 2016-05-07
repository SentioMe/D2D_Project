#pragma once

//#########################################################################
#pragma region Safe Macro

/** 参照してる対象が有効ならば、そのメモリーを解除してnullptrを代入します。*/
#define SAFE_DELETE(p)				if(p){delete p; p = nullptr;}
/** 参照してる配列が有効ならば、そのメモリーを解除してnullptrを代入します。*/
#define SAFE_DELETE_ARRAY(p)		if(p){delete[] p; p = nullptr;}
/** 参照してるCOMの対象が有効ならば、そのメモリーを解除して（メモリーの参照のカウンターを減少する）nullptrを代入します。*/
#define SAFE_RELEASE(p)				if(p){p->Release(); p = nullptr;}
/** 参照してる対象が有効ならば、指定した命令を実行します。*/
#define SAFE_OPERATE(p, Methode)	if(p){p->Methode();}

#pragma endregion
//#########################################################################


//#########################################################################
#pragma region Variable-Getter-Setter Synthesize : Create Property Macro


#define PROPERTY(varType, varName, funcName)\
	protected: varType varName;\
	public : inline varType Get##funcName(void) const {return varName;}\
	public : inline void Set##funcName(varType var) {varName = var;}

#define PROPERTY_GET(varType, varName, funcName)\
	protected: varType varName;\
	public : inline varType Get##funcName(void) const {return varName;}

#define PROPERTY_SET(varType, varName, funcName)\
	protected: varType varName;\
	public : inline void Set##funcName(varType var) {varName = var;}

#pragma endregion
//#########################################################################


/** @warning
C++での動的なメモリーの割り当てに失敗した場合、std::bad_allocと値が返され、真偽を判断することができなくなる。
そのためにstd::nothrowを宣言して失敗した場合、falseが返されるようにする。*/
#define ALLOCATE(varType, varName) varType* varName = new (std::nothrow) varType()
