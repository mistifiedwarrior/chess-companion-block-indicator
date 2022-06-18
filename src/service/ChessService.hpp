#ifndef CHESS_SERVICE_HPP
#define CHESS_SERVICE_HPP

#include "service/Logger.hpp"
#include "service/CommunicationService.hpp"
#include "service/PinService.hpp"

class ChessService
{
private:
  PinService pinService;
  Log logger;

public:
  ChessService() {}

  ChessService(PinService pinService)
  {
    (*this).pinService = pinService;
  }

  String readMessage()
  {
    return logger.readMessage();
  }

  void turnOnLeds(String leds)
  {
    pinService.turnOnLeds(leds);
  }

  void turnOffLeds()
  {
    pinService.turnOfLeds();
  }

  void alert(String status)
  {
    pinService.alert(status);
  }
};

#endif