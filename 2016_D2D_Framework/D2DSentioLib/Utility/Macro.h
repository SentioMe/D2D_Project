#pragma once

//#########################################################################
//Safe Macro
//#########################################################################

//해당 참조가 유효할 때, 대상의 메모리를 해제하고 nullptr로 대입한다
#define SAFE_DELETE(p)				if(p){delete p; p = nullptr;}
//해당 참조가 유효할 때, 대상 배열의 메모리를 해제하고 nullptr로 대입한다
#define SAFE_DELETE_ARRAY(p)		if(p){delete[] p; p = nullptr;}
//해당 참조가 유효할 때, 대상의 메모리 참조 수를 감소시키고, nullptr로 대입한다
#define SAFE_RELEASE(p)				if(p){p->Release(); p = nullptr;}
//해당 참조가 유효할 때, 대상으로부터 지정 함수를 실행시킨다
#define SAFE_OPERATE(p, Methode)	if(p){p->Methode();}



//#########################################################################
//(Variable, Getter, Setter) Synthesize
//#########################################################################
#define Decl(varType, varName, funcName)\
	protected: varType varName;\
	public : inline varType Get##funcName(void) const {return varName;}\
	public : inline void Set##funcName(varType var) {varName = var;}

#define Alloc(varType, varName) varType* varName = new (std::nothrow) varType()
