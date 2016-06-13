#pragma once

#ifndef __DXLIB_XML_SERIALIZER_H__
#define __DXLIB_XML_SERIALIZER_H__

/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/

namespace DXLib
{
#define XML_ROOT "Root"

	/**
	@class XMLSerializer
	@brief XMLの形式でSerializeをするClass
			Share\tinyxml2を使います。
	*/
	class XMLSerializer sealed
	{
	public:
		XMLSerializer(void);
		XMLSerializer(const char* filePath);
		~XMLSerializer(void);

	public:
		static XMLSerializer* Load(const char* filePath);
		bool Save(void);

		bool XMLSerializer::Close(void);

	public:
		void Write(const char* key, IXMLSerializable& value);
		void Write(const char* key, const char* value);
		void Write(const char* key, std::string& value);
		void Write(const char* key, int value);
		void Write(const char* key, unsigned value);
		void Write(const char* key, bool value);
		void Write(const char* key, double value);
		void Write(const char* key, float value);

		template<typename T>
		void WriteArray(const char* key, T* value1DArrayBegin, int size);
		template<typename T>
		void WriteArray(const char* key, T* value2DArrayBegin, int row, int col);
		template<typename T>
		void WriteVector(const char* key, std::vector<T>& valueVector);

		void Read(const char* key, IXMLSerializable& value);
		void Read(const char* key, char*& value, const char* defaultValue = "\0");
		void Read(const char* key, std::string& value, const std::string defaultValue = "");
		void Read(const char* key, int& value, const int defaultValue = 0);
		void Read(const char* key, unsigned& value, const unsigned defaultValue = 0);
		void Read(const char* key, bool& value, const bool defaultValue = false);
		void Read(const char* key, double& value, const double defaultValue = 0.0);
		void Read(const char* key, float& value, const float defaultValue = 0.0f);

		template<typename T>
		void ReadArray(const char* key, T* value1DArrayBegin, int size);
		template<typename T>
		void ReadArray(const char* key, T* value2DArrayBegin, int row, int col);
		template<typename T>
		void ReadVector(const char* key, std::vector<T>& valueVector, int size);

	private:
		const char*							_filePath;
		tinyxml2::XMLDocument*				_document;
		std::stack<tinyxml2::XMLElement*>	_levelStack;

	};



	template<typename T>
	void XMLSerializer::WriteArray(const char* key, T* value1DArrayBegin, int size)
	{
		tinyxml2::XMLElement* data = _document->NewElement(key);
		_levelStack.top()->InsertEndChild(data);
		_levelStack.push(data);

		for (int i = 0; i < size; ++i)
		{
			char name[32];
			memset(name, 0, 32);
			sprintf(name, "ID_%d", i);
			tinyxml2::XMLElement* valueNode = _document->NewElement(name);
			_levelStack.top()->InsertEndChild(valueNode);

			_levelStack.push(valueNode);
			Write("var", *(value1DArrayBegin + i));
			_levelStack.pop();
		}

		_levelStack.pop();
	}
	template<typename T>
	void XMLSerializer::WriteArray(const char* key, T* value2DArrayBegin, int row, int col)
	{
		tinyxml2::XMLElement* data = _document->NewElement(key);
		_levelStack.top()->InsertEndChild(data);
		_levelStack.push(data);

		for (int i = 0; i < size; ++i)
		{
			char name[32];
			memset(name, 0, 32);
			sprintf(name, "ID_%d:%d", r, c);
			tinyxml2::XMLElement* valueNode = _document->NewElement(name);
			_levelStack.top()->InsertEndChild(valueNode);

			_levelStack.push(valueNode);
			Write("var", *(value2DArrayBegin + (c + r * col)));
			_levelStack.pop();
		}

		_levelStack.pop();
	}
	template<typename T>
	void XMLSerializer::WriteVector(const char* key, std::vector<T>& valueVector)
	{
		tinyxml2::XMLElement* data = _document->NewElement(key);
		_levelStack.top()->InsertEndChild(data);
		_levelStack.push(data);
		int size = valueVector.size();

		for (int i = 0; i < size; ++i)
		{
			char name[32];
			memset(name, 0, 32);
			sprintf(name, "ID_%d", i);
			tinyxml2::XMLElement* valueNode = _document->NewElement(name);
			_levelStack.top()->InsertEndChild(valueNode);

			_levelStack.push(valueNode);
			Write("var", valueVector[i]);
			_levelStack.pop();
		}

		_levelStack.pop();
	}

	template<typename T>
	void XMLSerializer::ReadArray(const char* key, T* value1DArrayBegin, int size)
	{
		tinyxml2::XMLElement* data = _levelStack.top()->FirstChildElement(key);
		_levelStack.push(data);

		tinyxml2::XMLElement* valueNode = _levelStack.top()->FirstChildElement("ID_0");

		int i = 0;
		while (valueNode != nullptr && i < size)
		{
			_levelStack.push(valueNode);
			Read("var", *(value1DArrayBegin + i));
			valueNode = (tinyxml2::XMLElement*)valueNode->NextSibling();
			++i;
			_levelStack.pop();
		}

		_levelStack.pop();
	}
	template<typename T>
	void XMLSerializer::ReadArray(const char* key, T* value2DArrayBegin, int row, int col)
	{
		tinyxml2::XMLElement* data = _levelStack.top()->FirstChildElement(key);
		_levelStack.push(data);

		tinyxml2::XMLElement* valueNode = _levelStack.top()->FirstChildElement("ID_0:0");

		int r, c = 0;

		while (valueNode != nullptr && r < row && c < col)
		{
			_levelStack.push(valueNode);
			Read("var", *(value2DArrayBegin + (c + r * col)));
			valueNode = (tinyxml2::XMLElement*)valueNode->NextSibling();
			++c;

			if (c >= col)
			{
				c = 0;
				++r;
			}

			_levelStack.pop();
		}

		_levelStack.pop();
	}

	template<typename T>
	void XMLSerializer::ReadVector(const char* key, std::vector<T>& valueVector, int size)
	{
		tinyxml2::XMLElement* data = _levelStack.top()->FirstChildElement(key);
		_levelStack.push(data);
		
		valueVector.resize(size);

		tinyxml2::XMLElement* valueNode = _levelStack.top()->FirstChildElement("ID_0");

		int i = 0;
		while (valueNode != nullptr && i < size)
		{
			_levelStack.push(valueNode);
			Read("var", valueVector[i]);
			valueNode = (tinyxml2::XMLElement*)valueNode->NextSibling();
			++i;
			_levelStack.pop();
		}

		_levelStack.pop();
	}
}

#endif //!__DXLIB_XML_SERIALIZER_H__