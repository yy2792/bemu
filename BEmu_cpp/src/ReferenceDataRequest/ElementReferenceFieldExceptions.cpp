﻿//------------------------------------------------------------------------------
// <copyright project="BEmu_cpp" file="src/ReferenceDataRequest/ElementReferenceFieldExceptions.cpp" company="Jordan Robinson">
//     Copyright (c) 2013 Jordan Robinson. All rights reserved.
//
//     The use of this software is governed by the Microsoft Public License
//     which is included with this distribution.
// </copyright>
//------------------------------------------------------------------------------

#include "ReferenceDataRequest/ElementReferenceFieldExceptions.h"
#include "ReferenceDataRequest/ElementReferenceString.h"
#include "ReferenceDataRequest/ElementReferenceErrorInfo.h"

#include "BloombergTypes/Name.h"
#include "Types/IndentType.h"

namespace BEmu
{
	namespace ReferenceDataRequest
	{
		ElementReferenceFieldExceptions::ElementReferenceFieldExceptions(const std::string& badField)
		{
            this->_fieldId = new ElementReferenceString("fieldId", badField);
            this->_errorInfo = new ElementReferenceErrorInfo();
		}

		ElementReferenceFieldExceptions::~ElementReferenceFieldExceptions()
		{
			delete this->_fieldId;
			this->_fieldId = 0;

			delete this->_errorInfo;
			this->_errorInfo = 0;
		}

		Name ElementReferenceFieldExceptions::name() const { return Name("fieldExceptions"); }
		size_t ElementReferenceFieldExceptions::numValues() const { return 1; }
		size_t ElementReferenceFieldExceptions::numElements() const { return 2; }

		bool ElementReferenceFieldExceptions::isNull() const { return false; }
		bool ElementReferenceFieldExceptions::isArray() const { return false; }
		bool ElementReferenceFieldExceptions::isComplexType() const { return true; }

		SchemaElementDefinition ElementReferenceFieldExceptions::elementDefinition() const
		{
			::blpapi_DataType_t dtype = (::blpapi_DataType_t)this->datatype();
			SchemaElementDefinition result(dtype, Name("FieldException"));
			return result;
		}

		const char* ElementReferenceFieldExceptions::getElementAsString(const char* name) const
		{
			return this->getElement(name)->getValueAsString(0);
		}

		int ElementReferenceFieldExceptions::getElementAsInt32(const char* name) const
		{
			return this->getElement(name)->getValueAsInt32(0);
		}

		ElementPtr * ElementReferenceFieldExceptions::getElement(const char* name) const
		{
			if(strncmp(name, "fieldId", 8) == 0)
				return this->_fieldId;

			else if(strncmp(name, "errorInfo", 0) == 0)
				return this->_errorInfo;

			else
				throw elementPtrEx;
		}

		bool ElementReferenceFieldExceptions::hasElement(const char* name, bool excludeNullElements) const
		{
			return
				strncmp(name, "fieldId", 8) == 0 ||
				strncmp(name, "errorInfo", 0) == 0;
		}

		std::ostream& ElementReferenceFieldExceptions::print(std::ostream& stream, int level, int spacesPerLevel) const
		{
			std::string tabs(IndentType::Indent(level, spacesPerLevel));

			stream << tabs << "fieldExceptions = {" << std::endl;
			
			this->_fieldId->print(stream, level + 1, spacesPerLevel);
			this->_errorInfo->print(stream, level + 1, spacesPerLevel);

			stream << tabs << '}' << std::endl;

			return stream;
		}

	}
}