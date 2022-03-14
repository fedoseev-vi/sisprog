FROM debian
RUN apt-get update && apt-get upgrade -y
RUN apt install gcc gdb gcc-multilib nano -y
COPY lab2.s .
COPY lab2.c .
RUN gcc -m32 -fno-pie -no-pie lab2.s -o lab2s
RUN gcc lab2.c -o lab2c
CMD ./lab2s && ./lab2c
