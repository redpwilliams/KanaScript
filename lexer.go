package main

import (
	"fmt"
)

type Lexer struct {
	tokens []Token
}

func (l *Lexer) Tokenize(input string) {
	//Read and interpret each character
	for i := 0; i < len([]rune(input)); i++ {
		// Write
		if input[i:i+len("書く")] == "書く" {
			l.tokens = append(l.tokens, Token{"書く", Kaku})
			i += len([]rune("書く"))
		}

		fmt.Printf("%c\n", []rune(input)[i])
	}
	//for _, char := range []rune(input) {
	//	fmt.Printf("%c", char)
	//	fmt.Println(string(char) == "書")
	//}
	//strTokens := strings.Fields(input)
	//l.tokens = append(l.tokens, strTokens...)

}
