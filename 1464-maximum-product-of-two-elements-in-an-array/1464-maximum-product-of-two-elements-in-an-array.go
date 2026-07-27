func maxProduct(nums []int) int {

    a:=0
    b:=0

    for i:=0;i<len(nums);i++{

        if nums[i]>a{
            b=a
            a=nums[i]

        }else if nums[i]>b{
            b=nums[i]
        }
    }
    return (a-1)*(b-1)
}