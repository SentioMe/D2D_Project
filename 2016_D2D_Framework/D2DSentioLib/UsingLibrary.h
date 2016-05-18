#pragma once

#ifndef __USING_LIBRARY_H__
#define __USING_LIBRARY_H__

/**
@brief　汎用的に使用しているライブラリー達を含める。
*/

#include <Windows.h>		//for Create a Window
#include <D2D1.h>			//for Use to Direct2D

#include <stdlib.h>			//for Use to stanard library
#include <malloc.h>			//for Control by memory
#include <memory.h>			//for Control by buffer
#include <tchar.h>			//for Control by string

#include <string>			//for Use to string

#include <sstream>			//for Control by string
#include <fstream>			//for Control by file

#include <vector>			//for Use to vector container
#include <map>				//for Use to map container
#include <stack>			//for Use to stack container

#include <cassert>			//for Use to CASSERT (Check error when compile)
#include <assert.h>			//for Use to ASSERT (Check error when exequte)

#endif //!__USING_LIBRARY_H__