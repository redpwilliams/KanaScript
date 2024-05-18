package lexer

import (
	"fmt"
	"strings"
)

var tokens []string

func Tokenize(input string) {
	fmt.Printf("ReadLine: %q\n", input)
	newTokens := strings.Fields(input)
	tokens = append(tokens, newTokens...)
}

func GetTokens() []string {
	return tokens
}
