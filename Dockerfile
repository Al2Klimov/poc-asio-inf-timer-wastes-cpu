FROM centos:7

RUN ["yum", "install", "-y", "epel-release"]
RUN ["yum", "install", "-y", "boost169-devel", "gcc-c++"]

COPY waste.cpp runfor.sh compare.sh /

RUN ["g++", "-std=c++11", "-O0", "-I/usr/include/boost169", "-L/usr/lib64/boost169", "-lboost_coroutine", "-lboost_context", "-lboost_thread", "-lpthread", "-o", "waste", "waste.cpp"]

CMD ["/compare.sh"]
