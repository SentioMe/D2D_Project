#pragma once

/**
@brief
내, 외부적으로 사용되는 라이브러리들을 호출한다
*/

#include <Windows.h>		//Window를 구성하기 위한 기본 헤더 파일
#include <D2D1.h>			//Direct 2D를 사용하기 위한 헤더 파일

#include <stdlib.h>			//Standard Library 헤더 파일
#include <malloc.h>			//메모리 제어 관련 헤더 파일
#include <memory.h>			//Buffer 제어 관련 헤더 파일
#include <tchar.h>			//문자열 처리 제어 관련 헤더 파일

#include <string>			//String형을 포함하는 헤더 파일

#include <sstream>			//String 제어 관련 헤더 파일
#include <fstream>			//File 제어 관련 헤더 파일

#include <vector>			//STL_Vector를 포함하는 헤더 파일
#include <map>				//STL_Map을 포함하는 헤더 파일

#include <cassert>			//컴파일 시간에 참, 거짓을 판단하는 CASSERT 관련 헤더 파일
#include <assert.h>			//실행 시간에 참, 거짓을 판단하는 ASSERT 관련 헤더 파일
