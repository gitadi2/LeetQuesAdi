func fun(matrix [][]int, n int, guess int) int {
    row:=n-1
    col:=0
    count:=0

    for row>=0 && col<n{
        if matrix[row][col]<=guess{
            count=count+row+1
            col++
        }else{
            row--
        }
    }
    return count
}

func kthSmallest(matrix [][]int, k int) int {
    n:=len(matrix)

    low:=matrix[0][0]
    high:=matrix[n-1][n-1]

    res:=-1

    for low<=high{
        guess:=low+(high-low)/2

        ans:=fun(matrix,n,guess)

        if ans<k{
            low=guess+1
        }else{
            res=guess
            high=guess-1
        }
    }
    return res
}