cmake_minimum_required(VERSION 3.5)

project(ezio CXX)
include(cotire.cmake)

set(CXX_FLAGS
#  -g
#  -Wall
#-Wextra
#-Werror
#-Wno-unused-parameter
#-Wold-style-cast
#-Woverloaded-virtual
#-Wpointer-arith
#-Wshadow
    -EHsc
)
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

add_definitions ( -DNOMINMAX )
add_definitions ( -DUNICODE )
add_definitions ( -DWIN32_LEAN_AND_MEAN )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

set(KBaseDir KBase/src)

include_directories(
    ${KBaseDir}
)

set(kbase_Header
    ${KBaseDir}/kbase/at_exit_manager.h
    ${KBaseDir}/kbase/auto_reset.h
    ${KBaseDir}/kbase/base_path_provider.h
    ${KBaseDir}/kbase/base64.h
    ${KBaseDir}/kbase/basic_macros.h
    ${KBaseDir}/kbase/basic_types.h
    ${KBaseDir}/kbase/chrono_util.h
    ${KBaseDir}/kbase/command_line.h
    ${KBaseDir}/kbase/debugger.h
    ${KBaseDir}/kbase/environment.h
    ${KBaseDir}/kbase/error_exception_util.h
    ${KBaseDir}/kbase/file_info.h
    ${KBaseDir}/kbase/file_iterator.h
    ${KBaseDir}/kbase/file_util.h
    ${KBaseDir}/kbase/file_version_info.h
    ${KBaseDir}/kbase/guid.h
    ${KBaseDir}/kbase/lazy.h
    ${KBaseDir}/kbase/logging.h
    ${KBaseDir}/kbase/lru_cache.h
    ${KBaseDir}/kbase/md5.h
    ${KBaseDir}/kbase/minidump.h
    ${KBaseDir}/kbase/os_info.h
    ${KBaseDir}/kbase/path.h
    ${KBaseDir}/kbase/path_service.h
    ${KBaseDir}/kbase/pickle.h
    ${KBaseDir}/kbase/registry.h
    ${KBaseDir}/kbase/scope_guard.h
    ${KBaseDir}/kbase/scoped_handle.h
    ${KBaseDir}/kbase/secure_c_runtime.h
    ${KBaseDir}/kbase/signals.h
    ${KBaseDir}/kbase/singleton.h
    ${KBaseDir}/kbase/stack_walker.h
    ${KBaseDir}/kbase/string_encoding_conversions.h
    ${KBaseDir}/kbase/string_format.h
    ${KBaseDir}/kbase/string_util.h
    ${KBaseDir}/kbase/string_view.h
    ${KBaseDir}/kbase/tokenizer.h
)
if(WIN32)
set(kbase_SRCS
    ${kbase_Header}
    ${KBaseDir}/kbase/at_exit_manager.cpp
    ${KBaseDir}/kbase/base_path_provider_win.cpp
    ${KBaseDir}/kbase/base64.cpp
    ${KBaseDir}/kbase/command_line.cpp
    ${KBaseDir}/kbase/chrono_util.cpp
    ${KBaseDir}/kbase/debugger_win.cpp
    ${KBaseDir}/kbase/environment_win.cpp
    ${KBaseDir}/kbase/error_exception_util.cpp
    ${KBaseDir}/kbase/file_iterator.cpp
    ${KBaseDir}/kbase/file_iterator_win.cpp
    ${KBaseDir}/kbase/file_util.cpp
    ${KBaseDir}/kbase/file_util_win.cpp
    ${KBaseDir}/kbase/guid.cpp
    ${KBaseDir}/kbase/logging.cpp
    ${KBaseDir}/kbase/md5.cpp
    ${KBaseDir}/kbase/os_info.cpp
    ${KBaseDir}/kbase/os_info_win.cpp
    ${KBaseDir}/kbase/path.cpp
    ${KBaseDir}/kbase/path_service.cpp
    ${KBaseDir}/kbase/pickle.cpp
    ${KBaseDir}/kbase/stack_walker_win.cpp
    ${KBaseDir}/kbase/string_encoding_conversions.cpp
    ${KBaseDir}/kbase/string_format.cpp
    ${KBaseDir}/kbase/string_util.cpp
)
elseif(UNIX)
set(kbase_SRCS
    ${kbase_Header}
    ${KBaseDir}/kbase/at_exit_manager.cpp
    ${KBaseDir}/kbase/base_path_provider_posix.cpp
    ${KBaseDir}/kbase/base64.cpp
    ${KBaseDir}/kbase/command_line.cpp
    ${KBaseDir}/kbase/chrono_util.cpp
    ${KBaseDir}/kbase/debugger_posix.cpp
    ${KBaseDir}/kbase/environment_posix.cpp
    ${KBaseDir}/kbase/error_exception_util.cpp
    ${KBaseDir}/kbase/file_iterator.cpp
    ${KBaseDir}/kbase/file_iterator_posix.cpp
    ${KBaseDir}/kbase/file_util.cpp
    ${KBaseDir}/kbase/file_util_posix.cpp
    ${KBaseDir}/kbase/guid.cpp
    ${KBaseDir}/kbase/logging.cpp
    ${KBaseDir}/kbase/md5.cpp
    ${KBaseDir}/kbase/os_info.cpp
    ${KBaseDir}/kbase/os_info_posix.cpp
    ${KBaseDir}/kbase/path.cpp
    ${KBaseDir}/kbase/path_service.cpp
    ${KBaseDir}/kbase/pickle.cpp
    ${KBaseDir}/kbase/stack_walker_posix.cpp
    ${KBaseDir}/kbase/string_encoding_conversions.cpp
    ${KBaseDir}/kbase/string_format.cpp
    ${KBaseDir}/kbase/string_util.cpp
)
endif(WIN32)

