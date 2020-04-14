FROM gcc:4.9
COPY isprime.c /usr/src/app
WORKDIR /usr/src/app
RUN gcc isprime.c -O3 -std=c11 -lm -ffast-math -o isprime
ENTRYPOINT ["./isprime"]