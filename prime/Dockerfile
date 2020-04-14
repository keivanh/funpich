FROM gcc:4.9
RUN mkdir /app
COPY isprime.c /app
WORKDIR /app
RUN gcc isprime.c -O3 -std=c11 -lm -ffast-math -o isprime
ENTRYPOINT ["./app/isprime"]