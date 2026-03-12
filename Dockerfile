#Inital setup
FROM ubuntu:latest
WORKDIR /dev/cardsim/

# Install dependances
RUN apt update
RUN apt upgrade -y
#RUN apt install gcc -y
RUN apt install g++ -y
RUN apt install make
RUN apt install git -y

# Copy Source files
COPY src/ src/
COPY headers/ headers/
COPY test/ test/
COPY makefile .

# Build
RUN make all

# Run on entrance
CMD ["./cardsim"]
