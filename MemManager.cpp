
#include "MemManager.h"
#include <stdlib.h>

MemManager::MemManager(boost::uint32_t bytes)
{
    buffer_ = (boost::uint32_t*) malloc(bytes);
    startIndex_ = buffer_;
    currentIndex_ = buffer_;
    endIndex_ = buffer_ + bytes;
}
MemManager::~MemManager()
{
    free(buffer_);
}

void* MemManager::alloc(boost::uint32_t bytes)
{
    currentIndex_ += bytes;
    return currentIndex_ - bytes;
}
boost::uint32_t* MemManager::getMarker() const
{
    return currentIndex_;
}
void MemManager::freeToMarker(boost::uint32_t* marker)
{
    currentIndex_ = marker;
}

void MemManager::clear()
{
    currentIndex_ = startIndex_;
}
boost::uint32_t MemManager::bytesLeft() const
{
    return endIndex_ - currentIndex_;
}

boost::uint32_t MemManager::bufferSize() const
{
    return endIndex_ - startIndex_;
}
