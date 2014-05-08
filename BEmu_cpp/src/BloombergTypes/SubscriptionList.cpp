//------------------------------------------------------------------------------------------------
// <copyright project="BEmu_cpp" file="src/BloombergTypes/SubscriptionList.cpp" company="Jordan Robinson">
//     Copyright (c) 2013 Jordan Robinson. All rights reserved.
//
//     The use of this software is governed by the Microsoft Public License
//     which is included with this distribution.
// </copyright>
//------------------------------------------------------------------------------------------------

#include "BloombergTypes/SubscriptionList.h"
#include "BloombergTypes/Subscription.h"

namespace BEmu
{
	SubscriptionList::SubscriptionList()
	{
		this->_subs = new std::vector<Subscription>();
	}
	
	SubscriptionList::~SubscriptionList()
	{
		delete this->_subs;
	}
	
	SubscriptionList::SubscriptionList(const SubscriptionList& original)
	{
		this->_subs = new std::vector<Subscription>(original._subs->begin(), original._subs->end());
	}

	int SubscriptionList::add(const char* topic, const char* fields, const char* options, const CorrelationId& correlationId)
	{
		Subscription sub(topic, fields, options, correlationId);
		this->_subs->push_back(sub);
		return 1; //I'm not sure what the add function returns
	}

	int SubscriptionList::add(const char* topic, const std::vector<std::string>& fields, const std::vector<std::string>& options, const CorrelationId& correlationId)
	{
		Subscription sub(topic, fields, options, correlationId);
		this->_subs->push_back(sub);
		return 1; //I'm not sure what the add function returns
	}

	int SubscriptionList::append(const SubscriptionList& other)
	{
		for(size_t i = 0; i < other._subs->size(); i++)
		{
			this->_subs->push_back(other._subs->operator[](i));
		}
		return 1; //I'm not sure what the append function returns
	}

	SubscriptionList& SubscriptionList::operator=(const SubscriptionList& rhs)
	{
		if (this != &rhs)
		{
			this->_subs->clear();
			this->append(rhs);
		}
		return *this;
	}

	size_t SubscriptionList::size() const
	{
		return this->_subs->size();
	}

	void SubscriptionList::clear()
	{
		this->_subs->clear();
	}

	void SubscriptionList::add(Subscription sub)
	{
		this->_subs->push_back(sub);
	}

	void SubscriptionList::remove(CorrelationId corr)
	{
		//Will replace the existing sub list with this new one
		//There's probably a better way to do this, but I don't know it
		std::vector<Subscription> * replacement = new std::vector<Subscription>();
		
		while(this->_subs->size() > 0)
		{
			Subscription sub = this->_subs->back();
			this->_subs->pop_back();

			if(sub.correlationId() != corr)
				replacement->push_back(sub);
		}

		delete this->_subs;
		this->_subs = replacement;
	}

	std::vector<Subscription> * SubscriptionList::list() const
	{
		return this->_subs;
	}
}