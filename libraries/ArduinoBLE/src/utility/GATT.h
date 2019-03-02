/*
  This file is part of the ArduinoBLE library.
  Copyright (c) 2018 Arduino SA. All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _GATT_H_
#define _GATT_H_

#include "utility/BLELinkedList.h"

#include "local/BLELocalService.h"
#include "local/BLELocalCharacteristic.h"

#include "BLEAttribute.h"
#include "BLEService.h"

class GATTClass {
public:
  GATTClass();
  virtual ~GATTClass();

  void begin();
  void end();

  void setDeviceName(const char* deviceName);
  void setAppearance(uint16_t appearance);

  void addService(BLEService& service);

protected:
  friend class ATTClass;

  unsigned int attributeCount() const;
  BLEAttribute* attribute(unsigned int index) const;

protected:
  friend class BLELocalCharacteristic;

  uint16_t serviceUuidForCharacteristic(BLELocalCharacteristic* characteristic) const;

private:
  void addService(BLELocalService* service);

  void clearAttributes();

private:
  BLELinkedList<BLEAttribute*> _attributes;

  BLELocalService              _genericAccessService;
  BLELocalCharacteristic       _deviceNameCharacteristic;
  BLELocalCharacteristic       _appearanceCharacteristic;
  BLELocalService              _genericAttributeService;
  BLELocalCharacteristic       _servicesChangedCharacteristic;
};

extern GATTClass GATT;

#endif
