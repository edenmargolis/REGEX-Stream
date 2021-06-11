# C++ based REGEX-Stream
Including a parser, a scanner, and a word generator that knows how to handle the ) , ( , | , * , + , - operators.
Also includes 2 methods:
nth- given a regex and a number, it will return the nth word that the generator generates that applies to the regex.
find- given a regex and a word, it will return the position of the word in my implementation of the generator if the word is applied to the regular expression, or get into an infinite loop other-wise.
