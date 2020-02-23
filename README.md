# Mod Harbour Http API (mhha)

The purpose of **Mod Harbour Http Api (mhha)** project is to provide a host 
environment based on Windows HTTP Server API 2.0 where run mod-harbour.dll
applications.

Mhha is not using Microsoft Internet Information Server (IIS), but can 
share same IP and PORT with IIS,wthout cause any conflict, the fact IIS is 
using HTTP server API itself.


## mhha components

- **mhha library** : Can be provided as static or dynamic library  and will 
    hold all the required functions and classes to build the controler and 
    the worker executables.

- **mhha-ctrl.exe**: This executable is the responsible to register the url 
    groups and maintain the pool of worker processes. Will be executed 
    under an account with enought permissions to launch 1 or more group 
    of worker processes with different permissions, so applications can 
    have restricted access to the folders they need to access.

- **mhha-worker.exe**: This executable is the responsible to attend the 
    http requests that arriving to the aplication. Can be configured to 
    use multithread as mod-harbour.dll currently have a reliable 
    multithread support, but also is posible to restrict the number of 
    threads and the life cycle of the worker. 1 thread 1 request is the 
    most secure approach when executing scripts of diferent sources, but 
    also, using more CPU and memory, but it will not affect the 
    performance as will be a pool of worker processes ready to attend 
    the requests.

## Q&A


- **What is the development environment used?**  
    The 3 mhha components are totally written in C++, the mhha shared 
    library obviously because is more easy to use the API components
    as provided by the system. 

    But for the other 2 executables the only reason they are written in C++ 
    is to debug everything together with Visual Studio at least on the 
    early stage of the development, but there is no reason to not rewrite 
    later in harbour, so harbour programmers can manipulate more easy.