/*
 * BitMath.h
 *
 * Created: 1/5/2023 10:42:36 PM
 *  Author: Kareem
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_



#define SetBit(Reg,BitNo) (Reg |= (1<<BitNo))
#define ClearBit(Reg,BitNo) (Reg &=~ (1<<BitNo))
#define ToggleBit(Reg,BitNo) (Reg ^= (1<<BitNo))
#define GetBit(Reg,BitNo) ((Reg>>BitNo)&1)


#endif /* BITMATH_H_ */