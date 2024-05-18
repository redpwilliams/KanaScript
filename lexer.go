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
	strTokens := strings.Fields(input)
	l.tokens = append(l.tokens, strTokens...)
}
