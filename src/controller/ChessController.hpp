#ifndef DUSTBIN_MANAGER_HPP
#define DUSTBIN_MANAGER_HPP

#include <ArduinoJson.h>
#include "service/Logger.hpp"
#include "service/ChessService.hpp"

class ChessController
{
private:
  Log logger = Log();
  ChessService chessService;
  String ledsOn = "";
  String buzzerStatus = "";

public:
  ChessController(ChessService chessService)
  {
    (*this).chessService = chessService;
  }

  void loop()
  {
    String message = chessService.readMessage();
    logger.info("message recieved");
    logger.info(":" + message + ":");
    if (message.startsWith("blocks "))
    {
      int spaceIndex = message.indexOf(" ", 7);
      ledsOn = message.substring(7, spaceIndex);
      logger.info(ledsOn + String(spaceIndex));
      int lastIndex = message.lastIndexOf(" ");
      buzzerStatus = message.substring(lastIndex + 1);
      logger.info("buzzerStatus");
      logger.info(buzzerStatus);
    }

    if (ledsOn == "")
    {
      logger.info("leds off");
      chessService.turnOffLeds();
    }

    if (ledsOn != "")
    {
      logger.info("leds on");
      logger.info(ledsOn);
      chessService.turnOnLeds(ledsOn);
    }

    if (buzzerStatus != "")
    {
      chessService.alert(buzzerStatus);
      buzzerStatus = "";
    }
  }

private:
};

#endif