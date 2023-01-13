#pragma once

#if defined(FEPLIB_SHARED)
    #define FEPLIB_API __declspec(dllexport)
#else
    #define FEPLIB_API __declspec(dllimport)
#endif

#include <functional>
#include <string>
#include <memory>

#define FEPLIB_VERSION "1.0"

struct host
{
    std::string ip;
    uint16_t port{ 0 };

    operator bool() const
    {
        return !ip.empty() || port != 0;
    }
};

struct file_trans
{
    std::string filename;
    std::string from;
    std::string to;
    std::size_t filelen;
    double progress;

    bool ok{ true };
    std::string err;
};
using file_trans_progress = std::function<void(const file_trans &)>;

struct FEPLIB_API fep_server
{
    virtual ~fep_server(){};
    virtual fep_server &set_local_host(const host &) = 0;
    virtual void run(const file_trans_progress &) = 0;
};

struct FEPLIB_API fep_client
{
    virtual ~fep_client(){};
    virtual fep_client &set_local_host(const host &) = 0;
    virtual fep_client &set_remote_host(const host &) = 0;
    virtual void send(const std::string &filepath, const file_trans_progress &tracker) = 0;
};

enum class fep_protocol
{
    TCP,
    UDP,
};

FEPLIB_API std::unique_ptr<fep_server> make_fep_server(fep_protocol);
FEPLIB_API std::unique_ptr<fep_client> make_fep_client(fep_protocol);
