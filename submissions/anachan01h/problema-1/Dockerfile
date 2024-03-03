FROM emilienmottet/nasm:latest

COPY . /problema-1
WORKDIR /problema-1
RUN make
ENTRYPOINT ["./bin/main"]
