#include <iostream>
#include <vector>
using namespace std;

//Binary Search concept
//Time:O(M + N)
//Space:O(1)
class Solution1
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int row = 0;
        int col = matrix[0].size() - 1;

        while(row < matrix.size() && col > -1)
        {
            if(target == matrix[row][col])
                return true;
            else if(target > matrix[row][col])
                row ++;
            else
                col --;
        }
        return false;
    }
};

//binary search in both row and col
//Time:O(logM + logN)
//Space:O(1)
class Solution2
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int rowLen = matrix.size();
        int colLen = matrix[0].size();
        int topRow = 0;
        int bottomRow = rowLen - 1;        

        while(topRow <= bottomRow)
        {
            int rowPivot = topRow + (bottomRow - topRow) / 2;

            if(target > matrix[rowPivot][colLen - 1])
                topRow = rowPivot + 1;
            else if(target < matrix[rowPivot][0])
                bottomRow = rowPivot - 1;
            else
                break;
        }

        if(topRow > bottomRow)
            return false;
       
        int rowPivot = topRow + (bottomRow - topRow) / 2;
        int leftCol = 0;
        int rightCol = colLen - 1;
        while(leftCol <= rightCol)
        {
            int colPivot = leftCol + (rightCol - leftCol) / 2;
            if(target == matrix[rowPivot][colPivot])
                return true;
            else if(target > matrix[rowPivot][colPivot])
                leftCol = colPivot + 1;
            else
                rightCol = colPivot - 1;
        }

        return false;
    }
};


int main()
{
    vector<vector<int>> testMatrix = {{1, 2, 3, 4}, {10, 11, 12, 13}, {20, 21, 22, 23}}; //target = 1, 13, 23, 0, 30

    Solution1 solution1;
    Solution2 solution2;

    cout << "Sol 1, test 1, true: " << solution1.searchMatrix(testMatrix, 1) << endl;
    cout << "Sol 1, test 2, true: " << solution1.searchMatrix(testMatrix, 13) << endl;
    cout << "Sol 1, test 3, true: " << solution1.searchMatrix(testMatrix, 23) << endl;
    cout << "Sol 1, test 4, false: " << solution1.searchMatrix(testMatrix, 0) << endl;
    cout << "Sol 1, test 5, false: " << solution1.searchMatrix(testMatrix, 30) << endl;

    cout << "Sol 2, test 1, true: " << solution2.searchMatrix(testMatrix, 1) << endl;
    cout << "Sol 2, test 2, true: " << solution2.searchMatrix(testMatrix, 13) << endl;
    cout << "Sol 2, test 3, true: " << solution2.searchMatrix(testMatrix, 23) << endl;
    cout << "Sol 2, test 4, false: " << solution2.searchMatrix(testMatrix, 0) << endl;
    cout << "Sol 2, test 5, false: " << solution2.searchMatrix(testMatrix, 30) << endl;
    
    return 0;
}