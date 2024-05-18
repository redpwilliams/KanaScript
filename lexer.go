package main

import (
	"fmt"
	"strings"
)

type Lexer struct {
	tokens []string
}

func (l *Lexer) Tokenize(input string) {
	fmt.Printf("ReadLine: %q\n", input)
	fmt.Println(len("書"))
	// Read and interpret each character
	//for i := 0; i < len([]rune(input)); i++ {
	//	if input[i:i+len("書")] == "書" {
	//		fmt.Println("Found")
	//	} else {
	//		fmt.Printf("%c\n", input[i])
	//	}
	//}
	for pos, char := range []rune(input) {
		if pos%2 == 1 {
			continue
		}
		fmt.Printf("%c", char)
		fmt.Println(string(char) == "書")
	}
	strTokens := strings.Fields(input)
	l.tokens = append(l.tokens, strTokens...)

}
