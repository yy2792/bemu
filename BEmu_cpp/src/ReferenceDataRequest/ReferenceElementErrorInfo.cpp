﻿//------------------------------------------------------------------------------
// <copyright project="BEmu_cpp" file="src/ReferenceDataRequest/ReferenceElementErrorInfo.cpp" company="Jordan Robinson">
//     Copyright (c) 2013 Jordan Robinson. All rights reserved.
//
//     The use of this software is governed by the Microsoft Public License
//     which is included with this distribution.
// </copyright>
//------------------------------------------------------------------------------

#include "ReferenceDataRequest/ReferenceElementErrorInfo.h"
#include "Types/RandomDataGenerator.h"
#include "Types/IndentType.h"
#include "BloombergTypes/Name.h"

#include "ReferenceDataRequest/ReferenceElementString.h"
#include "ReferenceDataRequest/ReferenceElementInt.h"

namespace BEmu
{
	namespace ReferenceDataRequest
	{
		ReferenceElementErrorInfo::ReferenceElementErrorInfo()
		{
			std::string sourceGibberish = RandomDataGenerator::RandomString(5);
			std::transform(sourceGibberish.begin(), sourceGibberish.end(), sourceGibberish.begin(), ::tolower);

			std::stringstream ssSource;
			ssSource << RandomDataGenerator::RandomInt(99) << "::" << sourceGibberish.substr(0, sourceGibberish.length() - 2) << RandomDataGenerator::RandomInt(99);
			this->_source = new ReferenceElementString("source", ssSource.str());

			this->_code = new ReferenceElementInt("code", RandomDataGenerator::RandomInt(99));

			this->_category = new ReferenceElementString("category", "BAD_FLD");

            this->_message = new ReferenceElementString("message", "Field not valid");

            this->_subCategory = new ReferenceElementString("subcategory", "INVALID_FIELD");
		}

		ReferenceElementErrorInfo::~ReferenceElementErrorInfo()
		{
			delete this->_source;
			this->_source = 0;
			
			delete this->_code;
			this->_code = 0;
			
			delete this->_category;
			this->_category = 0;
			
			delete this->_message;
			this->_message = 0;
			
			delete this->_subCategory;
			this->_subCategory = 0;
		}

		Name ReferenceElementErrorInfo::name() const { return Name("errorInfo"); }
		size_t ReferenceElementErrorInfo::numValues() const { return 1; }
		size_t ReferenceElementErrorInfo::numElements() const { return 5; }

		SchemaElementDefinition ReferenceElementErrorInfo::elementDefinition() const
		{
			::blpapi_DataType_t dtype = (::blpapi_DataType_t)this->datatype();
			SchemaElementDefinition result(dtype, Name("ErrorInfo"));
			return result;
		}

		bool ReferenceElementErrorInfo::isNull() const { return false; }
		bool ReferenceElementErrorInfo::isArray() const { return false; }
		bool ReferenceElementErrorInfo::isComplexType() const { return true; }

		const char* ReferenceElementErrorInfo::getElementAsString(const char* name) const
		{
			return this->getElement(name)->getValueAsString(0);
		}

		int ReferenceElementErrorInfo::getElementAsInt32(const char* name) const
		{
			return this->getElement(name)->getValueAsInt32(0);
		}

		ElementPtr * ReferenceElementErrorInfo::getElement(const char* name) const
		{
			if(strncmp(name, "category", 9) == 0)
				return this->_category;

			else if(strncmp(name, "code", 5) == 0)
				return this->_code;

			else if(strncmp(name, "message", 8) == 0)
				return this->_message;

			else if(strncmp(name, "source", 7) == 0)
				return this->_source;

			else if(strncmp(name, "subcategory", 12) == 0)
				return this->_subCategory;

			else
				throw elementPtrEx;
		}

		bool ReferenceElementErrorInfo::hasElement(const char* name, bool excludeNullElements) const
		{
			return
				(strncmp(name, "category", 9) == 0) ||
				(strncmp(name, "code", 5) == 0) ||
				(strncmp(name, "message", 8) == 0) ||
				(strncmp(name, "source", 7) == 0) ||
				(strncmp(name, "subcategory", 12) == 0);
		}

		std::ostream& ReferenceElementErrorInfo::print(std::ostream& stream, int level, int spacesPerLevel) const
		{
			std::string tabs(IndentType::Indent(level, spacesPerLevel));

			stream << tabs << "errorInfo = {" << std::endl;

			this->_source->print(stream, level + 1, spacesPerLevel);
			this->_code->print(stream, level + 1, spacesPerLevel);
			this->_category->print(stream, level + 1, spacesPerLevel);
			this->_message->print(stream, level + 1, spacesPerLevel);
			this->_subCategory->print(stream, level + 1, spacesPerLevel);

			stream << tabs << '}' << std::endl;

			return stream;
		}

	}
}