# 32-bit wine for running MSVC under qemu-i386 on Apple Silicon (see th06/localtools/README.md)
FROM --platform=linux/386 debian:bookworm
RUN apt-get update && apt-get install -y --no-install-recommends \
      wine wine32 msitools p7zip-full cabextract python3 ca-certificates && \
    apt-get clean && rm -rf /var/lib/apt/lists/*
