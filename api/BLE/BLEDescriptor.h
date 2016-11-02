/*
  BLE Descriptor API
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

#ifndef ARDUINO_BLE_DESCRIPTOR_H
#define ARDUINO_BLE_DESCRIPTOR_H

#include "BLEAttributeWithValue.h"

class BLEDescriptor : public BLEAttributeWithValue
{
  public:
    BLEDescriptor();
    BLEDescriptor(const char* uuid, const unsigned char value[], unsigned char valueLength); // create a descriptor the specified uuid and value
    BLEDescriptor(const char* uuid, const char* value); // create a descriptor the specified uuid and string value

    virtual ~BLEDescriptor();

    const char* uuid() const;

    virtual const byte* value() const; // returns the value buffer
    virtual int valueLength() const; // returns the current length of the value
    virtual byte operator[] (int offset) const; // returns a byte of the value at the specified offset

    virtual operator bool() const;  // is the descriptor valid (discovered from peripheral)

    // write the value of the characteristic
    virtual bool writeValue(const byte value[], int length);
    bool writeValue(const byte value[], int length, int offset);
    bool writeValue(const char* value);
};

#endif