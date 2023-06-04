#ifndef BIT_STREAM_H
#define BIT_STREAM_H
#include <iostream>
#include <fstream>
#include <stdint.h>
class BitStream
{
public:
  BitStream(std::istream &is);
  BitStream(std::ostream &os);
  ~BitStream();
  uint8_t readBit();
  void writeBit(uint8_t bit);
  void writeByte(uint8_t byte);
  void flush();

private:
  std::istream *is_;
  std::ostream *os_;
  uint8_t buffer_;
  uint8_t bitsInBuffer_;
};
#endif // BIT_STREAM_H