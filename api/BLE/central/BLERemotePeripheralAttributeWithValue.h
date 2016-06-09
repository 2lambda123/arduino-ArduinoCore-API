/*
  BLE Remote Peripheral Attribute with value API
  Copyright (c) 2016 Arduino LLC. All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/

#ifndef ARDUINO_BLE_REMOTE_PERIPHERAL_ATTRIBUTE_H
#define ARDUINO_BLE_REMOTE_PERIPHERAL_ATTRIBUTE_H

#include "BLERemotePeripheralAttribute.h"


class BLERemotePeripheralAttributeWithValue : public BLERemotePeripheralAttribute
{
  public:
    BLERemotePeripheralAttributeWithValue();

    virtual bool read(); // read the attribute value from the peripheral
    virtual bool write(const unsigned char* value, int length); // write the specific value to the attribute of the peripheral

    int valueLength() const; // returns the length of the attribute value
    const unsigned char* value() const; // returns the value of the attribute array
    unsigned char operator[] (int offset) const; // access an attribute value at the specified offset

    // intepret the value of the attribute with the specified type
    String stringValue() const;
    char charValue() const;
    unsigned char unsignedCharValue() const;
    short shortValue() const;
    unsigned short unsignedShortValue() const;
    int intValue() const;
    unsigned int unsignedIntValue() const;
    long longValue() const;
    unsigned long unsignedLongValue() const;
    float floatValue() const;
    double doubleValue() const;

    // write the value of the attribute with the specified type
    bool writeString(const String& s);
    bool writeString(const char* s);
    bool writeChar(char c);
    bool writeUnsignedChar(unsigned char c);
    bool writeShort(short s);
    bool writeUnsignedShort(unsigned short s);
    bool writeInt(int i);
    bool writeUnsignedInt(unsigned int i);
    bool writeLong(long l);
    bool writeUnsignedLong(unsigned int l);
    bool writeFloat(float f);
    bool writeDouble(double d);
};

#endif