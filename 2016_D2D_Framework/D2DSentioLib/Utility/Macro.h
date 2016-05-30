#pragma once

#ifndef __MACRO_H__
#define __MACRO_H__

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

#define Property(varType, varName, funcName)\
	protected: varType varName;\
	public : inline const varType& Get##funcName(void) {return varName;}\
	public : inline void Set##funcName(const varType& var) {varName = var;}

#define PropertyReadonly(varType, varName, funcName)\
	protected: varType varName;\
	public : inline const varType& Get##funcName(void) {return varName;}

#define PropertyWriteonly(varType, varName, funcName)\
	protected: varType varName;\
	public : inline void Set##funcName(const varType& var) {varName = var;}

#define PtrProperty(varType, varName, funcName)\
	protected: varType* varName;\
	public : inline const varType* Get##funcName(void) const {return varName;}\
	public : inline void Set##funcName(varType* var) {varName = var;}

#define PtrPropertyReadonly(varType, varName, funcName)\
	protected: varType* varName;\
	public : inline const varType* Get##funcName(void) const {return varName;}

#define PtrPropertyWriteonly(varType, varName, funcName)\
	protected: varType* varName;\
	public : inline void Set##funcName(varType* var) {varName = var;}

#pragma endregion
//#########################################################################


/** @warning
C++での動的なメモリーの割り当てに失敗した場合、std::bad_allocと値が返され、真偽を判断することができなくなる。
そのためにstd::nothrowを宣言して失敗した場合、falseが返されるようにする。*/
#define ALLOCATE(varType, varName) varType* varName = new (std::nothrow) varType()


#endif //!__MACRO_H__