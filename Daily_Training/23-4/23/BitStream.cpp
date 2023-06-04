#include "BitStream.h"
BitStream::BitStream(std::istream &is) : is_(&is), os_(nullptr), buffer_(0), bitsInBuffer_(0) {}
BitStream::BitStream(std::ostream &os) : is_(nullptr), os_(&os), buffer_(0), bitsInBuffer_(0) {}
BitStream::~BitStream()
{
  flush();
}
uint8_t BitStream::readBit()
{
  if (bitsInBuffer_ == 0)
  {
    is_->read(reinterpret_cast<char *>(&buffer_), 1);
    bitsInBuffer_ = 8;
  }
  uint8_t bit = buffer_ & 0x80;
  buffer_ <<= 1;
  bitsInBuffer_--;
  return bit >> 7;
}
void BitStream::writeBit(uint8_t bit)
{
  buffer_ <<= 1;
  buffer_ |= bit;
  bitsInBuffer_++;
  if (bitsInBuffer_ == 8)
  {
    flush();
  }
}
void BitStream::writeByte(uint8_t byte)
{
  if (bitsInBuffer_ == 0)
  {
    os_->write(reinterpret_cast<char *>(&byte), 1);
  }
  else
  {
    buffer_ <<= (8 - bitsInBuffer_);
    buffer_ |= (byte >> bitsInBuffer_);
    os_->write(reinterpret_cast<char *>(&buffer_), 1);
    buffer_ = byte;
  }
}
void BitStream::flush()
{
  if (bitsInBuffer_ > 0)
  {
    buffer_ <<= (8 - bitsInBuffer_);
    os_->write(reinterpret_cast<char *>(&buffer_), 1);
    buffer_ = 0;
    bitsInBuffer_ = 0;
  }
}