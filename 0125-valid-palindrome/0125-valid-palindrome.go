import "unicode"

func fun(s string,low int,high int)bool{

    // non-alphanumeric characters ko skip karo
    for low<high && !unicode.IsLetter(rune(s[low])) && !unicode.IsDigit(rune(s[low])){
        low++
    }

    for low<high && !unicode.IsLetter(rune(s[high])) && !unicode.IsDigit(rune(s[high])){
        high--
    }

    // Base Case
    if low>=high{
        return true
    }

    // agar first aur last character equal nahi hai
    if unicode.ToLower(rune(s[low]))!=unicode.ToLower(rune(s[high])){
        return false
    }

    // Recursive Call nxt walo k liye
    return fun(s,low+1,high-1)
}

func isPalindrome(s string)bool{

    // Size of the String
    n:=len(s)

    low:=0
    high:=n-1

    // Recursive Fn. call kardo
    return fun(s,low,high)
}