// 二分查找算法
package main

import (
    "fmt"
)

func searchRe(array []int, target int, start int, end int)(int) {
    if (start > end) {
        return -1;
    }
    var mid int 
    mid = start + (end - start) / 2
    if array[mid] == target {
        return mid
    } 
    if target < array[mid] {
        return searchRe(array, target, start, mid - 1)
    } else {
        return searchRe(array, target, mid + 1, end)
    }
}

func search(target int,array []int) (int) {
    var start,end int
    start = 0
    end = len(array) - 1  
    for ; start <= end ;  {
        var mid = start + (end - start) / 2 
        if target == array[mid] { 
            return mid
        }
        if target < array[mid] {
            end = mid - 1
        } else {
            start = mid + 1
        } 
    }

    return -1;
}

func main() {
    var nums []int = []int{1, 2, 3, 4} 

    fmt.Println("res", search(2, nums))
    fmt.Println("res", searchRe(nums, 2, 0, len(nums)))
}