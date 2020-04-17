FROM gcc
RUN mkdir /usr/src/app
COPY . /usr/src/app
WORKDIR /usr/src/app
RUN gcc isprime.c -O3 -ffast-math -o isprime
ENTRYPOINT ["./isprime"]