EXEC=snake
FUNC=snakefunc

${EXEC}.exe: main.o ${FUNC}.o
	gcc main.o ${FUNC}.o -lSDL3 -o ${EXEC}.exe

${FUNC}.o: ${FUNC}.h
	gcc ${FUNC}.c -c -o ${FUNC}.o

main.o: main.c
	gcc main.c -c -o main.o

clean:
	del main.o ${FUNC}.o ${EXEC}.exe