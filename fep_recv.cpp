#include <feplib.h>
#include <iostream>

int main(int argc, char **argv)
{
    auto recv = make_fep_server(fep_protocol::UDP);
    recv->set_local_host({ "127.0.0.1", 28001 });
    recv->run([](auto &&progress) {
        std::cout << "received file: " << progress.filename << " progress: " << progress.progress << std::endl;
    });
    return 0;
}