add_library(kbase ${kbase_SRCS}  )
set_target_properties(kbase PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "KBase/build/pch/precompile.h")
cotire(kbase)

set(EzioDir ezio)
include_directories(
    .
)
set(ezio_Header
    ${EzioDir}/acceptor.h 
    ${EzioDir}/buffer.h 
    ${EzioDir}/chrono_utils.h 
    ${EzioDir}/common_event_handlers.h 
    ${EzioDir}/connector_base.h
    ${EzioDir}/connector.h
    ${EzioDir}/endian_utils.h 
    ${EzioDir}/event_loop.h 
    ${EzioDir}/event_pump.h 
    ${EzioDir}/io_context.h 
    ${EzioDir}/io_service_context.h 
    ${EzioDir}/notifier.h
    ${EzioDir}/scoped_socket.h
    ${EzioDir}/socket_address.h
    ${EzioDir}/tcp_server.h
    ${EzioDir}/tcp_client.h
    ${EzioDir}/tcp_connection.h
    ${EzioDir}/timer.h
    ${EzioDir}/timer_id.h
    ${EzioDir}/timer_queue.h
    ${EzioDir}/this_thread.h
    ${EzioDir}/thread.h
    ${EzioDir}/worker_pool.h
)

if(WIN32)

list(APPEND ezio_Header ${EzioDir}/winsock_context.h)
list(APPEND ezio_Header ${EzioDir}/connector_win.h)
set(ezio_SRCS
    ${EzioDir}/acceptor.cpp
    ${EzioDir}/acceptor_win.cpp
    ${EzioDir}/buffer.cpp
    ${EzioDir}/connector_base.cpp
    ${EzioDir}/connector_win.cpp
    ${EzioDir}/event_loop.cpp
    ${EzioDir}/event_pump.cpp
    ${EzioDir}/event_pump_impl_win.cpp
    ${EzioDir}/event_pump_impl_win.h
    ${EzioDir}/io_service_context.cpp
    ${EzioDir}/notifier.cpp
    ${EzioDir}/notifier_win.cpp
    ${EzioDir}/socket_address.cpp
    ${EzioDir}/socket_utils.cpp
    ${EzioDir}/socket_utils_win.cpp
    ${EzioDir}/tcp_server.cpp
    ${EzioDir}/tcp_client.cpp
    ${EzioDir}/tcp_connection.cpp
    ${EzioDir}/tcp_connection_win.cpp
    ${EzioDir}/timer.cpp
    ${EzioDir}/timer_queue.cpp
    ${EzioDir}/this_thread.cpp
    ${EzioDir}/thread.cpp
    ${EzioDir}/winsock_context.h
    ${EzioDir}/winsock_context.cpp
    ${EzioDir}/worker_pool.cpp
)
elseif(UNIX)
list(APPEND ezio_Header ${EzioDir}/connector_posix.h)
set(ezio_SRCS
    ${EzioDir}/acceptor.cpp
    ${EzioDir}/acceptor_posix.cpp
    ${EzioDir}/buffer.cpp
    ${EzioDir}/buffer_posix.cpp
    ${EzioDir}/connector_base.cpp
    ${EzioDir}/connector_posix.cpp
    ${EzioDir}/event_loop.cpp
    ${EzioDir}/event_pump.cpp
    ${EzioDir}/event_pump_impl_posix.cpp
    ${EzioDir}/ignore_sigpipe.cpp
    ${EzioDir}/io_service_context.cpp
    ${EzioDir}/notifier.cpp
    ${EzioDir}/notifier_posix.cpp
    ${EzioDir}/socket_address.cpp
    ${EzioDir}/socket_utils.cpp
    ${EzioDir}/socket_utils_posix.cpp
    ${EzioDir}/tcp_server.cpp
    ${EzioDir}/tcp_client.cpp
    ${EzioDir}/tcp_connection.cpp
    ${EzioDir}/tcp_connection_posix.cpp
    ${EzioDir}/timer.cpp
    ${EzioDir}/timer_queue.cpp
    ${EzioDir}/this_thread.cpp
    ${EzioDir}/thread.cpp
    ${EzioDir}/worker_pool.cpp
)
endif(WIN32)

add_library(ezio ${ezio_Header} ${ezio_SRCS})
target_link_libraries(ezio PRIVATE kbase)
# target_include_directories(ezio
#     PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/
# )

install (FILES ${ezio_Header} DESTINATION include/${PROJECT_NAME}/ezio)
install (FILES ${kbase_Header} DESTINATION include/${PROJECT_NAME}/kbase)
install (TARGETS ezio DESTINATION lib/${PROJECT_NAME})
install (TARGETS kbase DESTINATION lib/${PROJECT_NAME})
