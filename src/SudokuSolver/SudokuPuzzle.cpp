///-----------------------------------------------------------------------------
/// @file SudokuPuzzle.cpp
///
/// Author: Evan Loughlin
///-----------------------------------------------------------------------------

#include "SudokuPuzzle.h"
#include "iostream"

SudokuPuzzle::SudokuPuzzle()
{
    initializeBlankPuzzle();
}

SudokuPuzzle::SudokuPuzzle(QVector<SudokuCell> listOfCells)
{
    initializeBlankPuzzle();
    for(int i = 0; i < listOfCells.size(); i++)
    {
        int rowIndex = i/9;
        int columnIndex = i%9;
        this->setCell(rowIndex, columnIndex, listOfCells.at(i));
    }
}

SudokuPuzzle::SudokuPuzzle(QVector<QVector<SudokuCell>> cellMatrix)
{
    mCellMatrix = QVector<QVector<SudokuCell>>(cellMatrix);
}

SudokuPuzzle::~SudokuPuzzle()
{
}

QVector<QVector<SudokuCell>> SudokuPuzzle::cellMatrix()
{
    return mCellMatrix;
}

const SudokuCell& SudokuPuzzle::valueAt(int row, int column) const
{
    return mCellMatrix.at(row).at(column);
}

void SudokuPuzzle::setCell(int row, int column, SudokuCell value)
{
    mCellMatrix[row][column] = value;
}

void SudokuPuzzle::initializeBlankPuzzle()
{
    for(int row = 0; row < mNumRows; row++)
    {
        QVector<SudokuCell> entireRow;
        for(int column = 0; column < mNumColumns; column++)
        {
            entireRow.append(SudokuCell::BLANK);
        }

        mCellMatrix.append(entireRow);
    }
}

const QVector<SudokuCell>& SudokuPuzzle::rowAt(int rowIndex) const
{
    return mCellMatrix.at(rowIndex);
}

QVector<SudokuCell> SudokuPuzzle::columnAt(int columnIndex) const
{
    QVector<SudokuCell> column;
    for (int row = 0; row < mNumRows; row++)
    {
        column.append(mCellMatrix.at(row).at(columnIndex));
    }
    return column;      
}

// // Quadrants within SudokuPuzzle are the 9-cell regions distributed as follows:
// // -------------
// // | 1 | 2 | 3 |  
// // -------------
// // | 4 | 5 | 6 |  
// // -------------
// // | 7 | 8 | 9 |
// // -------------
// // This function returns a QVector containing the 9 SudokuCells 
// QVector<SudokuCell>& quadrantAt(int quadrantIndex) const
// {

// }
