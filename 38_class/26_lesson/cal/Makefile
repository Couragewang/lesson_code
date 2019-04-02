.PHONY:all
all:Client Server

Client:Client.cc
	g++ -o $@ $^
Server:Server.cc
	g++ -o $@ $^ -lpthread
.PHONY:clean
clean:
	rm -f Client Server
