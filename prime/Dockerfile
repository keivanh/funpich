FROM gcc:4.9
RUN mkdir /usr/src/app
COPY isprime.c /usr/src/appr
COPY isprime.h /usr/src/appr
WORKDIR /usr/src/app
RUN gcc isprime.c -O3 -std=c11 -lm -ffast-math -o isprime
ENTRYPOINT ["./isprime"]