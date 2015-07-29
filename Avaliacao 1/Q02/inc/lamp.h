#ifndef lamp_h
#define lamp_h

typedef char byte;

#define TURN_ON(lamps, position)  lamps |= 1 << (position-1)
#define TURN_OFF(lamps, position) lamps &= 0xFF ^ (1 << (position-1))
#define IS_ON(lamps, position)    lamps & (1 << (position-1))

#endif