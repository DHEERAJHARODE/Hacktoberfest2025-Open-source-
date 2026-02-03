package main

import "fmt"

type int_array []int

func (arr int_array) bubble_sort() {
	size := len(arr)
	for i := 0; i < size-1; i++ {
		for j := 0; j < (size - i - 1); j++ {
			if arr[j] > arr[j+1] {
				arr[j], arr[j+1] = arr[j+1], arr[j]
			}
		}
	}

}

func main() {
	var size int
	fmt.Print("Enter the size of the array: ")
	fmt.Scanf("%d", &size)
	fmt.Printf("\n")

	arr := make(int_array, size)
	fmt.Println("Enter the elements of the array:")
	for i := 0; i < size; i++ {
		fmt.Scanf("%d", &arr[i])
	}
	fmt.Printf("\n")

	arr.bubble_sort()

	fmt.Println("Sorted array is:")
	for _, n := range arr {
		fmt.Print(n, " ")
	}
	fmt.Printf("\n")
}
