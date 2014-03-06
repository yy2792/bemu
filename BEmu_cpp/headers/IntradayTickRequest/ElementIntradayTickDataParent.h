//------------------------------------------------------------------------------------------------
// <copyright project="BEmu_cpp" file="headers/IntradayTickRequest/ElementIntradayTickDataParent.h" company="Jordan Robinson">
//     Copyright (c) 2013 Jordan Robinson. All rights reserved.
//
//     The use of this software is governed by the Microsoft Public License
//     which is included with this distribution.
// </copyright>
//------------------------------------------------------------------------------------------------

#pragma once

#include <map>
#include "BloombergTypes/ElementPtr.h"

namespace BEmu
{
	class Name;
	class Datetime;
	class ElementPtr;

	namespace IntradayTickRequest
	{
		class ElementIntradayTickDataArray;
		class ElementIntradayTickDataTuple3;

		class ElementIntradayTickDataParent : public ElementPtr
		{
			private:
				ElementIntradayTickDataArray *_array;

			public:
				ElementIntradayTickDataParent(std::map<Datetime, ElementIntradayTickDataTuple3*>* ticks, bool includeConditionCodes);
				~ElementIntradayTickDataParent();

				virtual Name name() const;
				virtual size_t numValues() const { return 1; }
				virtual size_t numElements() const { return 1; }		
				virtual bool isArray() const { return false; }
				virtual bool isComplexType() const { return true; }
				virtual SchemaElementDefinition elementDefinition() const;

				virtual ElementPtr * getElement(const char* name) const;

				virtual std::ostream& print(std::ostream& stream, int level, int spacesPerLevel) const;
		};
	}
}