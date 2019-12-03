///-----------------------------------------------------------------------------
/// @file I_SudokuCell.h
///
/// Copyright (C) Circle Cardiovascular Imaging 2019
///
/// Author: Evan Loughlin
///-----------------------------------------------------------------------------


#ifndef ISUDOKUCELL_H
#define ISUDOKUCELL_H

class I_SudokuCell 
{
 public: 
    virtual ~I_SudokuCell(){}

 public:
    virtual int value() = 0;
    virtual int bitValue() = 0;
};

#endif //ISUDOKUCELL_H