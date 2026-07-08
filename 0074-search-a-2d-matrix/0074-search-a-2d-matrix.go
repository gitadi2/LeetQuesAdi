func searchMatrix(matrix [][]int, target int) bool {
    n:=len(matrix)
    m:=len(matrix[0])

    low:=0
    high:=n*m-1

    for low<=high{
        guess:=(low+high)/2

        row:=guess/m
        col:=guess%m

        if matrix[row][col]==target{
            return true
        }

        if matrix[row][col]<target{
            low=guess+1
        }else{
            high=guess-1
        }
    }
    return false
}