func mySqrt(x int) int {

    // agar x 0 ya 1 hai
    if x<=1{
        return x
    }

    l:=1
    h:=x
    ans:=0

    // binary search chalao
    for l<=h{

        m:=l+(h-l)/2

        // agar square root mil gaya
        if m==x/m{
            return m
        }

        // agar square chota hai
        if m<x/m{

            ans=m
            l=m+1

        }else{

            // warna left mei jao
            h=m-1
        }
    }

    // answer return kardo
    return ans
}