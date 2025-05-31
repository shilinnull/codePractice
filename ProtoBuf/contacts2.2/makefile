all:write read
read:read.cc contacts.pb.cc
	g++ -o $@ $^ -std=c++11 -lprotobuf

write:write.cc contacts.pb.cc
	g++ -o $@ $^ -std=c++11 -lprotobuf
.PHONY:clean
clean:
	rm -rf write read

# 编译proto文件
# protoc --cpp_out=. contacts.proto

# 以文本格式查看
# protoc --decode=namespace_Contacts.Contacts contacts.proto < contacts.bin