CC=gcc
CFLAGS=-Iinclude -Wall
SRC=src/main.c src/rpc.c lib/cJSON.c src/wallet.c
TARGET=btc-wallet

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) -lcurl

clean:
	rm -f $(TARGET)
