CC=tigcc
CFLAGS=-Os -Wall -W -Wwrite-strings -ffunction-sections -fdata-sections
EXENAME=pong
HEADERS=game.h pong_cc.h
SRC=main.c game.c

pong.89z: $(HEADERS) $(SRC)
	$(CC) $(CFGLAGS) -o $(EXENAME) $(SRC)

clean:
	rm -rf *.89z
