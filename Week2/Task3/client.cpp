#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include "helloworld.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using helloworld::Greeter;
using helloworld::CustomMessage;
using helloworld::HelloReply;

class GreeterClient {
public:
    GreeterClient(std::shared_ptr<Channel> channel) : stub_(Greeter::NewStub(channel)) {}

    std::string SendMessage(int user_id, const std::string& content) {
        CustomMessage request;
        request.set_user_id(user_id);
        request.set_content(content);
        HelloReply reply;
        ClientContext context;

        Status status = stub_->SendMessage(&context, request, &reply);
        if (status.ok()) {
            return reply.message();
        } else {
            std::cout << "RPC failed" << std::endl;
            return "RPC failed";
        }
    }

private:
    std::unique_ptr<Greeter::Stub> stub_;
};

int main(int argc, char** argv) {
    GreeterClient greeter(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
    
    int user_id = 1; // Example user ID
    std::string content = "Hello, this is a custom message!";
    
    std::string reply = greeter.SendMessage(user_id, content);
    std::cout << "Greeter received: " << reply << std::endl;
    
    return 0;
}
