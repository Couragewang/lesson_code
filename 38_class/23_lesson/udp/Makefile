.PHONY:all
all:client server

client:client.cc
	g++ -o $@ $^ -static
server:server.cc
	g++ -o $@ $^

.PHONY:clean
clean:
	rm -f client server
