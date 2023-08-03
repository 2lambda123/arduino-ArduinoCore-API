/*
 * Copyright (c) 2020 Arduino.  All rights reserved.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <CanMsg.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

using namespace arduino;

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE ("Test constructor with no data (data length = 0)", "[CanMsg-CanMsg-01]")
{
  CanMsg const msg(CanStandardId(0x20), 0, nullptr);

  REQUIRE(msg.data_length == 0);
  for (size_t i = 0; i < CanMsg::MAX_DATA_LENGTH; i++)
    REQUIRE(msg.data[i] == 0);
}

TEST_CASE ("Test constructor with data (data length < CanMsg::MAX_DATA_LENGTH)", "[CanMsg-CanMsg-02]")
{
  uint8_t const msg_data[4] = {0xDE, 0xAD, 0xC0, 0xDE};

  CanMsg const msg(CanStandardId(0x20), sizeof(msg_data), msg_data);

  REQUIRE(msg.data_length == 4);
  for (size_t i = 0; i < msg.data_length; i++)
    REQUIRE(msg.data[i] == msg_data[i]);
}

TEST_CASE ("Test constructor with data (data length > CanMsg::MAX_DATA_LENGTH)", "[CanMsg-CanMsg-03]")
{
  uint8_t const msg_data[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

  CanMsg const msg(CanStandardId(0x20), sizeof(msg_data), msg_data);

  REQUIRE(msg.data_length == 8);
  for (size_t i = 0; i < msg.data_length; i++)
    REQUIRE(msg.data[i] == msg_data[i]);
}
