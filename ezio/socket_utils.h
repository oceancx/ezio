/*
 @ 0xCCCCCCCC
*/

#ifndef EZIO_SOCKET_UTILS_H_
#define EZIO_SOCKET_UTILS_H_

#include "kbase/basic_macros.h"

#include "ezio/scoped_socket.h"
#include "ezio/socket_address.h"

#if defined(OS_POSIX)
#include <cerrno>
#include <sys/socket.h>
#elif defined(OS_WIN)
#include <Winsock2.h>
#endif

namespace ezio {
namespace socket {

inline int GetLastErrorCode() noexcept
{
#if defined(OS_POSIX)
    return errno;
#elif defined(OS_WIN)
    return WSAGetLastError();
#endif
}

// Create a non-blocking or an overlapped TCP socket.
ScopedSocket CreateNonBlockingSocket();

// Set SO_REUSEADDR option for a given sockt on Linux; while setting SO_EXCLUSIVEADDRUSE
// on Windows.
// Winsock has misinterpreted how SO_REUSEADDR should work, and enabling which will
// introduce security vulnerability, and that is why it then added SO_EXCLUSIVEADDRUSE
// for server applications to remedy the issue.
void SetReuseAddr(const ScopedSocket& sock, bool enable);

void BindOrThrow(const ScopedSocket& sock, const SocketAddress& listening_addr);

void ListenOrThrow(const ScopedSocket& sock);

}   // namespace socket
}   // namespace ezio

#endif  // EZIO_SOCKET_UTILS_H_
