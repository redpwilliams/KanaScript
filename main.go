package main

import (
	"fmt"
	"os"
)

func main() {

	// Check for correct number of arguments
	if len(os.Args) != 2 {
		err := fmt.Errorf("error: invalid number of arguments")
		fmt.Println(err.Error())
		os.Exit(1)
	}

	// Check that passed file is a .ks file
	if os.Args[1][len(os.Args[1])-3:] != ".ks" {
		err := fmt.Errorf("error: %s is not a KanaScript file - must end in .ks", os.Args[1])
		fmt.Println(err.Error())
		os.Exit(1)
	}

	//s := "成る [var] = value"

	//for i, r := range s {
	//	fmt.Printf("%d: %c\n", i, r)
	//}

	// File I/O (basic example)
	data, err := os.ReadFile(os.Args[1])
	if err != nil {
		fmt.Println((fmt.Errorf("error: cannot read %s", os.Args[1])).Error(), err)
		return
	}

	fmt.Println(string(data))
}
