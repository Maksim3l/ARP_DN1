FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    gcc \
    g++ \
    git

WORKDIR /app

COPY . .

RUN g++ -o my_app ARP_DN1_PROG/*.cpp -std=c++11

CMD ["./my_app"]