# Initial setup
FROM ubuntu:latest
WORKDIR /usr/cardsim/

# Install dependency
RUN apt update
RUN apt upgrade -y
#RUN apt install gcc -y
RUN apt install g++ -y
RUN apt install make -y
RUN apt install git -y
RUN apt install cmake -y
RUN apt install libcunit1-dev -y 

# Copy Source files
COPY src/ src/
COPY headers/ headers/
COPY test/ test/
COPY makefile .
COPY .git/ .git/

# Build
# Build argparse
RUN ls -la headers/argparse && mkdir headers/argparse/build
RUN cd headers/argparse/build && cmake -DARGPARSE_BUILD_SAMPLES=on -DARGPARSE_BUILD_TESTS=on .. && make && make install
# Build cardsim
RUN cd /usr/cardsim 
RUN make all

# Run test
RUN ./tests Automated

# Run on entrance
CMD ["./cardsim"]
