FROM gcc:4.9
RUN mkdir /usr/src/app
COPY . /usr/src/app
WORKDIR /usr/src/app
RUN gcc isprime.c -O3 -std=c11 -lm -ffast-math -o isprime
ENTRYPOINT ["./isprime"]