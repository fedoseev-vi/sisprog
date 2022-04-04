FROM debian
RUN apt-get update && apt-get upgrade -y
RUN apt install -y gcc  
RUN apt install -y g++
COPY lab3.cpp .
RUN g++ lab3.cpp -static -o lab3 
CMD ./lab3
