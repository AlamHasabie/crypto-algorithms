CC=g++

hellomake: display.cpp main.cpp playfair.cpp utils.cpp vigenere.cpp
	$(CC) display.cpp main.cpp playfair.cpp utils.cpp vigenere.cpp