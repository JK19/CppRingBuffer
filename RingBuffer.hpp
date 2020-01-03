#if !defined(RING_BUFFER)
#define RING_BUFFER

#include <array>
#include <utility>

namespace ring
{

    enum RingOpStatus {
        NONE = 0,
        EMPTY,
        FULL
    };
    

    template <typename T, std::size_t TBufferSize>
    class RingBuffer
    {
    private:
        
        // T buffer[TBufferSize];
        std::array<T, TBufferSize> buffer;
        std::size_t buffer_size;
        std::size_t elements;
        unsigned long head;
        unsigned long tail;

    public:

        RingBuffer():
            buffer_size(TBufferSize),
            elements(0),
            head(0),
            tail(0)
        {};

        ~RingBuffer(){};

        ////////////////////////////////////////////////////////////////////
        // Disable copy
        RingBuffer(const RingBuffer& other) = delete;
        RingBuffer& operator=(const RingBuffer& other) = delete;       
        ////////////////////////////////////////////////////////////////////


        ////////////////////////////////////////////////////////////////////
        // Move support
        RingBuffer(RingBuffer&& other):
            buffer_size(other.buffer_size),
            elements(other.elements),
            head(other.head),
            tail(other.tail),
            buffer(other.buffer)
        {
            other.buffer_size = other.head = other.tail = other.elements = 0;
        };

        RingBuffer& operator=(RingBuffer&& other)
        {
            if(this != *other)
            {
                buffer = other.buffer;
                buffer_size = other.buffer_size;
                elements = other.elements;
                head = other.head;
                tail = other.tail;

                other.buffer_size = other.head = other.tail = other.elements = 0;
            }

            return *this;
        };
        ////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////
        // Get/Put methods
        RingOpStatus get(T& into)
        {
            if ( empty() ) return RingOpStatus::EMPTY;

            // if T is not moveable copy assingment is called
            into = std::move( buffer[tail] );
            
            advanceTail(); // decreases elements

            return RingOpStatus::NONE;
        };

        RingOpStatus put(const T& elem)
        {
            if ( full() ) return RingOpStatus::FULL;

            buffer[head] = elem;

            advanceHead(); // increases elements

            return RingOpStatus::NONE;
        };

        RingOpStatus put(T&& elem)
        {
            if ( full() ) return RingOpStatus::FULL;

            buffer[head] = std::forward<T>( elem );

            advanceHead(); // increases elements

            return RingOpStatus::NONE;
        };
        ////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////
        // Const help methods
        bool empty() const {
          return elements == 0;
        };

        bool full() const {
            return elements == buffer_size;
        };

        std::size_t elems() const {
            return elements;
        };
        
        std::size_t capacity() const {
          return buffer_size;
        };
        ////////////////////////////////////////////////////////////////////

    private:
        ////////////////////////////////////////////////////////////////////
        void advanceTail()  {
            elements--;
            tail = (tail + 1) % buffer_size;
        };

        void advanceHead() {
            elements++;
            head = (head + 1) % buffer_size;
        };
        ////////////////////////////////////////////////////////////////////

    };

};

#endif // RING_BUFFER
