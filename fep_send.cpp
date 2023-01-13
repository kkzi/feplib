#include <feplib.h>
#include <iostream>

int main(int argc, char **argv)
{
    std::string filepath;
    if (argc == 1)
    {
        std::cout << "Usage: fep_send filepath" << std::endl;
        return EXIT_SUCCESS;
    }
    filepath = argv[1];
    std::cout << "send file: " << filepath << std::endl;

    auto sender = make_fep_client(fep_protocol::UDP);
    sender->set_local_host({ "127.0.0.1", 29001 });
    sender->set_remote_host({ "127.0.0.1", 28001 });
    sender->send(filepath, [](auto &&progress) {
        std::cout << "send " << progress.filename << " progress: " << progress.progress << std::endl;
    });
    return 0;
}
