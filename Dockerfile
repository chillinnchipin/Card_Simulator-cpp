# Initial setup
FROM ubuntu:latest
WORKDIR /usr/cardsim/

# Install dependency
RUN apt update
RUN apt upgrade -y
RUN apt install g++ -y
RUN apt install make -y
RUN apt install git -y
RUN apt install cmake -y
RUN apt install libcunit1-dev -y 

# Copy Source files
COPY makefile .
COPY test/ test/
COPY src/ src/
COPY .git/ .git/

# Build
RUN cd /usr/cardsim 
RUN make all

# Run test
RUN ./tests Automated

# Run on entrance
CMD ["./cardsim"]
