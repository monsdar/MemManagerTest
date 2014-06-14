

#ifndef _MEM_MANAGER_H_
#define _MEM_MANAGER_H_

#include <boost/cstdint.hpp>

class MemManager
{
public:
    /**
     * Constructs a MemManager with the given size
     */
    explicit MemManager(boost::uint32_t bytes);
    virtual ~MemManager();

    /**
     * Allocates a block of memory with the given size
     * Returns 0 if it fails
     */
    void* alloc(boost::uint32_t bytes);
    /**
     * Returns the current position in memory
     */
    boost::uint32_t* getMarker() const;
    /**
     * Frees all memory up to the given marker
     */
    void freeToMarker(boost::uint32_t* marker);

    /**
     * Clears the whole Memory
     */
    void clear();
    
    /**
     * Returns the number of bytes left
     */
    boost::uint32_t bytesLeft() const;
    /**
     * Returns the size of the buffer
     */
    boost::uint32_t bufferSize() const;

private:
    boost::uint32_t* buffer_;
    boost::uint32_t* startIndex_;
    boost::uint32_t* currentIndex_;
    boost::uint32_t* endIndex_;
};

#endif //_MEM_MANAGER_H_
