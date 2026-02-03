package main

import "fmt"

type int_array []int

func (arr int_array) selection_sort() {
	size := len(arr)
	for i := 0; i < size-1; i++ {
		for j := i + 1; j < size; j++ {
			if arr[j] < arr[i] {
				arr[i], arr[j] = arr[j], arr[i]
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

	arr.selection_sort()

	fmt.Println("Sorted array is:")
	for _, n := range arr {
		fmt.Print(n, " ")
	}
	fmt.Printf("\n")
}
