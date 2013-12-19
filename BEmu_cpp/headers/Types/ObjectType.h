//------------------------------------------------------------------------------------------------
// <copyright project="BEmu_cpp" file="headers/Types/ObjectType.h" company="Jordan Robinson">
//     Copyright (c) 2013 Jordan Robinson. All rights reserved.
//
//     The use of this software is governed by the Microsoft Public License
//     which is included with this distribution.
// </copyright>
//------------------------------------------------------------------------------------------------

#pragma once

#include "BloombergTypes/Datetime.h"

namespace BEmu
{
	namespace ReferenceDataRequest
	{
		class ElementReferenceArrayChainTickers;
	}

	class ObjectType
	{
		public:
			enum ObjectTypeEnum { eDouble, eInt, eBool, eString, eDatetime, eChainTickers, eNothing };

			ObjectType(); //null
			ObjectType(double arg);
			ObjectType(int arg);
			ObjectType(bool arg);
			ObjectType(const std::string& arg);
			ObjectType(const char * arg);
			ObjectType(const Datetime& arg);
			ObjectType(ReferenceDataRequest::ElementReferenceArrayChainTickers * arg);

			~ObjectType();

			ObjectType& operator=(const ObjectType &rhs);
			ObjectType(const ObjectType& arg);

			ObjectTypeEnum GetType() const;
			bool TryGetDouble(double &arg) const;
			bool TryGetInt(int &arg) const;
			bool TryGetBool(bool &arg) const;
			bool TryGetString(std::string& arg) const;
			bool TryGetDatetime(Datetime& arg) const;
			bool TryGetChainTickers(ReferenceDataRequest::ElementReferenceArrayChainTickers * arg) const;

			bool IsNull() const;

			double ValueAsDouble() const;
			int ValueAsInt() const;
			bool ValueAsBool() const;
			std::string ValueAsString() const;
			Datetime ValueAsDatetime() const;
			ReferenceDataRequest::ElementReferenceArrayChainTickers * ValueAsChainTickers() const;

			std::string ToString() const;

			class ObjectTypeException: public std::exception
			{
				virtual const char* what() const throw()
				{
					return "My exception happened";
				}
			} objectTypeEx;

		private:
			ObjectTypeEnum _otype;

			double _dbl;
			int _int;
			bool _bool;
			std::string _str;
			Datetime _datetime;
			ReferenceDataRequest::ElementReferenceArrayChainTickers * _chainTickers;
	};
}