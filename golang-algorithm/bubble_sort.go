// 冒泡排序
package main 

import (
	"fmt"
	"sort"
)

func bubbleSort(arr []int)([]int) {
    len := len(arr)
    var i, j int
    for i = 0; i < len - 1; i++ {
        for j = 0; j < len - 1 - i; j++ {
            if arr[j] > arr[j+1] {        
                var temp = arr[j+1]
                arr[j+1] = arr[j]
                arr[j] = temp
            }
        }
    }
    return arr
}

func main() {
	var nums []int = []int{1, 4, 3, 2} 
	fmt.Println(bubbleSort(nums))
}