// 插入排序
package main

import (
    "fmt"
)

func insertSort(arr []int){
    var i,j,key int
    for i = 1; i != len(arr); i++ {
        key = arr[i]
        j = i - 1

        for ; (j >= 0) && (arr[j] > key) ; {
            arr[j + 1] = arr[j]
            j--
        }
        arr[j + 1] = key
    }
}


func main() {
    var nums []int = []int{1, 55, 4, 3, 2} 
    insertSort(nums)
    fmt.Println(nums)
}