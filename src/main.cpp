#include "controller/ChessController.hpp"
#include "service/PinService.hpp"
#include "service/ChessService.hpp"

const int rx = D9, tx = D10;
const int baudrate = 115200;

void setup()
{
  PinService pinService = PinService();

  ChessService chessService = ChessService(pinService);

  ChessController chessController = ChessController(chessService);

  while (true)
  {
    chessController.loop();
  }
}

void loop() {}