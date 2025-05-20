TestProtoBuf:main.cc contacts.pb.cc
	g++ -o $@ $^ -std=c++11 -lprotobuf
.PHONY:clean
clean:
	rm -rf TestProtoBuf

# protoc --cpp_out=. contacts.proto