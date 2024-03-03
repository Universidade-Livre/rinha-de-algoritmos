FROM emilienmottet/nasm:latest

COPY . /problema-2
WORKDIR /problema-2
RUN make all
ENTRYPOINT ["./bin/main"]
