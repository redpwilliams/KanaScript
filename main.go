package main

import (
	"bufio"
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

	// File I/O (basic example)
	file, _ := os.Open(os.Args[1])
	defer func(file *os.File) {
		err := file.Close()
		if err != nil {
			fmt.Println(err.Error())
		}
	}(file)

	r := bufio.NewReader(file)

	// Lexing
	var lex Lexer

	for {
		line, _, err := r.ReadLine()
		if len(line) > 0 {
			lex.Tokenize(string(line))
		}
		if err != nil {
			break
		}
	}

	tokens := lex.tokens
	fmt.Println(tokens)

}
