#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <Arduino.h>
#include "domain/Error.hpp"

class Log
{
private:
  int baudrate = 115200;

public:
  Log()
  {
    Serial.begin(baudrate);
  }

  void info(String message)
  {
    Serial.println("Info: " + message);
  }

  void error(String errorCode, String errorMessage)
  {
    Serial.println("Error: " + errorCode + " " + errorMessage);
  }

  void error(Error error)
  {
    Serial.println("Error: " + error.code + " " + error.message);
  }

  void warn(String message)
  {
    Serial.println("Warn: " + message);
  }

  String readMessage()
  {
    return Serial.readString();
  }
};

#endif