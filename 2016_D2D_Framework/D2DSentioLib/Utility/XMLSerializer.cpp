#include "SentioD2D.h"
#include "XMLSerializer.h"

namespace DXLib
{
	XMLSerializer::XMLSerializer(void)
		: _document(nullptr), _filePath(nullptr)
	{
		_document = new tinyxml2::XMLDocument();
	}
	XMLSerializer::XMLSerializer(const char* filePath)
		: _filePath(filePath)
	{
		_document = new tinyxml2::XMLDocument();
		tinyxml2::XMLNode* root = _document->NewElement(XML_ROOT);
		_document->InsertFirstChild(root);

		_levelStack.push((tinyxml2::XMLElement*)root);
	}
	XMLSerializer::~XMLSerializer(void)
	{
		while (false == _levelStack.empty())
		{
			_levelStack.pop();
		}
		_document->Clear();
		SAFE_DELETE(_document);
	}

	XMLSerializer* XMLSerializer::Load(const char* filePath)
	{
		XMLSerializer* serializer = new XMLSerializer();
		tinyxml2::XMLError error = serializer->_document->LoadFile(filePath);

		if (error != tinyxml2::XMLError::XML_SUCCESS)
			return nullptr;

		serializer->_filePath = filePath;
		tinyxml2::XMLElement* root = (tinyxml2::XMLElement*)serializer->_document->FirstChild();
		serializer->_levelStack.push(root);

		return serializer;
	}

	bool XMLSerializer::Save(void)
	{
		tinyxml2::XMLError error = _document->SaveFile(_filePath);
		return error == tinyxml2::XMLError::XML_SUCCESS;
	}

	bool XMLSerializer::Close(void)
	{
		delete this;

		return true;
	}


	void XMLSerializer::Write(const char* key, IXMLSerializable& value)
	{
		tinyxml2::XMLElement* data = _document->NewElement(key);

		_levelStack.top()->InsertEndChild(data);

		_levelStack.push(data);
		value.Serialize(this);
		_levelStack.pop();
	}
	void XMLSerializer::Write(const char* key, const char* value)
	{
		tinyxml2::XMLElement* data = _document->NewElement(key);
		data->SetText(value);
		_levelStack.top()->InsertEndChild(data);
	}
	void XMLSerializer::Write(const char* key, int value)
	{
		tinyxml2::XMLElement* data = _document->NewElement(key);
		data->SetText(value);
		_levelStack.top()->InsertEndChild(data);
	}
	void XMLSerializer::Write(const char* key, unsigned value)
	{
		tinyxml2::XMLElement* data = _document->NewElement(key);
		data->SetText(value);
		_levelStack.top()->InsertEndChild(data);
	}
	void XMLSerializer::Write(const char* key, bool value)
	{
		tinyxml2::XMLElement* data = _document->NewElement(key);
		data->SetText(value);
		_levelStack.top()->InsertEndChild(data);
	}
	void XMLSerializer::Write(const char* key, double value)
	{
		tinyxml2::XMLElement* data = _document->NewElement(key);
		data->SetText(value);
		_levelStack.top()->InsertEndChild(data);
	}
	void XMLSerializer::Write(const char* key, float value)
	{
		tinyxml2::XMLElement* data = _document->NewElement(key);
		data->SetText(value);
		_levelStack.top()->InsertEndChild(data);
	}

	void XMLSerializer::Read(const char* key, IXMLSerializable& value)
	{
		tinyxml2::XMLElement* data = _levelStack.top()->FirstChildElement(key);
		if (data != nullptr)
		{
			_levelStack.push(data);
			value.Deserialize(this);
			_levelStack.pop();
		}
	}

	void XMLSerializer::Read(const char* key, char*& value, const char* defaultValue)
	{
		tinyxml2::XMLElement* data = _levelStack.top()->FirstChildElement(key);

		if (data != nullptr)
			value = const_cast<char*>(data->GetText());
		else
			value = const_cast<char*>(defaultValue);
	}
	void XMLSerializer::Read(const char* key, int& value, const int defaultValue)
	{
		tinyxml2::XMLElement* data = _levelStack.top()->FirstChildElement(key);

		if (data != nullptr)
			data->QueryIntText(&value);
		else
			value = defaultValue;
	}
	void XMLSerializer::Read(const char* key, unsigned& value, const unsigned defaultValue)
	{
		tinyxml2::XMLElement* data = _levelStack.top()->FirstChildElement(key);
		
		if (data != nullptr)
			data->QueryUnsignedText(&value);
		else
			value = defaultValue;
	}
	void XMLSerializer::Read(const char* key, bool& value, const bool defaultValue)
	{
		tinyxml2::XMLElement* data = _levelStack.top()->FirstChildElement(key);

		if (data != nullptr)
			data->QueryBoolText(&value);
		else
			value = defaultValue;
	}
	void XMLSerializer::Read(const char* key, double& value, const double defaultValue)
	{
		tinyxml2::XMLElement* data = _levelStack.top()->FirstChildElement(key);

		if (data != nullptr)
			data->QueryDoubleText(&value);
		else
			value = defaultValue;
	}
	void XMLSerializer::Read(const char* key, float& value, const float defaultValue)
	{
		tinyxml2::XMLElement* data = _levelStack.top()->FirstChildElement(key);

		if (data != nullptr)
			data->QueryFloatText(&value);
		else
			value = defaultValue;
	}

}