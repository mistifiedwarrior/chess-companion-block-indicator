#ifndef PIN_SERVICE_HPP
#define PIN_SERVICE_HPP

#include <Arduino.h>

class PinService
{
private:
  Log logger;
  int A = D2;
  int B = D3;
  int C = D4;
  int P = D6;
  int Q = D7;
  int R = D8;
  int positive = D5;
  int negative = D1;
  int buzzer = D0;

public:
  PinService()
  {
    setPinmode();
  }

  void turnOnLeds(String leds)
  {
    int count = 0;
    while (count < 10000)
    {
      count += leds.length();
      write(positive, HIGH);
      for (int i = 0; i < leds.length(); i += 2)
      {
        turnOnLed((char)leds[i], leds[i + 1] - 1);
        delayMicroseconds(100);
      }
    }
    write(positive, LOW);
  }

  void turnOfLeds()
  {
    write(positive, LOW);
  }

  void alert(String status)
  {
    if (status == "CHECK")
    {
      for (int i = 0; i < 3; i++)
      {
        write(buzzer, HIGH);
        delay(500);
        write(buzzer, LOW);
        delay(500);
      }
    }

    if (status == "END")
    {
      write(buzzer, HIGH);
      delay(3000);
      write(buzzer, LOW);
    }
  }

private:
  void write(int pinNo, int value)
  {
    return digitalWrite(pinNo, value);
  }

  void turnOnLed(char rowChar, int col)
  {
    int row = 'h' - rowChar;
    selectRow(row);
    selectCol(col);
  }

  void selectCol(int num)
  {
    write(A, num >> 0 & 1);
    write(B, num >> 1 & 1);
    write(C, num >> 2 & 1);
  }

  void selectRow(int num)
  {
    write(P, num >> 0 & 1);
    write(Q, num >> 1 & 1);
    write(R, num >> 2 & 1);
  }

  void setPinmode()
  {
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(P, OUTPUT);
    pinMode(Q, OUTPUT);
    pinMode(R, OUTPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(positive, OUTPUT);
    pinMode(negative, OUTPUT);
  }
};

#endif