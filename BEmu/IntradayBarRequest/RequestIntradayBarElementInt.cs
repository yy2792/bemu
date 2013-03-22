﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BEmu.IntradayBarRequest
{
    internal class RequestIntradayBarElementInt : RequestIntradayBarElementString
    {
        private readonly int _value;

        internal RequestIntradayBarElementInt(string elementName, int value)
            : base(elementName, value.ToString())
        {
            this._value = value;
        }

        //I can't override GetElementAsInt32 here because the Bloomberg Request object stores ints as strings, not ints.  You can't convert the string to an int
        internal int GetInt { get { return this._value; } } 
    }
}