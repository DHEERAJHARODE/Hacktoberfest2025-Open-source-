package main

import (
	"bufio"
	"fmt"
	"log"
	"math/rand"
	"os"
	"strings"
)

func main() {
	log.Println("dice simulator stared.")

	reader := bufio.NewReader(os.Stdin)

	run := true

	for {
		random := rand.Intn(6-1) + 1

		switch random {
		case 1:
			fmt.Println("-------------\n|           |\n|     O     |\n|           |\n-------------")
		case 2:
			fmt.Println("-------------\n| O         |\n|           |\n|         O |\n-------------")
		case 3:
			fmt.Println("-------------\n| O         |\n|     O     |\n|         O |\n-------------")
		case 4:
			fmt.Println("-------------\n| O       O |\n|           |\n| O       O |\n-------------")
		case 5:
			fmt.Println("-------------\n| O       O |\n|     O     |\n| O       O |\n-------------")
		case 6:
			fmt.Println("-------------\n| O       O |\n| O       O |\n| O       O |\n-------------")
		}

		log.Println("type 'r' and press ENTER to roll again")
		input, _ := reader.ReadString('\n')
		input = strings.Replace(input, "\n", "", 1)

		if input != "r" {
			run = false
		}

		if !run {
			return
		}
	}
}
