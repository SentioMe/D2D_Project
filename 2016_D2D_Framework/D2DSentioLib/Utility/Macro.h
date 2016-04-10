#pragma once

//#########################################################################
//Safe Macro
//#########################################################################

//�ش� ������ ��ȿ�� ��, ����� �޸𸮸� �����ϰ� nullptr�� �����Ѵ�
#define SAFE_DELETE(p)				if(p){delete p; p = nullptr;}
//�ش� ������ ��ȿ�� ��, ��� �迭�� �޸𸮸� �����ϰ� nullptr�� �����Ѵ�
#define SAFE_DELETE_ARRAY(p)		if(p){delete[] p; p = nullptr;}
//�ش� ������ ��ȿ�� ��, ����� �޸� ���� ���� ���ҽ�Ű��, nullptr�� �����Ѵ�
#define SAFE_RELEASE(p)				if(p){p->Release(); p = nullptr;}
//�ش� ������ ��ȿ�� ��, ������κ��� ���� �Լ��� �����Ų��
#define SAFE_OPERATE(p, Methode)	if(p){p->Methode();}



//#########################################################################
//(Variable, Getter, Setter) Synthesize
//#########################################################################
#define Decl(varType, varName, funcName)\
	protected: varType varName;\
	public : inline varType Get##funcName(void) const {return varName;}\
	public : inline void Set##funcName(varType var) {varName = var;}

#define Alloc(varType, varName) varType* varName = new (std::nothrow) varType()
