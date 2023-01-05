/*
 * STD_Types.h
 *
 * Created: 1/5/2023 10:43:13 PM
 *  Author: Kareem
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_



#define SetBit(Reg,BitNo) (Reg |= (1<<BitNo))
#define ClearBit(Reg,BitNo) (Reg &=~ (1<<BitNo))
#define ToggleBit(Reg,BitNo) (Reg ^= (1<<BitNo))
#define GetBit(Reg,BitNo) ((Reg>>BitNo)&1)


#endif /* STD_TYPES_H_ */