# 149 - Multidimensional Arrays: 3D and Beyond

## Overview
C supports arrays with any number of dimensions. 3D arrays are common in graphics, physics simulations, and volumetric data processing. Understanding the memory layout is key to efficient access.

## 3D Array Declaration

```c
int cube[DEPTH][ROWS][COLS];

// Example: 2 layers, 3 rows, 4 columns
int arr[2][3][4];
```

## Memory Layout

3D arrays are stored in **row-major order**, with the last index varying fastest:

```
arr[2][3][4] memory layout:
[0][0][0], [0][0][1], [0][0][2], [0][0][3],  // arr[0] row 0
[0][1][0], [0][1][1], [0][1][2], [0][1][3],  // arr[0] row 1
[0][2][0], [0][2][1], [0][2][2], [0][2][3],  // arr[0] row 2
[1][0][0], [1][0][1], [1][0][2], [1][0][3],  // arr[1] row 0
...
```

## Index Calculation

```c
// For arr[D][R][C]:
// arr[i][j][k] is at offset: i * R * C + j * C + k

int arr[2][3][4];
int *flat = &arr[0][0][0];

// arr[1][2][3] == flat[1*3*4 + 2*4 + 3] == flat[23]
```

## Initialization

```c
int cube[2][3][4] = {
    {   // First 2D slice (depth 0)
        {1, 2, 3, 4},     // row 0
        {5, 6, 7, 8},     // row 1
        {9, 10, 11, 12}   // row 2
    },
    {   // Second 2D slice (depth 1)
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24}
    }
};
```

## Higher Dimensions

```c
int hypercube[2][3][4][5];  // 4D array
// Total elements: 2 * 3 * 4 * 5 = 120

// Access formula for arr[A][B][C][D]:
// offset = i*B*C*D + j*C*D + k*D + l
```

## Practical Applications

- **3D Graphics**: Voxel grids `volume[x][y][z]`
- **Time Series**: Multiple channels over time `data[channel][sample][feature]`
- **Image Batches**: `images[batch][height][width]`
- **Tensors**: Neural network weights

---

# Kata Challenge

## Challenge: 3D Tic-Tac-Toe Board
Write a program that:
1. Creates a 4x4x4 game board (64 cells)
2. Allows placing 'X' or 'O' at coordinates
3. Displays each layer of the board
4. Detects wins in any direction (row, column, depth, diagonal)

## Requirements
- Use a 3D array `char board[4][4][4]`
- Initialize all cells to '.'
- Implement `place_mark(x, y, z, mark)`
- Implement `check_win()` for all 76 winning lines

## Expected Output
```
Layer 0:        Layer 1:        Layer 2:        Layer 3:
. . . .         . . . .         . . . .         . . . .
. . . .         . X . .         . . . .         . . . .
. . . .         . . . .         . . . .         . . . .
. . . .         . . . .         . . . .         . . . .

Place mark at (1,1,1): X placed
Place mark at (1,2,2): X placed
Place mark at (1,3,3): X placed
Place mark at (1,0,0): X placed

X wins with diagonal through layers!
```

## Winning Lines (76 total)
- 16 rows per layer × 4 layers = 16 × 4 = 64? No...
- 16 vertical columns, 16 horizontal rows, 16 depth lines
- 24 diagonal lines (6 per layer × 4, plus 4 space diagonals)

## Bonus
- Implement simple AI opponent
- Add undo functionality
