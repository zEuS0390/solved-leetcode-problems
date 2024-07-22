#include <iostream>
#include <vector>

// Function to calculate the sum of diagonals in a square matrix
int diagonalSum(std::vector<std::vector<int>>& mat) {
    int length = mat.size();  // Get the size of the matrix (number of rows or columns)
    int result = 0;           // Initialize variable to store the sum of diagonals

    // Loop through each row of the matrix
    for (int i = 0; i < length; ++i) {
        result += mat[i][i];                 // Add element from the primary diagonal (i, i)
        result += mat[i][length-1-i];        // Add element from the secondary diagonal (i, length-1-i)
    }

    // If the matrix size is odd, subtract the middle element which is counted twice
    if (mat.size() % 2 == 1)
        result -= mat[length/2][length/2];   // Subtract the middle element once from the total sum

    return result;  // Return the sum of both diagonals
}

int main(int argc, char* argv[]) {
    // Example matrix
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    // Calculate diagonal sum using the defined function
    int result = diagonalSum(matrix);

    // Output the result
    std::cout << result << std::endl;

    return 0;
}
